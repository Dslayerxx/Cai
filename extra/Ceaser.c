#include <stdio.h>
#include <string.h>

char yx[] ="jr penpxrq vg hfvat na bayvar gbby sbe penpxvat ene svyrf";
void main()
{
for (int y=0; y<26; y++){
    for (int x=0; x<(sizeof(yx)/sizeof(yx[1]))-1; x++){
        int convert;
        convert = (int)yx[x];
        if(convert != 32&& convert != 46){
            convert++;
            if(convert > 122){
                convert = convert - 26;
            }
            yx[x] = (char)convert;
        }
    }
    printf("%s \n", yx);
}
scanf("a");
}