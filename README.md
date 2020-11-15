# CliWidget
Widgets for using in C++ terminal

## What it is?

CliWidgets are a series of widgets to use in the terminal, with the idea to help programmers to build easy menus or inputs/outputs that users will use to interact with the application.

## Requirements

CliWidgets has been tested on Windows 10 (x64) and Linux (Ubuntu x64).

For Linux, the requisites are:

* A **C++11** compiler.
* The **stty** linux utility which I use to hide the terminal input for InputPassword and for hide the arrow keys when selecting an option in menus. 
* The **tput** to hide / restore the terminal cursor.



## Compile

On Linux, you can execute the script _cmake_build.sh_, in the root folder of the project.

On Windows you will have to do the steps manually:

1. Create a _build_ folder in the main directory of the project.
2. Execute this command: `cmake -G  "Visual Studio 16 2019" ../src`

It will generate a solution in the build folder with two projects:

1. A library (CliWidget).
2. An executable project that uses the main.cpp, used for the development of the library.

## Widgets

### Text

A simple output text to display a text. A format can be applied to it, enabling the next formats:
* Bold.
* Underline.
* Italic.
* Blink.
* Foreground color: sets the terminal foreground color, using a color defined in the *ForegroundColor* Enum.
* Background color: sets the terminal background color, using a color defined in the *BackgroundColor* Enum.

Example:

```cpp
#include "Text.hpp"

CliWidget::Text text("Hello World");

text.setBackgroundColor(CliWidget::BackgroundColor::GREEN);
text.setForegroundColor(CliWidget::ForegroundColor::BLUE);
text.setUnderline(true);
text.setBold(true);
text.setItalic(true);
text.setBlink(true);

text.display();
```

![Different Text format gif](https://i.imgur.com/jjiLuHP.gif "Different Text format gif")

### Input Password

A password input that hides the input when users are writting hteir passwords like in Linux. The password can be checked with a regex.

Example of input password and a regex to validate that it's length is 6 characters or more:

```cpp
#include "Text.hpp"
#include "InputPassword.hpp"

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
```

![Input Password gif](https://i.imgur.com/PMTMMso.gif "Input Password gif")

### Select

This widget display a set of options. The user can navigate through them with up and down keys and select one option with the enter key.

Example:

```cpp
#include "Select.hpp"
#include "Text.hpp"

CliWidget::Select select(std::vector<std::string> {"One", "Two", "Three"});
select.display();
 
CliWidget::Text text1("Selected index is " + std::to_string(select.getSelectedIndex()) + "");
CliWidget::Text text2("Selected value is " + select.getSelectedValue());

text1.display();
text2.display();
```

![Select gif](https://i.imgur.com/Caki9XJ.gif "Select")

### Multi Select

This widget is like the select, with the difference that the user can select more than one option. For selecting a option the user has to press the space bar.

Example:

```cpp
#include "MultiSelect.hpp"
#include "Text.hpp"

CliWidget::MultiSelect multiSelect(std::vector<std::string>{"Cat", "Dog", "Hamster", "Bird", "Fish"});
multiSelect.display();

std::string strText3 = "Selected indexes are ";
std::string strText4 = "Selected values are ";

for (int index : multiSelect.getSelectedIndexes())
    strText3 += std::to_string(index) + " ";

for (std::string value : multiSelect.getSelectedValues())
    strText4 += value + " ";
```

![MultiSelect gif](https://i.imgur.com/cbQuZmo.gif "MultiSelect")
