/**
  Multi Select widget: contains the definition of the class MultiSelect 
  @file MultiSelect.hpp
  @author Albert Lazaro de Lara
  @version 0.1 11/09/20 
  */

#ifndef MULTI_SELECT 
#define MULTI_SELECT

#include <vector>
#include <string>

#include "List.hpp"

namespace CliWidget {

    /**
      Create a widget that lets the user to select one or more items of a list
      */
    class MultiSelect: public List {
        public:
            /**
              sets the options for the list
              @param options The options for the list
              */
            MultiSelect(const std::vector<std::string> &options);

            /**
              return the index of the selected elements from the user
              @return a vector with the the indexes of the selected items
              */
            std::vector<int> getSelectedIndexes();

            /**
              return the values of the selected elements from the user
              @return a vector with the vaules of the selected items
              */
            std::vector<std::string> getSelectedValues();

            /**
              Display the widget in the terminal and lets the user to navigate between the options and select them
              */
            void display() override;

            /**
              Adds an option to the options vector
              @param option The option to add
              */
            void addOption(const std::string &option) override;

            /**
              Remove the option at the selected index
              @param index The index
              */
            void removeOption(unsigned int index) override;

        private:
            /**
              A vector for knowing which options have been selected (true)
              */
            std::vector<bool> _boolIndexes;

            /**
              Return the options in a string format, the current option under the cursor and if the options are selected (+) or not (-)
              @return the options in string format
              */
            std::string getTextToPrint();
    };
}

#endif
