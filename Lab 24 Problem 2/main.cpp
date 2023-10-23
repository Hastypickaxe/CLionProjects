#include <iostream>

using namespace std;

template<class T>

class Data{
public:
    Data(){}
    Data(T* num, int cnt){
        this->count = cnt;
        number = new T[count];
        for(int i = 0; i < count; i++){
            number[i] = num[i];
        }
    }
    Data(const Data& D){
        count = D.count;
        number = new T[count];
        for(int i = 0; i < D.count; i++){
            number[i] = D.number[i];
        }
    }
    ~Data(){}
    void setNumber(T* num){
        for(int i = 0; i < count; i++){
            number[i] = num[i];
        }
    }
    void setCount(T num){
        count = num;
    }
    T* getNumber(){return number;}
    T getCount(){return count;}

private:
    T* number;
    int count;
};

int main()
{
    int* x = new int[5]{ 1, 2, 3, 4, 5 };
    double* y = new double[3]{ 3.5, 2.4, 6.7 };
    char* z = new char[7]{ 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
    Data<int> dx(x, 5);
    Data<int> tempx;
    tempx = dx;
    int* tx = tempx.getNumber();
    int txc = tempx.getCount();
    for (int i = 0; i < txc; i++)
        cout << tx[i] << " ";
    cout << endl;
    Data<double> dy(y, 3);
    Data<double> tempy(dy);
    double* ty = tempy.getNumber();
    int tyc = tempy.getCount();
    for (int i = 0; i < tyc; i++)
        cout << ty[i] << " ";
    cout << endl;
    Data<char> dz(z, 7);
    char* temp = new char[7]{ 'o', 'p', 'q', 'r', 's', 't', 'u' };
    dz.setNumber(temp);
    dz.setCount(7);
    char* r = dz.getNumber();
    int count = dz.getCount();
    for (int i = 0; i < count; i++)
        cout << r[i] << " ";
    cout << endl;
}
