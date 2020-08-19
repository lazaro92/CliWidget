#include "Select.hpp"

#include <vector>
#include <iostream>
#include <string>

int main() {
	Select select("Text with options:");

	std::vector<std::string> options = {"One", "Two", "Three"};
	select.setOptions(options);

	select.display(std::cout);

	return 0;
}
