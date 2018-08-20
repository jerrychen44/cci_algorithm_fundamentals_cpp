#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define ASCII_7BIT_NUM 128
#define ASCII_8BIT_EXTEND_NUM 256



//solution 1
//idea: sorting two string, they should be the same.

bool arePermutation(string str1,string str2)
{
    // Get lengths of both strings
    int n1 = str1.length();
    int n2 = str2.length();

    //first checking
    // If length of both strings is not same, then they
    // cannot be anagram
    if (n1 != n2)
      return false;


    // Sort both strings

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // Compare sorted strings
    for (int i = 0; i < n1;  i++)
       if (str1[i] != str2[i])
         return false;

    return true;
}

//solution 2
//check if the two strings have identical character counts.
//
bool arePermutation_count(const string &str1, const string &str2) {


  //quick checking
  if(str1.length() != str2.length())
    return false;

  //count the appeared time of char
  int count[ASCII_8BIT_EXTEND_NUM]={0};
  for(int i = 0; i < str1.length(); i++) {
    int val = str1[i];
    count[val]++;
    //cout << count[val] << endl;
  }
  cout << endl;
  //reverse count to check the str2
  for(int i = 0; i < str2.length(); i++) {
    int val = str2[i];
    count[val]--;
    //cout << count[val] << endl;

    if(count[val]<0)
      return false;
  }
  return true;
}


int main(){

  string str1 = "test";
  string str2 = "estt";

  cout << "result: " << arePermutation(str1,str2) << endl;

  str1 = "test";
  str2 = "ttas";
  cout << "result: " << arePermutation(str1,str2) << endl;


  //solution2

  str1 = "test";
  str2 = "estt";
  cout << "result: " << arePermutation_count(str1,str2) << endl;
  cout << endl;

  str1 = "test";
  str2 = "ttas";
  cout << "result: " << arePermutation_count(str1,str2) << endl;







  return 0;
}