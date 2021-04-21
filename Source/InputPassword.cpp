/**
  Input password: contains the definition of the class InputPassword
  @file InputPassword.cpp
  @author Albert Lazaro de Lara
  @version 0.1 11/09/20 
  */

#if !defined(_WIN32) || !defined(_WIN64)
#include <cstdlib>
#include <csignal>
#endif

#include <iostream>
#include <regex>

#include "CliWidget/InputPassword.hpp"

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
#if defined(_WIN32) || defined(_WIN64)
        hstdin = GetStdHandle(STD_INPUT_HANDLE);
        if (!reset) {
            GetConsoleMode(hstdin, &mode);
            SetConsoleMode(hstdin, mode & ~ENABLE_ECHO_INPUT);
        }
        else {
            SetConsoleMode(hstdin, mode);
        }
#else
        if (!reset) {
            // disable printing of keys as they're pressed
            system("stty -echo");

            atexit([](){
                    //Reset the terminal to a sensible state
                    system("stty sane; tput cnorm");
                    });

            // Ensure clean exit to reset the terminal if the program is killed
            signal(SIGTERM, [](int){exit(1);});
        }
        else {
            system("stty sane");
        }
#endif
    }
}
