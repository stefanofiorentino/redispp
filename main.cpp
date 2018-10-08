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
    int error_code = blocking_redispp(&res, hostname, port, &timeout);
    if (!error_code)
    {
        std::cout << res << std::endl;
    }
}
