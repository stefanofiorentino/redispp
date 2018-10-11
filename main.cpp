#include <stdlib.h>
#include <string>
#include <iostream>
#include "lib/redispp.h"

int main(int argc, char **argv)
{
    const char *hostname = (argc > 1) ? argv[1] : "127.0.0.1";
    int port = static_cast<int>((argc > 2) ? std::strtol(argv[2], nullptr, 10) : 6379);

    struct timeval timeout = {1, 500000}; // 1.5 seconds

    char *res;
    int error_code;

    error_code = blocking_redispp(&res, hostname, port, &timeout, "PING");
    if (!error_code)
    {
        std::cout << res << std::endl;
    }

    if (res)
    {
        free(res);
        res = nullptr;
    }
    error_code = blocking_redispp(&res, hostname, port, &timeout, R"(HSET 1bcbbfa0-1303-463d-b882-519277892faa status "on")");
    if (!error_code && res)
    {
        std::cout << res << std::endl;
    }

    if (res)
    {
        free(res);
        res = nullptr;
    }
    error_code = blocking_redispp(&res, hostname, port, &timeout, "HGET 1bcbbfa0-1303-463d-b882-519277892faa status");
    if (!error_code && res)
    {
        std::cout << res << std::endl;
    }

    if (res)
    {
        free(res);
        res = nullptr;
    }
    error_code = blocking_redispp(&res, hostname, port, &timeout, R"(HSET 1bcbbfa0-1303-463d-b882-519277892faa level "50")");
    if (!error_code && res)
    {
        std::cout << res << std::endl;
    }

    if (res)
    {
        free(res);
        res = nullptr;
    }
    error_code = blocking_redispp(&res, hostname, port, &timeout, "HGET 1bcbbfa0-1303-463d-b882-519277892faa level");
    if (!error_code && res)
    {
        std::cout << res << std::endl;
    }

    if (res)
    {
        free(res);
        res = nullptr;
    }
    error_code = blocking_redispp(&res, hostname, port, &timeout, R"(HSET 1bcbbfa0-1303-463d-b882-519277892faa color.H "360")");
    if (!error_code && res)
    {
        std::cout << res << std::endl;
    }

    if (res)
    {
        free(res);
        res = nullptr;
    }
    error_code = blocking_redispp(&res, hostname, port, &timeout, "HGET 1bcbbfa0-1303-463d-b882-519277892faa color.H");
    if (!error_code && res)
    {
        std::cout << res << std::endl;
    }

    if (res)
    {
        free(res);
        res = nullptr;
    }
    error_code = blocking_redispp(&res, hostname, port, &timeout, R"(HSET 1bcbbfa0-1303-463d-b882-519277892faa color.S "100")");
    if (!error_code && res)
    {
        std::cout << res << std::endl;
    }

    if (res)
    {
        free(res);
        res = nullptr;
    }
    error_code = blocking_redispp(&res, hostname, port, &timeout, "HGET 1bcbbfa0-1303-463d-b882-519277892faa color.S");
    if (!error_code && res)
    {
        std::cout << res << std::endl;
    }

    if (res)
    {
        free(res);
        res = nullptr;
    }
    error_code = blocking_redispp(&res, hostname, port, &timeout, R"(HSET 1bcbbfa0-1303-463d-b882-519277892faa color.V "100")");
    if (!error_code && res)
    {
        std::cout << res << std::endl;
    }

    if (res)
    {
        free(res);
        res = nullptr;
    }
    error_code = blocking_redispp(&res, hostname, port, &timeout, "HGET 1bcbbfa0-1303-463d-b882-519277892faa color.V");
    if (!error_code && res)
    {
        std::cout << res << std::endl;
    }

}
