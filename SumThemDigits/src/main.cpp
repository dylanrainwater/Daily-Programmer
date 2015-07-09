#include <iostream>
#include <string>

using namespace std;
int main() {
    cout << "Enter number:" << endl;
    string input;
    cin >> input;
    
    int sum = 0;
    while (input.length() != 1) {
        for (int i = 0; i < input.length(); ++i) {
            int x = (int) input[i] - 48;
            sum += x;
        }
        input = to_string(sum);
        sum = 0;
    }
    cout << input << endl;
}
