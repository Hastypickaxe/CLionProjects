#include "mypair.cpp"

int main() {
    mypair<int, int> score(10, 90);
    score.setValue(95);
    mypair<int, string> name(5, "Alice");
    name.setKey(7);
    mypair<string, double> gpa("Peter", 3.5);
    gpa.setValue(3.7);
    score.show();
    name.show();
    gpa.show();
    return 0;

}
