#include <iostream>
#include <bitset>
#include <sstream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

void decimalToBinary() {
    int num;
    cout << "Enter a decimal number: ";
    cin >> num;
    cout << "Binary representation: " << bitset<16>(num) << endl;
}

void binaryToDecimal() {
    string binary;
    cout << "Enter a binary number: ";
    cin >> binary;
    int decimal = stoi(binary, nullptr, 2);
    cout << "Decimal representation: " << decimal << endl;
}

void hexToDecimal() {
    string hex;
    cout << "Enter a hexadecimal number: ";
    cin >> hex;
    int decimal = stoi(hex, nullptr, 16);
    cout << "Decimal representation: " << decimal << endl;
}

void decimalToHex() {
    int num;
    cout << "Enter a decimal number: ";
    cin >> num;
    stringstream ss;
    ss << hex << uppercase << num;
    cout << "Hexadecimal representation: " << ss.str() << endl;
}

void demoRandomToBinary() {
    srand(time(0)); 
    int randomNum = rand() % 100;  
    cout << "Generated random integer: " << randomNum << endl;
    cout << "Binary representation: " << bitset<16>(randomNum) << endl;
}

int main() {
    int choice;

    while (true) {
        cout << "\nConversion Menu:\n";
        cout << "1. Convert Decimal to Binary\n";
        cout << "2. Convert Binary to Decimal\n";
        cout << "3. Convert Hexadecimal to Decimal\n";
        cout << "4. Convert Decimal to Hexadecimal\n";
        cout << "5. Demo (Generate and convert random integers to binary)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        if (choice == 1) {
            decimalToBinary();
        }
        else if (choice == 2) {
            binaryToDecimal();
        }
        else if (choice == 3) {
            hexToDecimal();
        }
        else if (choice == 4) {
            decimalToHex();
        }
        else if (choice == 5) {
            demoRandomToBinary();
        }
        else if (choice == 6) {
            cout << "Exiting the program." << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please select between 1 and 6." << endl;
        }
    }

    return 0;
}
