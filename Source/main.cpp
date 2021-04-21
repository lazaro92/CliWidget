#include <vector>
#include <iostream>
#include <string>

#include "CliWidget/Select.hpp"
#include "CliWidget/MultiSelect.hpp"
#include "CliWidget/Text.hpp"
#include "CliWidget/InputPassword.hpp"

int main() {
    cliw::Select select(std::vector<std::string> {"One", "Two", "Three"});
    cliw::MultiSelect multiSelect(std::vector<std::string>{"Cat", "Dog", "Hamster", "Bird", "Fish"});

    select.setBackgroundColor(cliw::BackgroundColor::GREEN);
    select.display();

    cliw::Text text1("Selected index is " + std::to_string(select.getSelectedIndex()) + "");
    cliw::Text text2("Selected value is " + select.getSelectedValue() + "");

    text1.setBackgroundColor(cliw::BackgroundColor::GREEN);
    text1.setForegroundColor(cliw::ForegroundColor::BLUE);
    text1.setUnderline(true);
    text1.setBold(true);

    text2.setItalic(true);
    text2.setBlink(true);

    text1.display();
    text2.display();

    multiSelect.setBackgroundColor(cliw::BackgroundColor::BLUE);
    multiSelect.display();

    std::string strText3 = "Selected indexes are ";
    std::string strText4 = "Selected values are ";

    for (int index : multiSelect.getSelectedIndexes()) {
        strText3 += std::to_string(index) + " ";
    }

    for (std::string value : multiSelect.getSelectedValues()) {
        strText4 += value + " ";
    }

    cliw::Text text3(strText3);
    text3.display();

    cliw::Text text4(strText4);
    text4.display();

    cliw::Text textPwd("Insert a Password:");
    cliw::InputPassword inputPsw;
    inputPsw.setRegex("^.{6,}");

    textPwd.display();
    inputPsw.display();

    cliw::Text textResult("The entered password is " + inputPsw.getValue());
    textResult.setBold(true);
    textResult.display();

    if (!inputPsw.check()) {
        cliw::Text textResult("The entered password is short");
        textResult.display();
    }

    return 0;
}
