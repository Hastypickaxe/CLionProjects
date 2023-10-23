//
// Created by justd on 3/30/2023.
//

#ifndef LAB_20_PROBLEM_2_COUNT_H
#define LAB_20_PROBLEM_2_COUNT_H

#include <ostream>
#include "string"
#include "iomanip"
struct ActivityCount {
private:
    const static int NUM_ACTIVITIES = 5;
    void printIfMoreThan0(int itemIndex) const {
        int c = count[itemIndex];
        if (c > 0) {
            cout << setw(10) << activities[itemIndex] << " : " << c << endl;
        }
    }
public:
    std::string activities[NUM_ACTIVITIES] = { "swimming", "band",
                                  "polo", "wrestling", "soccer" };
    int count[NUM_ACTIVITIES] = {0};
    constexpr const static int year[4] = {9, 10, 11, 12};
    void updateCount(const string& activity) {
        for (int i = 0; i < NUM_ACTIVITIES; i++) {
            if (activity == activities[i]) {
                count[i] += 1;
                break;
            }
        }
    }

    void print(int grade) {
        cout << "Grade: " << grade << endl;
        for (int j = 0; j < NUM_ACTIVITIES; j++) {
            printIfMoreThan0(j);
        }
        cout << endl;
    }
};
#endif //LAB_20_PROBLEM_2_COUNT_H
