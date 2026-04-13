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

    cin >> name >> price >> time >> stock;

    out << name << " " << price << " " << time << " " << stock << endl;
}

void updatePrice(){
    string name[MAX];
    double price[MAX];
    int time[MAX], stock[MAX];
    int n;

    loadMenu(name, price, time, stock, n);

    int choice;
    cin >> choice;

    cin >> price[choice-1];

    ofstream out("MenuFood.txt");

    for(int i=0;i<n;i++){
        out << name[i] << " " << price[i] << " " << time[i] << " " << stock[i] << endl;
    }
}
void customer(){
    string name[MAX];
    double price[MAX];
    int time[MAX], stock[MAX];
    int n;

    loadMenu(name, price, time, stock, n);

    double total = 0;
    int choice;

    do{
        cin >> choice;
        total += price[choice-1];

        char more;
        cin >> more;

        if(more!='Y' && more!='y') break;

    }while(true);

    cout << "Total: " << total << endl;
}

void customer(){
    string name[MAX];
    double price[MAX];
    int time[MAX], stock[MAX];
    int n;

    loadMenu(name, price, time, stock, n);

    int popular[MAX] = {0};

    double total = 0;
    int choice;
    char more;

    do{
        cin >> choice;

        int i = choice-1;

        if(stock[i] <= 0){
            cout << "Out of stock\n";
            continue;
        }

        stock[i]--;
        popular[i]++;

        total += price[i];

        cin >> more;

    }while(more=='Y'||more=='y');

    int maxIndex = 0;
    for(int j=1;j<n;j++){
        if(popular[j] > popular[maxIndex]){
            maxIndex = j;
        }
    }

    cout << "Popular: " << name[maxIndex] << endl;

    double pay;
    cin >> pay;

    while(pay != total){
        cin >> pay;
    }


int main(){
    int choice;
    cin >> choice;

    if(choice == 1){
        if(login()){
            int m;
            cin >> m;

            if(m == 1) addFood();
            else if(m == 2) updatePrice();
        }
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