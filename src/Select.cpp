#include <cstdlib>
#include <csignal>

#include "Select.hpp"

namespace CliWidget {

    void Select::setText(const std::string &text) {
        _text = text;
    }

    std::string& Select::getText() {
        return _text;
    }

    void Select::setOptions(const std::vector<std::string> &options) {
        _options = options;
    }

    std::vector<std::string>& Select::getOptions() {
        return _options;
    }

    void Select::setCursor(char cursor) {
        _cursor = cursor;
    }

    void Select::addOption(std::string &option) {
        _options.push_back(option);
    }

    void Select::removeOption(unsigned int i) {
        _options.erase(_options.begin() + i);
    }

    unsigned int Select::getSelectedIndex() {
        return _index;
    }

    std::string Select::getSelectedValue() {
        return _options.at(_index);
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

    void Select::changeTerminalMode(bool reset) {
        if (!reset) {
            // Disable special processing of characters (e.g. delete line) and set the minimum number read to 1
            // disable printing of keys as they're pressed
            system("stty cbreak min 1 -echo");

            atexit([](){
                    //Reset the terminal to a sensible state
                    system("stty sane");
                    });

            // Ensure clean exit to reset the terminal if the program is killed
            signal(SIGTERM, [](int){exit(1);});
        }
        else {
            system("stty sane");
        }
    }

    std::ostream& Select::setTerminalCursor(std::ostream &stream) {
        return stream << "\033[" << _options.size()+1 << "A\033[99D";
    }

    std::string Select::getTextToPrint() {
        std::string text = _text + '\n';

        std::vector<std::string>::size_type i = 0;
        while (i < _options.size()) {
            if (i == _index) {
                text += std::string("\033[41m") + _cursor + " " + _options.at(i) + "\033[0m\n";
            }
            else {
                text += "  " + _options.at(i) + '\n';
            }
            ++i;
        }

        return text;
    }

}
