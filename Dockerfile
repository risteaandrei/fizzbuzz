FROM amd64/ubuntu:bionic
RUN apt-get update && apt-get install -y sudo git iputils-ping vim
RUN apt-get install -y g++ cmake make libgtest-dev
RUN cd /usr/src/gtest && sudo cmake CMakeLists.txt && sudo make && sudo cp *.a /usr/lib
 
