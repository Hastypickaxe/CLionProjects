//
// Created by justd on 3/30/2023.
//

#ifndef LAB_20_PROBLEM_2_MSSCORECALC_H
#define LAB_20_PROBLEM_2_MSSCORECALC_H

#include <ostream>

class MSScoreCalc {
public:
    const static int NUM_GRADE_MS = 3;
    constexpr const static int grades[3] = {6, 7, 8};
private:
    double sumScoreMATH[NUM_GRADE_MS] = {0};
    double sumScoreScience[NUM_GRADE_MS] = {0};
    int numScoreMATH[NUM_GRADE_MS] = {0};
    int numScoreScience[NUM_GRADE_MS] = {0};
public:
    void updateMath(int mathScore, int grade) {
        sumScoreMATH[grade - 6] += mathScore;
        numScoreMATH[grade - 6] ++;
    }

    void updateScience(int scienceScore, int grade) {
        sumScoreScience[grade - 6] += scienceScore;
        numScoreScience[grade - 6] ++;
    }

    friend std::ostream &operator<<(std::ostream &os, const MSScoreCalc &calc) {
        os << "    Middle School Students\n";
        os << "-------------------------------------\n";
        for (int i = 0; i < 3; i++) {

            os << std::fixed << std::setprecision(2) << grades[i] << "th grade :     " << calc.sumScoreMATH[i] / calc.numScoreMATH[i]  << "     " << calc.sumScoreScience[i] / calc.numScoreScience[i] << endl;
        }
        return os;
    }
};
#endif //LAB_20_PROBLEM_2_MSSCORECALC_H
