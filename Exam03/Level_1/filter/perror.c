#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("not_exist.txt", "r");
    if (!fp)
        perror("Error");
    return 0;
}

