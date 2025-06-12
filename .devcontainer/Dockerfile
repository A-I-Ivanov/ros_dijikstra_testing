FROM ros:jazzy

ENV ROS_DISTRO=jazzy

RUN apt-get update && \
    apt-get install -y nano && \
    rm -rf /var/lib/apt/lists/*

RUN apt-get update &&\
    apt-get install -y curl && \
    rm -rf /var/lib/apt/lists/*

RUN apt-get install bash-completion

RUN apt-get install git

RUN . /opt/ros/$ROS_DISTRO/setup.sh 

RUN curl https://raw.githubusercontent.com/git/git/v2.41.0/contrib/completion/git-completion.bash \
    -o /etc/bash_completion.d/.git-completion.bash \
    echo 'source /etc/bash_completion.d/.git-completion.bash' >> ~/.bashrc

#The ros jazzy image has a default user named "ubuntu"    
ARG USERNAME=ubuntu

#Change the default password to allow sudo access
RUN echo "ubuntu:pwd" | chpasswd
# [Optional] Set the default user. Omit if you want to keep the default as root.
USER $USERNAME




