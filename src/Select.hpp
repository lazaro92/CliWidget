#ifndef SELECT_HPP
#define SELECT_HPP

#include <vector>
#include <string>
#include <iostream>


class Select {
	public:
		Select();
		Select(const std::string &text): outText(text) {}
		Select(std::vector<std::string> &options, const std::string &text) : opts(options),outText(text) {}

		void setText(const std::string &text); 
		std::string &getText(); 
		void setOptions(const std::vector<std::string> &options);
		std::vector<std::string> &getOptions();
		void addOption(std::string &option);
		void removeOption(unsigned int i);
		unsigned int getSelectedIndex();
		std::string getSelectedValue();
		std::ostream& display(std::ostream &stream);

	private:
		void changeTerminalMode(bool reset);
		std::ostream& setTerminalCursor(std::ostream& stream);
		std::string getTextToPrint();

	private:
		std::vector<std::string> opts;
		std::string outText;
		std::vector<std::string>::size_type index = 0;
 };

 #endif
