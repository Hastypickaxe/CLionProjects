/*
//
// Created by justd on 4/18/2023.
//

#ifndef LAB_24_PROBLEM_2_DATA_H
#define LAB_24_PROBLEM_2_DATA_H
#include <iostream>

using namespace std;

template <typename T>
class Data {
private:
    T* number;
    int count;
public:
    Data() : number(nullptr), count(0){}

    Data(T* num, int cnt) : number(nullptr), count(0){
        setNumber(num);
        setCount(cnt);
    }

    Data(const Data& other) : number(nullptr), count(0){
        setNumber(other.getNumber());
        setCount(other.getCount());
    }

    Data& operator=(const Data* other){
        if(this != &other){
            setNumber(other->getNumber());
            setCount(other->getCount());
        }
    }

    ~Data(){
        delete[] number;
    }

    T *getNumber() const;

    void setNumber(T *num);

    int getCount() const;

    void setCount(int cnt);
};


#endif //LAB_24_PROBLEM_2_DATA_H
*/
