#include <iostream>
#include <string>
using namespace std;

class Car {
private:
	int year;//int that holds the car’s  year
	string model;//a string that holds the model of the car
	string make;//a string that holds the make of the car
	double speed;//a double that holds the car’s current speed
public:
	//Getter and Setter Methods
	int accessorYear() { return year; }//Getter method for year
	void setYear(int year) { this->year = year; }//Setter method for year
	string accessorModel() { return model; }//Getter method for model
	void setModel(string model) { this->model = model; }//Setter method for model
	string accessorMake() { return make; }//Getter method for make
	void setMake(string make) { this->make = make; }//Setter method for make
	double accessorSpeed() { return speed; }//Getter method for speed
	void setSpeed(double speed) { this->speed = speed; }//Setter method for speed

	//Constructor
	Car(int, string, string, double);
	Car();

	//Destructor
	~Car();

	//Car Methods
	void Accelerate();//The accelerate function should add 12.5 to the speed member variable each time it is called.
	void Brake();//The brake function should subtract 11.5 from the speed member variable each time it is called.
};

//Constructor
Car::Car(int year, string model, string make, double speed) {
	this -> year = year;
	this -> model = model;
	this -> make = make;
	this -> speed = speed;
}
Car::Car() {//Overload Constructor in case the user wants to make an object but doesn't know what will go in it at the moment
	this-> year = 0000;
	this-> model = "Mon-Mon";
	this-> make = "Imani";
	this-> speed = 0.0;
}

void Car::Accelerate() {
	this->speed = speed + 12.5;
}

void Car::Brake() {
	this->speed = speed - 11.5;
}

Car::~Car() {
	cout << "The " << this->year << " " << this->make << " " << this->model << " was sent to the wreck."<<endl;
}

int main() {
	Car Jotaro(1970, "Crosstrek", "Subaru", 0);

	for (int i = 0; i < 5; i++) {
		Jotaro.Accelerate();
		cout << "The car's speed is " << Jotaro.accessorSpeed() << " mph." << endl;
	}
	cout << "\n";
	for (int i = 0; i < 5; i++) {
		Jotaro.Brake();
		cout << "The car's speed is " << Jotaro.accessorSpeed() << " mph." << endl;
	}
	cout << "\n";

	system("pause");
	return 0;
}