/*#include <iostream>

using namespace std;

class Parent
{
public:
    virtual void play() = 0;
    virtual void study() = 0;
    void test(){cout<<"parent test"<<endl;}
    virtual void read() = 0;
};

class Child1 : public Parent
{
public:
    void play(){ cout<<"child1 play"<<endl;}
    void study(){ cout<<"child1 study"<<endl;}
    void read(){ }
};

class Child2 : public Parent
{
public:
    void read(){{ cout<<"child2 read"<<endl;}}
    void play(){}
    void study(){}
};

int main() {
   Parent* p = new Child2;
   p->read();
   Parent* q = new Child1;
}*/

#include <iostream>

using namespace std;

int main() {
    int donuts, milk;
    double dpg;
    cout << "Enter number of donuts: ";
    cin >> donuts;
    cout << "Enter number of glasses of milk: ";
    cin >> milk;
    try {
        if (milk <= 0) {
            throw donuts;
        } else {
            dpg = donuts / static_cast<double>(milk);
            cout << donuts << " donuts.\n"
                 << milk << " glasses of milk.\n"
                 << "You have " << dpg
                 << " donuts for each glass of milk.\n";
        }
    }
    catch (int x)
    {
        cout << donuts << " donuts, and No Milk!\n"
             << "Go buy some milk.\n";
    }
    cout << "End of program.\n";
    return 0;
}
