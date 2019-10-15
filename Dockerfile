FROM amd64/ubuntu:bionic
RUN apt-get update && apt-get install -y sudo git iputils-ping vim curl
RUN apt-get install -y g++ cmake make libgtest-dev

RUN cd /usr/src/gtest && \
    sudo cmake CMakeLists.txt && \
    sudo make && \
    sudo cp *.a /usr/lib

RUN mkdir -p ~/boost && cd ~/boost
RUN cd ~/boost/ && curl -OL https://dl.bintray.com/boostorg/release/1.71.0/source/boost_1_71_0.tar.gz
RUN cd ~/boost/ && tar -xzf boost_1_71_0.tar.gz
RUN export BOOST_ROOT=~/boost/install/boost-1.71.0
RUN cd ~/boost/boost_1_71_0 && ./bootstrap.sh --prefix=$BOOST_ROOT
RUN cd ~/boost/boost_1_71_0 && ./b2
RUN cd ~/boost/boost_1_71_0 && ./b2 install
