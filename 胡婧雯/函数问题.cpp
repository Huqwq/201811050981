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