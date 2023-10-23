/*
//
// Created by justd on 4/18/2023.
//

#include "Data.h"

template<typename T>
T *Data<T>::getNumber() const {
    return number;
}

template<typename T>
void Data<T>::setNumber(T *num) {
    delete[] number;
    number = new T[count];
    for(int i = 0; i < count; i++){
        number[i] = num[i];
    }
}

template<typename T>
int Data<T>::getCount() const {
    return count;
}

template<typename T>
void Data<T>::setCount(int cnt) {
     count = cnt;
}
*/
