#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <limits>
#include <cctype>

using namespace std;

// ============================================================
// Account Structure
// ============================================================

struct Account {
    int id;
    string website;
    string username;
    string password;
};

// ============================================================
// Password Manager Class
// ============================================================

class PasswordManager {

private:

    vector<Account> accounts;

    const string dataFile = "passwords.txt";
    const string masterPassword = "admin123";

    // --------------------------------------------------------
    // Generate next ID
    // --------------------------------------------------------

    int getNextId() const {

        int maxId = 0;

        for (const auto& account : accounts) {

            if (account.id > maxId) {
                maxId = account.id;
            }
        }

        return maxId + 1;
    }

    // --------------------------------------------------------
    // Save accounts
    // --------------------------------------------------------

    void saveToFile() const {

        ofstream file(dataFile);

        if (!file) {

            cout << "\nError: Could not save data.\n";
            return;
        }

        for (const auto& account : accounts) {

            file << account.id << "|"
                 << account.website << "|"
                 << account.username << "|"
                 << account.password
                 << "\n";
        }

        file.close();
    }

    // --------------------------------------------------------
    // Hide password
    // --------------------------------------------------------

    string maskPassword(const string& password) const {

        return string(password.length(), '*');
    }

public:

    // ========================================================
    // Login
    // ========================================================

    bool login() const {

        string password;

        cout << "\n=====================================\n";
        cout << "        PASSWORD MANAGER\n";
        cout << "=====================================\n";

        cout << "Enter master password: ";
        cin >> password;

        if (password == masterPassword) {

            cout << "\nLogin successful!\n";
            return true;
        }

        cout << "\nIncorrect master password.\n";

        return false;
    }

    // ========================================================
    // Load accounts
    // ========================================================

    void loadFromFile() {

        ifstream file(dataFile);

        if (!file) {
            return;
        }

        accounts.clear();

        string line;

        while (getline(file, line)) {

            if (line.empty()) {
                continue;
            }

            size_t p1 = line.find('|');
            size_t p2 = line.find('|', p1 + 1);
            size_t p3 = line.find('|', p2 + 1);

            if (p1 == string::npos ||
                p2 == string::npos ||
                p3 == string::npos) {

                continue;
            }

            try {

                Account account;

                account.id =
                    stoi(line.substr(0, p1));

                account.website =
                    line.substr(
                        p1 + 1,
                        p2 - p1 - 1
                    );

                account.username =
                    line.substr(
                        p2 + 1,
                        p3 - p2 - 1
                    );

                account.password =
                    line.substr(p3 + 1);

                accounts.push_back(account);
            }

            catch (...) {

                // Ignore invalid records
            }
        }

        file.close();
    }

    // ========================================================
    // Add Account
    // ========================================================

    void addAccount() {

        Account account;

        account.id = getNextId();

        cout << "\n========== ADD ACCOUNT ==========\n";

        cout << "Website/App: ";
        cin >> account.website;

        cout << "Username/Email: ";
        cin >> account.username;

        cout << "Password: ";
        cin >> account.password;

        accounts.push_back(account);

        saveToFile();

        cout << "\nAccount saved successfully!\n";
        cout << "Account ID: "
             << account.id
             << "\n";
    }

    // ========================================================
    // Display accounts
    // ========================================================

    void viewAccounts() const {

        if (accounts.empty()) {

            cout << "\nNo accounts saved.\n";
            return;
        }

        cout << "\n================ SAVED ACCOUNTS ================\n";

        cout << left
             << setw(6) << "ID"
             << setw(25) << "Website"
             << setw(30) << "Username"
             << "Password\n";

        cout << string(80, '-') << "\n";

        for (const auto& account : accounts) {

            cout << left
                 << setw(6)
                 << account.id

                 << setw(25)
                 << account.website

                 << setw(30)
                 << account.username

                 << maskPassword(account.password)

                 << "\n";
        }
    }

    // ========================================================
    // Search account
    // ========================================================

