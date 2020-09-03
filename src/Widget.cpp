#include "Widget.hpp"

namespace CliWidget {
    
    Widget::Widget(const std::vector<std::string> &options) : _options(options)
    {
   
    }

    void Widget::setOptions(const std::vector<std::string> &options) {
        _options = options;
    }

    std::vector<std::string>& Widget::getOptions() {
        return _options;
    }


    void Widget::addOption(std::string &option) {
        _options.push_back(option);
    }

    void Widget::removeOption(unsigned int i) {
        _options.erase(_options.begin() + i);
    }
}
