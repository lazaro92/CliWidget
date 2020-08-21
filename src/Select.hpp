#ifndef SELECT_HPP
#define SELECT_HPP

#include <vector>
#include <string>
#include <iostream>

#include <cstdlib>
#include <csignal>

class Select {
	public:
		Select();
		Select(const std::string &text): outText(text) {}
		Select(const std::string &text, std::vector<std::string> &options): outText(text), opts(options) {}

		void setText(const std::string &text) {
			outText = text;
		}

		std::string &getText() {
			return outText;
		}
		
		void setOptions(const std::vector<std::string> &options) {
			opts = options;
		}

		std::vector<std::string> &getOptions() {
			return opts;
		}

		std::ostream& display(std::ostream &stream) {
			int c = 'A';

			changeTerminalMode();

			do {
				if (c == 'A' || c == 'B' || c == '\n') {
					stream << getTextToPrint();
				}

				c = std::cin.get();

				if (c == 'A' && index > 0) {
					--index;
				}
				else if (c == 'B' && index < opts.size()) {
					++index;
				}
			} while(c != '\n');

			return stream;
		}

		void addOption(std::string &option) {
			opts.push_back(option);
		}

		int getSelectedIndex() {
			return index;
		}

	private:
		void changeTerminalMode() {
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

		std::string getTextToPrint() {
			std::string text = outText + '\n';

			int i = 0;
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

	private:
		std::vector<std::string> opts;
		std::string outText;
		int index = 0;
 };

 #endif
