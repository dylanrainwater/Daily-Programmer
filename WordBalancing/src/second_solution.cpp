#include <iostream>
#include <string>
#include <vector>

int balancePosition(const std::string &word, int &weight) {
	for (int i = 0; i < word.length(); ++i) {
		int leftWeight = 0;
		int rightWeight = 0;

		// Get the weight from the right side
		for (int j = 0; j < i; ++j) { 
			leftWeight += (1 + toupper(word[j]) - 'A') * (i - j);
		}
		// Get the weight from the right side
		for (int j = i; j < word.length(); ++j) {
			rightWeight += (1 + toupper(word[j]) - 'A') * (j - i);
		}
		// If they're equal, we found a balance
		if (leftWeight == rightWeight) {
			weight = leftWeight;
			return i;
		} // If left > right, there is no balance.
		else if (leftWeight > rightWeight) {
			return 0;
		}
	}
	return 0;
}

int main() {
	std::cout << "Enter input in capital letters, just press enter to stop." << std::endl;
	std::vector<std::string> input;
	std::string inputLine;
	while (getline(std::cin, inputLine)) {
		if (inputLine != "") {
			input.push_back(inputLine);
		}
		else {
			break;
		}
	}

	// Go through the input
	for (std::string &word : input) {
		int weight = 0;		
		size_t position = balancePosition(word, weight);
		
		if (position > 0) {
			std::cout << word.substr(0, position) << " " << word[position] << " " << word.substr(position+1)  << " - " << weight << std::endl;
		}
		else {
			std::cout << word << " DOES NOT BALANCE" << std::endl;
		}
	}
}
