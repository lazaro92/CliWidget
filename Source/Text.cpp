/**
  Text widget: contains the implementation of the class Text
  @file Text.hpp
  @author Albert Lazaro de Lara
  @version 0.1 11/09/20 
  */

#include "CliWidget/Text.hpp"

namespace cliw {
    Text::Text(const std::string &text): _text(text) {

    }

    void Text::setText(const std::string &text) {
        _text = text;
    }

    std::string& Text::getText() {
        return _text;
    }

    void Text::setBackgroundColor(cliw::BackgroundColor color) {
        _bgrColor = color;
    }

    void Text::setForegroundColor(cliw::ForegroundColor color) {
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

    void Text::display() {
        if (_bgrColor != cliw::BackgroundColor::NONE)
            std::cout << "\033[" << _bgrColor << "m";
        if (_fgrColor != cliw::ForegroundColor::NONE)
            std::cout << "\033[" << _fgrColor << "m";
        if (_bold)
            std::cout << "\033[" << "1m";
        if (_underline)
            std::cout << "\033[" << "4m";
        if (_blink)
            std::cout << "\033[" << "5m";
        if (_italic)
            std::cout << "\033[" << "3m";
        std::cout << _text << "\033[0m" << std::endl;
    }
}
