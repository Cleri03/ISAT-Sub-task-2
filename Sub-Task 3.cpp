#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_ORDERS = 50;

string orderIDs[MAX_ORDERS];
string customerNames[MAX_ORDERS];
int quantities[MAX_ORDERS];
float totals[MAX_ORDERS];

void initializeSampleData() {
    string ids[] = {"101","102","103","104","105","106","107","108","109","110"};
    string names[] = {"Thabo","Lerato","Nomvula","Sipho","Bongani","Lindiwe","Jabulani","Ayanda","Kgosi","Refilwe"};
    int qtys[] = {3,5,2,4,6,1,3,2,6,4};
    float totals[] = {15.75,30.50,10.00,22.00,40.25,5.50,18.00,12.75,24.50,28.00};

    for (int i = 0; i < 10; ++i) {
        orderIDs[i] = ids[i];
        customerNames[i] = names[i];
        quantities[i] = qtys[i];
        totals[i] = tots[i];
    }
    for (int i = 10; i < MAX_ORDERS; ++i) {
        orderIDs[i] = "0";  
    }
}

int findNextEmptySlot() {
    for (int i = 0; i < MAX_ORDERS; ++i) {
        if (orderIDs[i] == "0") return i;
    }
    return -1;
}

string getNextOrderID() {
    int maxID = 100;
    for (int i = 0; i < MAX_ORDERS; ++i) {
        if (orderIDs[i] != "0") {
            int id = stoi(orderIDs[i]);
            if (id > maxID) maxID = id;
        }
    }
    return to_string(maxID + 1);
}

void addOrder() {
    int idx = findNextEmptySlot();
    if (idx == -1) {
        cout << "Cannot add more orders (max " << MAX_ORDERS << ").\n";
        return;
    }

    string newID = getNextOrderID();
    string cname;
    int qty;
    float total;

    cout << "New Order ID: " << newID << "\n";
    cout << "Customer Name: "; getline(cin >> ws, cname);
    cout << "Number of Magwinyas: "; cin >> qty;
    cout << "Total Cost: R"; cin >> total;

    orderIDs[idx] = newID;
    customerNames[idx] = cname;
    quantities[idx] = qty;
    totals[idx] = total;

    cout << "Order added successfully.\n";
}

void displayAllOrders() {
    cout << left << setw(10) << "OrderID"
         << setw(15) << "Customer"
         << setw(10) << "Qty"
         << setw(10) << "Total (R)" << "\n";
    cout << string(45, '-') << "\n";

    for (int i = 0; i < MAX_ORDERS; ++i) {
        if (orderIDs[i] != "0") {
            cout << setw(10) << orderIDs[i]
                 << setw(15) << customerNames[i]
                 << setw(10) << quantities[i]
                 << setw(10) << fixed << setprecision(2) << totals[i]
                 << "\n";
        }
    }
}

void findOrder() {
    cout << "Enter Order ID to search: ";
    string searchID; cin >> searchID;

    for (int i = 0; i < MAX_ORDERS; ++i) {
        if (orderIDs[i] == searchID) {
            cout << "Order found:\n"
                 << "Customer: " << customerNames[i] << "\n"
                 << "Qty: " << quantities[i] << "\n"
                 << "Total: R" << fixed << setprecision(2) << totals[i] << "\n";
            return;
        }
    }
    cout << "Order ID " << searchID << " not found.\n";
}

void calculateTotalRevenue() {
    float totalRevenue = 0;
    for (int i = 0; i < MAX_ORDERS; ++i) {
        if (orderIDs[i] != "0") {
            totalRevenue += totals[i];
        }
    }
    cout << "Total revenue: R" << fixed << setprecision(2) << totalRevenue << "\n";
}

int main() {
    initializeSampleData();

    int choice = 0;
    do {
        cout << "\n=== Magwinya Magic Orders Menu ===\n"
             << "1. Add new order\n"
             << "2. Display all orders\n"
             << "3. Find order by Order ID\n"
             << "4. Calculate total revenue\n"
             << "5. Exit\n"
             << "Select an option (1–5): ";
        cin >> choice;

        if (choice == 1) {
            addOrder();
        } else if (choice == 2) {
            displayAllOrders();
        } else if (choice == 3) {
            findOrder();
        } else if (choice == 4) {
            calculateTotalRevenue();
        } else if (choice == 5) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid selection. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
