#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;

int main() {
    double a, b, step;
    int n;
    int finish = 0;

    //comment

    cout << "-------------------------------------------- \n"
        << "|            Software engineering          | \n"
        << "|            Laboratory work 2             | \n"
        << "|            Coding domain 21              | \n"
        << "-------------------------------------------- \n"
        << "Welcome to the program 'Formula calculator'!\n\n";

    cout << "Press Enter to open the main menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true) {


     

        cout << "-------------------------------------------- \n"
            << "|                Main menu                 | \n"
            << "-------------------------------------------- \n"
            << "1. Calculate for a SINGLE x\n"
            << "2. Calculate for a RANGE of x\n"
            << "3. Exit program"  
            << "  >> ";

        if (!(cin >> finish)) {
            cout << "INPUT ONLY NUMBERS\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            finish = 0;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (finish == 3) {
            cout << "                                \n";
            cout << "Thank you for using the program!\n";
            cout << "Goodbye...\n";
            break;
        }

        if (finish != 1 && finish != 2) {
            cout << "Unknown option. Returning to menu.\n";
            continue;
        }

        while (true) {
            cout << "Enter n (must be > 3): ";
            if (!(cin >> n)) {
                cout << "Invalid input! Please enter an integer.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (n <= 3) {
                cout << "n must be greater than 3. Try again.\n";
                continue;
            }
            break;
        }

        if (finish == 2) {
            while (true) {
                cout << "Enter start of range (a): ";
                if (!(cin >> a)) {
                    cout << "Invalid input! Please enter a number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                cout << "Enter end of range (b): ";
                if (!(cin >> b)) {
                    cout << "Invalid input! Please enter a number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                if (a >= b) {
                    cout << "Start of range (a) must be smaller than end (b). Try again.\n";
                    continue;
                }
                break;
            }

            while (true) {
                cout << "Enter step value: ";
                if (!(cin >> step)) {
                    cout << "Invalid input! Please enter a number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                if (step <= 0) {
                    cout << "Step must be greater than 0. Try again.\n";
                    continue;
                }
                break;
            }

            cout << fixed << setprecision(6);
            cout << "\n x\t\t y\n";
            cout << "----------------------------\n";

            for (double x = a; x <= b; x += step) {
                double y;

                if (x < 0) {
                    double product = 1.0;
                    for (int i = 2; i <= n - 1; i++) {
                        double term = (x * i) + (x * x) / (i + 1);
                        product *= term;
                    }
                    y = product;
                } else {
                    double sum = 0.0;
                    for (int j = 1; j <= n; j++) {
                        double product = 1.0;
                        for (int i = 1; i <= n + 1; i++) {
                            if (i == j) continue; 
                            double term = (x / (2 + i)) + (3.0 * i / (i - j));
                            product *= term;
                        }
                        sum += product;
                    }
                    y = sum;
                }

                cout << setw(8) << x << "\t" << setw(12) << y << endl;
            }

            cout << "\nCalculation complete. Press Enter to return to menu.";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

        if (finish == 1) {
            double x;
            while (true) {
                cout << "Enter x: ";
                if (!(cin >> x)) {
                    cout << "Invalid input! Please enter a number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                break;
            }

            double y;

            if (x < 0) {
                double product = 1.0;
                for (int i = 2; i <= n - 1; i++) {
                    double term = (x * i) + (x * x) / (i + 1);
                    product *= term;
                }
                y = product;
            } else {
                double sum = 0.0;
                for (int j = 1; j <= n; j++) {
                    double product = 1.0;
                    for (int i = 1; i <= n + 1; i++) {
                        if (i == j) continue; 
                        double term = (x / (2 + i)) + (3.0 * i / (i - j));
                        product *= term;
                    }
                    sum += product;
                }
                y = sum;
            }

            cout << fixed << setprecision(6);
            cout << "\n x\t\t y\n";
            cout << "----------------------------\n";
            cout << setw(8) << x << "\t" << setw(12) << y << endl;

            cout << "\nCalculation complete. Press Enter to return to menu.";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
    }

    return 0;
}