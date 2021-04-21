/**
  Text widget: contains the definition of the class Text
  @file Text.hpp
  @author Albert Lazaro de Lara
  @version 0.1 11/09/20 
  */

#ifndef TEXT_HPP
#define TEXT_HPP

#include <string>
#include <iostream>

#include "ColorsEnum.hpp"

namespace cliw {

    /**
      Create a widget that lets the user to display text with format
      */
    class Text {
        public:
            /**
              Create and sets the text to display.
              @param text The text to display
              */
            Text(const std::string &text); 

            /**
              set the text which will be displayed
              text The text to display
              */
            void setText(const std::string &text);  

            /**
              get the text to display
              @return the text to display
              */
            std::string &getText(); 

            /**
              set the background color of the text
              @param color The color of the background
              */
            void setBackgroundColor(cliw::BackgroundColor color);

            /**
              set the foreground color of the text
              @param color The color of the foreground
              */
            void setForegroundColor(cliw::ForegroundColor color);

            /**
              enable the underline format. The text will be underline
              @param enable If true enables the underline
              */
            void setUnderline(bool enable);

            /**
              enable the bold format. The text will be bold
              @param enable If true enables the bold
              */
            void setBold(bool  enable);

            /**
              enable the blink format. The text will blink
              @param enable If true enables blink
              */
            void setBlink(bool enable);

            /**
              enable the italic format. The text will have a italic format
              @param enable If true enables italic
              */
            void setItalic(bool enable);

            /**
              Display the widget in the terminal, showing the text in it
              */
            void display();

        private:
            /**
              The text to show
              */
            std::string _text;

            /**
              The underline format flag
              */
            bool _underline = false;

            /**
              The bold format flag
              */
            bool _bold = false;

            /**
              The blink format flag
              */
            bool _blink = false;

            /**
              The italic format flag
              */
            bool _italic = false;

            /**
              The foreground color
              */
            cliw::ForegroundColor _fgrColor = cliw::ForegroundColor::NONE;

            /**
              The background color
              */
            cliw::BackgroundColor _bgrColor = cliw::BackgroundColor::NONE;
    };
}

#endif

