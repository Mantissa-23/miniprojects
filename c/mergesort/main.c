#include <stdio.h>
#include <string.h>
#define ARRAYSIZE(arr) sizeof(arr)/sizeof(arr[0])


int main() {
    int testarray[] = {1, 2, 3, 4, 5};

    int i;

    for(i=0; i < ARRAYSIZE(testarray); i++) {
        printf("%d", testarray[i]);
    }

    printf("\n");
    return 0;
}
