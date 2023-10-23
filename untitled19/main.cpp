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
    string result = "";

    for (int num : input) {
        while (!st.empty() && st.top() == current) {
            st.pop();
            current++;
            result += "-";
        }

        if (num == current) {
            current++;
            result += "+";
        } else {
            st.push(num);
        }
    }

    while (!st.empty() && st.top() == current) {
        st.pop();
        current++;
        result += "-";
    }

    if (st.empty()) {
        cout << "YES: " << result << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
