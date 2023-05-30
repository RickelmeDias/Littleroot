# Docker Persist

## Getting Started

1. [The Problem](#the-problem)
2. [How to Persist Data](#how-to-persist-data)
    - [Bind Mounts](#bind-mounts)
    - [Volumes](#volumes)

### The problem

The problem happen when is necessary to persist data, transit it, and not lose it when have a problem with a container or when is necessary to up other containers that will use same data or a part of some datas.

Let see this problem in practice...

Run a container:

`docker run -it ubuntu bash`

See the size of this container started now running `docker container ls -s`:

```
CONTAINER ID   IMAGE     COMMAND   CREATED          STATUS          PORTS     NAMES          SIZE
fakeid001122   ubuntu    "bash"    27 seconds ago   Up 23 seconds             jovial_tharp   0B (virtual 77.8MB)
```

The size virtual 77.8 MB in the container started is like the total image size, to see the image total size run `docker history ubuntu`:

```
IMAGE          CREATED       CREATED BY                                      SIZE      COMMENT
fakeid001122   5 weeks ago   /bin/sh -c #(nop)  CMD ["/bin/bash"]            0B        
<missing>      5 weeks ago   /bin/sh -c #(nop) ADD file:ccccccccccccccccc…   77.8MB    
```

With this idea is possible to notice that the container size without count the virtual size (77.8 MB), in fact is 0 B.

If run the command `apt-get update` inside this container, it will install deps on container and grow the size.

After finish the update inside container, and run again the command `docker container ls -s`, will show:

```
CONTAINER ID   IMAGE     COMMAND   CREATED          STATUS          PORTS     NAMES          SIZE
fakeid001122   ubuntu    "bash"    9 minutes ago    Up 9 minutes              jovial_tharp   42.8MB (virtual 77.8MB)
```

If run the command `docker history ubuntu`, the image will show the same information again. It means that our container can save (Write files) and the image can't. Each container has its own separate writing layer, if start 5 containers ubuntu, only this one that we run `apt-get update` will have these files.

See:

![Docker Image VS Container: What is the difference? on PhoenixNAP](https://phoenixnap.com/kb/wp-content/uploads/2021/04/container-layers.png)

## How to Persist Data

![Manage data in Docker | Docker Documentation](https://docs.docker.com/storage/images/types-of-mounts.png)


### Bind mounts

A Docker bind mount is a way to mount a directory or file from the host machine into a Docker container. This allows the container to access and modify files on the host system, so **this solution provide a bind between the host machine directory and a container directory.**

To make this bind exists two ways:

Simple way

```bash
docker run -it -v /home/$USER/host_folder:/cont_folder ubuntu bash
```

Recommended way

```bash
docker run -it --mount type=bind,source=/home/$USER/host_folder,target=/cont_folder ubuntu bash
```

This code above means that all files save in the container directory with the name `/cont_folder` also need be persisted in the host directory named by `/home/$USER/host_folder`.

After running the code above, use `ls` to list:

```bash
bin   cont_folder  etc   lib    lib64   media  opt   root  sbin  sys  usr
boot  dev          home  lib32  libx32  mnt    proc  run   srv   tmp  var
```

Is possible to see **cont_folder**, the new folder create by us on container.

So if access the dir `/cont_folder` in the container and create a new file `touch file_example.py` it will be added also to the host machine dir `/home/$USER/host_folder`.

Is possible to check if the file was persisted using the command `ls /home/$USER/host_folder` on the host machine.

### Volumes

Volues are more recommended in some cases, because the volumes are managed by the docker inside of our filesystem, so it is more secure, because the docker will managed instead an user.

- Create a docker volume: `docker volume create mydockervolume`
- List docker volumes `docker volume ls`.

To use these volumes created is like the bind, see an example:

Simple way

```bash
docker run -it -v mydockervolume:/cont_folder ubuntu bash
```

Recommended way

```bash
docker run -it --mount source=mydockervolume,target=/cont_folder ubuntu bash
```

**Q:** Where the `mydockervolume` is generated ?
**A:** In the directory `/var/lib/docker/volumes`

**Q:** How to see the files inside my volume ?
**A:** Run the list to see files `sudo ls /var/lib/docker/volumes/mydockervolume` 