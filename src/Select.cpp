/**
  Select widget: contains the implementation of the class Select 
  @file Select.cpp
  @author Albert Lazaro de Lara
  @version 0.1 11/09/20 
  */

#include "Select.hpp"

namespace CliWidget {

    Select::Select(const std::vector<std::string> &options) : List(options) {
    
    }

    unsigned int Select::getSelectedIndex() {
        return _index;
    }

    std::string Select::getSelectedValue() {
        return _options.at(_index);
    }

    void Select::setCursor(char cursor) {
        _cursor = cursor;
    }
    
    void Select::display() {
        unsigned int c = 'A';
        bool arrowKeyPressed = false;

        changeTerminalMode(false);
        std::cout << getTextToPrint();

        do {
            c = std::cin.get();
            if (c == '[') {
                arrowKeyPressed = true;
            }
            else if (c == 'A' && _index > 0 && arrowKeyPressed) {
                --_index;
                arrowKeyPressed = false;
                setTerminalCursor(std::cout);
                std::cout << getTextToPrint();
            }
            else if (c == 'B' && (_index < _options.size() -1) && arrowKeyPressed) {
                ++_index;
                arrowKeyPressed = false; 
                setTerminalCursor(std::cout);
                std::cout << getTextToPrint();
            }
        } while(c != '\n');

        changeTerminalMode(true);
    }

    std::string Select::getTextToPrint() {
        std::string text = "", bgBegin = "", bgEnd ="";

        if (_bgColor != CliWidget::BackgroundColor::NONE) {
            bgBegin = "\033[" + _bgColor + "m";
            bgEnd = "\033[0m";
        }
        
        std::vector<std::string>::size_type i = 0;
        while (i < _options.size()) {
            if (i == _index) {
                text += bgBegin +_cursor + " " + _options.at(i) + bgEnd + "\n";
            }
            else {
                text += "  " + _options.at(i) + "\n";
            }
            ++i;
        }

        return text;
    }
}
