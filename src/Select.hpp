#ifndef SELECT_HPP
#define SELECT_HPP

#include <vector>
#include <string>
#include <iostream>

namespace CliWidget {

    class Select {
        public:
            Select();
            Select(const std::string &text): _text(text) {}
            Select(std::vector<std::string> &options, const std::string &text) : _options(options), _text(text) {}

            void setText(const std::string &text); 
            std::string &getText(); 
            void setOptions(const std::vector<std::string> &options);
            std::vector<std::string> &getOptions();
            void setCursor(char cursor);

            void addOption(std::string &option);
            void removeOption(unsigned int i);
            unsigned int getSelectedIndex();
            std::string getSelectedValue();
            std::ostream& display(std::ostream &stream);

        private:
            void changeTerminalMode(bool reset);
            std::ostream& setTerminalCursor(std::ostream& stream);
            std::string getTextToPrint();

        private:
            std::vector<std::string> _options;
            std::string _text;
            std::vector<std::string>::size_type _index = 0;
            char _cursor = '>';
    };
}

#endif
