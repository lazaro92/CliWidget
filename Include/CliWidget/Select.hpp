/**
  Select widget: contains the definition of the class Select 
  @file Select.hpp
  @author Albert Lazaro de Lara
  @version 0.1 11/09/20 
  */

#ifndef SELECT_HPP
#define SELECT_HPP

#include <vector>
#include <string>

#include "List.hpp"

namespace CliWidget {

    /**
      Create a widget that lets the user select one item of a list
      */
    class Select: public List {
        public:
            /**
              sets the options for the list
              @param options The options for the list
              */
            Select(const std::vector<std::string> &options); 

            /**
              Return the index of the selected option
              @return the index of the selected option
              */
            unsigned int getSelectedIndex();

            /**
              Return the value of the selected option
              @return the value of the selected option
              */
            std::string getSelectedValue();

            /**
              Display the widget in the terminal and lets the user to navigate between the options and select one of them
              */
            void display() override;

            /**
              set the cursor character to distinct the current option where the user is
              @param cursor The character to represent it
              */
            void setCursor(char cursor);

        private:
            /**
              Return the options in a string format and the current option under the cursor
              @return the options in string format
              */
            std::string getTextToPrint();
    };
}

#endif
