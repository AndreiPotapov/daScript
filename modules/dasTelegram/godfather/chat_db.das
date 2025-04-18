options gen2
options indenting = 4
options no_unused_block_arguments = false
options no_unused_function_arguments = false

module chat_db shared private

require sqlite/sqlite_boost

struct public UserEntry {
    user_id : int64
    is_bot : bool
    first_name : string
    last_name : string
    user_name : string
}

struct public ChatLogEntry {
    id : int64
    chat_id : int64
    message_id : int64
    date : int64
    from_id : int64
    reply_to_message : int64
    text : string
    transcription : string
}

struct public SummaryEntry {
    chat_id : int64
    id : int64
    text : string
}

struct public ChannelRights {
    chat_id : int64
    description : string
    decode_voice : bool
    draw_pictures : bool
    bot_answers : bool
    summary : bool
}

struct public ApiUseEntry {
    user_id : int64
    server_time : int64
    chat_id : int64
    message_id : int64
    tokens : int64
    voice_bytes : int64
}

var private g_db : sqlite3? = null

[finalize]
def private close_chat_log {
    if (g_db != null) {
        sqlite3_close(g_db)
        g_db = null
    }
}

def private create_chat_table {
    var sql = "CREATE TABLE IF NOT EXISTS chat_log (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                chat_id INTEGER,
                message_id INTEGER,
                date INTEGER,
                from_id INTEGER,
                reply_to_message INTEGER,
                text TEXT,
                transcription TEXT);"
    var rc = sqlite3_exec(g_db, sql, null)
    if (rc != SQLITE_OK) {
        to_log(LOG_ERROR, "Error creating table chat_log: {sqlite3_errmsg(g_db)}\n")
        return false
    }
    sql = "CREATE TABLE IF NOT EXISTS users (
                user_id INTEGER UNIQUE,
                is_bot INTEGER,
                first_name TEXT,
                last_name TEXT,
                user_name TEXT);"
    rc = sqlite3_exec(g_db, sql, null)
    if (rc != SQLITE_OK) {
        to_log(LOG_ERROR, "Error creating table users: {sqlite3_errmsg(g_db)}\n")
        return false
    }
    sql = "CREATE TABLE IF NOT EXISTS summary_log (
                chat_id INTEGER,
                id INTEGER,
                text TEXT);"
    rc = sqlite3_exec(g_db, sql, null)
    if (rc != SQLITE_OK) {
        to_log(LOG_ERROR, "Error creating table summary_log: {sqlite3_errmsg(g_db)}\n")
        return false
    }
    sql = "CREATE TABLE IF NOT EXISTS channel_rights (
                chat_id INTEGER PRIMARY KEY,
                description TEXT,
                decode_voice INTEGER,
                draw_pictures INTEGER,
                bot_answers INTEGER,
                summary INTEGER);"
    rc = sqlite3_exec(g_db, sql, null)
    if (rc != SQLITE_OK) {
        to_log(LOG_ERROR, "Error creating table summary_log: {sqlite3_errmsg(g_db)}\n")
        return false
    }
    sql = "CREATE TABLE IF NOT EXISTS api_use (
                user_id INTEGER,
                server_time INTEGER,
                chat_id INTEGER,
                message_id INTEGER,
                tokens INTEGER,
                voice_bytes INTEGER);"
    rc = sqlite3_exec(g_db, sql, null)
    if (rc != SQLITE_OK) {
        to_log(LOG_ERROR, "Error creating table api_use: {sqlite3_errmsg(g_db)}\n")
        return false
    }
    return true
}

def public reset_chat(chat_id : int64) {
    var sql = "DELETE FROM chat_log WHERE chat_id = {chat_id};"
    var rc = sqlite3_exec(g_db, sql, null)
    if (rc != SQLITE_OK) {
        to_log(LOG_ERROR, "Error creating table chat_log: {sqlite3_errmsg(g_db)}\n")
        return false
    }
    sql = "DELETE FROM summary_log WHERE chat_id = {chat_id};"
    rc = sqlite3_exec(g_db, sql, null)
    if (rc != SQLITE_OK) {
        to_log(LOG_ERROR, "Error creating table chat_log: {sqlite3_errmsg(g_db)}\n")
        return false
    }
    return true
}

