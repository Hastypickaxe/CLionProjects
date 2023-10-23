//
// Created by justd on 9/14/2023.
//

#ifndef CS8LAB6_MYSTRING_H
#define CS8LAB6_MYSTRING_H

#include <cstddef>
#include <iostream>
#include <cstring>

using namespace std;

class mystring
{
public:
// CONSTRUCTORS and DESTRUCTOR
    mystring(const char str[] = "") {
        slength = strlen(str);
        seq = new char[slength + 1];
        strcpy(seq, str);
    }
    mystring(const mystring& source);

    mystring(char *seq, const size_t &slength);

    // copy constructor
    ~mystring(); // destructor

// MODIFICATION MEMBER FUNCTIONS
    void operator +=(const mystring& addend);
    void operator +=(const char& addend);
    void operator +=(const char*& addend);
    mystring& operator =(const mystring& source);
    size_t length() const { return slength; }
    char operator[](size_t position) const;
    void insert(const mystring& source, int pos);

// Postcondition: insert source at pos
    void remove(int start, int end);
// Postcondition: delete seq[start] ~ seq[end-1]
    void replace(const mystring& olds, const mystring& news);
// Postcondition: replace all occurrences of 'olds' with 'news‘
    int search(const mystring& source);
// Postcondition: search for the first occurrence of 'source'
// and returns the index of it. If there is no 'source', return -1.
    mystring* tokenizer(mystring delim);

// Postcondition: break string into a series of tokens using the delimiter ‘delim’
    friend ostream& operator <<(ostream& outs, const mystring& source);
    friend istream& operator >>(istream& ins, mystring& target);

    char *getSeq() const;

    void setSeq(char *seq);

    size_t getSlength() const;

    void setSlength(size_t slength);

private:
    char* seq = nullptr;
    size_t slength; // total number of characters in sequence
};

#endif //CS8LAB6_MYSTRING_H