    void searchAccount() const {

        if (accounts.empty()) {

            cout << "\nNo accounts saved.\n";
            return;
        }

        string search;

        cout << "\nEnter website/app name: ";
        cin >> search;

        bool found = false;

        for (const auto& account : accounts) {

            if (account.website == search) {

                cout << "\n========== ACCOUNT FOUND ==========\n";

                cout << "ID       : "
                     << account.id
                     << "\n";

                cout << "Website  : "
                     << account.website
                     << "\n";

                cout << "Username : "
                     << account.username
                     << "\n";

                cout << "Password : "
                     << account.password
                     << "\n";

                found = true;
            }
        }

        if (!found) {

            cout << "\nNo account found for "
                 << search
                 << ".\n";
        }
    }

    // ========================================================
    // Update Password
    // ========================================================

    void updatePassword() {

        if (accounts.empty()) {

            cout << "\nNo accounts saved.\n";
            return;
        }

        int id;

        cout << "\nEnter account ID: ";

        while (!(cin >> id)) {

            cout << "Enter a valid ID: ";

            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );
        }

        for (auto& account : accounts) {

            if (account.id == id) {

                cout << "Website: "
                     << account.website
                     << "\n";

                cout << "New password: ";

                cin >> account.password;

                saveToFile();

                cout << "\nPassword updated successfully!\n";

                return;
            }
        }

        cout << "\nAccount ID not found.\n";
    }

    // ========================================================
    // Delete Account
    // ========================================================

    void deleteAccount() {

        if (accounts.empty()) {

            cout << "\nNo accounts saved.\n";
            return;
        }

        int id;

        cout << "\nEnter account ID to delete: ";

        while (!(cin >> id)) {

            cout << "Enter a valid ID: ";

            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );
        }

        auto oldSize = accounts.size();

        accounts.erase(
            remove_if(
                accounts.begin(),
                accounts.end(),

                [id](const Account& account) {

                    return account.id == id;
                }
            ),

            accounts.end()
        );

        if (accounts.size() < oldSize) {

            saveToFile();

            cout << "\nAccount deleted successfully!\n";
        }

        else {

            cout << "\nAccount ID not found.\n";
        }
    }

    // ========================================================
    // Generate Random Password
    // ========================================================

    void generatePassword() const {

        int length;

        cout << "\nEnter password length: ";

        while (!(cin >> length) || length < 6) {

            cout << "Password length must be at least 6: ";

            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );
        }

        const string characters =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz"
            "0123456789"
            "!@#$%^&*";

        random_device rd;

        mt19937 generator(rd());

        uniform_int_distribution<int> distribution(
            0,
            static_cast<int>(characters.length()) - 1
        );

        string password;

        for (int i = 0; i < length; i++) {

            password +=
                characters[distribution(generator)];
        }

        cout << "\nGenerated Password:\n";
        cout << password << "\n";
    }
};

// ============================================================
// Menu
// ============================================================

void showMenu() {

    cout << "\n";
    cout << "========================================\n";
    cout << "          PASSWORD MANAGER\n";
    cout << "========================================\n";

    cout << "1. Add Account\n";
    cout << "2. View Accounts\n";
    cout << "3. Search Account\n";
    cout << "4. Update Password\n";
    cout << "5. Delete Account\n";
    cout << "6. Generate Password\n";
    cout << "7. Exit\n";

    cout << "========================================\n";
    cout << "Enter choice: ";
}

// ============================================================
// Main
// ============================================================

int main() {

    PasswordManager manager;

    // Load existing accounts
    manager.loadFromFile();

    // Login
    if (!manager.login()) {

        cout << "\nAccess denied.\n";
        return 0;
    }

    int choice;

    while (true) {

        showMenu();

        while (!(cin >> choice)) {

            cout << "Invalid input. Enter a number: ";

            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );
        }

        switch (choice) {

            case 1:
                manager.addAccount();
                break;

            case 2:
                manager.viewAccounts();
                break;

            case 3:
                manager.searchAccount();
                break;

            case 4:
                manager.updatePassword();
                break;

            case 5:
                manager.deleteAccount();
                break;

            case 6:
                manager.generatePassword();
                break;

            case 7:

                cout << "\nThank you for using "
                     << "Password Manager!\n";

                return 0;

            default:

                cout << "\nInvalid choice.\n";
        }
    }

    return 0;
}
