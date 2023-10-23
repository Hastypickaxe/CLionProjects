#include <iostream>
#include "Menu.h"


using namespace std;


int main() {
    Menu menu;


    menu.run();






/*    for (int i = 0; i < menu.getPeopleSize(); i++) {
       Person* person = menu.getPeople()[i];


       if (person->getId() >= 1 && person->getId() <= 100) { // teacher
           Teacher* teacher = (Teacher*)person;


           teacher->print();
           // do something with data like print
       } else if(person->getId() >= 101 && person->getId() <= 300){
           Student* student = (Student*)person;


           student->print();
       }
   }*/


    return 0;
}


