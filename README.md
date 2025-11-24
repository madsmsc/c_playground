# example output

```
Window reset!

List contents: 42 -> 84 -> 11 -> 7 -> 99 -> 

msg: 'Hello, world!' 
charSize: 1 
msgLen: 8
5th char should be 'o' : o
8th char should be 'w' : w

random str: xV9xb bWBw0IYB387bce

Book: bob
| page 0:  lv xobNvFOkpI4T2VuX tu6SY3C ZU7f zrLStMEPLm Qae 2
| page 1: T2Tx5NZKL1pVG8fk9RQEa4Vb EdY VkTmh R6B76nqS2W ZG3
| page 2: L6Z wEYn0h omP84otD QNHtt2Ej tqQPicPOqcvgbSMtnFp s
| page 3: nss qcbPPomSx rS B 7ahKQyn76Dw16JkqFniAMbLAClZpS 1
| page 4: 7IsbU8xKvh4cs8S0Mco E3 LpQ78N ijPs7MswjMGJvvYxPhxN

+- 32 bytes
|  +- 48 bytes
|  |  +- 48 bytes
|  |  |  +- 48 bytes
|  |  |  |  +- 48 bytes
|  |  |  |  |  +- 48 bytes
|  +- 53 bytes
|  +- 56 bytes
|  |  +- 36 bytes
|  |  +- 112 bytes
|  +- 83 bytes
|  +- 83 bytes
|  +- 83 bytes
|  +- 83 bytes
|  +- 83 bytes

Total allocated memory: 944 bytes

+- 32 bytes

Total allocated memory: 32 bytes
```



# Container

## Resources and packages

* [CMake](https://cmake.org/download)
* [Ninja](https://ninja-build.org)
* [GCC](https://gcc.gnu.org/)


## Requirements

* [WSL](https://learn.microsoft.com/en-us/windows/wsl/install)
* [Docker](https://docs.docker.com/engine/install/)

### WSL

Enable WSL on your machine by going to your windows cli and typing

    wsl --install

Now install a linux distro by running

    wsl --install Debian

If Debian is not your thing, you can get a list of available distros by running

    wsl --list --online


### Docker

Open a WSL terminal by typing 'wsl' in your favorite cli

#### Add Docker's official GPG key:
    sudo apt-get update
    sudo apt-get install ca-certificates curl
    sudo install -m 0755 -d /etc/apt/keyrings
    sudo curl -fsSL https://download.docker.com/linux/ubuntu/gpg -o /etc/apt/keyrings/docker.asc
    sudo chmod a+r /etc/apt/keyrings/docker.asc

#### Add the repository to Apt sources:
    echo \
    "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.asc] https://download.docker.com/linux/ubuntu \
    $(. /etc/os-release && echo "${UBUNTU_CODENAME:-$VERSION_CODENAME}") stable" | \
    sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
    sudo apt-get update

#### Install Docker engine
    sudo apt-get install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin

Check that the docker service is running:

    sudo systemctl status docker

NOTE It may be needed to run "(wsl) sudo systemctl start docker" after pc restart to start docker again


## Troubleshooting

### Container fails to launch

Make sure docker is running in WSL. Attempt a start up by executing

    wsl sudo systemctl start docker


### Dev Container responds that no Docker is installed

Make sure that the following setting is enabled in your VScode settings

    Dev > Containers: Execute in WSL (applies to all profiles)
