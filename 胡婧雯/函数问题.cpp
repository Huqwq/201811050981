#include<stdio.h>
  void fun(int a, int b, int &c)     
{
	  c=10*(a/10)+(b/10)+1000*(a%10)+100*(b%10);
 
}    void main()     
{   int a,b;
  int n;     
  printf("������������λ��a,b:"); 
  scanf("%d%d", &a, &b);  
  fun(a, b, n);     
  printf("���Ϊ:%d", n);
}