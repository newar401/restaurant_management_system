#include <iostream>
using namespace std;

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

int main(){
    int choice;

    cout << "===== RESTAURANT =====\n";
    cout << "1. Manager\n2. Customer\n3. Exit\n";
    cin >> choice;

    if(choice == 1){
        login();
    }
    else if(choice == 2){
        cout << "Customer Mode\n";
    }

    return 0;
}