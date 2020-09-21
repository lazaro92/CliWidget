/**
  Multi Select widget: contains the implementation of the class MultiSelect 
  @file MultiSelect.cpp
  @author Albert Lazaro de Lara
  @version 0.1 11/09/20 
  */

#include "MultiSelect.hpp"

namespace CliWidget {

    MultiSelect::MultiSelect(const std::vector<std::string> &options) : List(options){
        _boolIndexes = std::vector<bool> (options.size(), false);
    }

    std::vector<int> MultiSelect::getSelectedIndexes() {
        std::vector<int> indexes;

        std::vector<bool>::size_type i = 0;
        while (i < _boolIndexes.size()) {
            if (_boolIndexes.at(i)) {
                indexes.push_back(i);
            }
            ++i;
        }

        return indexes;
    }

    std::vector<std::string> MultiSelect::getSelectedValues() {
        std::vector<std::string> values;

        std::vector<bool>::size_type i = 0;
        while (i < _boolIndexes.size()) {
            if (_boolIndexes.at(i)) {
                values.push_back(_options.at(i));
            }
            ++i;
        }

        return values;
    }

    void MultiSelect::display() {
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
            else if (c == ' ') {
                _boolIndexes.at(_index) = !_boolIndexes.at(_index);
                setTerminalCursor(std::cout);
                std::cout << getTextToPrint();
            }
        } while(c != '\n');
        changeTerminalMode(true);
    }

    void MultiSelect::addOption(const std::string &option) {
        _options.push_back(option);
        _boolIndexes.push_back(false);
    }

    void MultiSelect::removeOption(unsigned int index) {
        _options.erase(_options.begin() + index);
        _boolIndexes.erase(_boolIndexes.begin() + index);
    }

    std::string MultiSelect::getTextToPrint() {
        std::string text = ""; 

        std::vector<std::string>::size_type i = 0;
        while (i < _options.size()) {
            if (_boolIndexes.at(i)) 
                text += "+";
            else 
                text += "-";

            if (i == _index) 
                text += std::string("\033[41m") + _cursor + " " + _options.at(i) + "\033[0m\n";
            else 
                text += "  " + _options.at(i) + "\n";
            ++i;
        }

        return text;
    }
}
