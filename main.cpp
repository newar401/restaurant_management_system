#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int FOOD = 15;
const int COL = 4;

int main(){
    string menu[FOOD][COL];
    int count = 0;

    ifstream inFile("MenuFood.txt");

    while(count < FOOD &&
          getline(inFile, menu[count][0], '\t') &&
          getline(inFile, menu[count][1], '\t') &&
          getline(inFile, menu[count][2], ' ') &&
          getline(inFile, menu[count][3]))
    {
        count++;
    }

    for(int i = 0; i < count; i++){
        cout << i+1 << ". " << menu[i][0]
             << " RM " << menu[i][1] << endl;
    }

    return 0;
}