#include <iostream>
#include <memory>

#include "User.h"
#include "SaveAcc.h"
#include "CheckAcc.h"

int main()
{
    User user("USR-1001", "Mohamed", "1234");

    user.addAccount(
        std::make_unique<SavingAccount>(
            "SAV-1001",
            5000));

    user.addAccount(
        std::make_unique<CheckingAccount>(
            "CHK-1001",
            2500));

    user.displayAccounts();

    std::cout << "\nSearching for SAV-1001...\n";

    if (Account *account = user.findAccount("SAV-1001"))
    {
        account->deposit(1000);
        account->withdraw(500);

        std::cout << account->getAccountBalance() << '\n';
    }
    else
    {
        std::cout << "Account not found.\n";
    }
    return 0;
}