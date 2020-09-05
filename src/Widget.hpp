#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <vector>
#include <string>
#include <iostream>

namespace CliWidget {
    
    class Widget {
        public:
            Widget(const std::vector<std::string> &options);

            void setOptions(const std::vector<std::string> &options);
            std::vector<std::string> &getOptions();
            
            void addOption(std::string &option);
            void removeOption(unsigned int i);

            virtual ~Widget() = default;
        protected:
            void changeTerminalMode(bool reset);
            std::ostream& setTerminalCursor(std::ostream& stream);

            std::vector<std::string> _options;
		    std::vector<std::string>::size_type _index = 0;
            char _cursor = '>';
    };
}

#endif
