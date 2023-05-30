# Docker Images

![Understanding and Building Docker Images by JFROG](https://jfrog--c.documentforce.com/servlet/servlet.ImageServer?id=01569000008kqFT&oid=00D20000000M3v0&lastMod=1631619825000)

A Docker image is a read-only file that serves as a template for creating Docker containers. It contains a set of instructions that define how a container should be configured and the applications and services that should be installed within it. Docker images can be created and customized using a Dockerfile, which is a text file that specifies the configuration of the container and the steps required to build the image.

Docker images can be shared and distributed through public or private Docker registries, making it easy to deploy and scale applications across multiple environments. They are also immutable, which means that once an image is created, it cannot be modified. Instead, any changes to the container must be made by creating a new image based on the original image.

Containers are writable, but it is temporary, if execute a new container it not persist the data saved or modified, for [persist data using Docker read this](../Persist).

## Getting Started

How to build a new image on Docker using the image create by myself:

In this case the image created by myself is the [Dockerfile](./Dockerfile)

```docker
docker build -t rickelmedias/app-node:1.0 .
```

The `.` after image name (rickelmedias/app-node:1.0) is the Dockerfile local, in this case it is in the same folder that I was running the command.

See the images:
```docker
docker images
```

Running image:
```docker
docker run -d -p 80:6000 rickelmedias/app-node:1.0
```

Now is possible to access the application created using express.js dependency on node.js, how to:
1. Open the browser
2. access: http://localhost:80

## What is the Dockerfile

A Dockerfile is a text file that contains a set of instructions for building a Docker image.

It is a good way to create own Docker images.

In this example, I created this:

```dockerfile
FROM node:14
WORKDIR /app-node

ARG PORT_BUILD=6000
ENV PORT=$PORT_BUILD 
EXPOSE $PORT_BUILD

COPY . .
RUN npm install
ENTRYPOINT npm start
```

What these statements used above means:
- FROM: Is a statement in a Dockerfile is used to define the base image for the Docker image that you are creating. The base image contains the operating system (e.g. ubuntu) and other dependencies (e.g. node) that your Docker image will be built upon;
- WORKDIR: Is a Dockerfile instruction that is used to set the working directory for any subsequent instructions in the Dockerfile;
- ARG: This instruction is used to declare variables that can be passed to the Docker build command at runtime. The values of these variables can then be used within the Dockerfile to customize the build process, when the proccess is finished it is not inside the container _(to allow it, is necessary to use the ENV statament too)_.
- ENV: This instruction is used to set environment variables within the container that is created from the Docker image.
- EXPOSE: This instruction is like a documentation, it will inform Docker that the container will listen on the specified network ports at runtime, it allow to show the ports of our application when run `docker ps`.
- COPY: This instruction is used to copy files and directories from the host machine to the container. In this case all files from this folder to the `/app-node` on container.
- RUN: This instruction is used to execute a command inside the container during the build process. In this case the `npm install` will be running during the build process and will generate the `node_modules` file with the dependencies for the node project inside the folder `/app-node`.
- ENTRYPOINT: This instruction is used to configure the primary command that should be run when a container is started from the image. In this case the `npm start` will be the first command executed on the container, and it will start a server with express.js. The express server allow to access the `http:localhost:port/` route and get a message _Hello World!_ on webpage.
