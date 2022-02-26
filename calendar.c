#include<stdio.h>
#include<math.h>
#include<string.h>
#define size 8

int main(){
  char input[10];
  int len,list[10],lenc,sum;
  
  while(1){
  sum=0;
  printf("16進数の入力(qで終了):");
  scanf("%s", input);
  len=strlen(input);
  if(len>8){puts("オーバーフロー!"); continue;}
  lenc=len-1;
  if(input[0]=='q'){puts("終了しました。");return 0;}

  for(int i=0;i<len;i++){
    switch(input[i]){
      case 'a':
      case 'A':
      list[i]=10;
      break;

      case 'b':
      case 'B':
      list[i]=11;
      break;

      case 'c':
      case 'C':
      list[i]=12;
      break;

      case 'd':
      case 'D':
      list[i]=13;
      break;

      case 'e':
      case 'E':
      list[i]=14;
      break;

      case 'f':
      case 'F':
      list[i]=15;
      break;

      default:
      list[i]=input[i]-'0';
      break;
    }
  }
  
  for(int i=0;i<len;i++){
    if(list[i]<0 || list[i]>16)
      puts("不正な文字の使用されています。");
      continue;
  }

  for(int i=0;i<len;i++){
    sum+=pow(16,lenc)*list[i];
    lenc--;
  }
  printf("入力された桁数は%d桁です。\n",len);
  printf("%d\n",sum);
  }

  return 0;
}