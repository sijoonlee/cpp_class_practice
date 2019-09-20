#include "directory.h"

// stream operator overloading
ostream &operator <<(ostream &os, const Directory &obj)
{
    for (int idx = 0; idx < obj.noEmployees; idx++)
        os << obj.employees[idx].employeeName << " "
            << obj.employees[idx].phoneExt << " "
            << obj.employees[idx].officeNumber << " ";
    os << endl;
    return os;
}

int Directory::findEmployee(string name) const
{
    int idx;
    for (idx = 0; idx < noEmployees; idx++)
        if (employees[idx].employeeName == name)
            break;
    return idx;
}

void Directory::showPhoneOffice(string name) const
{
    int idx = findEmployee(name);
    cout << employees[idx].phoneExt;
}

int Directory::getNoEmployees() const
{
    return noEmployees;
}

void Directory::addEmployee(string employeeName, string phoneExt, int officeNumber)
{
    employees[noEmployees].employeeName = employeeName;
    employees[noEmployees].phoneExt = phoneExt;
    employees[noEmployees].officeNumber = officeNumber;
    noEmployees++;
}

void Directory::writeDirectory(ostream& out) const
{
    for (int idx = 0; idx < noEmployees; idx ++)
        out << employees[idx].employeeName << employees[idx].phoneExt << employees[idx].officeNumber << endl;
}

Directory::Directory(int max)
{
    noEmployees = 0;
    maxEmployees = max;
}

Directory::Directory(Phone phoneBook[], int noEmp, int maxEmp)
{
    noEmployees = noEmp;
    maxEmployees = maxEmp;
    for (int idx = 0; idx < noEmp; idx ++)
    {
        employees[idx] = phoneBook[idx];
    }
}

// Copy Constructor
Directory::Directory(const Directory &source)
{
    maxEmployees = source.maxEmployees;
    noEmployees = source.noEmployees;
    for (int idx = 0; idx < noEmployees; idx++)
    {
        employees[idx] = source.employees[idx];
    }
}

// Copy assignment
Directory &Directory::operator=(const Directory &source)
{
    if (this == &source)
        return *this;
    maxEmployees = source.maxEmployees;
    noEmployees = source.noEmployees;
    for (int idx = 0; idx < noEmployees; idx++)
    {
        employees[idx] = source.employees[idx];
    }
    return *this;
}

int main()
{
    fstream fout_a("/home/sijoonlee/Documents/COMP333/lab03/output_a.text");
    if(!fout_a.is_open())
    {
        cout << "error occured in opening output_a.text file";
        // system("pause");
        exit(-1);
    }
        
    Directory directory_x(10);
    cout << "directory_x instantiated" << endl;

    directory_x.addEmployee("Jone Doe", "111", 1);
    directory_x.addEmployee("James Brown", "222", 2);
    cout << "Two data added into directory_x" << endl;

    cout << directory_x;
    
    directory_x.showPhoneOffice("Jone Doe");
    cout << endl << "showPhoneOffice called" << endl;
    
    cout << directory_x.getNoEmployees();
    cout << "getNoEmployees() called" << endl;
    
    directory_x.writeDirectory(fout_a);
    cout << "wirteDirecotry() called, written into output_a.text" << endl;
    
    Phone phoneBook[2] = {{"Mountain", "333", 3}, {"River", "444", 4}};
    cout << "Phone array declared and initialized with 2 dataset" << endl;

    Directory directory_y(phoneBook, 2, 10);
    cout << "directory_y instanciated with Phone array" << endl;
    cout << "directory_y : " << endl;
    cout << directory_y;

    directory_x = directory_y;
    cout << "Copy assignment operator called, directory_x = directory_y" << endl;
    cout << "directory_x : " << endl;
    cout << directory_x;
    
    Directory directory_z(directory_y);
    cout << "directory_z is instanciated by copy constructor, directory_y used : " << endl;
    cout << "directory_z : " << endl;
    
    cout << directory_z;
}