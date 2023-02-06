#pragma once
#include <string>
#include <stdexcept>
using namespace std;

class CellPhone
{
private:
	string brandName;
	string modelName;
	string formFactor;
	int yearOfIssue;
	double screenSize;
	double price;

public:
	CellPhone(string brandName, string modelName, string formFactor, int yearOfIssue, double screenSize, double price);
	CellPhone();

	void setBrandName(string brandName);
	void setModelName(string modelName);
	void setFormFactor(string formFactor);
	void setYearOfIssue(int yearOfIssue);
	void setScreenSize(double screenSize);
	void setPrice(double price);

	string getBrandName();
	string getModelName();
	string getFormFactor();
	int getYearOfIssue();
	double getScreenSize();
	double getPrice();

};

