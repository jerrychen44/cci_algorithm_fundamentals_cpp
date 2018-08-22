/*
 * Cracking the coding interview edition 6
 * Problem 1-6 Implement a method to perform basic string compression.
 * Example string aabcccccaaa should be compressed to a2b1c5a3,
 * however if compressed string is bigger than original string, return original string
 */

#include <iostream>
#include <string>


std::string compress(std::string str)
{
	size_t original_length = str.length();
	if (original_length < 2) {
		return str;
	}
	//use another string
	std::string out{""};
	int count = 1;
	for( size_t i = 1; i < original_length; ++i ) {
		//check if the previous char is the same with current char or not
		if (str[i-1] == str[i]) {
			++count;
		} else {
			//we need to write down the char + repeated number
			out += str[i-1];
			out += std::to_string(count);
			count = 1;
		}
		if (out.length() >= original_length) {
			return str;
		}
	}
	//handle the last char
	out += str[original_length-1];
	out += std::to_string(count);
	if (out.length() >= original_length) {
		return str;
	}
	return out;
}

int main()
{
	std::string str, out;
	//std::cout << "Enter a string:\n";
	//std::cin >> str;

	//str = "aabcccccaaa";
	str = "ttttttest";

	out = compress(str);

	//The str.compare equal will return 0
	if (str.compare(out)) {
		std::cout << str << " can be compressed to " << out << std::endl;
	} else {
		std::cout << str << " can not be compressed\n";
	}
	return 0;
}
