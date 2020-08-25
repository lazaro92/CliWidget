#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <vector>
#include <string>

namespace CliWidget {
    
    class Widget {
        public:
            Widget() = default;
            Widget(const std::string &text): _text(text) {}
            Widget(std::vector<std::string> &options, const std::string &text) : _options(options), _text(text) {}

            void setText(const std::string &text); 
            std::string &getText(); 
            void setOptions(const std::vector<std::string> &options);
            std::vector<std::string> &getOptions();
            void setCursor(char cursor);
            
            void addOption(std::string &option);
            void removeOption(unsigned int i);

            virtual ~Widget() = default;
        protected:
            std::vector<std::string> _options;
		    std::string _text;
		    std::vector<std::string>::size_type _index = 0;
            char _cursor = '>';
    };
}

#endif
