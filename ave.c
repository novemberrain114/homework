#include "stdio.h"
int average(int a,int b, int c){
    return (a+b+c)/3;
}
int square(int a){
    return a*a;
}
int variance(int a,int b,int c){
    int ave=average(a,b,c);
    return (square(a-ave)+square(b-ave)+square(c-ave))/3;
}
int score(int a,int b,int c){
    return 3*average(a,b,c)-variance(a,b,c)/3;
}

void rank(int zh1,int zh2,int zh3){
    if (zh1 >= zh2 && zh2 >= zh3) {
      printf("小明 > 小强 > 小林");
  } else if (zh1 >= zh3 && zh3 >= zh2) {
      printf("小明 > 小林 > 小强");
  } else if (zh2 >= zh1 && zh1 >= zh3) {
      printf("小强 > 小明 > 小林");
  } else if (zh2 >= zh3 && zh3 >= zh1) {
      printf("小强 > 小林 > 小明");
  } else if (zh3 >= zh1 && zh1 >= zh2) {
      printf("小林 > 小明 > 小强");
  } else { // zh3 >= zh2 && zh2 >= zh1
      printf("小林 > 小强 > 小明");
  }
}
int main(){
    int x1, x2, x3;
    int y1, y2, y3;
    int z1, z2, z3;

    printf("请输入小明的三项成绩（顺序为A B C,以一个空格为间隔）：");
    scanf("%d %d %d", &x1, &x2, &x3);
    printf("请输入小强的三项成绩（顺序为A B C,以一个空格为间隔）：");
    scanf("%d %d %d", &y1, &y2, &y3);
    printf("请输入小林的三项成绩（顺序为A B C,以一个空格为间隔）：");
    scanf("%d %d %d", &z1, &z2, &z3);
    int zh1=score(x1,x2,x3);
    int zh2=score(y1,y2,y3);
    int zh3=score(z1,z2,z3);
    rank( zh1, zh2, zh3);
    return 0;
}