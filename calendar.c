#include<stdio.h>
#include<stdbool.h>

int main(){
  int countDay1(int cullentYear);
  int countDay2(int cullentYear,int cullentMonth);
  bool urudoshi(int Year);
  int nowMonth,nowYear,dayToNow,day,lengthCounter,countDay=1;

  printf("西暦：");
  scanf("%d",&nowYear);
  printf("月　：");
  scanf("%d",&nowMonth);

  dayToNow=countDay1(nowYear)+countDay2(nowYear,nowMonth);
  switch(nowMonth){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: day=31; break;
    case 2: (urudoshi(nowYear))?(day=29):(day=28); break;
    case 4:
    case 6:
    case 9:
    case 11: day=30; break;
  }
  puts("日 月 火 水 木 金 土 ");
  switch(dayToNow%7){
    case 5: printf("   "); lengthCounter=1; break;
    case 6: printf("      "); lengthCounter=2; break;
    case 0: printf("         "); lengthCounter=3; break;
    case 1: printf("            "); lengthCounter=4; break;
    case 2: printf("               "); lengthCounter=5; break;
    case 3: printf("                  "); lengthCounter=6; break;
    case 4: lengthCounter=0; break;
    default: puts("Error"); break;
  }
  for(int i=0;i<6;i++){
    for(int j=0;j<7;j++){
      if(i==0&&j==0){
        j=lengthCounter;
      }
      if(day==0)break;
      printf("%2d ",countDay);
      day--;
      countDay++;
    }
    printf("\n");
  }
  
  return 0;
}

int countDay1(int cullentYear){
  int sumDay=0;
  bool urudoshi(int Year);
  for(;cullentYear>0;cullentYear--){
    if(urudoshi(cullentYear))sumDay+=364;
    else sumDay+=365;
  }
  return sumDay;
}

int countDay2(int cullentYear,int cullentMonth){
  int sumDay=0;
  bool urudoshi(int Year);
  cullentMonth--;
  if(cullentMonth>0){
    for(;cullentMonth>0;cullentMonth--){
      switch(cullentMonth){
        case 1: sumDay+=31; break;
        case 2: (urudoshi(cullentYear))?(sumDay+=29):(sumDay+=28); break;
        case 3: sumDay+=31; break;
        case 4: sumDay+=30; break;
        case 5: sumDay+=31; break;
        case 6: sumDay+=30; break;
        case 7: sumDay+=31; break;
        case 8: sumDay+=31; break;
        case 9: sumDay+=30; break;
        case 10: sumDay+=31; break;
        case 11: sumDay+=30; break;
        default: puts("error"); break;
      }
    }
  }
  return sumDay;
}

bool urudoshi(int Year){
  if(Year/4==0&&Year/400==0)return true;
  else if(Year/4==0&&Year/100==0)return false;
  else if(Year/4==0)return true;
  else return false;
}
//閏年で"true"を返す