#include <ctime>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

enum class AmountType
{
    DEPOSIT,
    WITHDRAWAL,

};

class Transaction
{
public:
    string transactionId = "";
    int amount;
    AmountType amountType;
    time_t timestamp;

    Transaction(string id, int amount, AmountType amountType, time_t timestamp)
    {
        this->transactionId = id;
        this->amount = amount;
        this->amountType = amountType;
        this->timestamp = timestamp;
    }
};

class DigitalWallet
{
public:
    string walletId;
    string ownerName;
    int balance;
    vector<Transaction> transactionHistory;

    DigitalWallet(string namee)
    {
        ownerName = namee;
        balance = 0;
    }
    int deposit(int amount)
    {
        balance += amount;
        time_t timestamp = time(nullptr);
        Transaction t1("101", amount, AmountType::DEPOSIT, timestamp);
        transactionHistory.push_back(t1);
        return balance;
    }
    bool withDrawalAmount(int amount)
    {
        if (amount < 0 || balance < amount)
        {
            cout << "Invalid Amount Entered" << endl;
            return false;
        }
        balance -= amount; // updated balance
        time_t timestamp = time(nullptr);
        Transaction t2("101", amount, AmountType::WITHDRAWAL, timestamp);
        transactionHistory.push_back(t2);
        return true;
    }
    vector<Transaction> getTransactionHistory()
    {
        cout << "Giving Transaction History " << endl;
        return transactionHistory;
    }
    int getCurrentBalance()
    {
        cout << "Balance: " << balance << endl;
        return balance;
    }
};

int main()
{
    DigitalWallet w1("Ahmed");
    DigitalWallet w2("Ahmed");

    w1.deposit(11000);
    w1.deposit(2000);
    w1.deposit(7000);

    DigitalWallet &w3 = w1;

    cout << "Done " << endl;
    w3.withDrawalAmount(5000);
    w3.withDrawalAmount(2000);
    w1.getCurrentBalance();
}