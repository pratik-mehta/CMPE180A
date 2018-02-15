//IGNORESPACE false
/**
   This program reads in the name of a file from stdin.
   Then it opens the file and reads all lines of the file.
   Each line has the form 

   label abbreviation value

   The label and abbreviation are nonempty strings without spaces. 
   The value is a floating-point number. 

   Print out the label and abbreviation with the smallest and 
   largest value, in a left-justified, field of width 50, 
   followed by the value in a right-justified field of width 10, with
   three digits after the decimal point. 
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
   cout << "Input file:" << endl;
   string input_file;
   cin >> input_file;
   ifstream in(input_file);
   double minValue, maxValue, value = 0.0;
   string strMin, strMax, label, abbrev;
   in>>label>>abbrev>>value;
   strMin = label + " " + abbrev;
   strMax = label + " " + abbrev;
   minValue = value;
   maxValue = value;
   while(!in.eof())
   {
      in>>label>>abbrev>>value;
      if(value<minValue)
      {
         minValue=value;
         strMin = label + " " + abbrev;
      }
      else if(value>maxValue)
      {
         maxValue=value;
         strMax = label + " " + abbrev;
      }
   }
   cout.setf(ios::fixed);
   cout<<setw(50)<<left<<strMin<<setw(12)<<setprecision(2)<<right<<minValue<<endl;
   cout<<setw(50)<<left<<strMax<<setw(12)<<setprecision(2)<<right<<maxValue<<endl;
}
