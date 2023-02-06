// TechnicalTask.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "CellPhone.h"
#include "CellPhoneShop.h"

int main()
{
    int action;
    string brandName;
    string modelName;
    string formFactor;
    int yearOfIssue;
    double screenSize;
    double price;
    CellPhoneShop shop;
    CellPhone phone;

    string userBrand, userFormFactor;
    double userScreenSize;
    int maxQuantity;
    do {
        cout << "What u want to do?" << endl;
        cout << "1.Add Phone\n" << "2.Delete Phone\n" << "3.Reports\n" << "4.Load list from file\n" << "5.Save list to file\n" << "6.Quit\n";
        cin >> action;
        switch (action)
        {
        case 1:
            cout << "Brand name: "; cin >> brandName; phone.setBrandName(brandName);
            cout << "\nModel name: "; cin >> modelName; phone.setModelName(modelName);
            cout << "\nForm factor: "; cin >> formFactor; phone.setFormFactor(formFactor);
            cout << "\nYear of issue: "; cin >> yearOfIssue; phone.setYearOfIssue(yearOfIssue);
            cout << "\nScreen size: "; cin >> screenSize; phone.setScreenSize(screenSize);
            cout << "\nPrice: "; cin >> price; phone.setPrice(price);
            shop.addPhone(phone);
            break;
        case 2:
            int index;
            cout << "Which phone u want to delete?(index): "; cin >> index; shop.deletePhone(index);
            break;
        case 3:
            int reportAction;
            cout << "1.By the brand\n" << "2.By the form factor and screen size\n" << "3.By the brand with max quantity\n" << "4.Top 3 screen size\n" << "5.Quit\n";
            cin >> reportAction;
            switch (reportAction)
            {
            case 1:
                cout << "Brand name: "; cin >> userBrand;
                for (int i = 0; i < shop.brandReport(userBrand).size(); i++)
                    cout << shop.brandReport(userBrand)[i].getBrandName() << endl;
                break;
            case 2:
                cout << "Form Factor: "; cin >> userFormFactor;
                cout << "Screen Size: "; cin >> userScreenSize;
                for (int i = 0; i < shop.formFactorScreenSizeReport(userFormFactor, userScreenSize).size(); i++) {
                    cout << shop.formFactorScreenSizeReport(userFormFactor, userScreenSize)[i].getBrandName() << " ";
                    cout << shop.formFactorScreenSizeReport(userFormFactor, userScreenSize)[i].getModelName() << endl;
                }
                break;
            case 3:
                cout << "Brand name: "; cin >> userBrand;
                cout << "Max quantity: "; cin >> maxQuantity;
                for (int i = 0; i < shop.maxBrandReport(userBrand, maxQuantity).size(); i++)
                    cout << shop.maxBrandReport(userBrand, maxQuantity)[i].getBrandName() << endl;
            case 4:
                for (int i = 0; i < shop.top3ScreenSizeReport().size(); i++)
                    cout << shop.top3ScreenSizeReport()[i] << endl;
                break;
            case 5:
                break;
            }
            break;
        case 4:
            shop.loadList();
            break;
        case 5:
            shop.saveList();
        case 6:
            break;
        default:
            break;
        }
    } while (action != 6);
}


// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
