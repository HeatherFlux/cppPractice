/*
Implement an algorithm to determine if a string has all unique characters
What if you can not use additional data structures?
*/
#include <array>

using namespace std;

// Function to find out if it is unique or not
bool isUniqueChar(string s){
  array<bool, 256> inIt; // assuming ASCII is being used 256 sized array

  // Traverse the string and convert each letter to a char.
  for (int i = 0;i<s.length();i++){
    int numStr = s[i];

    //These are for error checking
    cout << s[i];
    cout << " : ";
    cout << numStr;
    cout << " : ";
    cout << inIt[numStr];

    // Checks if the index is true or false if true there was a duplicate.
    if (inIt[numStr] == true) {
      cout << " : ";
      cout << inIt[numStr];
      cout << "\nfalse";
      return false;
      break;
    }

    // If it isn't in the array yet, put true in its slot.
    inIt[numStr] = true;
    cout << " : ";
    cout << inIt[numStr];
    cout << "\n";
  }
  cout << "true";
  return true;
}

// Testing
int main()
{
    string s = "helol";
    isUniqueChar(s);
    return 0;
}
