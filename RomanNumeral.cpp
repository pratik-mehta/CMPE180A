using namespace std;
#include <cstdlib>
#include <iostream>
#include "RomanNumeral.h"


RomanNumeral::RomanNumeral() : roman(""), decimal(0)
{
 //default constructor
}

RomanNumeral::RomanNumeral(int value) : decimal(value)   //constructor with integer parameter
{
   to_roman();    //compute equivalent roman numeral
}

RomanNumeral::RomanNumeral(string str) : roman(str)   //constructor with string parameter
{
   to_decimal();  //compute equivalent decimal value
}

RomanNumeral::~RomanNumeral()
{
 //deconstructor
}

int RomanNumeral::get_decimal() const {return decimal; }

string RomanNumeral::get_roman() const {return roman; }

RomanNumeral RomanNumeral::operator +(const RomanNumeral& num)
{
   int sum = decimal+num.decimal;
   RomanNumeral sumNum(sum);
   return sumNum;
}

RomanNumeral RomanNumeral::operator -(const RomanNumeral& num)
{
   int difference = decimal-num.decimal;
   RomanNumeral differenceNum(difference);
   return differenceNum;
}

RomanNumeral RomanNumeral::operator *(const RomanNumeral& num)
{
   int product = decimal*num.decimal;
   RomanNumeral productNum(product);
   return productNum;
}

RomanNumeral RomanNumeral::operator /(const RomanNumeral& num)
{
   int quotient = decimal/num.decimal;
   RomanNumeral quotientNum(quotient);
   return quotientNum;
}

bool RomanNumeral::operator ==(const RomanNumeral& num)
{
   return decimal==num.decimal;
}
    
bool RomanNumeral::operator !=(const RomanNumeral& num)
{
   return decimal!=num.decimal;
}

istream& operator >>(istream& in, RomanNumeral& num)
{
   string str;
   in>>str;
   num.roman=str;
   num.to_decimal();
   return in;
}

ostream& operator <<(ostream& out, const RomanNumeral& num)
{
   out << "[" << num.decimal << ":" << num.roman << "]";
   return out;
}

void RomanNumeral::to_decimal() 
{
  int numLength = roman.length();
  decimal = 0;

  for (int i = 0; i < numLength; i++) {
    switch (roman[i]) {
    case 'M':
      decimal += 1000;
      break;

    case 'D':
      decimal += 500;
      break;
    case 'C':
      if (i + 1 < numLength) {
        switch (roman[i + 1]) {
        case 'D': // CD
          decimal += 400;
          i++;
          break;

        case 'M': // CM
          decimal += 900;
          i++;
          break;

        default:
          decimal += 100;
          break;
        }
      } else decimal += 100;
      break;
    case 'L':
      decimal += 50;
      break;

    case 'X':
      if (i + 1 < numLength) {
        switch (roman[i + 1]) {
        case 'L': // XL
          decimal += 40;
          i++;
          break;
        case 'C': // XC
          decimal += 90;
          i++;
          break;

        default:
          decimal += 10;
          break;
        }
      } else decimal += 10;
      break;
    case 'V':
      decimal += 5;
      break;

    case 'I':
      if (i + 1 < numLength) {
        switch (roman[i + 1]) {
        case 'V': // IV
          decimal += 4;
          i++;
          break;
        case 'X': // IX
          decimal += 9;
          i++;
          break;

        default:
          decimal++;
          break;
        }
      } else decimal++;
      break;
    }
  }
}

void RomanNumeral::to_roman() {
  int num = decimal;
  roman = "";

  while (num >= 1000) {
    roman += "M";
    num -= 1000;
  }

  if (num >= 900) {
    roman += "CM";
    num -= 900;
  } else if (num >= 500) {
    roman += "D";
    num -= 500;
  } else if (num >= 400) {
    roman += "CD";
    num -= 400;
  }

  while (num >= 100) {
    roman += "C";
    num -= 100;
  }
  if (num >= 90) {
    roman += "XC";
    num -= 90;
  } else if (num >= 50) {
    roman += "L";
    num -= 50;
  } else if (num >= 40) {
    roman += "XL";
    num -= 40;
  }

  while (num >= 10) {
    roman += "X";
    num -= 10;
  }
  if (num >= 9) {
    roman += "IX";
    num -= 9;
  } else if (num >= 5) {
    roman += "V";
    num -= 5;
  } else if (num >= 4) {
    roman += "IV";
    num -= 4;
  }

  while (num >= 1) {
    roman += "I";
    num--;
  }
}
