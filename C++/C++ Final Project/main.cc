#include <iostream>
#include <memory>
#include <filesystem>
#include <fstream>
#include <string>
#include <algorithm>
#include "Bank.h"
#include "SaveAcc.h"
#include "CheckAcc.h"
#include "Validation.h"
#include "SaveManger.h"

void UserMenu(Bank &bank, User *currentUser)
{
    int option;
    bool loggedIn = true;

    while (loggedIn)
    {
        std::string accountID;
        double balance;
        double amount;
        std::string senderID;
        std::string receiverID;

        std::cout << "\n=====================================\n";
        std::cout << "Welcome, " << currentUser->getUsername() << "\n";
        std::cout << "=====================================\n";
        std::cout << "1. Create Saving Account\n";
        std::cout << "2. Create Checking Account\n";
        std::cout << "3. Deposit\n";
        std::cout << "4. Withdraw\n";
        std::cout << "5. Transfer\n";
        std::cout << "6. Display My Accounts\n";
        std::cout << "7. Logout\n";

        option = Validation::getInt("Choice: ");

        switch (option)
        {
        case 1:
            balance = Validation::getDouble("Enter starter balance: ");

            try
            {
                bank.createSavingAccount(currentUser, balance);
                SaveManger::saveUsers(bank);
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << "\n";
            }
            break;

        case 2:
            balance = Validation::getDouble("Enter starter balance: ");

            try
            {
                bank.createCheckingAccount(currentUser, balance);
                SaveManger::saveUsers(bank);
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << "\n";
            }
            break;

        case 3:
            currentUser->displayAccounts();
            accountID = Validation::getString("Enter Account ID: ");

            try
            {
                Account *account = currentUser->findAccount(accountID);

                if (!account)
                    throw std::runtime_error("Account not found.");

                amount = Validation::getDouble("Enter Deposit Amount: ");

                account->deposit(amount);

                SaveManger::saveUsers(bank);

                std::cout << "Deposit done.\n";
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << "\n";
            }
            break;

        case 4:
            currentUser->displayAccounts();
            accountID = Validation::getString("Enter Account ID: ");

            try
            {
                Account *account = currentUser->findAccount(accountID);

                if (!account)
                    throw std::runtime_error("Account not found");

                amount = Validation::getDouble("Enter Withdraw Amount: ");

                account->withdraw(amount);

                SaveManger::saveUsers(bank);

                std::cout << "Withdrawal done\n";
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << "\n";
            }
            break;

        case 5:
            senderID = Validation::getString("Sender Account ID: ");
            receiverID = Validation::getString("Receiver Account ID: ");
            amount = Validation::getDouble("Transfer Amount: ");

            try
            {
                bank.transfer(senderID, receiverID, amount);

                SaveManger::saveUsers(bank);
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << "\n";
            }
            break;

        case 6:
            currentUser->displayAccounts();
            break;

        case 7:
            loggedIn = false;
            SaveManger::log("User Logged Out: " + currentUser->getUsername());
            break;

        default:
            std::cout << "Invalid choice\n";
        }
    }
}

