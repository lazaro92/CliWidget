#include "Widget.hpp"

namespace CliWidget {
    
    void Widget::setText(const std::string &text) {
        _text = text;
    }

    std::string& Widget::getText() {
        return _text;
    }

    void Widget::setOptions(const std::vector<std::string> &options) {
        _options = options;
    }

    std::vector<std::string>& Widget::getOptions() {
        return _options;
    }

    void Widget::setCursor(char cursor) {
        _cursor = cursor;
    }

    void Widget::addOption(std::string &option) {
        _options.push_back(option);
    }

    void Widget::removeOption(unsigned int i) {
        _options.erase(_options.begin() + i);
    }
}
