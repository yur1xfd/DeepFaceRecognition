FROM ubuntu:24.04

ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

WORKDIR /workspace
RUN apt-get update && apt-get install -y make
COPY Makefile preprocessing.cpp postprocessing.cpp process.py run_tests.py ./
RUN make prereqs
