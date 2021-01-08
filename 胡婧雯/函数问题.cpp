/*值传递*/
#include <stdio.h>
int fun(int a,int b){
int c=10*(a/10)+(b/10)+1000*(a%10)+100*(b%10);
return c;
}
int main() {
int a,b;
printf("请输入两个两位数a,b:");
scanf("%d%d",&a,&b);
int c=fun(a,b);
printf("结果为:%d",c);
return 0;
}

/*引用传递*/
/*
#include<stdio.h>
  void fun(int a, int b, int &c)     
{
	  c=10*(a/10)+(b/10)+1000*(a%10)+100*(b%10);
 
}    void main()     
{   int a,b;
  int n;     
  printf("请输入两个两位数a,b:"); 
  scanf("%d%d", &a, &b);  
  fun(a, b, n);     
  printf("结果为:%d", n);
}
*/

/*指针传递*/
/*
#include<stdio.h>
  void fun(int a, int b, int *c)     
{ *c=10*(a/10)+(b/10)+1000*(a%10)+100*(b%10);
 
}  void main()     
{   int a,b;
  int n=0;     
  printf("请输入两个两位数a,b:"); 
  scanf("%d%d", &a, &b);  
  fun(a, b, &n);     
  printf("结果为:%d", n);
}
*/
