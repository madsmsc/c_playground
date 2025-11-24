# Base image: Ubuntu Dev Container
# FROM mcr.microsoft.com/devcontainers/base:debian
FROM mcr.microsoft.com/devcontainers/base:ubuntu

# Root user for setup
USER root

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
    ninja-build \
    curl \
    make \
    tar \
    gcc \
    gdb \
    && rm -rf /var/lib/apt/lists/*

# Setup dir for packages installation
WORKDIR /tmp

#- CMake -----------------------------------------------------------------------
ARG CMAKE_VERSION=4.1.2
ARG CMAKE_URL="https://github.com/Kitware/CMake/releases/download/v$CMAKE_VERSION/cmake-$CMAKE_VERSION-linux-x86_64.tar.gz"
ARG CMAKE_HASH="https://github.com/Kitware/CMake/releases/download/v$CMAKE_VERSION/cmake-$CMAKE_VERSION-SHA-256.txt"

# Download and install package
RUN curl -sLO ${CMAKE_URL} && \
    curl -sL ${CMAKE_HASH} | grep $(basename "${CMAKE_URL}") | sha256sum -c - && \
    tar -xf $(basename "${CMAKE_URL}") -C /usr --strip-components=1 && \
    rm $(basename "${CMAKE_URL}")

#- Devcontainer utilities ------------------------------------------------------
ARG UTILS_INSTALL_DIR="/opt/devcontainer/"

# Add setup files and register in path
# COPY cmake-tools-kits.json ${UTILS_INSTALL_DIR}
ENV PATH=$PATH:${UTILS_INSTALL_DIR}bin

#- User setup ------------------------------------------------------------------
# Add plugdev group for non-root ttyUSB access
RUN usermod -aG plugdev vscode

USER vscode

VOLUME [ "/workspaces" ]
WORKDIR /workspaces
