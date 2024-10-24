.PHONY: all prereqs build preprocessing postprocessing

all: prereqs build preprocessing processing postprocessing

run: preprocessing processing postprocessing

# Default target
prereqs:
        sudo apt-get install libopencv-dev
        git clone https://github.com/nlohmann/json.git ./output_raw
build:

preprocessing:

processing:

postprocessing:
