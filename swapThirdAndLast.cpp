#include <vector>
using namespace std;

/**
   Swaps the third and last value of a.
   For example, if a is {3, 1, 4, 1, 5, 9, 2, 6}
   after calling this method it is {3, 1, 6, 1, 5, 9, 1, 4}.
   If the array has length < 3, do nothing.
   @param a a vector of integers      
*/
void swap3last(vector<int>& a)
{
   if (a.size()<3)
      return;
   else
   {
      int temp = a[2];
      a[2]=a[a.size()-1];
      a[a.size()-1]=temp;
      return;
   }
} 
