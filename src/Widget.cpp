#include <cstdlib>
#include <csignal>

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

    void Widget::changeTerminalMode(bool reset) {
        if (!reset) {
            // Disable special processing of characters (e.g. delete line) and set the minimum number read to 1
            // disable printing of keys as they're pressed
            system("stty cbreak min 1 -echo");
            system("tput civis");

            atexit([](){
                    //Reset the terminal to a sensible state
                    system("stty sane");
                    system("tput cnorm");
                    });

            // Ensure clean exit to reset the terminal if the program is killed
            signal(SIGTERM, [](int){exit(1);});
        }
        else {
            system("stty sane");
            system("tput cnorm");
        }
    }

    std::ostream& Widget::setTerminalCursor(std::ostream &stream) {
        return stream << "\033[" << _options.size() << "A\033[99D";
    }
}
