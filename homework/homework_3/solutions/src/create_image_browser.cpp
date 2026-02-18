#include "image_browser.hpp"
#include <iostream>
#include <vector>
#include <tuple>

int main() {
    using namespace image_browser;
    std::vector<ImageRow> rows;
    
    // Create some dummy data based on example.html
    ScoredImage img1 = {"data/000000.png", 0.98f};
    ScoredImage img2 = {"data/000100.png", 0.96f};
    ScoredImage img3 = {"data/000200.png", 0.88f};
    rows.push_back({img1, img2, img3});

    ScoredImage img4 = {"data/000300.png", 0.87f};
    ScoredImage img5 = {"data/000400.png", 0.80f};
    ScoredImage img6 = {"data/000500.png", 0.79f};
    rows.push_back({img4, img5, img6});

    ScoredImage img7 = {"data/000600.png", 0.76f};
    ScoredImage img8 = {"data/000700.png", 0.75f};
    ScoredImage img9 = {"data/000800.png", 0.20f};
    rows.push_back({img7, img8, img9});

    CreateImageBrowser("Image Browser", "style.css", rows);
    return 0;
}
