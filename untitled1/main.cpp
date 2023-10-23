#include <iostream>
#include <fstream>

using namespace std;

class Student
{
public:
    Student(int id, const string &name, int score) : id(id), name(name), score(score) {}

    int getId() const {
        return id;
    }

    void setId(int id) {
        Student::id = id;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Student::name = name;
    }

    int getScore() const {
        return score;
    }

    void setScore(int score) {
        Student::score = score;
    }

private:
    int id;
    string name;
    int score;
};

struct Node
{
    Student data;
    Node* link;

    Node(const Student &data, Node *link) : data(data), link(link) {}
};
typedef Node* NodePtr;


NodePtr readFile(string filePath) {
    ifstream in(filePath);
    int id;
    string name;
    int score;
    Node* head = NULL;
    Node* curr = NULL;
    while (in >> id >> name >> score) {
        Node* tmp = new Node(Student(id, name, score), NULL);
        if (head == NULL) {
            head = tmp;
            curr = tmp;
        }
        curr->link = tmp;
        curr = curr->link;
    }
    return head;
}

void printList(NodePtr head) {
    for (NodePtr ptr = head; ptr != NULL; ptr = ptr->link) {
        Student& s = ptr->data;
        cout << s.getId() << s.getName()<<s.getScore() << " \n";
    }
    cout << endl;
}

int main() {
    string filename = "student.txt";
    NodePtr nodePtr = readFile(filename);
    printList(nodePtr);

}