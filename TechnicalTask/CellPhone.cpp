#include "CellPhone.h"

CellPhone::CellPhone(string brandName, string modelName, string formFactor, int yearOfIssue, double screenSize, double price):brandName(brandName), modelName(modelName), formFactor(formFactor)
{
	(yearOfIssue > 0) ? this->yearOfIssue = yearOfIssue : throw invalid_argument("Year of issue cannot be less than 0");
	(screenSize > 0) ? this->screenSize = screenSize : throw invalid_argument("Screen size cannot be less than 0");
	(price > 0) ? this->price = price : throw invalid_argument("price cannot be less than 0");
}

CellPhone::CellPhone()
{
}

void CellPhone::setBrandName(string brandName)
{
	this->brandName = brandName;
}

void CellPhone::setModelName(string modelName)
{
	this->modelName = modelName;
}

void CellPhone::setFormFactor(string formFactor)
{
	this->formFactor = formFactor;
}

void CellPhone::setYearOfIssue(int yearOfIssue)
{
	this->yearOfIssue = yearOfIssue;
}

void CellPhone::setScreenSize(double screenSize)
{
	this->screenSize = screenSize;
}

void CellPhone::setPrice(double price)
{
	this->price = price;
}


string CellPhone::getBrandName()
{
	return brandName;
}

string CellPhone::getModelName()
{
	return modelName;
}

string CellPhone::getFormFactor()
{
	return formFactor;
}

int CellPhone::getYearOfIssue()
{
	return yearOfIssue;
}

double CellPhone::getScreenSize()
{
	return screenSize;
}

double CellPhone::getPrice()
{
	return price;
}
