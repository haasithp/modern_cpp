#include "image_browser.hpp"

#include "html_writer.hpp"

namespace image_browser {

void AddFullRow(const ImageRow& row, bool first_row) {
    for (size_t i = 0; i < row.size(); ++i) {
        const auto& [path, score] = row[i];
        bool highlight = first_row && (i == 0);
        html_writer::AddImage(path, score, highlight);
    }
}

void CreateImageBrowser(const std::string& title, const std::string& stylesheet,
                        const std::vector<ImageRow>& rows) {
    html_writer::OpenDocument();
    html_writer::AddTitle(title);
    html_writer::AddCSSStyle(stylesheet);
    html_writer::OpenBody();

    for (size_t i = 0; i < rows.size(); ++i) {
        html_writer::OpenRow();
        AddFullRow(rows[i], i == 0);
        html_writer::CloseRow();
    }

    html_writer::CloseBody();
    html_writer::CloseDocument();
}

}  // namespace image_browser
