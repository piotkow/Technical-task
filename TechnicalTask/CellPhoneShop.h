#pragma once
#include <algorithm>
#include <vector>
#include <map>
#include "CellPhone.h"
#include <fstream>

using namespace std;

class CellPhoneShop
{
private:
	vector<CellPhone> phoneList;
public:
	void addPhone(CellPhone phone);

	void deletePhone(int index);

	vector<CellPhone> brandReport(string brand);
	vector<CellPhone> formFactorScreenSizeReport(string formFactor, double screenSize);
	vector<CellPhone> maxBrandReport(string brand, int maxQuantity);
	vector<double> top3ScreenSizeReport();

	void saveList();
	void loadList();
};

