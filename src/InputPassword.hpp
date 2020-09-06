#ifndef INPUT_PASSWORD
#define INPUT_PASSWORD

#include <string>

namespace CliWidget {
    class InputPassword {
        public:
            InputPassword() = default;
            std::string getValue();
            void display();

        private:
            std::string value;
            void changeTerminalMode(bool reset);
    };
}

#endif
