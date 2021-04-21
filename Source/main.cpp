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

    select.setBackgroundColor(CliWidget::BackgroundColor::GREEN);
    select.display();

    CliWidget::Text text1("Selected index is " + std::to_string(select.getSelectedIndex()) + "");
    CliWidget::Text text2("Selected value is " + select.getSelectedValue() + "");

    text1.setBackgroundColor(CliWidget::BackgroundColor::GREEN);
    text1.setForegroundColor(CliWidget::ForegroundColor::BLUE);
    text1.setUnderline(true);
    text1.setBold(true);

    text2.setItalic(true);
    text2.setBlink(true);

    text1.display();
    text2.display();

    multiSelect.setBackgroundColor(CliWidget::BackgroundColor::BLUE);
    multiSelect.display();

    std::string strText3 = "Selected indexes are ";
    std::string strText4 = "Selected values are ";

    for (int index : multiSelect.getSelectedIndexes()) {
        strText3 += std::to_string(index) + " ";
    }

    for (std::string value : multiSelect.getSelectedValues()) {
        strText4 += value + " ";
    }

    CliWidget::Text text3(strText3);
    text3.display();

    CliWidget::Text text4(strText4);
    text4.display();

    CliWidget::Text textPwd("Insert a Password:");
    CliWidget::InputPassword inputPsw;
    inputPsw.setRegex("^.{6,}");

    textPwd.display();
    inputPsw.display();

    CliWidget::Text textResult("The entered password is " + inputPsw.getValue());
    textResult.setBold(true);
    textResult.display();

    if (!inputPsw.check()) {
        CliWidget::Text textResult("The entered password is short");
        textResult.display();
    }

    return 0;
}
