//
// Created by justd on 9/7/2023.
//

#ifndef CS8LAB4_BAG_H
#define CS8LAB4_BAG_H
#include <iostream>
#include <cstdlib> // Provides size_t

using namespace std;

namespace main_savitch_3
{
    class bag
    {
    public:
// TYPEDEFS and MEMBER CONSTANTS
        typedef int value_type;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 30;
// CONSTRUCTOR
        bag() { used = 0; }

        explicit bag(size_type used);

        bag(value_type *data, size_type used);

        explicit bag(value_type *data);

// MODIFICATION MEMBER FUNCTIONS
        size_type erase(const value_type& target);
        bool erase_one(const value_type& target);
        void insert(const value_type& entry);
        void operator +=(const bag& addend);
        void operator -=(const bag& subtrahend);
        bag operator -(const bag& subtrahend) const;
        bag operator ^(const bag& other) const;
        bag operator &(const bag& other) const;
        void squeeze();
        void sort();
        void show() const;

        // CONSTANT MEMBER FUNCTIONS
        size_type size() const { return used; }
        size_type count(const value_type& target) const;
    private:
        value_type data[CAPACITY]; // The array to store items
        size_type used; // How much of array is used
    };
// NONMEMBER FUNCTIONS for the bag class
    bag operator +(const bag& b1, const bag& b2);
}

#endif //CS8LAB4_BAG_H
