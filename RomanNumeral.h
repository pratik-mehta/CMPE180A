#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_
#include <cstdlib>
#include <iostream>
using namespace std;

class RomanNumeral
{
public:
    RomanNumeral();              //default constructor
    RomanNumeral(int decimal);   //constructor with integer parameter
    RomanNumeral(string roman);  //constructor with string parameter
    ~RomanNumeral();             //deconstructor
    
    int get_decimal() const;  //public getter for decimal value
    string get_roman() const; //public getter for roman numeral
    
    //Overload the arithmetic operators  + - * /
    RomanNumeral operator +(const RomanNumeral& num);
    RomanNumeral operator -(const RomanNumeral& num);
    RomanNumeral operator *(const RomanNumeral& num);
    RomanNumeral operator /(const RomanNumeral& num);

    //Overload the equality operators  == !=
    bool operator ==(const RomanNumeral& num);
    bool operator !=(const RomanNumeral& num);

    //Overload the stream operators  >>  and  <<
    friend istream& operator >>(istream& in, RomanNumeral& num);
    friend ostream& operator <<(ostream& out, const RomanNumeral& num);

private:
   int decimal;   //decimal value as an integer
   string roman;  //roman numeral as a string
   
   void to_decimal();    //convert roman numeral to decimal value
   void to_roman();   //convert decimal value to roman numeral
};

#endif /* ROMANNUMERAL_H_ */
