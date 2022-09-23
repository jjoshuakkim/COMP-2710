/* FILE NAME: project1_Kim_jjk0027
 * AUTHOR: Joshua Kim
 * I used stackOverflow to figure out how to
 * differentiate between string and double.
 */
#include <iostream>
#include <limits> 
using namespace std;

int main()
{
    cout.setf(ios  ::fixed); 
    cout.setf(ios  ::showpoint); 
    cout.precision(2); 

    double loan, monthlyPay, interestRate, interestRateDec, interest, principal, interestPaid;
    loan = 0;
    monthlyPay = 0;
    interestRate = -1;
    
    while (loan <= 0)
    {
        cout << "\nLoan amount: ";
        cin >> loan;

        if (!cin)
        {
            cout << "\nInvalid loan";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
        if (loan < 0)
        {
            cout << "\nInvalid loan";
        }
    }

    while (interestRate < 0)
    {
        cout << "\nInterest rate (% per year): ";
        cin >> interestRate;

        if (!cin)
        {
            cout << "\nInvalid interest rate";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            interestRate = -1;
        }

        else if (interestRate < 0)
        {
            cout << "\nInvalid interest rate";
        }
    }

    interestRate /= 12;
    interestRateDec = interestRate / 100;

    while (monthlyPay <= 0)
    {
        cout << "\nMonthly payments: ";
        cin >> monthlyPay;

        if (!cin)
        {
            cout << "\nInvalid monthly pay";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
        if (monthlyPay < 0)
        {
            cout << "\nInvalid monthlyPay";
        }
    }

    int month = 0;
    cout << "\n*****************************************************************\n"  
         << "\tAmortization Table\n" 
         << "*****************************************************************\n"  
         << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n"
         << month << "\t$" << loan << "\tN/A\tN/A\tN/A\t\tN/A\n";
    
    while (loan > 0)
    {
        interest = loan * interestRateDec;
        principal = monthlyPay - interest;
        loan = loan - principal;
        month++;

        if (interest > monthlyPay || monthlyPay - interest == 0)
        {
            cout << "\nInsufficient payment";
            break;
        }

        if (loan < 0)
        {
            monthlyPay = monthlyPay + loan;
            principal += loan;
            loan = 0;
        }
        interestPaid += interest;

        cout << month << "\t$" << loan << "   \t$" << monthlyPay << "\t" 
             << interestRate << "\t$" << interest << "\t\t$" << principal << "\n";
    }

    if (interest > monthlyPay || monthlyPay - interest == 0)
    {
        cout << endl;
    }
    
    else
    {
        cout << "*****************************************************************\n"
             << "It takes " << month << " months to pay off the loan.\n"
             << "Total interest paid: $" << interestPaid << "\n";
    }

    return 0;

}
