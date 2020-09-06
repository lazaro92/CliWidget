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
            
            std::ostream& display(std::ostream &stream);

        private:
		    std::string _text;
            CliWidget::ForegroundColor _fgrColor = CliWidget::ForegroundColor::NONE;
            CliWidget::BackgroundColor _bgrColor = CliWidget::BackgroundColor::NONE;
    };
}

#endif

