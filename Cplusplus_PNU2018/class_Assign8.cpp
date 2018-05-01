//
//  class_Assign8.cpp
//  Cplusplus_PNU2018
//
//  Created by MJMacBook on 25/04/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//
#include <iostream>
using namespace std;

class Euro;
class USD {
    int   dollars;
    float cents; // 0.0<=cent<100
    
public:
    friend USD operator+(const USD&, const USD&);
    friend USD operator-(const USD&, const USD&);
    friend ostream& operator<<(ostream&, const USD&);
    USD& operator=(const Euro&);
    USD(const USD &);
    USD();
    USD(int, float);
    
    int getDollars() const{
        return dollars;
    }
    float getCents() const{
        return cents;
    }
    friend class Euro;
};

class Euro {
    int   euros;
    float cents; // 0.0<=cent<100
    
public:
    friend Euro operator+(const Euro&, const Euro&);
    friend Euro operator-(const Euro&, const Euro&);
    friend ostream& operator<<(ostream&, const Euro&);
    Euro& operator=(const USD&);
    Euro(const Euro &);
    Euro(USD);
    Euro();
    Euro(int, float);
    
    int getEuros() const{
        return euros;
    }
    float getCents() const{
        return cents;
    }
    friend class USD;
};



/* main함수 */
int main(){
    Euro  myMoneyEuro;
    USD   myMoneyUSD;
    myMoneyUSD = Euro(10,20.0) + USD(20,20.0);
    myMoneyEuro = USD(100,30.0) + Euro(300,20.0);
    cout << myMoneyUSD;
    cout << myMoneyEuro;
    USD myMoneyUSDM;
    Euro myMoneyEuroM;
    myMoneyUSDM = Euro(10, 20.0) - USD(5, 10.0);
    myMoneyEuroM = USD(5, 10.0) - Euro(200, 0); // myMoneyEuro will be 0.
    cout << myMoneyUSDM;
    cout << myMoneyEuroM;
}

/* 복사 생성자*/
USD::USD(const USD &a){
    dollars = a.dollars;
    cents = a.cents;
}
Euro::Euro(const Euro &a){
    euros = a.euros;
    cents = a.cents;
}

/*  생성자 (인자가 다를 때) */
Euro :: Euro(USD a){
    cout << "USD to Euro" << endl;
    float money = a.getDollars() * 0.81;
    euros = (int)money;
    cents = a.getCents() * 0.81 + money - a.getDollars();
    if(cents >= 100){
        euros = euros + 1;
        cents = cents - 100;
    }
}

/* 생성자 */
USD::USD()
:dollars(0), cents(0){}
USD::USD(int _dollars, float _cents)
:dollars(_dollars), cents(_cents){}
Euro::Euro()
:euros(0), cents(0){}
Euro::Euro(int _euros, float _cents)
:euros(_euros), cents(_cents){}

/* << 정의 */
ostream& operator<<(ostream& os, const USD& a)
{
    cout <<"Dollars:" << a.dollars << ", Cents:" <<a.cents;
    os << endl;
    return os;
}

ostream& operator<<(ostream& os, const Euro& a)
{
    cout <<"Euros:" << a.euros << ", Cents:" <<a.cents;
    os << endl;
    
    return os;
}

Euro operator+(const Euro& a, const Euro& b) {
    cout << "Euro operator+" << endl;
    Euro temp;
    temp.euros = a.euros + b.euros;
    temp.cents = a.cents + b.cents;
    if(temp.cents >= 100){
        temp.cents = temp.cents - 100;
        temp.euros = temp.euros + 1;
    }
    // complete here. See lecture slides
    return temp;
}
// myMoneyUSD = Euro(10, 20.0) - USD(5, 10.0);
Euro operator-(const Euro& a, const Euro& b){
    cout << "Euro operator-" << endl;
    Euro temp;
    temp.euros = a.euros - b.euros;
    if (temp.euros < 0) {
        temp.euros = 0;
        temp.cents = 0;
        return temp;
    }
    temp.cents = a.cents - b.cents;
    if(temp.cents >= 100){
        temp.cents = temp.cents - 100;
        temp.euros = temp.euros + 1;
    }
    if( temp.cents < 0 && temp.euros > 0){
        temp.euros = temp.euros - 1;
        temp.cents = temp.cents + 100;
    }
    // complete here. See lecture slides
    return temp;
}

USD operator+(const USD& a, const USD& b) {
    cout << "USD operator+" << endl;
    USD temp;
    temp.dollars = a.dollars + b.dollars;
    temp.cents = a.cents + b.cents;
    if(temp.cents >= 100){
        temp.cents = temp.cents - 100;
        temp.dollars = temp.dollars + 1;
    }
    // complete here. See lecture slides
    return temp;
}

USD operator-(const USD& a, const USD& b) {
    cout << "USD operator-" << endl;
    USD temp;
    temp.dollars = a.dollars - b.dollars;
    if (temp.dollars < 0) {
        temp.dollars = 0;
        temp.cents = 0;
        return temp;
    }
    temp.cents = a.cents - b.cents;
    if(temp.cents >= 100){
        temp.cents = temp.cents - 100;
        temp.dollars = temp.dollars + 1;
    }
    if( temp.cents < 0 && temp.dollars > 0){
        temp.dollars = temp.dollars - 1;
        temp.cents = temp.cents + 100;
    }
    // complete here. See lecture slides
    return temp;
}

Euro& Euro::operator=(const USD& pUSD){
    cout << "operator Euro = USD" << endl;
    float money = (pUSD.getDollars()) * (float)81.0 / (float)100.0;
    this->euros = (int)money;
    this->cents = pUSD.getCents() * (float)81.0 / (float)100.0 + (money - this->cents) * 100;
    while (this->cents >= 100.0){
        this->cents -= 100.0;
        this->euros += 1;
    }
    return *this;
}

USD& USD::operator=(const Euro& pEuro){
    cout << "operator USD = Euro" << endl;
    float money = (pEuro.getEuros()) * (float)100.0 / (float)81.0;
    this->dollars = (int)money ;
    this->cents = pEuro.getCents() * (float)100.0 / (float)81.0 + (money - this->dollars) * 100;
    while (this->cents >= 100.0){
        this->cents -= 100.0;
        this->dollars += 1;
    }
    return *this;
}
