#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Account;
int numOfAccInDB(const char *);

class Account //simple class data structure for Bank account representaion.
{
    char name[50];
    int phn_num;
    int amount;
    int ac_num;
    int acc_typ;

public:
    Account() {}
    Account(const char *n, int p, int amnt, int t)
    {
        strcpy(name, n);
        phn_num = p;
        amount = amnt;
        acc_typ = t;
        this->ac_num = 654321 + numOfAccInDB("DB.dat"); //giving account number.(654321 so ac_num looks real)
    }

    void createAcc();
    void depositAmount(int a);
    void withdrawAmount(int a);
    void displayAccDetails();
    void dispNameAccNum();
    void closeAccount();
};

int numOfAccInDB(const char *s)
{
    ifstream file(s, ios::binary);
    file.seekg(0, ios::end);
    int file_size = file.tellg();        //returns file size (size in bytes)
    int n = file_size / sizeof(Account); //returns number of Accounts/objects in file.
    file.close();
    return n;
}

void Account::createAcc()
{
    this->ac_num = 654321 + numOfAccInDB("DB.dat"); //giving account number.(654321 so ac_num looks real)

    printf("\t\t\t\t\t=============================================\n");
    printf("\t\t\t\t\t\t     CREATEING NEW ACCOUNT\n");
    printf("\t\t\t\t\t=============================================\n");

    fflush(stdin);
    cout << "\t\t\t\t\tEnter Your name: ";
    gets(this->name);

    cout << "\t\t\t\t\tEnter Your Phone Number: ";
    cin >> this->phn_num;
    cout << "\t\t\t\t\tEnter Your Initial Amount: ";
    cin >> this->amount;
    cout << "\t\t\t\t\tEnter Your Account Type(for saving = 101 and current = 102) : ";
    cin >> this->acc_typ;
}

void Account::displayAccDetails()
{
    printf("\t\t\t\t\t\t      ACCOUNT Details\n");
    printf("\t\t\t\t\t=============================================\n");
    cout << "\t\t\t\t\tName:            " << this->name << endl;
    cout << "\t\t\t\t\tAccount Number:  SBBI-" << this->ac_num << endl;
    cout << "\t\t\t\t\tPhone Number:    " << this->phn_num << endl;

    if (acc_typ == 101)
        cout << "\t\t\t\t\tAccount Type:    saving"
             << "\n\n";
    else
        cout << "\t\t\t\t\tAccount Type:    current"
             << "\n\n";

    cout << "\t\t\t\t\t\tBALANCE:     " << this->amount << " Rs" << endl;
    cout << endl;
}

void Account::dispNameAccNum()
{
    cout << "\t\t\t\t\t" << this->name << "\t     SBIN-" << this->ac_num << "\t" << this->amount << "Rs" << endl;
}

void Account::depositAmount(int a)
{
    this->amount += a;
}

void Account::withdrawAmount(int a)
{
    if (a > this->amount)
    {
        cout << "\t\t\t\t\t\tError: Insufficient Balance\n";
        return;
    }
    this->amount -= a;
}

void Account::closeAccount()
{
    printf("\t\t\t\t\t=============================================\n");
    printf("\t\t\t\t\t\t     CLOSING ACCOUNT\n");
    printf("\t\t\t\t\t=============================================\n");

    cout << "\t\t\t\t\tEnter Your name: " << name << "\n";
    cout << "\t\t\t\t\tEnter Your Phone Number: " << phn_num << "\n";
    cout << "\t\t\t\t\tEnter Your Initial Amount: " << amount << "\n";
    cout << "\t\t\t\t\tEnter Your Account Type(for saving = 101 and current = 102) : " << acc_typ << "\n";

    name[0] = '0';
    ac_num = phn_num = amount = acc_typ = -1;
}
