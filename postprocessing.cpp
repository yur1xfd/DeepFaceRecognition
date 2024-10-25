#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

void drawBoundingBoxes(const std::string& imagePath, const json& boxes, const std::string& outputPath) {
    cv::Mat image = cv::imread(imagePath);
    if (image.empty()) {
        std::cerr << "Error: Could not open image " << imagePath << std::endl;
        return;
    }

    for (const auto& box : boxes) {
        int x = box["x"];
        x = x*2;
        int y = box["y"];
        y = y*2;
        int w = box["w"];
        w = w*2;
        int h = box["h"];
        h = h*2;
        cv::rectangle(image, cv::Point(x, y), cv::Point(x + w, y + h), cv::Scalar(0, 0, 255), 2);
    }

    cv::imwrite(outputPath, image);
}

int main() {
    std::ifstream jsonFile("./output_raw/bounding_boxes.json");
    if (!jsonFile.is_open()) {
        std::cerr << "Error: Could not open JSON file" << std::endl;
        return 1;
    }

    json data;
    jsonFile >> data;
    for (const auto& [imagePath, boxes] : data.items()) {
        std::string x = imagePath;
        x.insert(5, "_raw");
        std::string outputPath = "./output/output_" + imagePath.substr(imagePath.find_last_of('/') + 1);
        drawBoundingBoxes(x, boxes, outputPath);
        std::cout << "Bounding boxes drawn on " << x << " and saved to " << outputPath << std::endl;
    }

    return 0;
}