#include <stdio.h>
int main()
{
    char dir;
    printf("Enter thr direction: ");
    scanf("%c", &dir);
    switch(dir)
    {
        case 'N':
        case 'n':             // for if you enter small case letter also it will work
            printf(" North DIRECTION\n");
            break;
        case 'S':
        case 's':
            printf(" South DIRECTION\n");
            break;
        case 'E':
        case 'e':
            printf(" East DIRECTION\n");
            break;
        case 'W':
        case 'w':
            printf(" West DIRECTION\n");
            break;
        default:
            printf("Invalid direction\n");
    }
    return 0;
}