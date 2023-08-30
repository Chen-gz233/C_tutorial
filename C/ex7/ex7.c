
#include <stdio.h>




/*
我们使用了sizeof关键字来问C语言这些东西占多少个字节。
C语言无非是内存块的大小和地址以及在上面执行的操作。
它向你提供了sizeof便于你理解它们，所以你在使用一个东西之前可以先询问它占多少空间。
*/

int main(int argc, char *argv[])
{
    int areas[] = {10, 12, 13, 14, 20};
    char name[] = "Zed";
    char full_name[] = {'Z', 'e', 'd', ' ', 'A', '.', ' ', 'S', 'h', 'a', 'w', '\0'};


    // WARNING: On some systems you may have to change the
    // %ld in this code to a %u since it will use unsigned ints
    printf("The size of an int: %ld\n", sizeof(int)); //int is 4 byte
    printf("The size of areas (int[]): %ld\n", sizeof(areas)); //the array has 5 member
    printf("The number of ints in areas: %ld\n", sizeof(areas) / sizeof(int));

    printf("The first area is %d, the 2nd %d.\n", areas[0], areas[1]);

    printf("The size of a char: %ld\n", sizeof(char)); //char is 1 byte
    printf("The size of name (char[]): %ld\n", sizeof(name));
    printf("The number of chars: %ld\n", sizeof(name) / sizeof(char));

    printf("The size of full_name (char[]): %ld\n", sizeof(full_name));
    printf("The number of chars: %ld\n", sizeof(full_name) / sizeof(char));

    printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);

    return 0;
}