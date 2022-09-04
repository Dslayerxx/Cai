#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float randos();

void main()
{
  float x = 5;
    FILE *fp0;
    FILE *fp1;
    FILE *fp2;
    FILE *fp3;
    FILE *fp4;
    fp0=fopen("Aiweights0","w");
    fp1=fopen("Aiweights1","w");
    fp2=fopen("Aiweights2","w");
    fp3=fopen("Aiweights3","w");
    fp4=fopen("Aiweights4","w");
    for(int i = 0; i<178214;i++){//print the neuron weights
      fprintf(fp0,"%f",randos());
      fprintf(fp1,"%f",randos());
      fprintf(fp2,"%f",randos());
      fprintf(fp3,"%f",randos());
      fprintf(fp4,"%f",randos());//put back the randos
    }
}

float randos(){
    float x = fmodf((float)rand()/1000,10);
    return x;
}
