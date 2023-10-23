//
// Created by justd on 3/30/2023.
//

#ifndef LAB_20_PROBLEM_1_TRUCK_H
#define LAB_20_PROBLEM_1_TRUCK_H

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Person
{
private:
    string owner;
    int age;
public:
    Person(){}
    Person(string o, int a):owner(o), age(a){}
    ~Person(){}
    void setName(string o){owner = o;}
    void setAge(int a){age = a;}
    string getName(){return owner;}
    int getAge(){return age;}
    this->owner = o;
};

class Vehicle
{
private:
    string manufacturer;
    int cylinder;
    Person owner;
public:
    Vehicle(){}
    Vehicle(string m, int c, Person o):manufacturer(m), cylinder(c), owner(o){}
    ~Vehicle(){}
    void setManufacturer(string m){manufacturer = m;}
    void setCylinder(int c){cylinder = c;}
    void setOwner(Person o){owner = o;}
    string getManfacturer(){return manufacturer;}
    int getCylinder(){return cylinder;}
    Person getOwner(){return owner;}
};

class Truck:public Vehicle
{
private:
    int loadCapacity;
public:
    Truck(){}
    Truck(string m, int c, int loadCapacity, Person o):Vehicle(m, c, o){
        this->loadCapacity = loadCapacity;
        this->getOwner() = o;
    }
    ~Truck(){}
    void setLoadCapacity(int load){loadCapacity = load;}
    int getLoadCapacity(){return loadCapacity;}
};


#endif //LAB_20_PROBLEM_1_TRUCK_H
