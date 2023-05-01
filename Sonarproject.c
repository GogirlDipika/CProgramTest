#include <stdio.h>
#include <stdlib.h>

int main() {
    char* str = (char*)malloc(10);
    if (str != NULL) {
        printf("Enter a string: ");
        scanf_s("%s", str);
        printf("You entered: %s\n", str);
    }
    free(str);
    return 0;
}