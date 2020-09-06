#ifndef INPUT_PASSWORD
#define INPUT_PASSWORD

#include <string>

namespace CliWidget {
    class InputPassword {
        public:
            InputPassword() = default;
            std::string getValue();
            void setRegex(std::string);
            void display();
            bool check();
        private:
            std::string _value;
            std::string _regex;

            void changeTerminalMode(bool reset);
    };
}

#endif
