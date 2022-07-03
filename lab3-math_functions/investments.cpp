/**
 * @file investments.cpp
 * @author Conner Graham (connergraham888@gmail.com)
 * @brief This program computes the value of an investment, after a certain number of
 * years at a certain interest rate. It calculates this compounded annually and
 * continuously along with the profit for each. It then calculates the difference
 * between both investment types.
 * @version 0.1
 * @date 2016-09-15
 * 
 * @copyright Copyright (c) 2016
 * 
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int     initialInvest;  // Initial investment (dollars)
    int     percent;        // Interest rate per year (percentage)
    int     months;         // Number of months compounded
    double  finalInvestA;   // Value of investment compounded annually (dollars)
    double  profitA;        // Profit from annual compoundment (dollars)
    double  finalInvestC;   // Value of investment compounded continuously (dollars)
    double  profitC;        // Profit from continuous compoundment (dollars)
    double  investDiff;     // Difference in annual vs continuous compoundment (dollars)

    /* Prompt and read in initial investment, interest rate (percent), and number of months */
    cout << "Enter initial investment (dollars): ", cin >> initialInvest;
    cout << "Enter interest rate per year (percentage): ", cin >> percent;
    cout << "Enter number of months: ", cin >> months;
    cout << endl;

    /* Calculate years compounded and yearly interest rate for use in calculations */
    double r    = percent / 100.0;  // Interest rate per year
    double y    = months / 12.0;    // Number of years compounded

    /* Compute and print final value of investment compounded annually and the profit */
    finalInvestA    = initialInvest * pow(1+r, y);
    profitA         = finalInvestA - initialInvest;
    cout << "Value of your investment compounded annually after " << y << " year(s) is " << finalInvestA << " dollars." << endl;
    cout << "Profit from your investment after " << y << " year(s) is " << profitA << " dollars." << endl;
    cout << endl;

    /* Compute and print final value of investment compounded annually and the profit */
    finalInvestC    = initialInvest * exp(r*y);
    profitC         = finalInvestC - initialInvest;
    cout << "Value of your investment compounded continuously after " << y << " year(s) is " << finalInvestC << " dollars." << endl;
    cout << "Profit from your investment after " << y << " year(s) is " << profitC << " dollars." << endl;
    cout << endl;

    /* Compute and print difference in annual vs continuous compoundment */
    investDiff = abs(finalInvestC - finalInvestA);
    cout << "The difference between both investment types is " << investDiff << " dollars." << endl;

    return (0);
}
