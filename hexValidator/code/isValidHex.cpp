/* Check README file for more details (link below)
https://github.com/OneDollarCat/sloth-bytes/blob/main/hexValidator/README.md
*/
#include "hex.hpp"
#include <vector>
#include <algorithm>
using namespace std;

bool isValidHex(const string& code) {
     if ((code.length() != 7) || (code[0] != '#')) {
          return false;
     }
     else {
         vector<char> validChars = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'A', 'B', 'C', 'D', 'E', 'F'};
         for (int i=1; i<=6; i++) {
              if ((find(validChars.begin(), validChars.end(), code[i])) == validChars.end()) {
                    return false;
               }
          }
          return true;
     }
}