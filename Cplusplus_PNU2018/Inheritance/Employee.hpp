//
//  Employee.hpp
//  Cplusplus_PNU2018
//
//  Created by MJMacBook on 29/05/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//

#ifndef Employee_hpp
#define Employee_hpp

#include <string>
using std::string;

namespace SavitchEmployees {
    class Employee{
    private:
        string name;
        string ssn;
        double netPay;
    public:
        Employee();
        Employee(string theName, string theSsn);
        string getName() const;
        string getSsn() const;
        double getNetPay() const;
        void SetName(string newName);
        void SetSsn(string newSsn);
        void SetNetPay(double newNetPay);
        void printCheck() const;
    };
}

#endif /* Employee_hpp */
