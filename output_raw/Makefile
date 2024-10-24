# Компилятор
CXX = g++

# Флаги компилятора
CXXFLAGS = -std=c++17 -Ijson/single_include -I/usr/include/opencv4

# Библиотеки
LDFLAGS = -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_imgproc

# Исходные файлы
SRCS = main.cpp

# Объектные файлы
OBJS = $(SRCS:.cpp=.o)

# Исполняемый файл
TARGET = DrawBoundingBoxes

# Правила сборки
all: install $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

install: 
	sudo apt-get install libopencv-dev
	git clone https://github.com/nlohmann/json.git

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean

