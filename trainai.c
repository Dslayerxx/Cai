#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

float weights0[5][6][256][512];//yes im not messing with jagged arrays
float neuronw0[5][7][512];
float calcN[5][8][512]; //the first layer is a value saving for normalization
float biasneur[5][6];
float biasweights[5][6][512];
float storage[32];

FILE *fp0[6];
FILE *fp;


void loadweights(){//loading all the weights into memory
  printf("loading neurons, please wait");
  long int x = 0;
  int layers[]={32,32,32,64,128,256,512};
  for(int z = 0; z<7;z++){//repeat per layer
    for(int i = 0; i<layers[z];i++){//load neuron layer for file
      for(int m = 0; m<5;m++){ //load neuron layer in all files
        fseek(fp0[m],x*8,SEEK_SET);
        fscanf(fp0[m],"%f",&neuronw0[m][z][i]);

      }
      x++;//keep count of where you need to read in the weight files
    }
  }
  printf("\nloading weights, please wait");
  for(int z = 0; z<6;z++){//load weights all layers
    for(int i = 0; i<layers[z];i++){//load weights on a singular layer
      for(int ii = 0; ii<layers[z+1];ii++){//load weights on a singular value
        for(int m = 0; m<5;m++){//load weights per file
          fseek(fp0[m],x*8,SEEK_SET);
          fscanf(fp0[m],"%f",&weights0[m][z][i][ii]);

        }
        x++;//same here
      }
    }
  }
  for (int i = 0; i < 6; i++) {
    for(int m = 0; m<5;m++){//load weights per file
      fseek(fp0[m],x*8,SEEK_SET);
      fscanf(fp0[m],"%f",&biasneur[m][i]);

    }
    x++;
  }
  for (int i = 0; i < 6; i++) {
    for (int p = 0; p < layers[i+1]; p++) {
      for(int m = 0; m<5;m++){//load weights per file
        fseek(fp0[m],x*8,SEEK_SET);
        fscanf(fp0[m],"%f",&biasweights[m][i][p]);
        biasweights[m][i][p] = biasweights[m][i][p]/10;
      }
      x++;
    }
  }
  printf("\nweights have been loaded");
}

void saveweights(){
  fclose(fp0[0]);
  fclose(fp0[1]);
  fclose(fp0[2]);
  fclose(fp0[3]);
  fclose(fp0[4]);
  fp0[0]=fopen("Aiweights0","w+");//opening the weight files
  fp0[1]=fopen("Aiweights1","w+");
  fp0[2]=fopen("Aiweights2","w+");
  fp0[3]=fopen("Aiweights3","w+");
  fp0[4]=fopen("Aiweights4","w+");
  long int x = 0;
  int layers[]={32,32,32,64,128,256,512};
  for(int z = 0; z<7;z++){//repeat per layer
    for(int i = 0; i<layers[z];i++){//load neuron layer for file
      for(int m = 0; m<5;m++){ //load neuron layer in all files
        fprintf(fp0[m],"%f",neuronw0[m][z][i]);
      }
      x++;//keep count of where you need to read in the weight files
    }
  }
  for(int z = 0; z<6;z++){//load weights all layers
    for(int i = 0; i<layers[z];i++){//load weights on a singular layer
      for(int ii = 0; ii<layers[z+1];ii++){//load weights on a singular value
        for(int m = 0; m<5;m++){//load weights per file
          fprintf(fp0[m],"%f",weights0[m][z][i][ii]);
        }
        x++;//same here
      }
    }
  }
  for (int i = 0; i < 6; i++) {
    for(int m = 0; m<5;m++){//load weights per file
      fprintf(fp0[m],"%f",biasneur[m][i]);
    }
    x++;
  }
  for (int i = 0; i < 6; i++) {
    for (int p = 0; p < layers[i+1]; p++) {
      for(int m = 0; m<5;m++){//load weights per file
        fprintf(fp0[m],"%f",biasweights[m][i][p]/10);
      }
      x++;
    }
  }
  fclose(fp0[0]);
  fclose(fp0[1]);
  fclose(fp0[2]);
  fclose(fp0[3]);
  fclose(fp0[4]);
  fp0[0]=fopen("Aiweights0","r+");//opening the weight files
  fp0[1]=fopen("Aiweights1","r+");
  fp0[2]=fopen("Aiweights2","r+");
  fp0[3]=fopen("Aiweights3","r+");
  fp0[4]=fopen("Aiweights4","r+");
}

void printarray(){
  int layers[]={32,32,32,32,64,128,256,512};
  for(int i = 0; i<8;i++){
  for(int z=0;z<layers[i];z++){
  printf("%.2f ",calcN[0][i][z]);
}printf("\n\n");}
}

