#ifndef SELECT_HPP
#define SELECT_HPP

#include <vector>
#include <string>
#include <iostream>

#include "Widget.hpp"

namespace CliWidget {

    class Select: public Widget {
        public:
            Select();
            Select(const std::string &text): Widget(text) {}
            Select(std::vector<std::string> &options, const std::string &text) : Widget(options, text) {}

            unsigned int getSelectedIndex();
            std::string getSelectedValue();
            std::ostream& display(std::ostream &stream);

        private:
            void changeTerminalMode(bool reset);
            std::ostream& setTerminalCursor(std::ostream& stream);
            std::string getTextToPrint();
    };
}

#endif
