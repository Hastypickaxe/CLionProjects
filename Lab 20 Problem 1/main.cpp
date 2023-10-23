#include "Truck.h"

using namespace std;

int main() {

    Person p1("Justin", 20);
    Person p2("Kevin", 50);

    Truck myTruck("Ford", 8, 5000, p1);
    Truck yourTruck("Chevy", 8, 4500, p2);

    cout << "Brand: " << myTruck.getManfacturer() << ", " << "Engine Cylinder: " << myTruck.getCylinder() << ", "
         << "Capacity: " << myTruck.getLoadCapacity() << ", " << "Name: " << Person().getName() << ", " << "Age: "
         << Person().getAge();
/*    cout << "Brand: " << yourTruck.getManfacturer() << ", " << "Engine Cylinder: " << yourTruck.getCylinder() << ", "
         << "Capacity: " << yourTruck.getLoadCapacity();*/
}