def public create_chat_log(dbname : string) {
    var rc = sqlite3_open(dbname, g_db)
    if (rc != SQLITE_OK) {
        to_log(LOG_ERROR, "Cannot open database: {sqlite3_errmsg(g_db)}\n")
        sqlite3_close(g_db)
        g_db = null
        return false
    }
    rc = sqlite3_exec(g_db, "PRAGMA journal_mode=WAL", null)
    if (rc != SQLITE_OK) {
        to_log(LOG_ERROR, "Cannot set journal mode: {sqlite3_errmsg(g_db)}\n")
        sqlite3_close(g_db)
        g_db = null
        return false
    }
    if (!create_chat_table()) {
        sqlite3_close(g_db)
        g_db = null
        return false
    }
    return true
}

def public write_to_log(entry : ChatLogEntry) {
    var sql = "INSERT INTO chat_log (chat_id, message_id, date, from_id, reply_to_message, text, transcription) VALUES (?, ?, ?, ?, ?, ?, ?)"
    var stmt : sqlite3_stmt?
    var rc = sqlite3_prepare_v2(g_db, sql, -1, unsafe(addr(stmt)), null)
    if (rc != SQLITE_OK) {
        to_log(LOG_ERROR, "Error preparing statement: {sqlite3_errmsg(g_db)}\n")
        return false
    }
    sqlite3_bind_int64(stmt, 1, entry.chat_id)
    sqlite3_bind_int64(stmt, 2, entry.message_id)
    sqlite3_bind_int64(stmt, 3, entry.date)
    sqlite3_bind_int64(stmt, 4, entry.from_id)
    sqlite3_bind_int64(stmt, 5, entry.reply_to_message)
    sqlite3_bind_text(stmt, 6, entry.text)
    sqlite3_bind_text(stmt, 7, entry.transcription)
    rc = sqlite3_step(stmt)
    if (rc != SQLITE_DONE) {
        to_log(LOG_ERROR, "Error inserting data: {sqlite3_errmsg(g_db)}\n")
        return false
    }
    return true
} finally {
    sqlite3_finalize(stmt)
}

def public write_user(user : UserEntry) {
    var sql = "INSERT OR IGNORE INTO users (user_id, is_bot, first_name, last_name, user_name) VALUES (?, ?, ?, ?, ?)"
    var stmt : sqlite3_stmt?
    var rc = sqlite3_prepare_v2(g_db, sql, -1, unsafe(addr(stmt)), null)
    if (rc != SQLITE_OK) {
        to_log(LOG_ERROR, "Error preparing statement: {sqlite3_errmsg(g_db)}\n")
        return false
    }
    sqlite3_bind_int64(stmt, 1, user.user_id)
    sqlite3_bind_int(stmt, 2, user.is_bot ? 1 : 0)
    sqlite3_bind_text(stmt, 3, user.first_name)
    sqlite3_bind_text(stmt, 4, user.last_name)
    sqlite3_bind_text(stmt, 5, user.user_name)
    rc = sqlite3_step(stmt)
    if (rc != SQLITE_DONE) {
        to_log(LOG_ERROR, "Error inserting data: {sqlite3_errmsg(g_db)}\n")
        return false
    }
    return true
} finally {
    sqlite3_finalize(stmt)
}

def public write_summary(summary : SummaryEntry) {
    var sql = "INSERT OR IGNORE INTO summary_log (chat_id, id, text) VALUES (?, ?, ?)"
    var stmt : sqlite3_stmt?
    var rc = sqlite3_prepare_v2(g_db, sql, -1, unsafe(addr(stmt)), null)
    if (rc != SQLITE_OK) {
        to_log(LOG_ERROR, "Error preparing statement: {sqlite3_errmsg(g_db)}\n")
        return false
    }
    sqlite3_bind_int64(stmt, 1, summary.chat_id)
    sqlite3_bind_int64(stmt, 2, summary.id)
    sqlite3_bind_text(stmt,  3, summary.text)
    rc = sqlite3_step(stmt)
    if (rc != SQLITE_DONE) {
        to_log(LOG_ERROR, "Error inserting data: {sqlite3_errmsg(g_db)}\n")
        return false
    }
    return true
} finally {
    sqlite3_finalize(stmt)
}

