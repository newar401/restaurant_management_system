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

    if(!in){
        cout << "Menu file not found!\n";
        return;
    }

    while(n < MAX && in >> name[n] >> price[n] >> time[n] >> stock[n]){
        n++;
    }
    in.close();
}

// SAVE MENU
void saveMenu(string name[], double price[], int time[], int stock[], int n){
    ofstream out("MenuFood.txt");

    for(int i=0;i<n;i++){
        out << name[i] << " "
            << price[i] << " "
            << time[i] << " "
            << stock[i] << endl;
    }

    out.close();
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
        cin >> ws;
        getline(cin, name);

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

    saveMenu(name, price, time, stock, n);

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

    if(total == 0){
        cout << "No orders made.\n";
        return;
    }

    int maxIndex = 0;
    for(int j=1;j<n;j++){
        if(popular[j] > popular[maxIndex]){
            maxIndex = j;
        }
    }

    double pay;
    cout << "Enter payment: ";
    cin >> pay;

    while(pay < total){
        cout << "Insufficient amount. Enter again: ";
        cin >> pay;
    }

    cout << "Payment successful!\n";
    cout << "Change: RM " << pay - total << endl;
    cout << "Most popular dish: " << name[maxIndex] << endl;

    saveMenu(name, price, time, stock, n);

    ofstream out("OutputFile.txt");
    out << "Total: RM " << total << endl;
    out << "Delivery Time: " << totalTime << endl;
    out << "Popular Dish: " << name[maxIndex] << endl;
    out.close();
}

// MAIN
int main(){
    int choice;

    do{
        cout << "\n==============================\n";
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

    }while(choice != 3);

    cout << "Thank you!\n";

    return 0;
}