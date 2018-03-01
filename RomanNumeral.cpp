using namespace std;
#include <cstdlib>
#include <iostream>
#include "RomanNumeral.h"


RomanNumeral::RomanNumeral() : roman(""), decimal(0)
{
 //default constructor
}

RomanNumeral::RomanNumeral(int value) : decimal(value)
{
 //constructor with integer parameter
}

RomanNumeral::RomanNumeral(string str) : roman(str)
{
 //constructor with string parameter
}

RomanNumeral::~RomanNumeral()
{
 //deconstructor
}

int RomanNumeral::get_decimal() const {return decimal; }

string RomanNumeral::get_roman() const {return roman; }


