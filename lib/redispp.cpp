#include "redispp.h"
#include <hiredis.h>
#include <string.h>


int blocking_redispp(char **out_string, const char *hostname, int port, struct timeval *timeout, const char *command)
{
    redisContext *conn;
    redisReply *reply;
    conn = redisConnectWithTimeout(hostname, port, *timeout);
    if (conn == NULL || conn->err)
    {
        if (conn)
        {
            redisFree(conn);
        }
        return 1;
    }

    /* PING server */

    reply = static_cast<redisReply *>(redisCommand(conn, command));
    if (reply->str)
    {
        *out_string = strdup(reply->str);
    }
    freeReplyObject(reply);
    redisFree(conn);
    return 0;
}
