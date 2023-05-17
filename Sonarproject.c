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
    if (str != NULL) {
        printf("Enter a string: ");
        scanf_s("%s", str);
        printf("You entered: %s\n", str);
    }
    if (pi == 3.14159)                  // empty if statement
    {
    }
    free(str);
    return 0;
}
