#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;

    cout << "Enter number of data : ";
    cin >> n;

    stack<int> st;
    vector<int> input(n);

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int current = 1;
    bool possible = true;
    string output ="";

    for(int num : input) {
        while(!st.empty() && st.top() == current) {
            st.pop();
            current++;
            output += "-";
        }

        if(num == current) {
            current++;
            output += "+";
        } else {
            st.push(num);
        }
    }

    while(!st.empty() && st.top() == current) {
        st.pop();
        current++;
        output += "-";
    }

    if(st.empty()) {
        cout<< "OK : " << output << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
