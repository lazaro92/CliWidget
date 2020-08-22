#include <cstdlib>
#include <csignal>

#include "Select.hpp"

void Select::setText(const std::string &text) {
		outText = text;
}

std::string& Select::getText() {
		return outText;
}

void Select::setOptions(const std::vector<std::string> &options) {
		opts = options;
}

std::vector<std::string>& Select::getOptions() {
		return opts;
}

void Select::addOption(std::string &option) {
		opts.push_back(option);
}

void Select::removeOption(unsigned int i) {
		opts.erase(opts.begin() + i);
}

unsigned int Select::getSelectedIndex() {
		return index;
}

std::string Select::getSelectedValue() {
	return opts.at(index);
}

std::ostream& Select::display(std::ostream &stream) {
		unsigned int c = 'A';

		changeTerminalMode(false);
		stream << getTextToPrint();

		do {
				c = std::cin.get();

				if (c == 'A' && index > 0) {
						--index;
						setTerminalCursor(stream);
						stream << getTextToPrint();
				}
				else if (c == 'B' && index < opts.size() -1) {
						++index;
						setTerminalCursor(stream);
						stream << getTextToPrint();
				}
		} while(c != '\n');

		
		changeTerminalMode(true);
		return stream << std::endl;
}

void Select::changeTerminalMode(bool reset) {
		if (!reset) {
			// Disable special processing of characters (e.g. delete line) and set the minimum number read to 1
			// disable printing of keys as they're pressed
			system("stty cbreak min 1 -echo");

			atexit([](){
						//Reset the terminal to a sensible state
						system("stty sane");
						});

			// Ensure clean exit to reset the terminal if the program is killed
			signal(SIGTERM, [](int){exit(1);});
		}
		else {
			system("stty sane");
		}
}

std::ostream& Select::setTerminalCursor(std::ostream &stream) {
	return stream << "\033[" << opts.size()+1 << "A\033[99D";
}

std::string Select::getTextToPrint() {
		std::string text = outText + '\n';

		std::vector<std::string>::size_type i = 0;
		while (i < opts.size()) {
				if (i == index) {
						text += "\033[41m> " + opts.at(i) + "\033[0m\n";
				}
				else {
						text += "  " + opts.at(i) + '\n';
				}
				++i;
		}

		return text;
}
