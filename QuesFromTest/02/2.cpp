/* Problem Name is &&& Snowpack &&& PLEASE DO NOT REMOVE THIS LINE. */

/*
** Instructions to candidate.
**  1) Given an array of non-negative integers representing the elevations
**     from the vertical cross section of a range of hills, determine how
**     many units of snow could be captured between the hills.
**
**     See the example array and elevation map below.
**                                 ___
**             ___                |   |        ___
**            |   |        ___    |   |___    |   |
**         ___|   |    ___|   |   |   |   |   |   | 5
**     ___|___|___|___|___|___|___|___|___|___|___|___
**     {0,  1,  3,  0,  1,  2,  0,  4,  2,  0,  3,  0}
**                                 ___
**             ___                |   |        ___
**            |   | *   *  _*_  * |   |_*_  * |   |
**         ___|   | *  _*_|   | * |   |   | * |   |
**     ___|___|___|_*_|___|___|_*_|___|___|_*_|___|___
**     {0,  1,  3,  0,  1,  2,  0,  4,  2,  0,  3,  0}
**
**     Solution: In this example 13 units of snow (*) could be captured.
**
**  2) Consider adding some additional tests in doTestsPass().
**  3) Implement computeSnowpack() correctly.
*/

// #include <iostream>
#include<bits/stdc++.h>
using namespace std;

/*
**  Find the amount of snow that could be captured.
*/
int computeSnowpack(int arr[], int arr_size)
{
  // Todo: Implement computeSnowpack
  int lmax[arr_size];
  int LMAX = INT_MIN;
  for(int i=0;i<arr_size; i++){
    LMAX = max(LMAX, arr[i]);
    lmax[i] = LMAX;
  }
  int rmax[arr_size];
  int RMAX = INT_MIN;
  for(int i=arr_size-1; i>=0; i--){
    RMAX = max(RMAX, arr[i]);
    rmax[i] = RMAX;
  }
  long long ans=0;
  for(int i=0;i<arr_size; i++) {
    ans += min(lmax[i], rmax[i]) - arr[i];
  }

  /*
  10 x 20
  0 5 2 or 2 10 3 or similar
  */
  return ans;
}

/*
**  Returns true if the tests pass. Otherwise, returns false;
*/
bool doTestsPass()
{
  bool result = 1;
  int int_size = sizeof(int);

  int a[] = {0,1,3,0,1,2,0,4,2,0,3,0};
  result &= computeSnowpack(a, sizeof(a)/int_size) == 13;
  int b[] = {1,0,0,0,0,0,0,0,0,0,0,1};
  result &= computeSnowpack(b, sizeof(b)/int_size) == 10;
  int c[] = {0,0,0,0,0};
  result &= computeSnowpack(c, sizeof(c)/int_size) == 0;
  int d[] = {0,0,1,0,0};
  result &= computeSnowpack(d, sizeof(d)/int_size) == 0;
  int e[] = {1};
  result &= computeSnowpack(e, sizeof(e)/int_size) == 0;
  int f[] = {};
  result &= computeSnowpack(f, sizeof(f)/int_size) == 0;


  return result;
}

/*
**  Execution entry point.
*/
int main()
{
  // Run the tests
  if(doTestsPass())
  {
  printf("All tests pass");
  }
  else
  {
  printf("Tests failed");
  }

  return 0;
}
