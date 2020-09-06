#ifndef TEXT_HPP
#define TEXT_HPP

#include <string>
#include <iostream>

#include "ColorsEnum.hpp"

namespace CliWidget {
    
    class Text {
        public:
            Text(const std::string &text); 

            void setText(const std::string &text);  
            std::string &getText(); 
            void setBackgroundColor(CliWidget::BackgroundColor color);
            void setForegroundColor(CliWidget::ForegroundColor color);
            void setUnderline(bool underline);
            void setBold(bool bold);
            void setBlink(bool  blink);
            void setItalic(bool italic);
            std::ostream& display(std::ostream &stream);

        private:
		    std::string _text;
            bool _underline = false;
            bool _bold = false;
            bool _blink = false;
            bool _italic = false;
            CliWidget::ForegroundColor _fgrColor = CliWidget::ForegroundColor::NONE;
            CliWidget::BackgroundColor _bgrColor = CliWidget::BackgroundColor::NONE;
    };
}

#endif

