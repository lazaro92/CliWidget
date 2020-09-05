#include "MultiSelect.hpp"

namespace CliWidget {

    MultiSelect::MultiSelect(const std::vector<std::string> &options) : Widget(options){
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

    std::ostream& MultiSelect::display(std::ostream &stream) {
        unsigned int c = 'A';

        changeTerminalMode(false);
        stream << getTextToPrint();

        do {
            c = std::cin.get();

            if (c == 'A' && _index > 0) {
                --_index;
                setTerminalCursor(stream);
                stream << getTextToPrint();
            }
            else if (c == 'B' && _index < _options.size() -1) {
                ++_index;
                setTerminalCursor(stream);
                stream << getTextToPrint();
            }
            else if (c == ' ') {
                _boolIndexes.at(_index) = !_boolIndexes.at(_index);
                setTerminalCursor(stream);
                stream << getTextToPrint();
            }
        } while(c != '\n');
        changeTerminalMode(true);
        return stream << std::endl;
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
