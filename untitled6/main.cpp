#include <iostream>

using namespace std;

/*
int rlsearch(int A[], int size, int x)
{
    size--;
    if(size < 0)
        return -1;
    if(A[size]==x)
    return size;
    return rlsearch(A, size, x);
}

int main() {
    int A[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, target;

    cout<<"Enter the size to find: ";
    cin>>target;

    int result = rlsearch(A, 10, target);

    if(result == target)
    {
        cout<<target<<"Found"<<endl;
    }
    else
    {
        cout<<target<<"Not Found"<<endl;
    }
}
*/

class A
{
public:
    A();
    A(int);
    void show();
    ~A();
private:
    int dataA;
};
A::A() : dataA(0) {
    cout << "A default constructor" << endl;
}
A::A(int x) : dataA(x) {
    cout << "A second constructor" << endl;
}
void A::show() {
    cout << "dataA : " << dataA << endl;
}
A::~A() {
    cout << "A destructor called" << endl;
}
class B : public A
{
public:
    B();
    B(int, int);
    void show();
    ~B();
private:
    int dataB;
};

B::B() : A(0), dataB(0) {
    cout << "B default constructor" << endl;
}
B::B(int x, int y) : A(x), dataB(y) {
    cout << "A second constructor" << endl;
}
void B::show() {
    A::show();
    cout << "dataB : " << dataB << endl;
}
B::~B() {
    cout << "B destructor called" << endl;
}

class C : public B
{
public:
    C();
    C(int, int, int);
    void show();
    ~C();
private:
    int dataC;
};
C::C() : B(0,0), dataC(0) {
    cout << "C default constructor" << endl;
}
C::C(int x, int y, int z) : B(x,y), dataC(z) {
    cout << "C second constructor" << endl;
}
void C::show() {
    B::show();
    cout << "dataC : " << dataC << endl;
}
C::~C() {
    cout << "C destructor called" << endl;
}
int main()
{
    cout << "Creating A object" << endl;
    A a;
    a.show();
    cout << "Creating B object" << endl;
    B b;
    b.show();
    cout << "Creating C object" << endl;
    C c;
    c.show();
    return 0;
}
