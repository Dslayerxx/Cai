#include <stdio.h>

int main()
{
FILE *fp0;
int x1 = 0;
int x2 = 0;
int x3 = 0;
int x4 = 0;
fp0=fopen("Aiweights0","w");

for(int x = 0; x < 9999; x++){
    fprintf(fp0,"%d%d%d%d\n",x1,x2,x3,x4);
    x1++;
    if(x1==10){
        x2++;
        x1 = 0;
    }
    if(x2==10){
        x3++;
        x2 = 0;
    }
    if(x3==10){
        x4++;
        x3 = 0;
    }
}
}