#include "Select.hpp"

namespace CliWidget {

    Select::Select(const std::vector<std::string> &options) : Widget(options) {
    
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
    
    std::ostream& Select::display(std::ostream &stream) {
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
        } while(c != '\n');


        changeTerminalMode(true);
        return stream << std::endl;
    }

    std::string Select::getTextToPrint() {
        std::string text = ""; 

        std::vector<std::string>::size_type i = 0;
        while (i < _options.size()) {
            if (i == _index) {
                text += std::string("\033[41m") + _cursor + " " + _options.at(i) + "\033[0m\n";
            }
            else {
                text += "  " + _options.at(i) + "\n";
            }
            ++i;
        }

        return text;
    }
}
