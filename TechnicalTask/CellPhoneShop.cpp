#include "CellPhoneShop.h"

void CellPhoneShop::addPhone(CellPhone phone)
{
	phoneList.push_back(phone);
}

void CellPhoneShop::deletePhone(int index)
{
	phoneList.erase(phoneList.begin() + index);
}

vector<CellPhone> CellPhoneShop::brandReport(string brand)
{
	vector<CellPhone> report;
	for(int i=0;i<phoneList.size();i++){
		if (phoneList.at(i).getBrandName() == brand) {
			report.push_back(phoneList.at(i));
		}
	}
	return report;
}

vector<CellPhone> CellPhoneShop::formFactorScreenSizeReport(string formFactor, double screenSize)
{
	vector<CellPhone> report;
	for (int i = 0; i < phoneList.size(); i++) {
		if (phoneList.at(i).getFormFactor() == formFactor && phoneList.at(i).getScreenSize() == screenSize) {
			report.push_back(phoneList.at(i));
		}
	}
	return report;
}

vector<CellPhone> CellPhoneShop::maxBrandReport(string brand, int maxQuantity)
{
	vector<CellPhone> report;
	for (int i = 0; i < phoneList.size(); i++) {
		if (phoneList.at(i).getBrandName() == brand && report.size() < maxQuantity) {
			report.push_back(phoneList.at(i));
		}
	}
	return report;
}

vector<double> CellPhoneShop::top3ScreenSizeReport()
{
	map<double, int> screenSizeCounts;
	for (CellPhone phone : phoneList) {
		++screenSizeCounts[phone.getScreenSize()];
	}

	vector<pair<float, int>> screenSizes(screenSizeCounts.begin(), screenSizeCounts.end());
	sort(screenSizes.begin(), screenSizes.end(), [](const auto& a, const auto& b) {
		return a.second > b.second;
		});

	vector<double> result;
	for (int i = 0; i < 3 && i < screenSizes.size(); ++i) {
		result.push_back(screenSizes[i].first);
	}

	return result;
}

void CellPhoneShop::saveList()
{
	ofstream file("phonelist.txt",ios::out);
	if (file.is_open()) {
		for (int i = 0; i < phoneList.size(); i++) {
			file << phoneList.at(i).getBrandName() << " ";
			file << phoneList.at(i).getModelName() << " ";
			file << phoneList.at(i).getFormFactor() << " ";
			file << phoneList.at(i).getYearOfIssue() << " ";
			file << phoneList.at(i).getScreenSize() << " ";
			file << phoneList.at(i).getPrice() << endl;
		}
		file.close();
	}
}

void CellPhoneShop::loadList()
{
	ifstream file("phonelist.txt");
	if (file.is_open()) {
		string brandName;
		string modelName;
		string formFactor;
		int yearOfIssue;
		double screenSize;
		double price;
		phoneList.clear();
		while (file >> brandName >> modelName >> formFactor >> yearOfIssue >> screenSize >> price) {
			CellPhone phone(brandName, modelName, formFactor, yearOfIssue, screenSize, price);
			phoneList.push_back(phone);
		}
		file.close();
	}
}


