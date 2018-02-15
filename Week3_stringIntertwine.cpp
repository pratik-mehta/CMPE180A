#include <string>
using namespace std;


/**
   Return a string that mixes the characters in the string a 
   with the characters in b reversed. For example,
   intertwine("Fred", "Mary") yields "FyrreadM".

   If one string is longer than the other, append the unused
   characters (in reverse order if the second string is longer).
   intertwine("Sue", "Peggy") yields "SyugegeP".
*/
string intertwine(string a, string b)
{
   string intertwine;
   int minLength = 0;
   if(a.length()<=b.length())
      minLength = a.length();
   else
      minLength = b.length();
   for(int i=0;i<minLength;i++)
   {
      intertwine = intertwine + a.at(i);
      intertwine = intertwine + b.at(b.length()-1-i);
   }
   if(a.length()>b.length())
      intertwine = intertwine + a.substr(minLength,a.length()-minLength);
   else
   {
      for(int i=b.length()-minLength-1;i>=0;i--)
      {
         intertwine = intertwine + b.at(i);
      }
   }
   return intertwine;
}
