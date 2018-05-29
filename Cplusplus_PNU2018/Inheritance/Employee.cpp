//
//  Employee.cpp
//  Cplusplus_PNU2018
//
//  Created by MJMacBook on 29/05/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//

#include <string>
#include <cstdlib>
#include <iostream>
#include "Employee.hpp"
using std::string;
using std::cout;

namespace SavitchEmployees {
    Employee::Employee()
    : name("No name yet"), ssn("No number yet"), netPay(0) { }
    Employee::Employee(string theName, string theNumber)
    : name(theName), ssn(theNumber), netPay(0) { }
    
    string Employee::getName() const
    {
        return name;
    }
    
    string Employee::getSsn() const
    {
        return ssn;
    }
    
    double Employee::getNetPay() const
    {
        return netPay;
    }
    
    void Employee::SetName(string newName)
    {
        name = newName;
    }
    
    void Employee::SetSsn(string newSsn)
    {
        ssn = newSsn;
    }
    
    void Employee::SetNetPay(double newNetPay)
    {
        netPay = newNetPay;
    }
    
    void Employee::printCheck() const
    {
        
    }
}
