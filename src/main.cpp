#include "Select.hpp"

#include <vector>
#include <iostream>
#include <string>

int main() {
	Select select("Text with options:");

	std::vector<std::string> options = {"One", "Two", "Three"};
	select.setOptions(options);

	select.display(std::cout);

	int index = select.getSelectedIndex();
	std::string value = select.getSelectedValue();

	std::cout << "Selected index is " << index << std::endl;
	std::cout << "Selected value is " << value << std::endl;

	return 0;
}
