FROM ubuntu:20.04
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y \
    gcc \ 
    build-essential  \
    software-properties-common \
    git \
    pkg-config \
    cmake  \
    libcurl4-openssl-dev --fix-broken \
    libjsoncpp-dev \
    librlog-dev \
    libgmock-dev \
    cpputest \
    libboost-all-dev && \
    rm -rf /var/lib/apt/lists/*
WORKDIR /home/RayTracer
