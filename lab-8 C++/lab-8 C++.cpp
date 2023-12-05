#include <iostream>
#include <Windows.h>
#include <string>
#include <stack>

using namespace std;

class Cat 
{
private:
	int age;
	string breed;
	float weight;
	string color;

public:
	Cat(int catAge, const string& catBreed, float catWeight, const string& catColor)
		: age(catAge), breed(catBreed), weight(catWeight), color(catColor)
	{
		cout << "Called constructor with parameters" << endl;
	}

	Cat() : age(0), breed(""), weight(5.0), color("Unknown")
	{
		cout << "Called default constructor" << endl;
	}

	Cat(const Cat& other)
		: age(other.age), breed(other.breed), weight(other.weight), color(other.color)
	{
		cout << "Called copy constructor" << endl;
	}

	~Cat()
	{
		cout << "Called destructor" << endl;
	}

	int getAge() const
	{
		return age;
	}

	string getBreed() const
	{
		return breed;
	}

	float getWeight() const
	{
		return weight;
	}

	string getColor() const
	{
		return color;
	}

	void setAge(int catAge)
	{
		age = catAge;
	}

	void setBreed(const string& catBreed)
	{
		breed = catBreed;
	}

	void setWeight(float catWeight)
	{
		weight = catWeight;
	}

	void setColor(const string& catColor)
	{
		color = catColor;
	}

	void inputData()
	{
		cout << "Enter age: ";
		cin >> age;

		cout << "Enter breed: ";
		cin.ignore();
		getline(cin, breed);

		cout << "Enter weight: ";
		cin >> weight;

		cout << "Enter color: ";
		cin.ignore();
		getline(cin, color);
	}

	void displayInfo()
	{
		cout << "Age: " << age << endl;
		cout << "Breed: " << breed << endl;
		cout << "Weight: " << weight << " kg" << endl;
		cout << "Color: " << color << endl;
	}
};

// з динамічним виділенням пам'яті
class Cat_2
{
private:
	int age;
	string* breed;
	float weight;
	string color;

public:
	Cat_2(int catAge, const string& catBreed, float catWeight, const string& catColor)
		: age(catAge), weight(catWeight), color(catColor)
	{
		breed = new string(catBreed);
		cout << "Called constructor with parameters" << endl;
	}

	Cat_2() : age(0), breed(nullptr), weight(5.0), color("Unknown")
	{
		cout << "Called default constructor" << endl;
	}

	Cat_2(const Cat_2& other)
		: age(other.age), weight(other.weight), color(other.color)
	{
		breed = new string(*(other.breed));
		cout << "Called copy constructor" << endl;
	}

	~Cat_2()
	{
		delete breed;
		cout << "Called destructor" << endl;
	}

	int getAge() const
	{
		return age;
	}

	string getBreed() const
	{
		return *breed;
	}

	float getWeight() const
	{
		return weight;
	}

	string getColor() const
	{
		return color;
	}

	void setAge(int catAge)
	{
		age = catAge;
	}

	void setBreed(const string& catBreed)
	{
		*breed = catBreed;
	}

	void setWeight(float catWeight)
	{
		weight = catWeight;
	}

	void setColor(const string& catColor)
	{
		color = catColor;
	}

	void inputData()
	{
		cout << "Enter age: ";
		cin >> age;

		cout << "Enter breed: ";
		cin.ignore();
		getline(cin, *breed);

		cout << "Enter weight: ";
		cin >> weight;

		cout << "Enter color: ";
		cin.ignore();
		getline(cin, color);
	}

	void displayInfo()
	{
		cout << "Age: " << age << endl;
		cout << "Breed: " << *breed << endl;
		cout << "Weight: " << weight << " kg" << endl;
		cout << "Color: " << color << endl;
	}
};


class Employee 
{
public:
    string name;
    int age;
    int yearsWorked;
    double salary;

    Employee(const string& n, int a, int y, double s)
        : name(n), age(a), yearsWorked(y), salary(s) {}

    void displayInfo() 
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << " years old" << endl;
        cout << "Work experience: " << yearsWorked << " years" << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main()
{
    //Task_2

    unsigned short int yourAge = 25;

    // Оголошення покажчика і призначення йому адреси yourAge
    unsigned short int* pYourAge = &yourAge;

    //Task_3

    yourAge = 50;

    //Task_4

    int myInteger;
    int* pMyInteger;

    pMyInteger = &myInteger;

    *pMyInteger = 42;

    cout << "The value of the myInteger variable: " << myInteger << endl;
    cout << "The value of the pointer pMyInteger: " << *pMyInteger << endl;

    //Task_5

    int* pInt; 

    pInt = new int;
    *pInt = 9;

    cout << "The value at pInt: " << *pInt << endl;

    delete pInt;

    //Task_6

    int SomeVariable = 5; 
    int* pVar = &SomeVariable; 

    cout << "SomeVariable: " << *pVar << endl;

    //Task_7

    Employee* employee1 = new Employee("Employee 1", 30, 5, 50000.0);
    Employee* employee2 = new Employee("Employee 2", 25, 3, 45000.0);
    employee1->displayInfo();
    employee2->displayInfo();

    //Task_8

    stack<int> myStack;

    int myInt = 42;
    myStack.push(myInt);

    int* pointer = &myStack.top();

    *pointer = 100;
    cout << "The new value of the object on the stack: " << myStack.top() << endl;

    //Task_9

    stack<Cat*> catStack;

    Cat* catObject = new Cat();

    catStack.push(catObject);

    catObject->inputData();

    cout << "New information about the cat:" << endl;
    catObject->displayInfo(); 

    delete catObject;

    //Task_10


    Cat* CatObj = new Cat(3, "str", 4.34, "str");

    CatObj->displayInfo(); 

    CatObj->setAge(5);
    CatObj->setBreed("Siamese");
    CatObj->setWeight(6.2);
    CatObj->setColor("Brown");

    cout << "new information about a cat:" << endl;
    CatObj->displayInfo();

    delete CatObj;

    //Task_11
    //11.	Напишіть програму, що створює вказівник 
    // на об'єкт будь-якого раніше розробленого класу (Cat, Worker, Pencil ...).
    // Поясніть, як її виправити.

	//Task_12




    //Task_13

	Cat_2* CatObj_2 = new Cat_2(3, "Persian", 4.5, "Gray");

	cout << "Before changing data\n";
	CatObj_2->displayInfo();

	CatObj_2->setAge(4);
	CatObj_2->setBreed("Maine Coon");
	CatObj_2->setWeight(6.2);
	CatObj_2->setColor("Tabby");


	cout << "After changing data\n";
	CatObj_2->displayInfo();
}