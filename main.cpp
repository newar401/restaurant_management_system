#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 15;

// LOGIN
bool login(){
    string pass;
    cout << "Enter manager password: ";
    cin >> pass;

    if(pass == "admin"){
        cout << "Access granted\n";
        return true;
    }else{
        cout << "Wrong password\n";
        return false;
    }
}

// LOAD MENU
void loadMenu(string name[], double price[], int time[], int stock[], int &n){
    ifstream in("MenuFood.txt");
    n = 0;

    while(in >> name[n] >> price[n] >> time[n] >> stock[n]){
        n++;
    }
    in.close();
}

// SHOW MENU
void showMenu(string name[], double price[], int time[], int stock[], int n){
    cout << "\n==============================\n";
    cout << "           MENU\n";
    cout << "==============================\n";

    for(int i=0;i<n;i++){
        cout << i+1 << ". " << name[i]
             << " | RM " << price[i]
             << " | Time: " << time[i]
             << " | Stock: " << stock[i] << endl;
    }

    cout << "==============================\n";
}

// ADD FOOD
void addFood(){
    ofstream out("MenuFood.txt", ios::app);

    string name;
    double price;
    int time, stock;
    char ch;

    do{
        cout << "Name: ";
        cin >> name;

        cout << "Price: ";
        cin >> price;

        cout << "Time: ";
        cin >> time;

        cout << "Stock: ";
        cin >> stock;

        out << name << " " << price << " " << time << " " << stock << endl;

        cout << "Add more? (Y/N): ";
        cin >> ch;

    }while(ch=='Y'||ch=='y');

    out.close();
}

// UPDATE PRICE
void updatePrice(){
    string name[MAX];
    double price[MAX];
    int time[MAX], stock[MAX];
    int n;

    loadMenu(name, price, time, stock, n);
    showMenu(name, price, time, stock, n);

    int choice;
    cout << "Select food number: ";
    cin >> choice;

    if(choice < 1 || choice > n){
        cout << "Invalid choice\n";
        return;
    }

    cout << "New price: ";
    cin >> price[choice-1];

    ofstream out("MenuFood.txt");

    for(int i=0;i<n;i++){
        out << name[i] << " "
            << price[i] << " "
            << time[i] << " "
            << stock[i] << endl;
    }

    out.close();
    cout << "Price updated!\n";
}

// CUSTOMER SYSTEM
void customer(){
    string name[MAX];
    double price[MAX];
    int time[MAX], stock[MAX];
    int n;

    loadMenu(name, price, time, stock, n);

    double total = 0;
    int totalTime = 0;
    int popular[MAX] = {0};

    int choice;
    char more;

    do{
        showMenu(name, price, time, stock, n);

        cout << "Select food: ";
        cin >> choice;

        int i = choice - 1;

        if(i < 0 || i >= n){
            cout << "Invalid choice\n";
            continue;
        }

        if(stock[i] <= 0){
            cout << "Out of stock!\n";
            continue;
        }

        stock[i]--;
        popular[i]++;

        total += price[i];
        totalTime += time[i];

        cout << "Total: RM " << total << endl;
        cout << "Delivery Time: " << totalTime << " min\n";

        cout << "Order more? (Y/N): ";
        cin >> more;

    }while(more=='Y'||more=='y');

    // MOST POPULAR
    int maxIndex = 0;
    for(int j=1;j<n;j++){
        if(popular[j] > popular[maxIndex]){
            maxIndex = j;
        }
    }

    // PAYMENT
    double pay;
    cout << "Enter payment: ";
    cin >> pay;

    while(pay != total){
        cout << "Enter exact amount: ";
        cin >> pay;
    }

    cout << "Payment successful!\n";
    cout << "Most popular dish: " << name[maxIndex] << endl;

    // SAVE OUTPUT
    ofstream out("OutputFile.txt");
    out << "Total: RM " << total << endl;
    out << "Delivery Time: " << totalTime << endl;
    out << "Popular Dish: " << name[maxIndex] << endl;
    out.close();
}

// MAIN
int main(){
    int choice;

    cout << "==============================\n";
    cout << "   RESTAURANT SYSTEM\n";
    cout << "==============================\n";
    cout << "1. Manager\n";
    cout << "2. Customer\n";
    cout << "3. Exit\n";
    cout << "==============================\n";

    cin >> choice;

    if(choice == 1){
        if(login()){
            int m;
            cout << "1. Add Food\n2. Update Price\n";
            cin >> m;

            if(m == 1) addFood();
            else if(m == 2) updatePrice();
        }
    }
    else if(choice == 2){
        customer();
    }
    else{
        cout << "Thank you!\n";
    }

    return 0;
}