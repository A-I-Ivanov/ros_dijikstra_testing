FROM ros:jazzy

ENV ROS_DISTRO=jazzy

RUN apt-get update && \
    apt-get install -y nano && \
    apt install python3-pip && \
    apt install python3-colcon-clean && \
    rm -rf /var/lib/apt/lists/*

RUN apt-get update && \
    apt-get install -y curl && \
    apt-get install bash-completion -y && \
    rm -rf /var/lib/apt/lists/* 

RUN apt-get update && \
    apt-get install -y openssh-client && \
    rm -rf /var/lib/apt/lists/* 

RUN apt-get update && \
    apt install software-properties-common && \
    add-apt-repository universe && \
    apt install ros-jazzy-ament-cmake-clang-format && \
    rm -rf /var/lib/apt/lists/* 

RUN . /opt/ros/$ROS_DISTRO/setup.sh 

#The ros jazzy image has a default user named "ubuntu"    
ARG USERNAME=ubuntu

#Change the default password to allow sudo access
RUN echo "ubuntu:pwd" | chpasswd
# [Optional] Set the default user. Omit if you want to keep the default as root.
USER $USERNAME




