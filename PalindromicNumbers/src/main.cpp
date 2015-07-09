#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	/*
	 * Collect and validate user input.
	 */
	long long input;
	long long originalInput = 0;
	
	cout << "Enter input: " << endl;
	cin >> input;
	
	
	while (!cin.good()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input, try again:" << endl;
		cin >> input;
	}
	originalInput = input;

	/*
	 * Check if the input is a palindrome yet
	 * If so exit the program, if not add the flipped version of the number to itself
	 * Example: 123 -> 123 + 321 -> 444
	 * In the end, print out the palindromic number and the amount of steps taken to get there.
	 */
	bool isPalindrome = false;
	string inputString;
	string reverseInput;
	int steps = 0;
	while (!isPalindrome) {
		inputString = to_string(input);
		reverseInput = inputString;

		reverse(reverseInput.begin(), reverseInput.end());

		isPalindrome = reverseInput == inputString;

		if (isPalindrome) {
			break;
		}
		else {
			cout << steps+1 << ") " << input << " + " << reverseInput << " = " << (input + stoll(reverseInput)) << endl << endl;
			input += stoll(reverseInput);
		}
		++steps;
	}

	cout << originalInput << " gets palindromic after " << steps << " steps: " << input << endl;
	system("pause"); 
}