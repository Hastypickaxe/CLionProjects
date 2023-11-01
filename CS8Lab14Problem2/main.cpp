#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int main() {
    ifstream infile;
    string filename;

    cout << "Enter Filename : ";
    cin >> filename;

    infile.open(filename);

    if(infile.fail()) {
        cout << "Failed to open file" << endl;
        return 1;
    }

    int input;
    stack <int> nums;

    while (infile >> input) {
        nums.push(input);
    }

    infile.close();

    stack <int> sorted;

    while (!nums.empty()) {
        int top = nums.top();
        nums.pop();
        while (!sorted.empty() && sorted.top() < top) {
            nums.push(sorted.top());
            sorted.pop();
        }

        sorted.push(top);
    }

    cout << "< Iterative inorder result >" << endl;

    while (!sorted.empty()) {
        cout << sorted.top() << " ";
        sorted.pop();
    }

    return 0;
}