def public write_api_use(api_use : ApiUseEntry) {
    var sql = "INSERT INTO api_use (user_id, server_time, chat_id, message_id, tokens, voice_bytes) VALUES (?, ?, ?, ?, ?, ?)"
    var stmt : sqlite3_stmt?
    var rc = sqlite3_prepare_v2(g_db, sql, -1, unsafe(addr(stmt)), null)
    if (rc != SQLITE_OK) {
        to_log(LOG_ERROR, "Error preparing statement: {sqlite3_errmsg(g_db)}\n")
        return false
    }
    sqlite3_bind_int64(stmt, 1, api_use.user_id)
    sqlite3_bind_int64(stmt, 2, api_use.server_time)
    sqlite3_bind_int64(stmt, 3, api_use.chat_id)
    sqlite3_bind_int64(stmt, 4, api_use.message_id)
    sqlite3_bind_int64(stmt, 5, api_use.tokens)
    sqlite3_bind_int64(stmt, 6, api_use.voice_bytes)
    rc = sqlite3_step(stmt)
    if (rc != SQLITE_DONE) {
        to_log(LOG_ERROR, "Error inserting data: {sqlite3_errmsg(g_db)}\n")
        return false
    }
    return true
} finally {
    sqlite3_finalize(stmt)
}

def public list_unique_users(chat_id : int64) : array<int64> {
    var sql = "SELECT DISTINCT from_id FROM chat_log WHERE chat_id = ?"
    var stmt : sqlite3_stmt?
    var rc = sqlite3_prepare_v2(g_db, sql, -1, unsafe(addr(stmt)), null)
    if (rc != SQLITE_OK) {
        to_log(LOG_ERROR, "Error preparing statement: {sqlite3_errmsg(g_db)}\n")
        return <- array<int64>()
    }
    sqlite3_bind_int64(stmt, 1, chat_id)
    var users : array<int64>
    while (true) {
        rc = sqlite3_step(stmt)
        if (rc == SQLITE_DONE) {
            break
        }
        if (rc != SQLITE_ROW) {
            to_log(LOG_ERROR, "Error reading data: {sqlite3_errmsg(g_db)}\n")
            return <- array<int64>()
        }
        users |> push(sqlite3_column_int64(stmt, 0))
    }
    return <- users
} finally {
    sqlite3_finalize(stmt)
}

def public list_chat_users(chat_id : int64; blk : block<(entry : UserEntry) : void>) {
    var stmt : sqlite3_stmt?
    var inscope users <- list_unique_users(chat_id)
    if (users |> empty) {
        return false
    }
    var inscope user_table : table<int64>
    for (u in users) {
        user_table |> insert(u)
    }
    var sql = "SELECT user_id, is_bot, first_name, last_name, user_name FROM users"
    var rc = sqlite3_prepare_v2(g_db, sql, -1, unsafe(addr(stmt)), null)
    if (rc != SQLITE_OK) {
        to_log(LOG_ERROR, "Error preparing statement: {sqlite3_errmsg(g_db)}\n")
        return false
    }
    while (true) {
        rc = sqlite3_step(stmt)
        if (rc == SQLITE_DONE) {
            break
        }
        if (rc != SQLITE_ROW) {
            to_log(LOG_ERROR, "Error reading data: {sqlite3_errmsg(g_db)}\n")
            return false
        }
        let user_id = sqlite3_column_int64(stmt, 0)
        if (user_table |> key_exists(user_id)) {
            var entry = UserEntry(
                user_id = user_id,
                is_bot = sqlite3_column_int(stmt, 1) != 0,
                first_name = sqlite3_column_text_(stmt, 2),
                last_name = sqlite3_column_text_(stmt, 3),
                user_name = sqlite3_column_text_(stmt, 4)
            )
            invoke(blk, entry)
        }
    }
    return true
} finally {
    sqlite3_finalize(stmt)
}

