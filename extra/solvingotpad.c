#include <stdio.h>
#include <string.h>



void main(){
char input[2][16] = {"PNUKLYLWRQKGKBE","EICTDGYIYZKTHNS"};
int save[2][16];
char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
for (int i = 0; i < 2; i++){
    for (int x = 0; x < 16; x++){
        save[i][x]=((int)input[i][x])-65;
    }
}
char printed[16];
for (int i = 0; i < 16; i++)
{
    printed[i] = alphabet[save[0][i]-save[1][i]+26];
}
printf("%16s",printed);
scanf(" ");
}