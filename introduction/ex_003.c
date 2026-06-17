#include <stdio.h>
int main()
{
//declaration of variables

int num;  
char cnum;
float fnum;
double dnum;

scanf("%d%c%f%lf", &num, &cnum, &fnum, &dnum); //printing inputs or store the value from user
printf("Integer is :%d\n", num);
printf("Character is :%c\n", cnum);
printf("Float is :%f\n", fnum);
printf("Double is :%lf\n", dnum);

    return 0;  //return is a special keyword in c programing
}
