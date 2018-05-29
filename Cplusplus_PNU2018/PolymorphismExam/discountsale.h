//
//  discountsale.hpp
//  Cplusplus_PNU2018
//
//  Created by MJMacBook on 29/05/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//

#ifndef discountsale_hpp
#define discountsale_hpp
#include "sale.h"

namespace SavitchSale {
    class DiscountSale : public Sale
    {
    private:
        double discount;
    public:
        DiscountSale();
        DiscountSale(double thePrice, double theDiscount);
        double getDiscount() const;
        void setDiscount(double newDiscount);
        double bill() const;
    };
}
#endif /* discountsale_hpp */
