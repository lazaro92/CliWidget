#ifndef SELECT_HPP
#define SELECT_HPP

#include <vector>
#include <string>

#include "Widget.hpp"

namespace CliWidget {

    class Select: public Widget {
        public:
            Select(const std::vector<std::string> &options); 

            unsigned int getSelectedIndex();
            std::string getSelectedValue();
            std::ostream& display(std::ostream &stream);
            void setCursor(char cursor);

        private:
            std::string getTextToPrint();
    };
}

#endif
