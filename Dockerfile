FROM ubuntu:22.04

ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

WORKDIR /workspace
RUN apt-get update && apt-get install -y make
COPY Makefile preprocessing.cpp postprocessing.cpp process.py ./
RUN make prereqs
