#include <vector>
#include <iostream>
#include <string>

#include "Select.hpp"
#include "MultiSelect.hpp"
#include "Text.hpp"
#include "InputPassword.hpp"

int main() {
    CliWidget::Select select(std::vector<std::string> {"One", "Two", "Three"});
    CliWidget::MultiSelect multiSelect(std::vector<std::string>{"Cat", "Dog", "Hamster", "Bird", "Fish"});

    select.display(std::cout);

    CliWidget::Text text1("Selected index is " + std::to_string(select.getSelectedIndex()) + "");
    CliWidget::Text text2("Selected value is " + select.getSelectedValue() + "");

    text1.setBackgroundColor(CliWidget::BackgroundColor::GREEN);
    text2.setForegroundColor(CliWidget::ForegroundColor::BLUE);
    text1.display(std::cout);
    text2.display(std::cout);

    multiSelect.display(std::cout);

    std::string strText3 = "Selected indexes are ";
    std::string strText4 = "Selected values are ";

    for (int index : multiSelect.getSelectedIndexes()) {
        strText3 += std::to_string(index) + " ";
    }

    for (std::string value : multiSelect.getSelectedValues()) {
        strText4 += value + " ";
    }

    CliWidget::Text text3(strText3);
    text3.display(std::cout);

    CliWidget::Text text4(strText4);
    text4.display(std::cout);

    CliWidget::Text textPwd("Insert a Password:");
    CliWidget::InputPassword inputPsw;
    inputPsw.setRegex("^.{6,}");

    textPwd.display(std::cout);
    inputPsw.display();

    CliWidget::Text textResult("The entered password is " + inputPsw.getValue());
    textResult.display(std::cout);

    if (!inputPsw.check()) {
        CliWidget::Text textResult("The entered password is short");
        textResult.display(std::cout);
    }

    return 0;
}
