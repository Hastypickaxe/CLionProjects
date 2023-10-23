#include <iostream>

using namespace std;

/*
class Math {
public:
Math() : count(0), scores(nullptr) {}
Math(int scr[], int cnt) : count(cnt) {
scores = new int[cnt];
for (int i = 0; i < cnt; i++) scores[i] = scr[i];
}
Math(const Math& mt) {
cout<<"copy constructor called"<<endl;
count = mt.count; scores = new int[count];
for(int i = 0; i < count; i++)
    scores[i] = mt.scores[i];
} // complete copy constructor
~Math() {
    delete[] scores;
} // complete destructor
void show() {
cout << "There are " << count << " scores." << endl;
for (int i = 0; i < count; i++)
cout << scores[i] << " ";
cout << endl << endl;
}
Math& operator= (const Math& rs) {
   cout<<"operator called"<< endl;
    count = rs.count;
    for(int i = 0; i < count; i++)
        scores[i] = rs.scores[i];
    return*this;
} // complete operator=
private:
int count;
int* scores;
};

int main() {
    const int N = 5;
    int score[N] = { 80, 90, 85, 92, 77 };
    Math mt1(score, N);
    mt1.show();
    cout << "Math mt2 = mt1" << endl;
    Math mt2 = mt1;
    mt2.show();
    cout << "Math mt3(mt1)" << endl;
    Math mt3(mt1);
    mt3.show();
    Math mt4;
    cout << "mt4 = mt1" << endl;
    mt4 = mt1;
    mt4.show();
}
*/

class parent
{
public:
    parent() {}
    parent(int d1[], int cnt1) : count1(cnt1) {
        data1 = new int[cnt1];
        for (int i = 0; i < cnt1; i++) data1[i] = d1[i];
    }
    parent(const parent& cp):data1(cp.data1)
    {
        cout<<"Parent copy called"<<endl;
        delete[] data1;
        data1 = new int[count1];
        count1 = cp.count1;
      for(int i =0; i < count1; i++)
          data1[i]=
    }
    parent& operator= (const parent& p) {
        cout << "parent operator= called" << endl;
        count1 = p.count1; ;
        for (int i = 0; i < count1; i++) data1[i] = p.data1[i];
        return *this;
    }
    ~parent() { delete[] data1; }
private:
    int count1;
    int* data1;
};

class child : public parent
{
public:
    child() {}
    child(int d1[], int cnt1, int d2[], int cnt2) :
            parent(d1, cnt1), count2(cnt2) {
        data2 = new int[count2];
        for (int i = 0; i < count2; i++) data2[i] = d2[i];
    }
    child(const child& cp):parent(cp), data2(cp.data2)
    {
        cout<<"child copy called"<<endl;
        delete[]
        count2 = cp.count2;
    }
    child& operator= (const child& rhs) {
        cout << "child operator= called" << endl;
        parent::operator=(rhs);
        count2 = rhs.count2;
        for (int i = 0; i < rhs.count2; i++) data2[i] = rhs.data2[i];
        return *this;
    }
    ~child() { delete[] data2; }
private:
    int count2;
    int* data2;
};

int main()
{
    int d1[3] = { 4, 6, 7 };
    int d2[4] = { 6, 8, 1, 2 };
    child c1(d1, 3, d2, 4);
    child c2;
    c2 = c1;
}