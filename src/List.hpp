/**
List: contains the definition of the class List
@file List.hpp
@author Albert Lazaro de Lara
@version 0.1 11/09/20 
*/

#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <vector>
#include <string>
#include <iostream>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

#include "ColorsEnum.hpp"

namespace CliWidget {

    /**
      Parent class of Lists (for the moment List and MultiList)
      This can not be instantiated.
      */
    class List {
        public:
            /**
              Creates the widget and set the options
              @param options The options to display
              */
            List(const std::vector<std::string> &options);

            /**
              Set the vector of options
              @param options The options to display
              */
            void setOptions(const std::vector<std::string> &options);

            /**
              Get the options
              @return the options
              */
            std::vector<std::string> &getOptions();

            /**
              Add an option to the list
              @param option The option to append
              */
            virtual void addOption(const std::string &option);

            /**
              Remove the option at the index
              @param index The position of the option to remove
              */
            virtual void removeOption(unsigned int index);

            /**
              Set the bacground color for the current position
              @param bgColor The color
              */
            void setBackgroundColor(CliWidget::BackgroundColor bgColor);

            /**
              Display the widget in the terminal and lets the user to navigate between the options and select one of them
              */
            virtual void display() = 0;

            /**
              Default destructor (inheritance)
              */
            virtual ~List() = default;

        protected:

            /**
              Hide the terminal input and the cursor.
              @param reset If true reset the terminal to default, else hides the input and the cursor
             **/
#if defined(_WIN32) || defined(_WIN64)
            char changeTerminalMode(bool reset);
#else
            void changeTerminalMode(bool reset);
#endif

            /**
              Sets the terminal cursor to the first character written by the widget for replacing it
              */
            std::ostream& setTerminalCursor(std::ostream& stream);

            /**
              A vector of options
              */
            std::vector<std::string> _options;

            /**
              An index that points to the focused option 
              */
            std::vector<std::string>::size_type _index = 0;

            /**
              the cursor to indicate to the user the focused option
              */
            char _cursor = '>';

            /**
              The background color
              */
            CliWidget::BackgroundColor _bgColor = CliWidget::BackgroundColor::NONE;

#if defined(_WIN32) || defined(_WIN64)
            // TODO write -static const KEY_UP KEY_DOWN-
            static const int KEY_UP = 65;
            static const int KEY_DOWN = 66;
            static const int KEY_SPACE = 32;

        private:
            HANDLE    hstdin;
            DWORD     mode;

#else
            // TODO write -static const KEY_UP KEY_DOWN-
            static const int KEY_UP = 65;
            static const int KEY_DOWN = 66;
            static const int KEY_SPACE = 32;
#endif
    };
}

#endif
