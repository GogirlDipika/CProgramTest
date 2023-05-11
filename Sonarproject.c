#include <stdio.h>
#include <stdlib.h>

int main() {
    int c;
    char var;//unused variable
    //to check for bug and code smell.
    //memory allocation
    //c programming
    //soncloud testing.
    //how to check c programming
    char* str = (char*)malloc(10);
    if (str != NULL) {
        printf("Enter a string: ");
        scanf_s("%s", str);
        printf("You entered: %s\n", str);
    }
    free(str);
    return 0;
}