def public list_all_users(blk : block<(entry : chat_db::UserEntry const) : void>) {
    var sql = "SELECT user_id, is_bot, first_name, last_name, user_name FROM users"
    var stmt : sqlite3_stmt?
    var rc = sqlite3_prepare_v2(g_db, sql, -1, unsafe(addr(stmt)), null)
    if (rc != SQLITE_OK) {
        to_log(LOG_ERROR, "Error preparing statement: {sqlite3_errmsg(g_db)}\n")
        return false
    }
    while (true) {
        rc = sqlite3_step(stmt)
        if (rc == SQLITE_DONE) {
            break
        }
        if (rc != SQLITE_ROW) {
            to_log(LOG_ERROR, "Error reading data: {sqlite3_errmsg(g_db)}\n")
            return false
        }
        var entry = UserEntry(
            user_id = sqlite3_column_int64(stmt, 0),
            is_bot = sqlite3_column_int(stmt, 1) != 0,
            first_name = sqlite3_column_text_(stmt, 2),
            last_name = sqlite3_column_text_(stmt, 3),
            user_name = sqlite3_column_text_(stmt, 4)
        )
        invoke(blk, entry)
    }
    return true
} finally {
    sqlite3_finalize(stmt)
}

def public list_chat_log(chat_id : int64; last_n_entries : int; blk : block<(entry : ChatLogEntry) : void>) {
    var sql = "SELECT id, message_id, date, from_id, reply_to_message, text, transcription
                FROM chat_log
                WHERE chat_id = @cid
                ORDER BY id DESC
                LIMIT @limit"
    var stmt : sqlite3_stmt?
    var rc = sqlite3_prepare_v2(g_db, sql, -1, unsafe(addr(stmt)), null)
    if (rc != SQLITE_OK) {
        to_log(LOG_ERROR, "Error preparing statement: {sqlite3_errmsg(g_db)}\n")
        return false
    }
    sqlite3_bind_int64(stmt, sqlite3_bind_parameter_index(stmt, "@cid"), chat_id)
    sqlite3_bind_int(stmt, sqlite3_bind_parameter_index(stmt, "@limit"), last_n_entries)
    while (true) {
        rc = sqlite3_step(stmt)
        if (rc == SQLITE_DONE) {
            break
        }
        if (rc != SQLITE_ROW) {
            to_log(LOG_ERROR, "Error reading data: {sqlite3_errmsg(g_db)}\n")
            return false
        }
        var entry <- ChatLogEntry(
            id = sqlite3_column_int64(stmt, 0),
            chat_id = chat_id,
            message_id = sqlite3_column_int64(stmt, 1),
            date = sqlite3_column_int64(stmt, 2),
            from_id = sqlite3_column_int64(stmt, 3),
            reply_to_message = sqlite3_column_int64(stmt, 4),
            text = sqlite3_column_text_(stmt, 5),
            transcription = sqlite3_column_text_(stmt, 6)
        )
        invoke(blk, entry)
    }
    return true
} finally {
    sqlite3_finalize(stmt)
}

def public list_conversation_log(chat_id, bot_id : int64; bot_name : string; n_entries : int; blk : block<(entry : ChatLogEntry) : void>) {
    var sql = "SELECT id, message_id, date, from_id, reply_to_message, text, transcription
                FROM chat_log
                WHERE chat_id = @cid
                    AND (from_id = @botid
                        OR reply_to_message = @botid
                        OR text LIKE @botname)
                ORDER BY id DESC
                LIMIT @limit;"
    var stmt : sqlite3_stmt?
    var rc = sqlite3_prepare_v2(g_db, sql, -1, unsafe(addr(stmt)), null)
    if (rc != SQLITE_OK) {
        to_log(LOG_ERROR, "Error preparing statement: {sqlite3_errmsg(g_db)}\n")
        return false
    }
    sqlite3_bind_int64(stmt, sqlite3_bind_parameter_index(stmt, "@cid"), chat_id)
    sqlite3_bind_int64(stmt, sqlite3_bind_parameter_index(stmt, "@botid"), bot_id)
    sqlite3_bind_int(stmt, sqlite3_bind_parameter_index(stmt, "@limit"), n_entries)
    sqlite3_bind_text(stmt, sqlite3_bind_parameter_index(stmt, "@botname"), "%{bot_name}%")
    while (true) {
        rc = sqlite3_step(stmt)
        if (rc == SQLITE_DONE) {
            break
        }
        if (rc != SQLITE_ROW) {
            to_log(LOG_ERROR, "Error reading data: {sqlite3_errmsg(g_db)}\n")
            return false
        }
        var entry <- ChatLogEntry(
            id = sqlite3_column_int64(stmt, 0),
            chat_id = chat_id,
            message_id = sqlite3_column_int64(stmt, 1),
            date = sqlite3_column_int64(stmt, 2),
            from_id = sqlite3_column_int64(stmt, 3),
            reply_to_message = sqlite3_column_int64(stmt, 4),
            text = sqlite3_column_text_(stmt, 5),
            transcription = sqlite3_column_text_(stmt, 6)
        )
        invoke(blk, entry)
    }
    return true
} finally {
    sqlite3_finalize(stmt)
}

