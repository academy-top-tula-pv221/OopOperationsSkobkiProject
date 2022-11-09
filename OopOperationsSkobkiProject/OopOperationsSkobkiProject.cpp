#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class DArray
{
    int* array;
    int size;
public:
    DArray() : array{ nullptr }, size{ 0 } {}
    DArray(int size) : size{ size }
    {
        array = new int[size] {};
    }
    DArray(const DArray& darr)
    {
        this->size = darr.size;
        this->array = new int[this->size];
        for (int i = 0; i < size; i++)
            array[i] = darr.array[i];
    }
    ~DArray()
    {
        if (array)
            delete[] array;
    }

    int& operator[](int index)
    {
        return array[index];
    }

    int Size()
    {
        return size;
    }
};

class Person
{
    string name;
    string phone;
    string address;

    bool married;
    int age;
public:
    string& operator[](string index)
    {
        if (index == "name")
            return name;

        if (index == "phone")
            return phone;

        if (index == "address")
            return address;
    }

    friend ostream& operator<<(ostream& out, const Person& person)
    {
        out << "Name: " << person.name
            << ", phone: " << person.phone
            << ", address: " << person.address;
        return out;
    }
};

class Matrix
{
    /*DArray* matrix;
    int rows;
    int cols;*/

    int** array;
    int rows;
    int cols;
public:
    /*Matrix(int rows, int cols) : rows{ rows }, cols{ cols }
    {
        matrix = new DArray[rows];
        for (int i = 0; i < rows; i++)
            matrix[i] = *(new DArray(cols));
    }*/
    /*DArray& operator[](int row)
    {
        return matrix[row];
    }

    int& operator[](int col)
    {
        
    }*/
    

    Matrix(int r, int c) : rows{ r }, cols{ c } 
    {
        array = new int* [rows];
        for (int i = 0; i < rows; i++)
            array[i] = new int[cols];
    }
    int& operator()(int i, int j)
    {
        return array[i][j];
    }
};

class BankAccount
{
    int summa;

public:
    BankAccount(int summa = 0) : summa{ summa } {}

    void Add(int diff)
    {
        summa += diff;
    }

    int operator()(int diff)
    {
        summa += diff;
        return summa;
    }

    friend ostream& operator<<(ostream& out, BankAccount a)
    {
        out << "summa = " << a.summa;
        return out;
    }
};

class User
{
public:
    char* name;
    int age;

    User(const char* name, int age)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->age = age;
    }

    friend ostream& operator<<(ostream& out, const User& user)
    {
        out << user.name << " " << user.age;
        return out;
    }
};

class UserCompare
{
public:
    bool operator()(char* s1, char* s2)
    {
        return strcmp(s1, s2) < 0;
    }

    bool operator()(int n1, int n2)
    {
        return n1 < n2;
    }
};

void UsersSort(User* users, int size, UserCompare compare)
{
    for (int i = 0; i < size; i++)
    {
        int indexMin = i;
        for (int j = i; j < size; j++)
            if (compare(users[j].age, users[indexMin].age))
                indexMin = j;
        User temp = users[i];
        users[i] = users[indexMin];
        users[indexMin] = temp;
    }
}

void UsersPrint(User* users, int size)
{
    for (int i = 0; i < size; i++)
        cout << users[i] << "\n";
    cout << "\n";
}

int main()
{
    /*DArray arr(3);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    for (int i = 0; i < arr.Size(); i++)
        std::cout << arr[i] << " ";*/

    /*Person person;
    person["name"] = "Bob";
    person["phone"] = "+7 (999) 123-45-67";
    person["address"] = "Moscow. Red Square. Kremlin";

    cout << person;*/
    /*
    Matrix matr(2, 3);
    //[0][1]
    matr(0, 1) = 10;
    */
    /*BankAccount account(1000);

    cout << account << "\n";

    cout << account(500) << "\n";*/

    User users[5]
    {
        *(new User("Tim", 32)),
        *(new User("Joe", 19)),
        *(new User("Sam", 46)),
        *(new User("Bob", 28)),
        *(new User("Leo", 31))
    };

    UserCompare compare;

    UsersPrint(users, 5);
    UsersSort(users, 5, compare);
    UsersPrint(users, 5);

    return 0;
}
