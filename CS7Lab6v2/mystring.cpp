//
// Created by justd on 9/14/2023.
//

#include "mystring.h"

mystring::mystring(char *seq, const size_t &slength) : seq(seq), slength(slength) {}

ostream &operator<<(ostream &outs, const mystring &source) {
    outs << source.seq;
    return outs;
}

istream &operator>>(istream &ins, mystring &target) {
    int size = 100;
    char buff[size];

    ins.get(buff, size, '\n');

    strcpy(target.seq, buff);
    target.slength = strlen(buff);

//    delete[] buff;

    return ins;
}

mystring::mystring(const mystring& source)
{
    slength = source.slength;
    seq = new char[slength + 1];
    strcpy(seq, source.seq);
}

mystring::~mystring() {
    delete[] seq;
}



void mystring::replace(const mystring &olds, const mystring &news) {
    size_t pos = 0;
    while((pos = search(olds)) != 1){
        size_t remainingLegnth = slength - (pos + olds.length());
        char* newSeq = new char[slength - olds.length() + news.length() + 1];

        strncpy(newSeq, seq, pos);
        strcpy(newSeq + pos, news.getSeq());
        strcpy(newSeq + pos + news.length(), seq + pos + olds.length());

        delete[] seq;
        seq = newSeq;
        slength = slength - olds.length() + news.length();
    }
}

void mystring::remove(int start, int end) {
    if(start < 0 || end >= static_cast<int>(slength) || start > end)
    {
        throw out_of_range("Invalid start or end");
    }

    int removeLegnth = end - start + 1;
    char* newSeq = new char[slength - removeLegnth + 1];

    strncpy(newSeq, seq, start);
    strcpy(newSeq + start, seq + end + 1);

    delete[] seq;
    seq = newSeq;
    slength -= removeLegnth;
}

void mystring::insert(const mystring &source, int pos) {
    if(pos < 0 || pos > static_cast<int>(slength))
    {
        throw out_of_range("Position is out of range");
    }

    char* newSeq = new char[slength + source.length() + 1];
    strncpy(newSeq, seq, pos);
    strcpy(newSeq + pos, source.getSeq());
    strcpy(newSeq + pos + source.length(), seq + pos);

    delete[] seq;
    seq = newSeq;
    slength += source.length();
}

int mystring::search(const mystring &source) {
    bool find = true;
    size_t i = 0;
    for (; i <= slength - source.length(); i++)
    {
        find = true;
        for (size_t j = 0; j < source.length(); j++) {
            if(seq[i + j] != source[j])
            {
                find = false;
                break;
            }
        }
    }

    if(find){
        return static_cast<int>(i);
    } else {
        return -1;
    }
}

mystring* mystring::tokenizer(mystring delim)
{
    size_t maxTokens = 1;
    for(int i = 0; i < slength; i++)
    {
        if(delim.search(mystring(seq + i)) != -1){
            maxTokens++;
        }
    }

    mystring* tok = new mystring[maxTokens];

    size_t tokenIndex = 0;
    size_t startIndex = 0;

    for(size_t i = 0; i < slength; i++)
    {
        if(delim.search(mystring(seq + i)) != -1)
        {
            size_t tokenLegnth = i - startIndex;
            tok[tokenIndex] = mystring(seq + startIndex, tokenLegnth);
            tokenIndex++;
            startIndex = i + delim.length();
        }
    }

    size_t tokenLegnth = slength - startIndex;
    tok[tokenIndex] = mystring(seq + startIndex, tokenLegnth);

    return tok;
}

char *mystring::getSeq() const {
    return seq;
}

void mystring::setSeq(char *seq) {
    mystring::seq = seq;
}

size_t mystring::getSlength() const {
    return slength;
}

void mystring::setSlength(size_t slength) {
    mystring::slength = slength;
}

char mystring::operator[](size_t position) const {
    return seq[position];
}

mystring &mystring::operator=(const mystring &source) {

    return *this;
}

void mystring::operator+=(const mystring &addend){
    char* newSeq = new char[addend.slength + 1];
    strcpy(newSeq, addend.seq);
    strcat(seq, newSeq);
//    delete[] seq;
//    seq = newSeq;
    slength += addend.slength;
}

void mystring::operator+=(const char &addend) {
    strcat(this->seq, &addend);
    this->slength += 1;
    seq[slength] = '\0';
}

void mystring::operator+=(const char *&addend) {
    strcat(this->seq, addend);
    this->slength += strlen(addend);
    seq[slength] = '\0';
}
