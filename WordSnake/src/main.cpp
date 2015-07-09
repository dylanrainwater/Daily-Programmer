#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
	/*
	 * Take in the input words
	 */

	string input_line = "";
	cout << "Enter words separated by spaces." << endl;
	getline(cin, input_line);

	/*
	 * Capitalize and split the words
	 */

	string word_tmp;
	vector<string> words;

	istringstream iss(input_line);
	while (iss >> word_tmp) {
		for (int i = 0; i <= word_tmp.length(); ++i) {
			word_tmp[i] = toupper(word_tmp[i]);
		}
		words.push_back(word_tmp);
	}
	
	/*
	 * Print our snake! 
	 */

	int direction = 0;
	string spacing = "";
	for (string &word : words) {
		// Moving right
		if (direction == 0) {
			cout << spacing << word << endl;
			
			for (int i = 0; i < word.length() - 1; ++i) {
				spacing += " ";
			}
			direction = 1;
		}// Moving down
		else {
			for (int i = 1; i < word.length() - 1; ++i) {
				cout << spacing << word[i] << endl;
			}
			direction = 0;
		}
	}
}