float convertinput(char input){
  float storage;
    switch(input){
      case 'a':storage=0.015f;break;
      case 'b':storage=0.045f;break;
      case 'c':storage=0.075f;break;
      case 'd':storage=0.105f;break;
      case 'e':storage=0.135f;break;
      case 'f':storage=0.165f;break;
      case 'g':storage=0.195f;break;
      case 'h':storage=0.225f;break;
      case 'i':storage=0.255f;break;
      case 'j':storage=0.285f;break;
      case 'k':storage=0.315f;break;
      case 'l':storage=0.345f;break;
      case 'm':storage=0.375f;break;
      case 'n':storage=0.405f;break;
      case 'o':storage=0.435f;break;
      case 'p':storage=0.465f;break;
      case 'q':storage=0.495f;break;
      case 'r':storage=0.525f;break;
      case 's':storage=0.555f;break;
      case 't':storage=0.585f;break;
      case 'u':storage=0.615f;break;
      case 'v':storage=0.645f;break;
      case 'w':storage=0.675f;break;
      case 'x':storage=0.705f;break;
      case 'y':storage=0.735f;break;
      case 'z':storage=0.765f;break;
      case 'A':storage=0.005f;break;
      case 'B':storage=0.030f;break;
      case 'C':storage=0.060f;break;
      case 'D':storage=0.090f;break;
      case 'E':storage=0.120f;break;
      case 'F':storage=0.150f;break;
      case 'G':storage=0.180f;break;
      case 'H':storage=0.210f;break;
      case 'I':storage=0.240f;break;
      case 'J':storage=0.270f;break;
      case 'K':storage=0.300f;break;
      case 'L':storage=0.330f;break;
      case 'M':storage=0.360f;break;
      case 'N':storage=0.390f;break;
      case 'O':storage=0.420f;break;
      case 'P':storage=0.450f;break;
      case 'Q':storage=0.480f;break;
      case 'R':storage=0.510f;break;
      case 'S':storage=0.540f;break;
      case 'T':storage=0.570f;break;
      case 'U':storage=0.600f;break;
      case 'V':storage=0.630f;break;
      case 'W':storage=0.660f;break;
      case 'X':storage=0.690f;break;
      case 'Y':storage=0.720f;break;
      case 'Z':storage=0.750f;break;
      case ';':storage=0.78f;break;
      case ':':storage=0.785f;break;
      case '"':storage=0.79f;break;
      case '0':storage=0.8f;break;
      case '1':storage=0.82f;break;
      case '2':storage=0.84f;break;
      case '3':storage=0.86f;break;
      case '4':storage=0.88f;break;
      case '5':storage=0.9f;break;
      case '6':storage=0.92f;break;
      case '7':storage=0.94f;break;
      case '8':storage=0.96f;break;
      case '9':storage=0.98f;break;
      case ',':storage=0.795f;break;
      case '.':storage=0.985f;break;
      case '/':storage=0.99f;break;
      case '*':storage=0.995f;break;
      default: storage=0.0f; break;
    }
    return storage;
}

void calcai(){
  int layers[]={32,32,32,32,64,128,256,512};

  for(int i = 0;i<32;i++){ // vectorizes input and calcs the values of the first neurons
    for(int m = 0; m<5;m++){
      calcN[m][0][i]=storage[i];
      int y = calcN[m][0][i]*neuronw0[m][0][i];
      calcN[m][1][i]=fabs(y/(1+fabs(y))); //sigmoid function f(x) = x / (1 + fabs(x))+1
    }
  }

  for(int m = 0; m<5; m++){//for each file
    for(int z = 2; z<8; z++){//for each layer
      for(int i = 0; i<layers[z];i++){//for each neuron
        float temp=0;
        for(int w = 0; w<layers[z-1];w++){//for each weight and counts it up to for the value of the next neuron
          temp += calcN[m][z-1][w]*weights0[m][z-2][w][i]; //saves the total value for
        }
        temp = temp/layers[z-1];//normalizes value each layer
        temp += biasneur[m][z-2]*biasweights[m][z-2][i];//bias
        calcN[m][z][i]=fabs(temp/(1+fabs(temp)));//sigmoid function
      }
    }
  }
}

void printstory(){
  char storage[5][512];
  fp0[5]=fopen("aistories","w+");
  for (int m = 0; m < 5; m++) {
    int p = 0;
    for (int i = 0; i < 512; i++) {
      storage[m][i]=(char)(int)((calcN[m][7][i]*95)+32);
      fprintf(fp0[5],"%c", storage[m][i]);
      p++;
      if(p==80){
        fprintf(fp0[5], "\n");
        p = 0;
      }
    }
    fprintf(fp0[5],"\n\n");
  }
  fclose(fp0[5]);
}

