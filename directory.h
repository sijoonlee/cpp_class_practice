#include <string>
#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 25;
struct Phone
{
    string employeeName;
    string phoneExt;
    int officeNumber;
};

class Directory
{
    friend ostream &operator<<(ostream &, const Directory &); // stream insertion
private:
    int maxEmployees;
    int noEmployees;
    Phone employees[SIZE];
public:
    int findEmployee(string /**/) const;
    void showPhoneOffice(string) const;
    int getNoEmployees() const;
    void addEmployee(string, string, int);
    void writeDirectory(ostream&) const;
    Directory(int max); // init
    Directory(Phone[], int noEmp, int maxEmp); // init with Phone array
    Directory(const Directory &); // copy constructor
    Directory &operator=(const Directory &); // copy assignment
};



