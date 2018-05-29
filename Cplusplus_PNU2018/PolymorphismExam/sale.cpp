//
//  sale.cpp
//  Cplusplus_PNU2018
//
//  Created by MJMacBook on 29/05/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//  from ABSOLUTE C++

#include <iostream>
#include "sale.h"
using std::cout;

namespace SavitchSale {
    
    Sale::Sale() : price(0){}
    Sale::Sale(double thePrice)
    {
        if (thePrice >= 0 ) {
            price = thePrice;
        }
        else
        {
            cout << "Error: Cannot have a negative price!\n";
            exit(1);
        }
    }
    
    double Sale::bill() const
    {
        return price;
    }
    
    double Sale::getPrice() const
    {
        return price;
    }
    
    void Sale::SetPrice(double newPrice)
    {
        if (newPrice >= 0 ) {
            price = newPrice;
        }
        else {
            cout << "Error: Cannot have a negative price!\n";
            exit(1);
        }
    }
    
    double Sale::savings(const Sale& other) const
    {
        return (bill() - other.bill());
    }
    
    bool operator < (const Sale& first, const Sale& second)
    {
        return (first.bill() < second.bill());
    }
}
