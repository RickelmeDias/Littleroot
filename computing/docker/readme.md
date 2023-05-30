# Docker

![image](https://user-images.githubusercontent.com/43411893/231831896-8e783dd2-4f17-44b2-a16a-f2fb6f0e4818.png)

## Getting Started

1. [How it works?](#how-it-works)
2. [What is a container](#what-is-a-container)
3. [Namespaces](#namespaces)
4. [Cgroups](#cgroups)
5. [Commands](#commands)
6. Containers
    - [How to create image and generate a container](./Images/)
    - [How to persist data in the container](./Persist/)
    - [Container networks](./Networks/)
    - [Using compose](./Compose/)

### How it works?

![Image of docker containers vs virtual machines](https://i.ytimg.com/vi/TvnZTi_gaNc/maxresdefault.jpg)

Docker containers are isolated from each other and from the host system. This means that each container runs independently and securely, without interfering with other containers or the host system.

Docker achieves isolation through the use of containerization technology. When a container is created, it is given its own isolated environment that includes its own file system, network interfaces, and other system resources. This is achieved through the use of kernel namespaces and control groups (cgroups) in the host operating system.

Kernel namespaces provide a way to create separate environments for different processes running on the same system. For example, each container has its own namespace for the file system, which means that it can only see and access the files and directories within its own container. This helps ensure that a container cannot interfere with other containers or the host system.

Control groups (cgroups) are another mechanism used by Docker to isolate containers. They allow Docker to control the amount of system resources (such as CPU, memory, and disk I/O) that a container can use. This helps prevent one container from using up too many resources and causing problems for other containers or the host system.

Overall, Docker containers are isolated from each other and from the host system through the use of containerization technology, which provides each container with its own independent environment and limits its access to system resources.


### What is a container

![what is docker by Julia Evans](https://pbs.twimg.com/media/EQGomZFWoAYIU3T.jpg:large)


### Namespaces

[What are namespaces and cgroups?](https://www.nginx.com/blog/what-are-namespaces-cgroups-how-do-they-work/)
![What are Kubernetes Pods Anyway? - Ian Lewis](https://user-images.githubusercontent.com/43411893/231826766-07690225-4902-4a70-8f40-5009850ff6c9.png)
There are several types of namespaces that Docker uses to isolate containers from each other and from the host system. Here is a list of some of the most common types of namespaces:
-   PID Namespace: Each container has its own namespace for process IDs, which means that each container can only see and access the processes that are running within its own container.
-   Network Namespace: Each container has its own namespace for network interfaces, which means that each container can only access the network resources that are allocated to it.
-   Mount Namespace: Each container has its own namespace for the file system, which means that each container can only see and access the files and directories within its own container.
-   UTS Namespace: Each container has its own namespace for the hostname and domain name, which means that each container can have its own unique name that is separate from the host system and other containers.
-   IPC Namespace: Each container has its own namespace for interprocess communication (IPC), which means that each container can only access the IPC resources that are allocated to it.
-   User Namespace: Each container has its own namespace for user and group IDs, which means that each container can have its own set of users and groups that are separate from the host system and other containers.

These namespaces help ensure that each container is isolated from other containers and from the host system, which makes it easier to manage and deploy applications within a Docker environment.
![namespaces by Julia Evans](https://pbs.twimg.com/media/EJgR3NeXYAAFMaj.jpg:large)

### Cgroups

![cgroups by Julia Evans](https://pbs.twimg.com/media/ENo1dPRWsAA1CQE.jpg:large)

### Commands

A list of commands that I think interesting to save:
  
- Run docker: `docker run -d IMAGE`
- Exec command on container: `docker exec -it CONTAINER echo "I'm inside the container!"`
- Stop container: `docker stop CONTAINER`
- Start container: `docker start CONTAINER`
- Pause container: `docker pause CONTAINER`
- Unpause container: `docker unpause CONTAINER`
- See layers from image: `docker history IMAGE`
- See runnings containers: `docker ps`
- See size of containers: `docker ps -s`
- See all container: `docker ps -a`
- Stop all containers: `docker stop $(docker container ls -q)`
- Remove all images: `docker rmi images $(docker image ls -aq)`
- Remove all containers: `docker rm $(docker container ls -aq)`
