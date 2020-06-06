#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Person
{
    char name[100];
    char surname[100];
    int age;
    int weight;
    double length;
};

void writeToFile(const std::string& file_name, Person& data)
{
    std::ofstream out(file_name.c_str());
    out.write(reinterpret_cast<char*>(&data), sizeof(Person));
}

void readFromFile(const std::string& file_name, Person& data)
{
    std::ifstream in(file_name.c_str());
    in.read(reinterpret_cast<char*>(&data), sizeof(Person));
}

int main()
{
    Person person1;

    readFromFile("../file.dat", person1);
    // writeToFile("../file.dat", person1);
    cout << "Print out details:" << endl;
    cout << person1.length << endl;
}