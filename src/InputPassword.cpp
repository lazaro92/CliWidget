#include <cstdlib>
#include <csignal>
#include <iostream>
#include <regex>

#include "InputPassword.hpp"

namespace CliWidget {

    std::string InputPassword::getValue() {
        return _value;
    }

    void InputPassword::display() {
        changeTerminalMode(false);
        getline(std::cin, _value);
        changeTerminalMode(true);
    }

    bool InputPassword::check() {
        return _regex.empty() || std::regex_match(_value, std::regex(_regex));
    }

    void InputPassword::setRegex(std::string regex) {
        _regex = regex;
    }

    void InputPassword::changeTerminalMode(bool reset) {
        if (!reset) {
            // disable printing of keys as they're pressed
            system("stty -echo");
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
}
