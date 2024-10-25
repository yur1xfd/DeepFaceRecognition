# DeepFaceRecognition
DeepFaceRecognition repository provide an ability to detect faces on images. To use our project follow this instruction:
```git clone https://github.com/yur1xfd/DeepFaceRecognition.git
```
You can use our project in 2 different scenatio.
1. Build locally with Makefile
   Install all dependencies
   ```
   make prereqs
   ```

2. Build with Docker
   Build docker image using Dockerfile
   ```
   docker build -t deepface
   ```
   Run builded image
   ```
   docker compose up -d
   ```
   Attach to container
   ```docker attach deepface-service-1
   ```
Put images you want to use for face recognition to /input_raw folder
To run our DeepFaceRecognition pipeline
Build executables
```
make build
```
Run preprocessing stage
```
make preprocessing
```
Run processing stage
```
make processing
```
Run postprocessing stage
```
make postprocessing
```
Now you have the results in the /output folder
Also you can run full pipeline with one command:
```
make run
```
   
    
Foundations of Software Engineering for AI course final project
Our team:
1. Ivan Listopadov
2. Sergey Grozny
3. Roman Dyachenko
4. Yurii Melnik
