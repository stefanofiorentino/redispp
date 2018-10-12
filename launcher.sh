#!/bin/bash
export REDISPP_EXE=redispp_tester
export REDIS_HOSTNAME=cache
echo "$(date --universal --iso-8601=seconds) launching $REDISPP_EXE"
cd /usr/src/redispp/build
./$REDISPP_EXE $REDIS_HOSTNAME