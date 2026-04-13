#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ofstream out("MenuFood.txt", ios::app);

    string name;
    double price;
    int time, stock;
    char ch;

    do{
        cin.ignore();
        cout << "Food name: ";
        getline(cin, name);

        cout << "Price: ";
        cin >> price;

        cout << "Time: ";
        cin >> time;

        cout << "Stock: ";
        cin >> stock;

        out << "\n" << name << "\t" << price << "\t" << time << " " << stock;

        cout << "Add more? (Y/N): ";
        cin >> ch;

    }while(ch == 'Y' || ch == 'y');

    return 0;
}