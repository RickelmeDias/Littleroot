# Docker Compose

![Docker compose - come orchestrare diversi container - Flowygo](https://flowygo.com/wp-content/uploads/2021/01/docker-compose.jpg)

_[Docker Compose](https://docs.docker.com/compose/)_ is a tool for defining and running multi-container Docker applications. It allows you to define a set of containers, their configuration, and how they interact with each other in a single YAML file.

With Docker Compose, you can easily spin up and manage multiple Docker containers that work together as a single application. This can be especially useful for complex applications that require multiple containers, such as web applications that require a web server, a database server, and a caching server.

I used the documentation to install the plugin docker compose `https://docs.docker.com/compose/install/linux/#install-the-plugin-manually`.

So in short description, _Docker Compose will solve the problem of running multiple containers at once and in a coordinated way, avoiding running each run command individually_.

## Docker Compose Example

This file follows a logical idea according to the [previous explanations](../Networks/).

Is possible to run many docker containers with `docker run`, and we saw that is possible to run many dockers in a same custom networks, what allow an application running on a Container A to access the database running in a Container B if both are in the same network.

But to run many `docker run` manually is not a fast and organize way, instead, we will to improve it using the docker-compose tool. See an example for the last idea suggested and shown in the [Network Explanations](../Networks/)

```yml
version: "3.9"
services:
  mariadb:
    image: mariadb
    container_name: MARIA_DB_CONTAINER
    networks: 
      - MY_CUSTOM_BRIDGE_NETWORK
  
  myapplication:
    image: docker_user/my_application_image:1.0
    container_name: MY_APPLICATION
    networks: 
      - MY_CUSTOM_BRIDGE_NETWORK
    ports:
      - 3000:3000

networks:
  MY_CUSTOM_BRIDGE_NETWORK:
    driver: bridge
```

to run a docker-compose file just run: `docker-compose up` inside the yml directory, to remove the container and network use `docker-compose down`.

##### Improve

A good way to improve this yml is to add that `myapplication` depends of `mariadb` to start, so the mariadb will start first.

- [Depends on](https://docs.docker.com/compose/compose-file/05-services/#depends_on), see the example below:

```yml
  myapplication:
    image: docker_user/my_application_image:1.0
    container_name: MY_APPLICATION
    networks: 
      - MY_CUSTOM_BRIDGE_NETWORK
    ports:
      - 3000:3000
    depends-on:
      - mariadb
```