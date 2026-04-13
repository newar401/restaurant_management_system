#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int FOOD = 15;
const int COL = 4;

int main(){
    string menu[FOOD][COL];
    int count = 0;

    ifstream in("MenuFood.txt");

    while(getline(in, menu[count][0], '\t') &&
          getline(in, menu[count][1], '\t') &&
          getline(in, menu[count][2], ' ') &&
          getline(in, menu[count][3]))
    {
        count++;
    }
    in.close();

    for(int i = 0; i < count; i++){
        cout << i+1 << ". " << menu[i][0]
             << " RM " << menu[i][1] << endl;
    }

    int choice;
    double newPrice;

    cout << "Select item: ";
    cin >> choice;

    cout << "New price: ";
    cin >> newPrice;

    ofstream out("MenuFood.txt");

    for(int i = 0; i < count; i++){
        if(i == choice-1){
            out << menu[i][0] << "\t" << newPrice << "\t"
                << menu[i][2] << " " << menu[i][3] << endl;
        } else {
            out << menu[i][0] << "\t" << menu[i][1] << "\t"
                << menu[i][2] << " " << menu[i][3] << endl;
        }
    }

    return 0;
}