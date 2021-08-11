#include <iostream>
#include "account_record.h"
#include <fstream>
#include <string.h>
using namespace std;

int main()
{
    system("cls");

    while (true)
    { // display options of Program ==============================================>
        printf("\t\t\t\t\t\t=================================\n");
        printf("\t\t\t\t\t\t      BANK MANAGEMENT SYSTEM\n");
        printf("\t\t\t\t\t\t=================================\n");
        printf("\t\t\t\t\t\t          ::MAIN MENU::\n");
        printf("\n");
        printf("\t\t\t\t\t\t1. New Account\n");
        printf("\t\t\t\t\t\t2. Deposit Amount\n");
        printf("\t\t\t\t\t\t3. Withdraw Amount\n");
        printf("\t\t\t\t\t\t4. Balance Enquiry\n");
        printf("\t\t\t\t\t\t5. All Acount Holders List\n");
        printf("\t\t\t\t\t\t6. Clear output console\n");
        printf("\t\t\t\t\t\t7. EXIT\n");
        printf("\n");
        printf("\t\t\t\t\t\tSelect Your Option (1 - 7): ");

        //Driver code from here:===================================================>
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            ofstream file("DB.dat", ios::binary | ios::out | ios::app);
            Account tmp;
            tmp.createAcc();
            file.seekp(0, ios::end);
            file.write((char *)&tmp, sizeof(tmp));
            file.close();
            cout << "\t\t\t\t\t||||| ACCOUNT CREATED ||||\n\n";
            printf("\n\t\t\t\t----------------------------------------------------------------------\n");
        }
        else if (choice == 2)
        {
            printf("\n\t\t\t\t----------------------------------------------------------------------\n");
            printf("\t\t\t\t\t\t     DEPOSINTING MONEY IN ACCOUNT\n");
            printf("\t\t\t\t----------------------------------------------------------------------\n");
            int k;
            cout << "\t\t\t\tEnter Account Number: ";
            cin >> k;
            k -= 654321;
            if (k >= 0 && k <= numOfAccInDB("DB.dat"))
            {
                Account tmp;
                //------------------------READING FROM HERE
                ifstream infile("DB.dat", ios::binary);
                infile.seekg(k * sizeof(Account), ios::beg);
                infile.read((char *)&tmp, sizeof(Account));
                tmp.displayAccDetails();
                int a;
                cout << "\t\t\t\tEnter amount To Be Deposited: ";
                cin >> a;
                tmp.depositAmount(a);
                infile.close();

                //------------------------WRITING FROM HERE !!!!!!!!!!!!Error ocuuring from here
                ofstream outfile("DB.dat", ios::binary);
                outfile.seekp(k * sizeof(Account), ios::beg);
                outfile.write((char *)&tmp, sizeof(Account));
                outfile.close();
                cout << "\t\t\t\tMONEY DEPOSITED IN ACCOUNT.\n";
            }
            else
                cout << "No such Account exist.\n";
            printf("\n\t\t\t\t----------------------------------------------------------------------\n");
        }
        else if (choice == 3)
        {
            printf("\n\t\t\t\t----------------------------------------------------------------------\n");
            printf("\t\t\t\t\t\t     WITHDRAWING MONEY FROM ACCOUNT\n");
            printf("\t\t\t\t----------------------------------------------------------------------\n");
            int k;
            cout << "\t\t\t\tEnter Account Number: ";
            cin >> k;
            k -= 654321;
            if (k >= 0 && k <= numOfAccInDB("DB.dat"))
            {
                Account tmp;
                //------------------------READING FROM HERE
                ifstream infile("DB.dat", ios::binary);
                infile.seekg(k * sizeof(Account), ios::beg);
                infile.read((char *)&tmp, sizeof(Account));
                tmp.displayAccDetails();
                int a;
                cout << "\t\t\t\tEnter amount To Be Withdrawn: ";
                cin >> a;
                tmp.withdrawAmount(a);
                infile.close();

                //------------------------WRITING FROM HERE !!!!!!!!!!!!Error ocuuring from here
                ofstream outfile("DB.dat", ios::binary);
                outfile.seekp(k * sizeof(Account), ios::beg);
                outfile.write((char *)&tmp, sizeof(Account));
                outfile.close();
                cout << "\t\t\t\tMONEY WITHDRAWN FROM ACCOUNT.\n";
            }
            else
                cout << "No such Account exist.\n";
            printf("\n\t\t\t\t----------------------------------------------------------------------\n");
        }
        else if (choice == 4)
        {
            int m;
            cout << "\t\t\t\tEnter Account Number: ";
            cin >> m;
            m = m - 654321;
            if (m >= 0 && m <= numOfAccInDB("DB.dat"))
            {
                ifstream file("DB.dat", ios::binary);
                Account tmp;
                file.seekg(m * sizeof(Account), ios::beg);
                file.read((char *)&tmp, sizeof(tmp));
                printf("\n\t\t\t\t----------------------------------------------------------------------\n");
                tmp.displayAccDetails();
                printf("\n\t\t\t\t----------------------------------------------------------------------\n");
                file.close();
            }
            else
                cout << "No such Account exist.\n";
        }
        else if (choice == 5)
        {
            ifstream file("DB.dat", ios::binary);
            Account tmp;
            file.seekg(0, ios::beg);
            printf("\n\t\t\t\t----------------------------------------------------------------------\n");
            printf("\t\t\t\t\tName                 Account Number     Balnace\n");
            while (file.read((char *)&tmp, sizeof(tmp)))
            {
                tmp.dispNameAccNum();
            }
            printf("\n\t\t\t\t----------------------------------------------------------------------\n");
            file.close();
        }
        else if (choice == 6)
            system("cls");
        else if (choice == 7)
            exit(1);
        else
        {
            printf("\n\t\t\t\t\t\t!Error Occured: choose from options (1 - 8).\n\n");
        }
    }

    return 0;
}
