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
        int y = box["y"];
        int w = box["w"];
        int h = box["h"];
        cv::rectangle(image, cv::Point(x, y), cv::Point(x + w, y + h), cv::Scalar(0, 0, 255), 2);
    }

    cv::imwrite(outputPath, image);
}

int main() {
    std::ifstream jsonFile("bounding_boxes.json");
    if (!jsonFile.is_open()) {
        std::cerr << "Error: Could not open JSON file" << std::endl;
        return 1;
    }

    json data;
    jsonFile >> data;

    for (const auto& [imagePath, boxes] : data.items()) {
        std::string outputPath = "output_" + imagePath.substr(imagePath.find_last_of('/') + 1);
        drawBoundingBoxes(imagePath, boxes, outputPath);
        std::cout << "Bounding boxes drawn on " << imagePath << " and saved to " << outputPath << std::endl;
    }

    return 0;
}

