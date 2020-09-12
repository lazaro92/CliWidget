/**
  Text widget: contains the implementation of the class Text
  @file Text.hpp
  @author Albert Lazaro de Lara
  @version 0.1 11/09/20 
  */

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

    void Text::setBold(bool enable) {
        _bold = enable;
    }

    void Text::setUnderline(bool enable) {
        _underline = enable;
    }

    void Text::setBlink(bool enable) {
        _blink = enable;
    }

    void Text::setItalic(bool enable) {
        _italic = enable;
    }

    std::ostream& Text::display(std::ostream &stream) {
        if (_bgrColor != CliWidget::BackgroundColor::NONE)
            stream << "\033[" << _bgrColor << "m";
        if (_fgrColor != CliWidget::ForegroundColor::NONE)
            stream << "\033[" << _fgrColor << "m";
        if (_bold)
            stream << "\033[" << "1m";
        if (_underline)
            stream << "\033[" << "4m";
        if (_blink)
            stream << "\033[" << "5m";
        if (_italic)
            stream << "\033[" << "3m";
        stream << _text << "\033[0m" << std::endl;

        return stream;
    }
}
