/**
   Computes the average of all nonnegative elements in the given array.
   @param a an array of integers
   @param alen the number of elements in a
   @return the average of all nonnegative elements in a, or 0 if there are none.
*/
double nnavg(int a[], int alen)
{
int count = 0;
int sum = 0;
for(int n=0;n<alen;n++)
{
   if(a[n]>=0)
   {
      count++;
      sum+=a[n];
   }
}
if(count==0)
   return 0.0;
else
{
   double avg = static_cast<double>(sum)/count;
   return avg;
}
}
