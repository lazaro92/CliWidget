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

           void addOption(const std::string &option) override;
           void removeOption(unsigned int i) override;
           
       private:
	       std::vector<bool> _boolIndexes;

           std::string getTextToPrint();
    };
}

#endif
