#include <stdio.h>
#include <stdlib.h>

int main() {
    int c;
    double pi = 3.14159;
    char var;//unused variable
    //to check for bug and code smell
    //memory allocation
    //c programming
    //soncloud testin
    //how to check c programming
    char* str = (char*)malloc(10);
    if      (       str != NULL) {
        printf("Enter a string: ");
        scanf_s("%s", str);
        printf("You entered: %s\n", str);
    }
    if (pi == 3.14159)                  // empty if statement
    {
    }
    free(str);
     A:
        a();
    goto A;     // Considered Harmful
    
    
    for (int i =                                                   0; i < 10; i++)
    {
        if (foo(i))
        {
            continue;
        }
        break;      // this break is confusing
    }
    
    // This line has an extra space before the opening parenthesis.
  if ( 1 ) {
    // This line has an extra space after the closing parenthesis.
  }

  // This line has an extra space before the opening curly brace.
  {
    // This line has an extra space after the closing curly brace.
  }
    
    
    return 0;
}

void f() {
 if (p)
 free(p);
}
