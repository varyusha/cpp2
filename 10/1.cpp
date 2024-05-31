#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string name;
    int age;
    double height; 
    double weight; 
};

void print(Person* person)
{
    cout << person->name << " is " << person->age << " years old" << endl;
    cout << "Height: " << person->height << " meters" << endl;
    cout << "Weight: " << person->weight << " kg" << endl;
}

int main()
{
    Person person;
    person.name = "Harry";
    person.age = 23;
    person.height = 1.75; 
    person.weight = 70.5; 

    cout << "Meet " << person.name << endl;
    print(&person);

    return 0;
}
