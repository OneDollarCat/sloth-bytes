# #️⃣ Valid Hex Code
## ❓ Problem Statement*
### About a hex code
A **hex color code** is a *6-character string* prefixed with a **hashtag #**, that *represents a color* using the **RGB (Red, Green, Blue) color model**.
### Properties of a hex code
- A hex code *must* begin with a **pound key `#`** and is *exactly* **6 characters long**.
- Each character must be a **digit from *0 - 9*** or an **alphabetic character from *A - F***.
- All *alphabetic characters* may be **uppercase** or **lowercase**.
### Task
Create a *function* that determines whether a string is a *valid **hex code***.
### Examples
``` C++
is_valid_hex_code("#CD5C5C");
// output = true

is_valid_hex_code("#EAECEE");
// output = true

is_valid_hex_code("#eaecee");
// output = true

is_valid_hex_code("#CD5C58C");
/* output = false
   reason: length exceeds 6
*/

is_valid_hex_code("#CD5C5Z");
/* output = false
   reason: not all alphabetic characters in A-F
*/

is_valid_hex_code("#CD5C&C");
/* output = false
   reason: contains unacceptable character
*/

is_valid_hex_code("CD5C5C");
/* output = false
   reason: missing #
*/
```
## 🔍 Problem Analysis
**Note**: I am analyzing with *C++* in mind.  
This problem requires a *function* which determines whether a passed string is a *valid* **hex code** or not, therefore this should return `true` or `false`, aka this is a `bool` function.
#### Steps
1. The function will first have to check if the string is ***7* characters long** (including the `#`), and starts with `#`, else it will have to *return* `false`.
2. The function will then have to **iterate over *each character of* the string** and check if it is in a `vector` (array) of **valid characters**(aka **0 - 9**, **A - F** and **a - f**).
3. If even *one* of the characters is invalid, it should *return* `false`, else it should *return* `true`.
Here is a **flowchart** illustrating this (Not necessary, just because I was wanting to practice **Mermaid.js**):
``` mermaid
flowchart TD
      A[String] --> H[isValidHex] --> B{Starts with '#' and is 7 characters long?}
      B -- true --> C(Iterate through string)
      B -- false --> D([Return false])
      C --> E{Are all characters valid?}
      E -- true --> F([Return true])
      E -- false --> G([Return false])
```
## 🛠 Implementation
I will be making ***3* files** for this:
1. The *first* one will be a `.hpp` file which is a ***user-defined* header file in C++** so I can ***separate* the `function.cpp`  (the function source file) and the `main.cpp` (the main function to call other functions) files** and still use the function in *both*. Here, I will put the *function signature*, and since the function has a ***string* parameter**, and since string is a ***composite* data type in C++**, I will also have to add the line `#include <string>`, so this is the code inside the **header file**(*not* the **function definition**):
``` C++
#ifndef hexValidator_hpp
#define hexValidator_hpp

#include <string>

bool isValidHex(const std::string& code);

#endif
```
2. Then, I will have to make the second file, which is the **actual function source file**, `isValidHex.cpp`.  
This is where the *actual* implementation starts:
So, basically, I first have to *link* the `hexValidator.hpp` **header file** with the function source file, so I have to put this line at the *top*:
``` C++
#include "hexValidator.hpp"
```
And also since I will have to store the ***valid* characters** (**0 - 9**, **A - F**, **a - f**) in a **`vector` (array)**, I will also have to *include* the `vector` **header file** with this line at the *second*:
``` C++
#include <vector>
```
And to check if *each* **character of the string** is *in* the `vector` of **accepted characters**, it's *not* as straightforward as **Python**'s `in` keyword, instead I have to use the `find` **function**, which is in the **C++ STL** in the `algorithm` **header file**, so I also have to put this line at the third:
``` C++
#include <algorithm>
```
Then I have to make it check if the string *starts* with `#` and is ***7* characters long*** (in *total*), and then I have to *declare* and *initialize* a `vector` (**array**) of ***accepted* characters** *after* the `#` (**0 - 9**, **A - F**, **a - f**).
Then I have to ***iterate* over the *characters* of the string from *after* the `#`** and check if *each* character is *in* the `vector` of **accepted characters** using the **STL `find` function**.
This is how the `find` function looks like:
``` C++
find(arrayName.begin(), arrayName.end(), c)
// arrayName is the array which holds the accepted characters.
// c is the character we are looking for in the array.
```
The function either returns an ***iterator* pointing to the first occurrence of `c`, or it returns an iterator pointing to the position just past the last element (aka, `arrayName.end()`). So, if it returns `.end()`, the character was not found in the whitelist, which means it's an invalid character.
It would take some time to understand it, I know! So, you could also consider reading this [documentation](https://cplusplus.com/reference/Algorithm/Find/).  
So, for this, I have to *replace* `arrayName` with the **name of the `vector` *holding* all the accepted characters**, and I also have to *replace* `c` with the ***current* character in the string being iterated over**, which is `code[i]`. (Assuming that `code` is the string being passed into the function. )
Then we check if the `find` function *returns* `arrayName.end()`, if it does, it means that the **current character** is *not* in the whitelist, aka **an *unaccepted* character**, and so the hex validator function should *return* `false`, else if the iteration **completes** *without* failing, the hex function should *return* `true`.
**Note** that it will *return* `true` *outside* the loop, *not* inside it!
That's all in the function source file.
3. Then, I have to make the **C++ `main` function file**, aka `main.cpp`. The problem just asked for the *hex function*, but I'm making this `main` function too to `call the hex function`, if you don't know: The `main.cpp` file *contains* the `main` *function* which *calls other functions* or does other stuff *outside* of functions.
I made about ***10* to *15* test cases** (see the `main.cpp` file), so I'm calling the function about 15 times to print out its value with `cout << `
I also put the line `cout << boolalpha` at the beginning so that ***every* *boolean* value** being printed after that gets printed as `true` or `false`, not as the default `1` or `0`.
Phew! That was a *lot*!
## ▶️ Compiling and executing
Note: I'm talking about compiling with a **terminal and a compiler**, *not* using an IDE.
For this, first clone the repo locally, then make sure you have a **C++ compiler *installed***, I'll be using `g++` here.
Then to **compile**:
1. On **Windows**:
``` Bash
g++ isValidHex.cpp main.cpp -o hexValidator
```
2. On **Linux**:
``` Bash
g++ isValidHex.cpp main.cpp -o hexValidator
```
And then to **execute**:
1. On **Windows**:
``` Bash
.\hexValidator.exe
```
2. On **Linux**:
``` Bash
./hexValidator
```
___
Ok, that's all! `</OneDollarCat>`
___
*Paraphrased a *bit* by me
