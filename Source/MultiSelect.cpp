/**
  Multi Select widget: contains the implementation of the class MultiSelect 
  @file MultiSelect.cpp
  @author Albert Lazaro de Lara
  @version 0.1 11/09/20 
  */
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

#include "CliWidget/MultiSelect.hpp"

namespace CliWidget {

    MultiSelect::MultiSelect(const std::vector<std::string> &options) : List(options){
        _boolIndexes = std::vector<bool> (options.size(), false);
    }

    std::vector<int> MultiSelect::getSelectedIndexes() {
        std::vector<int> indexes;

        std::vector<bool>::size_type i = 0;
        while (i < _boolIndexes.size()) {
            if (_boolIndexes.at(i)) {
                indexes.push_back(i);
            }
            ++i;
        }

        return indexes;
    }

    std::vector<std::string> MultiSelect::getSelectedValues() {
        std::vector<std::string> values;

        std::vector<bool>::size_type i = 0;
        while (i < _boolIndexes.size()) {
            if (_boolIndexes.at(i)) {
                values.push_back(_options.at(i));
            }
            ++i;
        }

        return values;
    }

    void MultiSelect::display() {
#if defined(_WIN32) || defined(_WIN64)
        DWORD count;
        WORD  result;
        INPUT_RECORD inrec;

        if (changeTerminalMode(false) == '\0') {
            // TODO controle this (not connected to cmd)
            return;
        }

        std::string textToPrint = getTextToPrint();
        HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);

        WriteConsole(
            GetStdHandle(STD_OUTPUT_HANDLE),
            textToPrint.c_str(),
            textToPrint.length() + 1,
            &count,
            NULL
        );
        FlushConsoleInputBuffer(hstdin);

        do {
            /* Wait for and get a single key PRESS */
            do ReadConsoleInput(hstdin, &inrec, 1, &count);
            while ((inrec.EventType != KEY_EVENT) || !inrec.Event.KeyEvent.bKeyDown);

            /* Remember which key the user pressed */
            result = inrec.Event.KeyEvent.wVirtualKeyCode;

            /* Wait for and get a single key RELEASE */
            do ReadConsoleInput(hstdin, &inrec, 1, &count);
            while ((inrec.EventType != KEY_EVENT) || inrec.Event.KeyEvent.bKeyDown);

            if (result == VK_UP && _index > 0) {
                --_index;
                setTerminalCursor(std::cout);
                std::cout << getTextToPrint();
    }
            else if (result == VK_DOWN && (_index < _options.size() - 1)) {
                ++_index;
                setTerminalCursor(std::cout);
                std::cout << getTextToPrint();
            }
            else if (result == VK_SPACE) {
                _boolIndexes.at(_index) = !_boolIndexes.at(_index);
                setTerminalCursor(std::cout);
                std::cout << getTextToPrint();
            }
        } while (result != VK_RETURN);
        changeTerminalMode(true);
#else
        unsigned int c;
        bool arrowKeyPressed = false;

        changeTerminalMode(false);
        std::cout << getTextToPrint();

        do {
            c = std::cin.get();
            if (c == '[') {
                arrowKeyPressed = true;
            }
            else if (c == KEY_UP && _index > 0 && arrowKeyPressed) {
                --_index;
                arrowKeyPressed = false;
                setTerminalCursor(std::cout);
                std::cout << getTextToPrint();
            }
            else if (c == KEY_DOWN && (_index < _options.size() -1) && arrowKeyPressed) {
                ++_index;
                arrowKeyPressed = false;
                setTerminalCursor(std::cout);
                std::cout << getTextToPrint();
            }
            else if (c == KEY_SPACE) {
                _boolIndexes.at(_index) = !_boolIndexes.at(_index);
                setTerminalCursor(std::cout);
                std::cout << getTextToPrint();
            }
        } while(c != KEY_ENTER);
        changeTerminalMode(true);
#endif
    }

    void MultiSelect::addOption(const std::string &option) {
        _options.push_back(option);
        _boolIndexes.push_back(false);
    }

    void MultiSelect::removeOption(unsigned int index) {
        _options.erase(_options.begin() + index);
        _boolIndexes.erase(_boolIndexes.begin() + index);
    }

    std::string MultiSelect::getTextToPrint() {
        std::string text = "", bgBegin = "", bgEnd ="";

        if (_bgColor != CliWidget::BackgroundColor::NONE) {
            bgBegin = "\033[" + _bgColor + "m";
            bgEnd = "\033[0m";
        }

        std::vector<std::string>::size_type i = 0;
        while (i < _options.size()) {
            if (_boolIndexes.at(i)) 
                text += "+";
            else 
                text += "-";

            if (i == _index) 
                text += bgBegin + _cursor + " " + _options.at(i) + bgEnd + "\n";
            else 
                text += "  " + _options.at(i) + "\n";
            ++i;
        }

        return text;
    }
}
