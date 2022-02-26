#include<stdio.h>
#include<stdbool.h>

int main(){
  int inYear,inGankin,hensai=1;
  float riritu;
  bool hensaiNensu(int gankin,int hensai,float riritu,int inYear);

  printf("何年間のローンですか：");
  scanf("%d",&inYear);
  printf("利率は何％ですか：");
  scanf("%f",&riritu);
  riritu/=100;
  printf("借金はいくらですか：");
  scanf("%d",&inGankin);
  
  for(int i=1;i<inGankin;i++){
    if(hensaiNensu(inGankin,i,riritu,inYear)){
      printf("月々の返済は%d円になります\n",i);
      break;
    }
  }
  return 0;
}

bool hensaiNensu(int gankin,int hensai,float riritu,int inYear){
  int year=0;
  for(int i=0;i<inYear;i++){
  	gankin=gankin-(hensai*12);
    gankin*=(1+riritu);
    if(gankin<=0)return true;
  }
  return false;
}