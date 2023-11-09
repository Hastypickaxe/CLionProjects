#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> max;

    int n;
    int count = 0;

    while (true) {
        cout << "Enter a number " << count << ": ";
        cin >> n;

        if (n == 0) {
            break;
        }

        max.push(n);

        cout << "Current heap: ";
        priority_queue<int> copy = max;
        while (!copy.empty()) {
            cout << copy.top() << " ";
            copy.pop();
        }
        cout << endl;

        count++;
    }

    cout << "Numbers in final heap: ";
    while (!max.empty()) {
        cout << max.top() << " ";
        max.pop();
    }

    return 0;
}
