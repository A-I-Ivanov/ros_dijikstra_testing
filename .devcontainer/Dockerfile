FROM ros:jazzy

RUN apt-get update && \
    apt-get install -y nano && \
    rm -rf /var/lib/apt/lists/*

RUN apt-get update \
  && apt-get install -y curl && \
    rm -rf /var/lib/apt/lists/*

#The ros jazzy image has a default user named "ubuntu"    
ARG USERNAME=ubuntu

#Change the default password to allow sudo access
RUN echo "ubuntu:pwd" | chpasswd
# [Optional] Set the default user. Omit if you want to keep the default as root.
USER $USERNAME


