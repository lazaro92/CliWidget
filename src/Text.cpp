#include "Text.hpp"

namespace CliWidget {
    Text::Text(const std::string &text): _text(text) {

    }

    void Text::setText(const std::string &text) {
        _text = text;
    }

    std::string& Text::getText() {
        return _text;
    }

    void Text::setBackgroundColor(CliWidget::BackgroundColor color) {
        _bgrColor = color;
    }

    void Text::setForegroundColor(CliWidget::ForegroundColor color) {
        _fgrColor = color;
    }

    void Text::setBold(bool bold) {
        _bold = bold;
    }

    std::ostream& Text::display(std::ostream &stream) {
        if (_bgrColor != CliWidget::BackgroundColor::NONE)
            stream << "\033[" << _bgrColor << "m";
        if (_fgrColor != CliWidget::ForegroundColor::NONE)
            stream << "\033[" << _fgrColor << "m";
        if (_bold)
            stream << "\033[" << "1m";
        stream << _text << "\033[0m" << std::endl;

        return stream;
    }
}
