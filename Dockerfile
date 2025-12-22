FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y \
    build-essential clang make git pkg-config \
    curl ca-certificates \
    xorg x11-apps \
    libx11-dev libxext-dev zlib1g-dev libbsd-dev \
    && rm -rf /var/lib/apt/lists/*


WORKDIR /opt
RUN curl -L -o minilibx-linux.tgz "https://cdn.intra.42.fr/document/document/40487/minilibx-linux.tgz" \
    && tar -xzf minilibx-linux.tgz \
    && rm -f minilibx-linux.tgz

RUN make -C /opt/minilibx-linux

WORKDIR /work