FROM ubuntu:latest

RUN apt update && apt upgrade -y

RUN apt-get update && apt-get install -y make apt-utils sudo

WORKDIR /workspace

COPY Makefile preprocessing.cpp processing.py postpeocessing.cpp ./
