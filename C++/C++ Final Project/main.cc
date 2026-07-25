#include <iostream>
#include <memory>
#include <filesystem>
#include <fstream>
#include <string>
#include "Bank.h"
#include "SaveAcc.h"
#include "CheckAcc.h"
#include "Validation.h"

void Menu(Bank &bank)
{
    int option;

    bool running = true;

    while (running)
    {
        int choice;
        std::string accountID;
        double balance;
        double amount;
        std::string senderID;
        std::string receiverID;

        std::cout << "\n=====================================\n";
        std::cout << "      BANK MANAGEMENT SYSTEM\n";
        std::cout << "=====================================\n";
        std::cout << "1. Register User\n";
        std::cout << "2. Login\n";
        std::cout << "3. Display Users\n";
        std::cout << "4. Exit\n";
        std::cout << "Choice: ";
        choice = Validation::getInt("Choice: ");

        switch (choice)
        {
        case 1:
        {
            std::string id, username, password;

            id = Validation::getString("User ID: ");
            username = Validation::getString("Username: ");
            password = Validation::getString("Password: ");

            try
            {
                bank.registerUser(id, username, password);
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << '\n';
            }

            break;
        }

        case 2:
        {
            std::string id, password;

            id = Validation::getString("User ID: ");
            password = Validation::getString("Password: ");

            User *currentUser = bank.login(id, password);

            if (currentUser == nullptr)
            {
                std::cout << "Invalid User ID or Password\n";
                break;
            }

            bool loggedIn = true;

            while (loggedIn)
            {

                std::cout << "\n=====================================\n";
                std::cout << "           Welcome, " << currentUser->getUsername() << '\n';
                std::cout << "=====================================\n";
                std::cout << "1. Create Saving Account\n";
                std::cout << "2. Create Checking Account\n";
                std::cout << "3. Deposit\n";
                std::cout << "4. Withdraw\n";
                std::cout << "5. Transfer\n";
                std::cout << "6. Display My Accounts\n";
                std::cout << "7. Logout\n";
                std::cout << "Choice: ";
                option = Validation::getInt("Choice: ");

                switch (option)
                {
                case 1:
                {

                    accountID = Validation::getString("Enter Account ID: ");
                    balance = Validation::getDouble("Enter starter balance: ");

                    try
                    {
                        if (bank.findAccount(accountID) != nullptr)
                        {
                            throw std::runtime_error("Account ID already exists");
                        }

                        currentUser->addAccount(
                            std::make_unique<SavingAccount>(accountID, balance));

                        std::cout << "Saving account created \n";
                    }
                    catch (const std::exception &e)
                    {
                        std::cout << e.what() << '\n';
                    }

                    break;
                }

                case 2:
                {

                    accountID = Validation::getString("Enter Account ID: ");
                    balance = Validation::getDouble("Enter starter balance: ");

                    try
                    {
                        if (bank.findAccount(accountID) != nullptr)
                        {
                            throw std::runtime_error("Account ID already exists");
                        }

                        currentUser->addAccount(
                            std::make_unique<CheckingAccount>(accountID, balance));

                        std::cout << "Saving account created\n";
                    }
                    catch (const std::exception &e)
                    {
                        std::cout << e.what() << '\n';
                    }

                    break;
                }

                case 3:
                {

                    accountID = Validation::getString("Enter Account ID: ");
                    amount = Validation::getDouble("Enter Deposit Amount: ");

                    try
                    {
                        Account *account = currentUser->findAccount(accountID);

                        if (!account)
                        {
                            throw std::runtime_error("Account not found or does not belong to you");
                        }

                        account->deposit(amount);

                        std::cout << "Deposit done\n";
                        std::cout << "Current Balance: " << account->getAccountBalance() << '\n';
                    }
                    catch (const std::exception &e)
                    {
                        std::cout << e.what() << '\n';
                    }

                    break;
                }

                case 4:
                {

                    accountID = Validation::getString("Enter Account ID: ");
                    amount = Validation::getDouble("Enter Withdraw Amount: ");

                    try
                    {
                        Account *account = currentUser->findAccount(accountID);

                        if (account == nullptr)
                        {
                            throw std::runtime_error("Account not found or does not belong to you");
                        }

                        account->withdraw(amount);

                        std::cout << "Withdrawal done\n";
                        std::cout << "Current Balance: "
                                  << account->getAccountBalance()
                                  << '\n';
                    }
                    catch (const std::exception &e)
                    {
                        std::cout << e.what() << '\n';
                    }

                    break;
                }

                case 5:
                {

                    senderID = Validation::getString("Sender Account ID: ");
                    receiverID = Validation::getString("Receiver Account ID: ");
                    amount = Validation::getDouble("Transfer Amount: ");

                    try
                    {
                        Account *sender = currentUser->findAccount(senderID);

                        if (sender == nullptr)
                        {
                            throw std::runtime_error("Sender account is not yours");
                        }

                        Account *receiver = bank.findAccount(receiverID);

                        if (receiver == nullptr)
                        {
                            throw std::runtime_error("Receiver account not found");
                        }

                        bank.transfer(senderID, receiverID, amount);

                        std::cout << "Transfer completed\n";

                        std::cout << "\nSender Balance   : " << sender->getAccountBalance() << '\n';

                        std::cout << "Receiver Balance : " << receiver->getAccountBalance() << '\n';
                    }
                    catch (const std::exception &e)
                    {
                        std::cout << e.what() << '\n';
                    }

                    break;
                }

                case 6:
                    currentUser->displayAccounts();
                    break;

                case 7:
                    loggedIn = false;
                    std::cout << "Logged out\n";
                    break;

                default:
                    std::cout << "Invalid\n";
                }
            }

            break;
        }

        case 3:
        {
            bank.displayUsers();
            break;
        }

        case 4:
        {
            running = false;
            std::cout << "\n\n";
            break;
        }

        default:
        {
            std::cout << "Invalid\n";
        }
        }
    }
}

int main()
{

    int option;

    Bank bank;

    Menu(bank);

    return 0;
}