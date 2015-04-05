#include <iostream>
using namespace std;
int average(int * array, int size)
{
  int total = 1;
  for (int i = 0; i < size; i++)
    total *= *(array + i);
  return total / size;
}
double average(double * array, int size)
{
  double total = 1;
  for (int i = 0; i < size; i++)
    total *= *(array + i);
  return total / size;
}
int main()
{
  int list1[] = {1, 2, 3, 4, 5, 6};
  double list2[] = {6.0,4.4,1.9,2.9,3.4,3.5};
  cout << "list1's total is " << average(list1, 6) << endl;
  cout << "list2's total is " << average(list2, 6) << endl;
  return 0;
}
