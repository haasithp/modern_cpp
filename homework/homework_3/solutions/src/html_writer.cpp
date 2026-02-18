#include "html_writer.hpp"

#include <filesystem>
#include <fmt/core.h>
#include <iostream>

namespace html_writer {

void OpenDocument() {
    fmt::print("<!DOCTYPE html>\n<html>\n");
}

void CloseDocument() {
    fmt::print("</html>\n");
}

void AddCSSStyle(const std::string& stylesheet) {
    fmt::print("<link rel=\"stylesheet\" type=\"text/css\" href=\"{}\" />\n", stylesheet);
}

void AddTitle(const std::string& title) {
    fmt::print("<head>\n<title>{}</title>\n", title);
}

void OpenBody() {
    fmt::print("</head>\n<body>\n");
}

void CloseBody() {
    fmt::print("</body>\n");
}

void OpenRow() {
    fmt::print("<div class=\"row\">\n");
}

void CloseRow() {
    fmt::print("</div>\n");
}

void AddImage(const std::string& image_path, float score, bool highlight) {
    std::filesystem::path p(image_path);
    std::string extension = p.extension().string();
    std::string filename = p.filename().string();
    if (extension == ".png" || extension == ".jpg" || extension == ".jpeg") {
        if (highlight) {
            fmt::print("<div class=\"column\" style=\"border: 5px solid green;\">\n");
        } else {
            fmt::print("<div class=\"column\">\n");
        }
        fmt::print("<h2>{}</h2>\n", filename);
        fmt::print("<img src=\"{}\" />\n", image_path);
        fmt::print("<p>score = {:.2f}</p>\n", score);
        fmt::print("</div>\n");
    } else {
        std::cerr << "Error: Invalid image extension: " << extension << std::endl;
    }
}

}  // namespace html_writer