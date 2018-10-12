FROM gcc:7.3.0

RUN apt-get update
RUN apt-get install -y cmake
RUN apt-get install -y libhiredis-dev
RUN apt install redis-server -y
RUN apt install gdb -y

ADD . /usr/src/redispp

RUN chmod +x /usr/src/redispp/launcher.sh

RUN cd /usr/src/redispp \
    && mkdir -p build \
    && cd build \
    && cmake .. -DCMAKE_BUILD_TYPE=Debug \
    && make
