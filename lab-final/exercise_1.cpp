// Zybooks 22.10 LAB*: Program: Income tax form -- functions
// Modified by: Ali Mortada

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Calculate AGI and repair any negative values
int CalcAGI(int wages, int interest, int unemployment) {
    return abs(wages) + abs(interest) + abs(unemployment);
}

// Calculate deduction depending on single, dependent or married
int GetDeduction(int status) {
    if (status == 1) {
        return 12000;   
    } else if (status == 2) {
        return 24000;   
    } else {
        return 6000;  
    }
}

// Calculate taxable but not allow negative results
int CalcTaxable(int agi, int deduction) {
    int taxable = agi - deduction;
    if (taxable < 0) {
        return 0;
    }
    return taxable;
}

// Calculate tax for single or dependent
int CalcTax(int status, int taxable) {
    double tax = 0.0;
    if (status == 2) {                     // Case for married filers first
        if (taxable >= 0 && taxable <= 20000) {
            tax = taxable * .10;   
        } else if (taxable >= 20001 && taxable <= 80000) {
            tax = 2000 + ((taxable - 20000) * .12);
        } else if (taxable >= 80001 && taxable <= 160000) {
            tax = 9200 + ((taxable - 80000) * .22); 
        } else {
            tax = 26800 + ((taxable - 160000) * .27);
        }
    } else {                               // Case for dependent/single filers second
        if (taxable >= 0 && taxable <= 10000) {
            tax = taxable * .10;   
        } else if (taxable >= 10001 && taxable <= 40000) {
            tax = 1000 + ((taxable - 10000) * .12);
        } else if (taxable >= 40001 && taxable <= 85000) {
            tax = 4600 + ((taxable - 40000) * .22); 
        } else if (taxable >= 85001 && taxable <= 150000) {
            tax = 14500 + ((taxable - 85000) * .24);
        } else {
            tax = 30100 + ((taxable - 150000) * .30);
        }
    }

    tax = round(tax);

    return static_cast<int>(tax);
}

// Calculate tax due and check for negative withheld
int CalcTaxDue(int tax, int withheld) {
    if (withheld < 0)
    withheld = 0;

    return tax - withheld;
}

int main() {
    int wages, interest, unemployment, status, withheld;
    int tax, agi, due, deduction, taxable;

    // Step #1: Input information
    cin >> wages >> interest >> unemployment >> status >> withheld;

    // Step #2: Calculate AGI
    agi = CalcAGI(wages, interest, unemployment);
    cout << "AGI: $" << agi << endl;

    // Step #3: Get deduction AGI
    deduction = GetDeduction(status);
    cout << "Deduction: $" << deduction << endl;

    // Step #4: Calculate taxable income
    taxable = CalcTaxable(agi, deduction);
    cout << "Taxable income: $" << taxable << endl;

    // Step #5: Calculate federal tax
    tax = CalcTax(status, taxable);
    cout << "Federal tax: $" << tax << endl;

    // Step #6: Calculate tax due
    due = CalcTaxDue(tax, withheld);
    cout << "Tax due: $" << due << endl;


    return 0;
}
