#include <opencv2/opencv.hpp>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

#define TARGET_WIDTH 640
#define TARGET_HEIGHT 640

void preprocess(const std::string &input_dir, const std::string 
&output_dir) {
    // Create output directory if it doesn't exist
    fs::create_directories(output_dir);

    for (const auto &entry : fs::directory_iterator(input_dir)) {
        if (entry.is_regular_file()) {
            std::string input_path = entry.path().string();
            std::string output_path = output_dir + "/" + 
entry.path().filename().string();

            // Read image
            cv::Mat img = cv::imread(input_path);
            if (img.empty()) {
                std::cerr << "Could not open or find the image: " << 
input_path << std::endl;
                continue;
            }
            int width = img.cols;   // Width of the image
            int height = img.rows;  // Height of the image
            // Resize image
            cv::Mat img_resized;
            cv::resize(img, img_resized, cv::Size(width /  2, 
height / 2));

            // Save processed image (convert back to uint8 for saving)
            cv::imwrite(output_path, img_resized);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_directory> <output_directory>" << std::endl;
        return EXIT_FAILURE;
    }

    preprocess(argv[1], argv[2]);
    return EXIT_SUCCESS;
}