float mutcha(float x){
  int gh = (int)(rand()/100)%100;
  switch(gh){
    case 0 ... 5: x=x*0.9f; break;
    case 6 ... 11: x=x*1.1f; break;
    case 12 ... 15: x=fmodf((float)rand()/1000,10); break;
    default: break;
  }
  if(x>9.9999f){
    x=9.999f;
  }
  if(x<0){
    x=0;
  }
  return x;
}

void mutweight(int num){ //mutates the weights
  size_t layers[]={32,32,32,64,128,256,512};
  int muse[4];
  int extra = 0;
  for(int i = 0; i<4;i++){
    if((i+1)==num){
      extra = 1;
    }
    muse[i]=i+extra;
  }

  num -= 1;

  for (size_t m = 0; m < 4; m++) {
    for (size_t z = 0; z < 7; z++) {
      for (size_t i = 0; i < layers[z]; i++) {
        neuronw0[muse[m]][z][i]=mutcha(neuronw0[num][z][i]);
      }
    }
    for (size_t z = 0; z < 6; z++) {
      biasneur[muse[m]][z]=mutcha(biasneur[num][z]);
      for (size_t i = 0; i < layers[z+1]; i++) {
        biasweights[muse[m]][z][i]=mutcha(biasweights[num][z][i]);
      }
      for (size_t i = 0; i < layers[z]; i++) {
        for (size_t w = 0; w < layers[z+1]; w++) {
          //printf("\n%d %d %d %d ", muse[m],z,i,w);
          weights0[muse[m]][z][i][w]=mutcha(weights0[num][z][i][w]);
        }
      }
    }
  }
}

void autotrain(){
  char input[33];
  char check[512];
  
  fp=fopen("Autotrain.txt","r");
  int zxy=0;
  while(1){
    printf("\nBusy with training on text%d, progress-",zxy);
    fseek(fp,zxy*544,SEEK_SET);
    //fscanf(fp,"%32s", &input);
    fgets(input,32,fp);
    for(int i = 0;i<32;i++){ // converts input to a more legible value
      storage[i] = convertinput(input[i]);
    }
    fseek(fp,(zxy*544)+32,SEEK_SET);
    //fscanf(fp,"%s512", &check);
    fgets(check,512,fp);
    for(int aii=0;aii<100;aii++){
      int best[6]={0,0,0,0,0,0};
      int high=0;
      for(int rept=0;rept<floor(log10(aii))+1;rept++){//dynamic progress printing
        printf("\b");
      }
      printf("%d",aii);
      calcai();
      for(int m=0;m<5;m++){
        for(int i=0;i<512;i++){
          if((char)(int)((calcN[m][7][i]*95)+32)==check[i]){
            best[m]++;
          }
        }
      }
      int save[2] = {0,0};
      for(int m = 0;m<5;m++){
        if(best[m]>save[0]){
          save[0]=best[m];
          save[1]=m;
          high = save[1];
        }
      }
      if(aii == 99){
        printf("\n%d \n",save[0]);
      }
      mutweight(high+1);
    }
    zxy++;
    if(zxy>0){//zxy>number of stories - 1
      zxy=0;
      saveweights();
      printstory();
    }
  }
}

void main(){
  char in[2];
  char input[33];
  char output[512];

    fp0[0]=fopen("Aiweights0","r+");//opening the weight files
    fp0[1]=fopen("Aiweights1","r+");
    fp0[2]=fopen("Aiweights2","r+");
    fp0[3]=fopen("Aiweights3","r+");
    fp0[4]=fopen("Aiweights4","r+");

    loadweights();
    int automatic = 0;
    printf("\ndo you want to train automaticly? (1=yes, 0=no)\n");
    scanf("%d", &automatic);

  if(automatic==0){
    printf("\nplease input a maximum 32 chararacter prompt:");
    scanf("%32[^\n]",input);
    printf("\ngenerating 5 stories, please wait");

    for(int i = 0;i<32;i++){ // converts input to a more legible value
      storage[i] = convertinput(input[i]);
    }

    while(1){
      calcai();
      printstory();
      printf("\nthe generated stories can be found in the story file");
      printf("\ntell me which ai did the best job?");
      printf("\nyou can use q to quit");
        printf("\nplease give a number from 1 to 5 to indicate which ai did the best:\n");
      scanf("%1s", &in);
      if((int)in[0]==113){
        return;
        exit(0);
      }
      int num = (int)in[0]-48;//converts input to a integer
      printf("\nmutating weights");
      mutweight(num);
      printf("\nsaving weights");
      saveweights();
    }
  }else{
    autotrain();
  }
}
