/**
  List: contains the implementation of the class List
  @file List.cpp
  @author Albert Lazaro de Lara
  @version 0.1 11/09/20 
  */

#include <cstdlib>
#include <csignal>

#include "List.hpp"

namespace CliWidget {

    List::List(const std::vector<std::string> &options) : _options(options)
    {

    }

    void List::setOptions(const std::vector<std::string> &options) {
        _options = options;
    }

    std::vector<std::string>& List::getOptions() {
        return _options;
    }


    void List::addOption(const std::string &option) {
        _options.push_back(option);
    }

    void List::removeOption(unsigned int index) {
        _options.erase(_options.begin() + index);
    }

    void List::changeTerminalMode(bool reset) {
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

    std::ostream& List::setTerminalCursor(std::ostream &stream) {
        return stream << "\033[" << _options.size() << "A\033[99D";
    }
}
