//
//  sale.hpp
//  Cplusplus_PNU2018
//
//  Created by MJMacBook on 29/05/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//

#ifndef sale_hpp
#define sale_hpp
namespace SavitchSale {
    
    class Sale
    {
    private:
        double price;
    public:
        Sale();
        Sale(double thePrice);
        double getPrice() const;
        void SetPrice(double newPrice);
        virtual double bill() const;
        double savings(const Sale& other) const;
    };
    
    bool operator < (const Sale& first, const Sale& second);
}
#endif /* sale_hpp */
