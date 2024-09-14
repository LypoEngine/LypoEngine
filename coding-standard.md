# Coding Standard   
# Naming Conventions   
## Classes and Structs   
- PascalCase   
   
## Functions   
- camelCase   
   
## Variables   
- sname\_case   
   
## Constants   
- ALL\_CAPS   
   
   
# Header Files   
## Foward Declaration   
- Use foward declarations when possible to reduce dependencies. This minimize the need for including full header files, which can reduce compilation time and decrease dependencies which make it easier to maintain   
   
## Include Guards   
- Always use include guard or `#pragma once` in header files to prevent multiple inclusion of the same file   
   
## Header File Content   
- Should only declare classes, structs and functions. Their implementation should be in their associated `.cpp`  file   
   
   
# General Coding Practices   
- Use `const`  and `constexpr` where they are appropriate. This improve code safety and optimization   
- Prefer smart pointers to automatically manage memory, reducing the rick of memory leaks and dangling pointers. You must be careful when using smart pointer that have a destructor on static variable since they might depend on something that is already shutdown   
- Avoid using `using namespace std;` in headers files   
- Avoid throwing error, instead manage them and return an error code as an enum or other value. It would also be useful to use the Logging system to log what went wrong   
