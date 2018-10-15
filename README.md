# Step by step (require 2 terminals)
## Terminal 1
### host$ 
docker exec -it cache bash
### cache$ 
redis-cli monitor #here you can see results
## Terminal 2
### host$ 
docker run -ti --link cache:cache --security-opt seccomp:unconfined redispp_redispp /usr/src/redispp/build/redispp_tester

# All in one Terminal
## Composer
docker-compose up --build --abort-on-container-exit