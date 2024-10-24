FROM ubuntu:latest AS deepface

ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt update && apt upgrade -y
RUN apt-get update && apt-get install -y make apt-utils sudo

WORKDIR /workspace
COPY Makefile preprocessing.cpp processing.py postpeocessing.cpp ./

RUN make prereqs
