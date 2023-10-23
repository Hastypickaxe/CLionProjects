#include <iostream>

const int MAX = 100;

using namespace std;

class parent
{
public:
    parent(): count(0) {data = new int[MAX];}
    parent(int c, int* d):count(c)
    {
        data = new int[count];
        for (int i = 0; i < count; i++)
        {
            data[i] = d[i];
        }
    }
    parent(const parent& p)
    {
        count = p.count;
        data = new int[count];
        for(int i =0; i < count; i++) data[i] = p.data[i];
    }
    ~parent(){delete[] data;}
    parent& operator=(const parent& p)
    {
        count = p.count;
        data = new int[count];
        for(int i =0; i < count; i++)data[i]=p.data[i];
    }
private:
    int count;
    int* data;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
