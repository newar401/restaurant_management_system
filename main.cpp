#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 15;

bool login(){
    string pass;
    cout << "Enter manager password: ";
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
    cout << "\n===== MENU =====\n";
    for(int i=0;i<n;i++){
        cout << i+1 << ". " << name[i]
             << " RM " << price[i]
             << " Time:" << time[i]
             << " Stock:" << stock[i] << endl;
    }
}

int main(){
    int choice;

    string name[MAX];
    double price[MAX];
    int time[MAX], stock[MAX];
    int n;

    cout << "===== RESTAURANT =====\n";
    cin >> choice;

    if(choice == 1){
        login();
    }
    else if(choice == 2){
        loadMenu(name, price, time, stock, n);
        showMenu(name, price, time, stock, n);
    }

    return 0;
}