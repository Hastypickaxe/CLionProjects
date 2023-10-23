//
// Created by justd on 4/18/2023.
//

#include "mypair.h"

template<typename T, typename U>
T mypair<T, U>::getKey() const {
    return key;
}

template<typename T, typename U>
void mypair<T, U>::setKey(T key) {
    mypair::key = key;
}

template<typename T, typename U>
U mypair<T, U>::getValue() const {
    return value;
}

template<typename T, typename U>
void mypair<T, U>::setValue(U value) {
    mypair::value = value;
}

template<typename T, typename U>
mypair<T, U>::mypair() {

}

template<typename T, typename U>
void mypair<T, U>::show() {
    cout<<"Key: "<< key << ", Value: "<< value <<endl;
}
