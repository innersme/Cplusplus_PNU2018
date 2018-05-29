//
//  discountsale.cpp
//  Cplusplus_PNU2018
//
//  Created by MJMacBook on 29/05/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//

#include "discountsale.h"

namespace SavitchSale {
    DiscountSale::DiscountSale() : Sale(), discount(0){ }
    
    DiscountSale::DiscountSale(double thePrice, double theDiscount)
    : Sale(thePrice), discount(theDiscount) { }
    
    double DiscountSale::getDiscount() const
    {
        return discount;
    }
    
    void DiscountSale::setDiscount(double newDiscount)
    {
        discount = newDiscount;
    }
    
    double DiscountSale::bill() const
    {
        double fraction = discount / 100;
        return (1 - fraction) * getPrice();
    }
}
