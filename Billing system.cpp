#include <iostream>
#include <iomanip> // For formatting output
using namespace std;

void design_of_Bill(const char name[], const char date[]) {
    cout << "\n\n";
    cout << "\t   GREAT OBSERVER RESTAURANT CLUB   \n";
    cout << "\n\t-------------------------------------------\n";
    cout << "Date: " << date << endl;
    cout << "Invoice To: " << name << endl;
    cout << "\n";
    cout << "--------------------------------------------------------------\n";
    cout << "Items\t\t\t";
    cout << "Qty\t\t";
    cout << "Price\t\t";
    cout << "\n--------------------------------------------------------------\n";
}

void print_in_Bill(const char item[], int qty, float price) {
    cout << left << setw(20) << item;
    cout << "\t" << qty << "\t\t";
    cout << fixed << setprecision(2) << qty * price << "\n";
}

void calculate_Bill(float total) {
    cout << "\n============================================================\n";
    cout << "Total Amount: \t\t\t\t\t" << fixed << setprecision(2) << total << endl;
    cout << "============================================================\n";
}

struct Restaurant {
    char name[50];
    char date[20];
    char item[40];
    int qty;
    float unit_price;
};

int main() {
    float total = 0.0;
    int num_orders;
    Restaurant orders[50];

    cout << "\nEnter the Date (dd/mm/yyyy): ";
    cin.getline(orders[0].date, 20);

    cout << "Enter the Customer Name: ";
    cin.getline(orders[0].name, 50);

    cout << "\nEnter the number of items ordered by the customer: ";
    cin >> num_orders;

    for (int i = 0; i < num_orders; i++) {
        cin.ignore(); // To ignore the newline character left in the input buffer
        cout << "\nEnter item " << i + 1 << ": ";
        cin.getline(orders[i].item, 40);

        cout << "Enter quantity of the item: ";
        cin >> orders[i].qty;

        cout << "Enter per-unit charge of the item: ";
        cin >> orders[i].unit_price;

        total += orders[i].qty * orders[i].unit_price;
    }

    design_of_Bill(orders[0].name, orders[0].date);

    for (int i = 0; i < num_orders; i++) {
        print_in_Bill(orders[i].item, orders[i].qty, orders[i].unit_price);
    }

    calculate_Bill(total);

    cout << "\n=======================================================================\n";
    cout << "\t********************* THANK YOU ****************************\n\n";

    return 0;
}