def public get_first_summary(chat_id : int64; dayZ : int64) : tuple<id : int64; text : string> {
    var sql = "SELECT id, text
                FROM summary_log
                WHERE chat_id=@cid AND id<@dayZ
                ORDER BY id DESC LIMIT 1;"
    var stmt : sqlite3_stmt?
    var rc = sqlite3_prepare_v2(g_db, sql, -1, unsafe(addr(stmt)), null)
    if (rc != SQLITE_OK) {
        to_log(LOG_ERROR, "Error preparing statement: {sqlite3_errmsg(g_db)}\n")
        return (-1l, "")
    }
    sqlite3_bind_int64(stmt, sqlite3_bind_parameter_index(stmt, "@cid"), chat_id)
    sqlite3_bind_int64(stmt, sqlite3_bind_parameter_index(stmt, "@dayZ"), dayZ)
    rc = sqlite3_step(stmt)
    if (rc == SQLITE_DONE) {
        to_log(LOG_ERROR, "Error reading data: {sqlite3_errmsg(g_db)}\n")
        return (-1l, "")
    }
    if (rc != SQLITE_ROW) {
        to_log(LOG_ERROR, "Error reading data: {sqlite3_errmsg(g_db)}\n")
        return (-1l, "")
    }
    return (sqlite3_column_int64(stmt, 0), sqlite3_column_text_(stmt, 1))
} finally {
    sqlite3_finalize(stmt)
}

def public list_channel_rights(blk : block<(rights : ChannelRights) : void>) {
    var sql = "SELECT chat_id, description, decode_voice, draw_pictures, bot_answers, summary
                FROM channel_rights
                ORDER BY chat_id"
    var stmt : sqlite3_stmt?
    var rc = sqlite3_prepare_v2(g_db, sql, -1, unsafe(addr(stmt)), null)
    if (rc != SQLITE_OK) {
        to_log(LOG_ERROR, "Error preparing statement: {sqlite3_errmsg(g_db)}\n")
        return false
    }
    while (true) {
        rc = sqlite3_step(stmt)
        if (rc == SQLITE_DONE) {
            break
        }
        if (rc != SQLITE_ROW) {
            to_log(LOG_ERROR, "Error reading data: {sqlite3_errmsg(g_db)}\n")
            return false
        }
        var rights <- ChannelRights(
            chat_id = sqlite3_column_int64(stmt, 0),
            description = sqlite3_column_text_(stmt, 1),
            decode_voice = sqlite3_column_int(stmt, 2) != 0,
            draw_pictures = sqlite3_column_int(stmt, 3) != 0,
            bot_answers = sqlite3_column_int(stmt, 4) != 0,
            summary = sqlite3_column_int(stmt, 5) != 0
        )
        invoke(blk, rights)
    }
    return true
} finally {
    sqlite3_finalize(stmt)
}

