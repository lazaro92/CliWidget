#ifndef SELECT_HPP
#define SELECT_HPP

#include <vector>
#include <string>
#include <iostream>

/**
 *
 */
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
			stream << outText << '\n';

			int i = 0;
			while (i < opts.size()) {
				if (i == index) {
					stream << "\033[41m> " << opts.at(i) << "\033[0m\n";
				}
				else {
					stream << "> " << opts.at(i) << '\n';
				}
				++i;
			}
			return stream;
		}

		void addOption(std::string &option) {
			opts.push_back(option);
		}



	private:
		std::vector<std::string> opts;
		std::string outText;
		int index = 0;
 };

 #endif
