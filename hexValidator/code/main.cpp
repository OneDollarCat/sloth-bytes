#include "hex.hpp" // Including my header file with the hex validation function
#include <iostream>
using namespace std;

int main() {
      // My test cases
      cout << boolalpha; // Required to print boolean values as "true" or "false", instead of 1 or 0
      cout << isValidHex("#123ABC") << '\n';     // true
      cout << isValidHex("#123ABG") << '\n';     // false
      cout << isValidHex("#A1B2C3") << '\n';     // true
      cout << isValidHex("123456") << '\n';        // false
      cout << isValidHex("#0F0F0F") << '\n';     // true
      cout << isValidHex("#12") << '\n';              // false
      cout << isValidHex("#abcdef") << '\n';      // true
      cout << isValidHex("#ABCDEG") << '\n';   // false
      cout << isValidHex("#987654") << '\n';     // true
      cout << isValidHex("#ffffff") << '\n';    // true
      cout << isValidHex("##123456") << "\n\n";  // false

      // Your test cases
      cout << isValidHex("#CD5C5C") << '\n'; // true
      cout << isValidHex("#EAECEE") << '\n'; // true
      cout << isValidHex("#eaecee") << '\n'; // true
      cout << isValidHex("#CD5C58C") << '\n'; // false
      cout << isValidHex("#CD5C5Z") << '\n'; // false
      cout << isValidHex("#CD5C&C") << '\n'; // false
      cout << isValidHex("CD5C5C") << '\n'; // false
      return 0;
}
