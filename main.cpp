#include <stdlib.h>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include "lib/redispp.h"

int main(int argc, char **argv)
{
    const char *hostname = (argc > 1) ? argv[1] : "127.0.0.1";
    int port = static_cast<int>((argc > 2) ? std::strtol(argv[2], nullptr, 10) : 6379);

    struct timeval timeout = {1, 500000}; // 1.5 seconds

    char *res = nullptr;
    int error_code;

    int counter = 30;
    while (counter > 0)
    {
        error_code = blocking_redispp(&res, hostname, port, &timeout, "PING");
        if (!error_code)
        {
            std::cout << res << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::seconds(5));
        counter--;
    }

    return 0;
}
