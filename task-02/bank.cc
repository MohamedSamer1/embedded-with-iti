#include <iostream>
#include <string>

int main()
{
    //    std::string userName = "Mohamed";
    //    std::string password = "password123";

    int choice1 = 0;
    int accountNum = 0;

    std::string userNames[10];
    std::string passwords[10];
    float balances[10] = {};

    std::cout << "=========================\n";
    std::cout << "      BANKING SYSTEM\n";
    std::cout << "=========================\n";
    std::cout << "1. Create Account\n";
    std::cin >> choice1;
    while (choice1 != 1)
    {
        std::cout << "Wrong input\n";
        std::cin >> choice1;
    }
    if (choice1 == 1)
    {
        std::cout << "Enter userName: ";
        std::cin >> userNames[accountNum];
        std::cout << "Enter password: ";
        std::cin >> passwords[accountNum];
        std::cout << "Your userName is: " << userNames[accountNum] << "and you password is '" << passwords[accountNum] << "'\n You ID is " << accountNum;
        ;
        accountNum++;
    }

    else
    {
        std::cout << "wrong input";
    }

    std::cout << "\nLets Login\n";

    std::string user;
    std::string password;
    int id = 0;

    std::cout << "Enter your ID: ";
    std::cin >> id;

    while (id < 0 || id >= accountNum)
    {
        std::cout << "Invalid ID. Enter again: ";
        std::cin >> id;
    }
    std::cout << "Enter your userName: ";
    std::cin >> user;

    std::cout << "Enter your password: ";
    std::cin >> password;

    if (user == userNames[id] && password == passwords[id])
    {
        std::cout << "\nLogin Succesful\n\n";
        int choice2;

        while (true)
        {
            std::cout << "\n=========================\n";
            std::cout << "      BANKING SYSTEM\n";
            std::cout << "      Hello user " << id << "\n";
            std::cout << "=========================\n";
            std::cout << "1. Deposit\n";
            std::cout << "2. Withdraw\n";
            std::cout << "3. Check Balance\n";
            std::cout << "4. Create New Account\n";
            std::cout << "5. Login from another account\n";
            std::cout << "6. Exit\n";
            std::cin >> choice2;

            switch (choice2)
            {
            case 1:
            {
                float deposit;

                std::cout << "Enter amount to deposit: ";
                std::cin >> deposit;

                while (deposit < 0)
                {
                    std::cout << "Invalid amount. Enter again: ";
                    std::cin >> deposit;
                }

                balances[id] += deposit;

                std::cout << "Deposit successful!\n";
                break;
            }

            case 2:
            {
                float withdraw;

                std::cout << "Enter amount to withdraw: ";
                std::cin >> withdraw;

                while (withdraw < 0)
                {
                    std::cout << "Invalid amount. Enter again: ";
                    std::cin >> withdraw;
                }

                if (withdraw > balances[id])
                {
                    std::cout << "Insufficient balance!\n";
                }
                else
                {
                    balances[id] -= withdraw;
                    std::cout << "Withdrawal successful!\n";
                }

                break;
            }

            case 3:
            {
                std::cout << "Current Balance: "
                          << balances[id]
                          << " EGP\n";
                break;
            }

            case 4:
            {
                if (accountNum >= 10)
                {
                    std::cout << "Maximum number of accounts reached!\n";
                    break;
                }

                std::cout << "Enter username: ";
                std::cin >> userNames[accountNum];

                std::cout << "Enter password: ";
                std::cin >> passwords[accountNum];

                balances[accountNum] = 0;

                std::cout << "\nAccount created successfully!\n";
                std::cout << "Your ID is: " << accountNum << '\n';

                accountNum++;

                break;
            }
            case 5:
            {
                std::cout << "\nLogging out...\n";

                std::cout << "Enter your ID: ";
                std::cin >> id;

                while (id < 0 || id >= accountNum)
                {
                    std::cout << "Invalid ID. Enter again: ";
                    std::cin >> id;
                }

                std::cout << "Enter your userName: ";
                std::cin >> user;

                std::cout << "Enter your password: ";
                std::cin >> password;

                if (user == userNames[id] && password == passwords[id])
                {
                    std::cout << "\nLogin Successful!\n";
                }
                else
                {
                    std::cout << "\nWrong username or password.\n";
                }

                break;
            }
            case 6:
                std::cout << "Thank you for using our banking system!\n";
                return 0;

            default:
                std::cout << "Invalid choice!\n";
            }
        }
    }
    else
    {
        std::cout << "password or username or ID is wrong\n";
    }
}