#ifndef MULTI_SELECT 
#define MULTI_SELECT

#include <vector>
#include <string>

#include "Widget.hpp"

namespace CliWidget {

    class MultiSelect: public Widget {
       public:
           MultiSelect(const std::vector<std::string> &options);
           std::vector<int> getSelectedIndexes();
           std::vector<std::string> getSelectedValues();
           std::ostream& display(std::ostream &stream);

       private:
	       std::vector<bool> _boolIndexes;

           std::string getTextToPrint();
    };
}

#endif
