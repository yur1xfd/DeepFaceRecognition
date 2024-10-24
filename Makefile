.PHONY: all prereqs build preprocessing postprocessing

all: prereqs build preprocessing processing postprocessing

run: preprocessing processing postprocessing

# Default target
prereqs:
        sudo apt-get install libopencv-dev
        git clone https://github.com/nlohmann/json.git 
build:
        g++ -c ./postprocessing.cpp -o postprocessing.o -std=c++17 -Ijson/single_include -I/usr/include/opencv4
        g++ -o postprocessing postprocessing.o -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_imgproc
        g++ -std=c++17 `pkg-config --cflags opencv4` -c preprocessing.cpp -o preprocessing.o
        g++ preprocessing.o `pkg-config --libs opencv4` -o preprocessing

preprocessing:
	./preprocessing

processing:
	
postprocessing:
        ./postprocessing
