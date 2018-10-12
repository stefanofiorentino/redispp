#ifndef REDISPP_REDISPP_H
#define REDISPP_REDISPP_H

#ifdef __cplusplus
extern "C" {
#endif

int blocking_redispp(char **out_string, const char *hostname, int port, struct timeval *timeout, const char *command);

#ifdef __cplusplus
};
#endif

#endif //REDISPP_REDISPP_H
