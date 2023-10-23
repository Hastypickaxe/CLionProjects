#include <iostream>
#include <algorithm>
using namespace std;
class child
{
public:
child(string n, int a) {
name = n;
age = a;
}
string getName() const { return name; }
int getAge() const { return age; }
private:
string name;
int age;
};

bool older(const child& c1, const child& c2)
{
return c1.getAge() < c2.getAge();
}
int main()
{
child alice("Alice", 9), bob("Bob", 8);
child temp(" ", 0);
temp = max(alice, bob, older);
cout << "Older : " << temp.getName() << endl;
return 0;
}

