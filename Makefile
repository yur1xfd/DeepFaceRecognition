.PHONY: all prereqs build preprocessing processing postprocessing

all: prereqs build preprocessing processing postprocessing test

run: preprocessing processing postprocessing

# Default target
prereqs:
	apt-get install -y \
    	ffmpeg \
    	libsm6 \
    	libxext6 \
    	libhdf5-dev \
    	python3 \
    	python3-pip \
    	git \
	vim \
	build-essential \
	libopencv-dev \
	apt-utils \
	pip install torch==2.4.1 torchvision==0.19.1
	git clone https://github.com/serengil/deepface.git
	cd deepface && pip install -e .
	cd ..
	pip install ultralytics tf-keras
	git clone https://github.com/nlohmann/json.git
	pip install pytest

build:
	g++ -c ./postprocessing.cpp -o postprocessing.o -std=c++17 -Ijson/single_include -I/usr/include/opencv4
	g++ -o postprocessing postprocessing.o -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_imgproc
	g++ -std=c++17 `pkg-config --cflags opencv4` -c preprocessing.cpp -o preprocessing.o
	g++ preprocessing.o `pkg-config --libs opencv4` -o preprocessing

preprocessing:
	rm -f ./input/*
	./preprocessing ./input_raw ./input

processing:
	rm -f ./output_raw/*
	python3 process.py -i "input" -o "output_raw"

postprocessing:
	rm -f ./output/*
	./postprocessing

test:
	python3 -m pytest run_tests.py
