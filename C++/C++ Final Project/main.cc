#include <iostream>
#include <string>
#include <memory>
#include "SaveAcc.h"
#include "CheckAcc.h"

int main()
{
    std::unique_ptr<Account> acc1 =
        std::make_unique<SavingAccount>("SAV-10001", "Mohamed", 5000);

    std::unique_ptr<Account> acc2 =
        std::make_unique<CheckingAccount>("CHK-10001", "Ali", 3000);

    acc1->deposit(1000);
    acc1->withdraw(500);

    std::cout << acc1->getAccountName() << '\n';
    std::cout << acc1->getAccountBalance() << '\n';
    std::cout << acc1->getAccountType() << '\n';

    return 0;
}