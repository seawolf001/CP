/* Problem Name is &&& First NonRepeating &&& PLEASE DO NOT REMOVE THIS LINE. */

// #include<iostream>
#include<bits/stdc++.h>

using namespace std;

/**
* Instructions to candidate.
*  1) Run this code in the REPL to observe its behaviour. The
*     execution entry point is main().
*  2) Consider adding some additional tests in doTestsPass().
*  3) Implement findFirst() correctly.
*  4) If time permits, some possible follow-ups.
*/

/**
* char findFirst(const char* input )
* Finds the first character that does not repeat anywhere in the input string
* If all characters are repeated, return 0
* Given "apple", the answer is "a"
* Given "racecars", the answer is "e"
* Given "ababdc", the answer is "d"
*/
char findFirst(const string input)
{
  // TODO: implement the solution here
  if(input=="") return '\0';
  map<char, int> freq;
  freq.clear();
  for(int i=0;i<input.size(); i++){
    freq[input[i]]++;
  }
  map<char, int>::iterator it;
  for(int i=0;i<input.size(); i++) {
    if(freq[input[i]]==1) {
      return input[i];
    }
  }
  return 0;
}

/**
 * bool doTestsPass()
 * Returns true if all tests pass. Otherwise returns false.
 */
bool doTestsPass()
{
  // todo: implement more tests, please
  // feel free to make testing more elegant
  bool result = true;
  result &= findFirst("apple") == 'a';
  result &= findFirst("racecars") == 'e';
  result &= findFirst("ababdc") == 'd';
  result &= findFirst("ababdc") == 'd';
  result &= findFirst("xxyyzz") == 0;

  return result;
}

/**
* Execution entry point.
*/
int main()
{
  if(doTestsPass())
  {
    cout << "All tests pass" << endl;
  }
  else
  {
    cout << "There are test failures" << endl;
  }

  return 0;
}
