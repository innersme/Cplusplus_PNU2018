//
//  main.cpp
//  Cplusplus_PNU2018
//
//  Created by MJMacBook on 29/05/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//

#include <iostream>
#include "sale.h"
#include "discountsale.h"
using std::cout;
using std::endl;
using std::ios;
using namespace SavitchSale;

int main()
{
    Sale simple(10.00);
    DiscountSale discount(11.00, 10);
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    if (discount < simple) {
        <#statements#>
    }
    return 0;
}
