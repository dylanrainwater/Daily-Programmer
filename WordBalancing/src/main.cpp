#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    /*
     * Enter multiple lines of input separated by '\n', when a line is empty stop collecting input.
     */
    cout << "Enter input in capital letters, just press enter to stop." << endl;
    vector<string> input;
    string inputLine;
    while (getline(cin, inputLine)) {
        if (inputLine != "") {
            input.push_back(inputLine);
        }
        else {
            break;
        }
    }

    /*
     * :/ there are a lot of for loops ahead. 
     * This initial for loop is just cycling
     * through all of the words from the input.
     */
    bool balances = false;
    for (string &word : input) {
        /*
         * This for loop goes through all of
         * the letters in the current word.
         */
        for (int i = 0; i < word.length(); ++i) {
        int leftWeight = 0;
        int rightWeight = 0;
            /*
             * This loop goes through all of the letters to the left
             * of the currently selected "balance point" and calculates
             * the total "weight" on the left side.
             */ 
            for (int j = 0; j < i; ++j) { // Left of index
                leftWeight += (1 + word[j] - 'A') * (i - j);
            }
            /*
             * Same as above, but for the right-side of the "balance point."
             */
            for (int j = i; j < word.length(); ++j) {
                rightWeight += (1 + word[j] - 'A') * (j - i);
            }

            balances = leftWeight == rightWeight;
            /*
             * This exits out as soon as the working "balance point" is found!
             */
            if (balances) {
                cout << word.substr(0, i) << " " << word[i] << " " << word.substr(i + 1, word.length()) << " - " << leftWeight << endl;
                break;
            }
        }
        if (!balances) { 
            cout << word << " DOES NOT BALANCE." << endl;
        }
        cout << endl;
    }
}