void AdminMenu(Bank &bank, User *currentUser)
{
    bool loggedIn = true;

    while (loggedIn)
    {
        std::cout << "\n=====================================\n";
        std::cout << "            ADMIN PANEL\n";
        std::cout << "=====================================\n";
        std::cout << "Welcome, " << currentUser->getUsername() << "\n\n";

        std::cout << "1. Create User\n";
        std::cout << "2. Create Saving Account\n";
        std::cout << "3. Create Checking Account\n";
        std::cout << "4. Delete User\n";
        std::cout << "5. Delete Account\n";
        std::cout << "6. Change Username\n";
        std::cout << "7. Change Password\n";
        std::cout << "8. Change Account Balance\n";
        std::cout << "9. List Users\n";
        std::cout << "10. List Accounts\n";
        std::cout << "11. Display Users (Sorted by Balance) \n";
        std::cout << "12. Logout\n";

        int choice = Validation::getInt("Choice: ");

        try
        {
            switch (choice)
            {
            case 1:
            {
                std::string username = Validation::getString("Username: ");
                std::string password = Validation::getString("Password: ");

                bank.registerUser(username, password);
                break;
            }

            case 2:
            {
                std::string userID = Validation::getString("User ID: ");
                double balance = Validation::getDouble("Initial Balance: ");

                User *user = bank.findUser(userID);

                if (!user)
                    throw std::runtime_error("User not found");

                bank.createSavingAccount(user, balance);
                break;
            }

            case 3:
            {
                std::string userID = Validation::getString("User ID: ");
                double balance = Validation::getDouble("Initial Balance: ");

                User *user = bank.findUser(userID);

                if (!user)
                    throw std::runtime_error("User not found");

                bank.createCheckingAccount(user, balance);
                break;
            }

            case 4:
            {
                std::string userID = Validation::getString("User ID: ");

                bank.deleteUser(userID);

                std::cout << "User deleted successfully\n";
                break;
            }

            case 5:
            {
                std::string accountID = Validation::getString("Account ID: ");

                bank.deleteAccount(accountID);

                std::cout << "Account deleted successfully\n";
                break;
            }

            case 6:
            {
                std::string userID = Validation::getString("User ID: ");
                std::string username = Validation::getString("New Username: ");

                bank.changeUsername(userID, username);

                std::cout << "Username changed successfully\n";
                break;
            }

            case 7:
            {
                std::string userID = Validation::getString("User ID: ");
                std::string password = Validation::getString("New Password: ");

                bank.changePassword(userID, password);

                std::cout << "Password changed successfully\n";
                break;
            }

            case 8:
            {
                std::string accountID = Validation::getString("Account ID: ");
                double balance = Validation::getDouble("New Balance: ");

                bank.changeAccountBalance(accountID, balance);

                std::cout << "Balance updated successfully\n";
                break;
            }

            case 9:
            {
                bank.displayUsers();
                break;
            }

            case 10:
            {
                bank.displayAllAccounts();
                break;
            }

            case 11:
            {
                std::string userID = Validation::getString("User ID: ");

                User *user = bank.findUser(userID);

                if (!user)
                    throw std::runtime_error("User not found");

                std::cout << "\n========== USER DETAILS ==========\n";
                std::cout << "User ID   : " << user->getUserID() << "\n";
                std::cout << "Username  : " << user->getUsername() << "\n";
                std::cout << "Admin     : "
                          << (user->getIsAdmin() ? "Yes" : "No") << "\n\n";

                user->displayAccounts();

                break;
            }

            case 12:
            {
                loggedIn = false;
                SaveManger::log("Admin Logged Out: " + currentUser->getUsername());
                break;
            }

            default:
                std::cout << "Invalid choice\n";
            }
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << "\n";
        }
    }
}

void Menu(Bank &bank)
{
    bool running = true;

    while (running)
    {
        std::cout << "\n=====================================\n";
        std::cout << "      BANK MANAGEMENT SYSTEM\n";
        std::cout << "=====================================\n";
        std::cout << "1. Register User\n";
        std::cout << "2. Login\n";
        std::cout << "3. Exit\n";

        int choice = Validation::getInt("Choice: ");

        switch (choice)
        {
        case 1:
        {
            std::string username = Validation::getString("Username: ");
            std::string password = Validation::getString("Password: ");

            try
            {
                bank.registerUser(username, password);
                SaveManger::saveUsers(bank);
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << "\n";
            }

            break;
        }

        case 2:
        {
            std::string id = Validation::getString("User ID: ");
            std::string password = Validation::getString("Password: ");

            User *currentUser = bank.login(id, password);

            if (!currentUser)
            {
                std::cout << "Invalid User ID or Password\n";
                break;
            }

            if (currentUser->getIsAdmin())
            {
                AdminMenu(bank, currentUser);
            }
            else
            {
                UserMenu(bank, currentUser);
            }

            break;
        }

        case 3:
            running = false;
            break;

        default:
            std::cout << "Invalid choice\n";
        }
    }
}

int main()
{

    Bank bank;

    SaveManger::initialize();
    SaveManger::loadUsers(bank);
    SaveManger::log("Program Started");

    Menu(bank);

    SaveManger::log("Program Closed");
    SaveManger::saveUsers(bank);
    return 0;
}