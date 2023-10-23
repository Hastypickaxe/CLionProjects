//
// Created by justd on 4/18/2023.
//

#ifndef LAB_24_PROBLEM_1_MYPAIR_H
#define LAB_24_PROBLEM_1_MYPAIR_H
#include <iostream>

using namespace std;

template <typename T, typename U>

class mypair {
public:
    mypair();

    mypair(T key, U value){
        this -> key = key;
        this -> value = value;
    }

    T getKey() const;

    void setKey(T key);

    U getValue() const;

    void setValue(U value);

    void show();

private:
    T key;
    U value;
public:

};


#endif //LAB_24_PROBLEM_1_MYPAIR_H
