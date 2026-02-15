#include <iostream>
#include <string>

int main(int argc, char* argv[]) {

    // Check for exactly two arguments
    if (argc != 3) {
        std::cerr << "Error: Exactly two input arguments are required.\n";
        return 1;
    }

    std::string arg1 = argv[1];
    std::string arg2 = argv[2];

    // Helper lambda to parse "<INT>.<EXT>"
    auto parse = [](const std::string& input, int& number, std::string& ext) -> bool {
        std::size_t dotPos = input.find('.');
        if (dotPos == std::string::npos) return false;

        try {
            number = std::stoi(input.substr(0, dotPos));
        } catch (...) {
            return false;
        }

        ext = input.substr(dotPos + 1);
        return true;
    };

    int num1, num2;
    std::string ext1, ext2;

    if (!parse(arg1, num1, ext1) || !parse(arg2, num2, ext2)) {
        std::cerr << "Error: Invalid input format.\n";
        return 1;
    }

    // Both .txt → mean
    if (ext1 == "txt" && ext2 == "txt") {
        double mean = (num1 + num2) / 2.0;
        std::cout << mean << std::endl;
    }
    // Both .png → sum
    else if (ext1 == "png" && ext2 == "png") {
        std::cout << (num1 + num2) << std::endl;
    }
    // First .txt and second .png → modulo
    else if (ext1 == "txt" && ext2 == "png") {
        if (num2 == 0) {
            std::cerr << "Error: Division by zero.\n";
            return 1;
        }
        std::cout << (num1 % num2) << std::endl;
    }
    else {
        std::cerr << "Error: Unsupported file extensions.\n";
        return 1;
    }

    return 0;
}