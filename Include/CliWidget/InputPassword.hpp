/**
  Input password: contains the definition of the class InputPassword
  @file InputPassword.hpp
  @author Albert Lazaro de Lara
  @version 0.1 11/09/20 
  */

#ifndef INPUT_PASSWORD
#define INPUT_PASSWORD

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif
#include <string>

namespace cliw {

    /**
      Create a widget that lets the user to input their password
      */
    class InputPassword {
        public:
            InputPassword() = default;

            /**
              Get the entered password
              @return the password
              */
            std::string getValue();

            /**
              Sets the regex for validating the password
              @param regex The regex for validation
              */
            void setRegex(std::string regex);

            /**
              Display the widget in the terminal and captures the user input as password
              */
            void display();

            /**
              If a regex is setted, check if the password pass the regex
              @return true if regex is not setted or if the password pass the regex, false otherwise
              */
            bool check();
        private:
            /**
              The input password
              */
            std::string _value;

            /**
              The regex for checking the password
              */
            std::string _regex;

            /**
              Hide the terminal input and the cursor.
              @param reset If true reset the terminal to default, else hides the input and the cursor
             **/
            void changeTerminalMode(bool reset);

#if defined(_WIN32) || defined(_WIN64)
        private:
            HANDLE    hstdin;
            DWORD     mode;
#endif
    };
}

#endif
