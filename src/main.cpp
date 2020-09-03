#include <vector>
#include <iostream>
#include <string>

#include "Select.hpp"
#include "Text.hpp"

int main() {
	CliWidget::Select select(std::vector<std::string> {"One", "Two", "Three"});

	select.display(std::cout);

	int index = select.getSelectedIndex();
	std::string value = select.getSelectedValue();

    CliWidget::Text text1("Selected index is " + std::to_string(index) + "");
    CliWidget::Text text2("Selected value is " + value + "");

    text1.setBackgroundColor(CliWidget::BackgroundColor::GREEN);

    text1.display(std::cout);
    text2.display(std::cout);

//	std::cout << "Selected index is " << index << std::endl;
//	std::cout << "Selected value is " << value << std::endl;

	return 0;
}
