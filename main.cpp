#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 15;

bool login(){
    string pass;
    cin >> pass;
    return pass == "admin";
}

void loadMenu(string name[], double price[], int time[], int stock[], int &n){
    ifstream in("MenuFood.txt");
    n = 0;

    while(in >> name[n] >> price[n] >> time[n] >> stock[n]){
        n++;
    }
}

void showMenu(string name[], double price[], int time[], int stock[], int n){
    for(int i=0;i<n;i++){
        cout << i+1 << ". " << name[i] << endl;
    }
}

void addFood(){
    ofstream out("MenuFood.txt", ios::app);

    string name;
    double price;
    int time, stock;

    cout << "Name: "; cin >> name;
    cout << "Price: "; cin >> price;
    cout << "Time: "; cin >> time;
    cout << "Stock: "; cin >> stock;

    out << name << " " << price << " " << time << " " << stock << endl;
}

int main(){
    int choice;
    cin >> choice;

    if(choice == 1){
        if(login()) addFood();
    }
    else if(choice == 2){
        string name[MAX];
        double price[MAX];
        int time[MAX], stock[MAX];
        int n;

        loadMenu(name, price, time, stock, n);
        showMenu(name, price, time, stock, n);
    }

    return 0;
}