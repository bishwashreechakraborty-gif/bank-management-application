#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

// --- Account Class ---
class Account {
private:
    int accountNum;
    char name[50];
    double balance;

public:
    void createAccount() {
        cout << "\nEnter Account Number: ";
        cin >> accountNum;
        cout << "Enter Account Holder Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter Initial Deposit Amount: ";
        cin >> balance;
        cout << "\nAccount Created Successfully!";
    }

    void showAccount() const {
        cout << "\nAcc No. : " << accountNum;
        cout << "\nHolder  : " << name;
        cout << "\nBalance : $" << fixed << setprecision(2) << balance << endl;
    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            return false;
        }
        balance -= amount;
        return true;
    }

    int getAccountNum() const { return accountNum; }
    double getBalance() const { return balance; }
};

// --- Function Prototypes for File Handling ---
void writeAccount();
void displayAll();
void depositWithdraw(int n, int sel);
void displayBalance(int n);

int main() {
    int choice;
    int num;

    do {
        cout << "\n\n============================";
        cout << "\n   BANK MANAGEMENT SYSTEM";
        cout << "\n============================";
        cout << "\n1. NEW ACCOUNT";
        cout << "\n2. DEPOSIT AMOUNT";
        cout << "\n3. WITHDRAW AMOUNT";
        cout << "\n4. BALANCE ENQUIRY";
        cout << "\n5. ALL ACCOUNT HOLDER LIST";
        cout << "\n6. EXIT";
        cout << "\n\nSelect Option (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                writeAccount();
                break;
            case 2:
                cout << "\nEnter Account Number: "; cin >> num;
                depositWithdraw(num, 1);
                break;
            case 3:
                cout << "\nEnter Account Number: "; cin >> num;
                depositWithdraw(num, 2);
                break;
            case 4:
                cout << "\nEnter Account Number: "; cin >> num;
                displayBalance(num);
                break;
            case 5:
                displayAll();
                break;
            case 6:
                cout << "\nThank you for using our banking system!";
                break;
            default:
                cout << "\aInvalid Selection!";
        }
    } while (choice != 6);

    return 0;
}

// --- Logic Implementation ---

void writeAccount() {
    Account ac;
    ofstream outFile;
    outFile.open("bank_data.dat", ios::binary | ios::app);
    ac.createAccount();
    outFile.write(reinterpret_cast<char*>(&ac), sizeof(Account));
    outFile.close();
}

void displayBalance(int n) {
    Account ac;
    bool found = false;
    ifstream inFile;
    inFile.open("bank_data.dat", ios::binary);
    if (!inFile) {
        cout << "File could not be opened!! Press any Key...";
        return;
    }
    while (inFile.read(reinterpret_cast<char*>(&ac), sizeof(Account))) {
        if (ac.getAccountNum() == n) {
            ac.showAccount();
            found = true;
        }
    }
    inFile.close();
    if (!found) cout << "\nAccount number does not exist.";
}

void depositWithdraw(int n, int sel) {
    double amt;
    bool found = false;
    Account ac;
    fstream File;
    File.open("bank_data.dat", ios::binary | ios::in | ios::out);
    
    if (!File) {
        cout << "File could not be opened!!";
        return;
    }

    while (!File.eof() && found == false) {
        File.read(reinterpret_cast<char*>(&ac), sizeof(Account));
        if (ac.getAccountNum() == n) {
            ac.showAccount();
            if (sel == 1) {
                cout << "\nEnter amount to DEPOSIT: ";
                cin >> amt;
                ac.deposit(amt);
            }
            if (sel == 2) {
                cout << "\nEnter amount to WITHDRAW: ";
                cin >> amt;
                if (!ac.withdraw(amt)) {
                    cout << "Insufficient balance!";
                }
            }
            // Move pointer back to update the record
            int pos = (-1) * static_cast<int>(sizeof(ac));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char*>(&ac), sizeof(Account));
            cout << "\nRecord Updated.";
            found = true;
        }
    }
    File.close();
    if (!found) cout << "\nRecord Not Found.";
}

void displayAll() {
    Account ac;
    ifstream inFile;
    inFile.open("bank_data.dat", ios::binary);
    if (!inFile) {
        cout << "File could not be opened!!";
        return;
    }
    cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout << "====================================================\n";
    cout << "A/c no.      NAME                Balance\n";
    cout << "====================================================\n";
    while (inFile.read(reinterpret_cast<char*>(&ac), sizeof(Account))) {
        cout << setw(10) << ac.getAccountNum() << setw(20) << ac.getAccountNum() 
             << setw(15) << ac.getBalance() << endl;
    }
    inFile.close();
}