def public get_channel_rights(chat_id : int64) {
    var sql = "SELECT description, decode_voice, draw_pictures, bot_answers, summary
                FROM channel_rights
                WHERE chat_id = ?"
    var stmt : sqlite3_stmt?
    var rc = sqlite3_prepare_v2(g_db, sql, -1, unsafe(addr(stmt)), null)
    if (rc != SQLITE_OK) {
        to_log(LOG_ERROR, "Error preparing statement: {sqlite3_errmsg(g_db)}\n")
        return ChannelRights()
    }
    sqlite3_bind_int64(stmt, 1, chat_id)
    rc = sqlite3_step(stmt)
    if (rc == SQLITE_DONE) {
        return ChannelRights()
    }
    if (rc != SQLITE_ROW) {
        to_log(LOG_ERROR, "Error reading data: {sqlite3_errmsg(g_db)}\n")
        return ChannelRights()
    }
    return ChannelRights(
        chat_id = chat_id,
        description = sqlite3_column_text_(stmt, 0),
        decode_voice = sqlite3_column_int(stmt, 1) != 0,
        draw_pictures = sqlite3_column_int(stmt, 2) != 0,
        bot_answers = sqlite3_column_int(stmt, 3) != 0,
        summary = sqlite3_column_int(stmt, 4) != 0
    )
} finally {
    sqlite3_finalize(stmt)
}

def public set_channel_rights(rights : ChannelRights) {
    var sql = "INSERT OR REPLACE INTO channel_rights (chat_id, description, decode_voice, draw_pictures, bot_answers, summary) VALUES (?, ?, ?, ?, ?, ?)"
    var stmt : sqlite3_stmt?
    var rc = sqlite3_prepare_v2(g_db, sql, -1, unsafe(addr(stmt)), null)
    if (rc != SQLITE_OK) {
        to_log(LOG_ERROR, "Error preparing statement: {sqlite3_errmsg(g_db)}\n")
        return false
    }
    sqlite3_bind_int64(stmt, 1, rights.chat_id)
    sqlite3_bind_text(stmt, 2, rights.description)
    sqlite3_bind_int(stmt, 3, rights.decode_voice ? 1 : 0)
    sqlite3_bind_int(stmt, 4, rights.draw_pictures ? 1 : 0)
    sqlite3_bind_int(stmt, 5, rights.bot_answers ? 1 : 0)
    sqlite3_bind_int(stmt, 6, rights.summary ? 1 : 0)
    rc = sqlite3_step(stmt)
    if (rc != SQLITE_DONE) {
        to_log(LOG_ERROR, "Error inserting data: {sqlite3_errmsg(g_db)}\n")
        return false
    }
    return true
} finally {
    sqlite3_finalize(stmt)
}

def public delete_channel_rights(chat_id : int64) {
    var sql = "DELETE FROM channel_rights WHERE chat_id=?"
    var stmt : sqlite3_stmt?
    var rc = sqlite3_prepare_v2(g_db, sql, -1, unsafe(addr(stmt)), null)
    if (rc != SQLITE_OK) {
        to_log(LOG_ERROR, "Error preparing statement: {sqlite3_errmsg(g_db)}\n")
        return false
    }
    sqlite3_bind_int64(stmt, 1, chat_id)
    rc = sqlite3_step(stmt)
    if (rc != SQLITE_DONE) {
        to_log(LOG_ERROR, "Error deleting data: {sqlite3_errmsg(g_db)}\n")
        return false
    }
    return true
} finally {
    sqlite3_finalize(stmt)
}

def public get_all_api_use(blk : block<(use : ApiUseEntry) : void>) {
    let sql = "SELECT user_id, SUM(tokens) AS total_tokens, SUM(voice_bytes) AS total_voice_bytes
                FROM api_use
                GROUP BY user_id ORDER BY total_tokens DESC"
    var stmt : sqlite3_stmt?
    var rc = sqlite3_prepare_v2(g_db, sql, -1, unsafe(addr(stmt)), null)
    if (rc != SQLITE_OK) {
        to_log(LOG_ERROR, "Error preparing statement: {sqlite3_errmsg(g_db)}\n")
        return false
    }
    while (true) {
        rc = sqlite3_step(stmt)
        if (rc == SQLITE_DONE) {
            break
        }
        if (rc != SQLITE_ROW) {
            to_log(LOG_ERROR, "Error reading data: {sqlite3_errmsg(g_db)}\n")
            return false
        }
        var use <- ApiUseEntry(
            user_id = sqlite3_column_int64(stmt, 0),
            tokens = sqlite3_column_int64(stmt, 1),
            voice_bytes = sqlite3_column_int64(stmt, 2)
        )
        invoke(blk, use)
    }
    return true
} finally {
    sqlite3_finalize(stmt)
}

