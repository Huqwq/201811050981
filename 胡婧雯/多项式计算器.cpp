/*
#include<stdio.h>
#include<string.h>
#define MaxSize 100 
 
typedef struct CharStack				//�ַ�ջ 
{
	char data[MaxSize];
	int top;
}cStack;
 
typedef struct DoubleStack				//����ջ 
{
	double data[MaxSize];
	int top;
}dStack;
 
int Isop(char );				//��ǰɨ��Ԫ�����ȼ� 
int Inop(char );				//ջ��Ԫ�����ȼ� 
 
void Initc(cStack *);				//��ʼ���ַ�ջ 
int Pushc(cStack *,char);			//�ַ�ջѹջ 
char Gettopc(cStack *);				//����ջ��Ԫ�� 
char Popc(cStack *);				//��ջ 
 
void Initd(dStack *);				//��ʼ������ջ 
int Pushd(dStack *,double);			//����ѹջ 
double Popd(dStack *);				//��ջ 
 
void Trans(char*s1,char*s2);		        //ת��Ϊ��׺���ʽ 
 
double Calculate(char *s2);			//��׺���ʽ��ֵ 
 
 
 
 
 
int main()
{
	char s1[MaxSize];			//���ڴ洢ǰ׺���ʽ 
	char s2[MaxSize];			//���ڴ洢ת����ı��ʽ 
	printf("��������ʽ:");
	scanf("%s",s1);
	
	Trans(s1,s2);				//�����ַ�������ת��Ϊ��׺���ʽ,�����s2�� 
	
	printf("������Ϊ: %f",Calculate(s2));		//��׺���ʽ��ֵ 
	
		
	return 0;
}
 
//��ʼ�� 
void Initc(cStack *s1)
{
	s1->top=-1;
}
 
 //�ַ�ջѹջ 
 int Pushc(cStack *c1,char op)
 {
 	if(c1->top<MaxSize)
 	{
 		c1->data[++c1->top]=op;
 		return 1;
	}
	else return 0;
}
 
//GETջ��Ԫ�� 
char Gettopc(cStack *c1)
{
	return c1->data[c1->top];
}
 
//�ַ�ջ��ջ 
char Popc(cStack *c1)
{
	return c1->data[c1->top--];
}
 
//��ʼ������ջ 
void Initd(dStack *d1)
{
	d1->top=-1;
}
 
//����ջѹջ 
int Pushd(dStack *d1,double data)
{
	if(d1->top<MaxSize)
	{
		d1->data[++d1->top]=data;
		return 1;
	}
	else return 0;
}
 
//����ջ��ջ 
double Popd(dStack *d1)
{
	return d1->data[d1->top--];
}
 
int Isop(char op)		//��ǰɨ����������ȼ�
{
	switch(op)
	{
		case '(': return 6;
		case '+': case '-': return 2;
		case '*': case '/': return 4;
	}
}
int Inop(char op)		//��ǰɨ����������ȼ�
{
	switch(op)
	{
		case '(': return 1;
		case '+': case '-': return 3;
		case '*': case '/': return 5;
	}
}
 
void Trans(char *s1,char *s2)
{
	int i=0;
	int j=0;
	int flag1=-1;				//flag1Ϊ0��ʾ�ϴ����Ϊ���֣�flag1Ϊ1��ʾ�ϴ����Ϊ�ַ�
	int flag2=-1; 				//flag2Ϊ0��ʾ�ϴ�ɨ��Ϊ���֣�flagΪ1��ʾ�ϴ�ɨ��Ϊ������������������ֺ�ӿո�
	cStack st1;				//�ݷ������ 
	Initc(&st1);
	
	while(s1[i]!='\0')			//������ 
	{
		if(s1[0]=='-')			//��һλ����Ϊ����ʱ 
		{
			j=strlen(s1);
			while(j>0)
			{
				s1[j+5]=s1[j];
				j--;
			}
			s1[j++]='(';
			s1[j++]='0';
			s1[j++]='-';
			s1[j++]='1';
			s1[j++]=')';
			s1[j]='*';
			
		}
		if(s1[i]=='('&&s1[i+1]=='-')	//�ǵ�һλ����ʱ 
		{
			j=strlen(s1);
			while(j>i+1)
			{
				s1[j+5]=s1[j];
				j--;
			}
			s1[j++]='(';
			s1[j++]='0';
			s1[j++]='-';
			s1[j++]='1';
			s1[j++]=')';
			s1[j]='*';
			i=i+5;
		}
		i++;
	}
	
	i=0;
	j=0;
	while(s1[i]!='\0')
	{
		if(flag1==0&&flag2==1)		//���ϴε����Ϊ���֣��ϴ�ѭ��ɨ��Ϊ�ַ������ʾ�����ִ��������������ֺ�ӿո����� 
		{
			s2[j++]=' ';
			flag1=1; 
		}
		if(s1[i]>='0'&&s1[i]<='9'||s1[i]=='.')
		{
			s2[j++]=s1[i];
			flag2=0;
			flag1=0;
		}
		else if(s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/'||s1[i]=='(')
		{
			flag2=1;
			if(st1.top<0||Isop(s1[i])>Inop(Gettopc(&st1)))
			{
				Pushc(&st1,s1[i]);
			}
			else
			{
				while(st1.top>=0&&Isop(s1[i])<Inop(Gettopc(&st1)))		//��ǰɨ���ַ����ȼ�������ջ���ַ����ȼ��Ƚϣ���ǰ�ַ�С��ջ���ַ�ʱ��ջ����� 
				{
						s2[j++]=Popc(&st1);
						flag1=1;
				}
				if(st1.top<0||Isop(s1[i])>Inop(Gettopc(&st1)))			//��ǰ�ַ����ȼ�����ջ�����ȼ���ջ��ʱ��ǰ�ַ�ѹ���ַ�ջ�� 
				{
					Pushc(&st1,s1[i]);
				}
				
			}
		}
		else if(s1[i]==')')				 
		{
			flag2=1;
			if(Gettopc(&st1)!='(')		//�����Ž�����������û���������� 
			{
				flag1=1;
			}
			while(Gettopc(&st1)!='(')
			{
				s2[j++]=Popc(&st1);
			}
			Popc(&st1);		//��'('��ջ 
		}
		i++;
	}
	while(st1.top>=0)		//��ջ��ʣ��������������ջ��� 
	{
		s2[j++]=Popc(&st1);
	}
	s2[j]='\0';
}
 
//���ʽ��ֵ 
double Calculate(char *s1)
{
	int i=0;
	int flag;				//char����ת��Ϊdouble�������ݱ�� 
	double data1,data2;
	double sum;
	dStack ds1;
	Initd(&ds1);
	while(s1[i]!='\0')
	{
		if(s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/')			//��Ϊ�������ȡջ������Ԫ�ؽ��м��� 
		{
			data1=Popd(&ds1);
			data2=Popd(&ds1);
			if(s1[i]=='+') Pushd(&ds1,data2+data1);
			else if(s1[i]=='-') Pushd(&ds1,data2-data1);
			else if(s1[i]=='*') Pushd(&ds1,data2*data1);
			else if(s1[i]=='/') Pushd(&ds1,data2/data1);
		}
		else							//Ϊ����ʱת��Ϊdouble����ѹջ 
		{
			flag=0;					//��ʼ��Ϊ0Ϊ�������ֱ�ǣ�1ΪС�����ֱ�� 
			sum=0;
			double divider=1;
			while(s1[i]!=' '&&s1[i]!='+'&&s1[i]!='-'&&s1[i]!='*'&&s1[i]!='/')
			{
				if(s1[i]=='.')		//����С���㣬����С��ת��ģʽ 
				{
					flag=1;
					i++;
					continue;
				}
				if(flag==0)
				{
					sum=sum*10+(double)(s1[i]-'0');
				}
				else
				{
					divider=divider*10;
					sum=sum+((double)(s1[i]-'0'))/divider;
				}
				i++;
			}
			if(s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/') i--;	//ת���ɹ�һ�����ݣ����¸��ַ�Ϊ���������i--���ص���ǰ���������λ�� 
			Pushd(&ds1,sum);
		}
		i++;		//i++׼����һ���ַ���ת�� 
	}
	 return Popd(&ds1);
}

*/

#include <cmath>
#include <string>
#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 5000
 
char c[MAXN], oper[MAXN];
double number[MAXN];
int oper_num, num_num, p;
 
void work();
void calc();
void get_number();
void get_operator();
int get_priority(int n);
 
int main(){
    scanf("%s", &c);
    work();
    printf("%lf", number[1]);
    return 0;
}
 
void work(){
    while (p < strlen(c)){
	if (c[p] >= '0' && c[p] <= '9') get_number();
	if (c[p] == '+' || c[p] == '-' || c[p] == '*' 
            || c[p] == '/' || c[p] == '^') get_operator();
	if (c[p] == '(') oper[++oper_num] = '(';
	if (c[p] == ')'){
	    oper[++oper_num] = ')';
	    while (oper_num > 1 && oper[oper_num-1] != '(') calc();
	    oper_num -= 2;
	}	
        p++;	
    }
    oper[++oper_num] = ')';
    while (oper_num > 1) calc();	
}
 
void calc(){
    double res = 1;
    double a2 = number[num_num--];
    double a1 = number[num_num];	
    char handle = oper[--oper_num];
    oper[oper_num] = oper[oper_num + 1];	
    if (handle == '+') res = a1 + a2;
    if (handle == '-') res = a1 - a2;
    if (handle == '*') res = a1 * a2;
    if (handle == '/') res = a1 * 1.0 / a2;
    if (handle == '^') {
    	for (int i = 1;i <= abs(a2); i++) res = res * a1;
    	if (a2<0) res = 1.0 / res;//ע����Ϊ���������
    }
    number[num_num] = res;
}
 
void get_number(){//��ȡ���֣�ע��С����Ĵ���
    int n = 1, start_p = p;
    char c_num[MAXN];	
    while ((c[p] <= '9' && c[p] >= '0') || c[p] == '.') {	
    	n++;
    	p++;
    }
    strncpy(c_num, c+start_p, n);
    sscanf(c_num, "%lf", &number[++num_num]);
    if (c[start_p-1] == '-' && (c[start_p-2] == '(' || start_p == 1)){
    	number[num_num] = -number[num_num];
    	oper_num--;
    }//��ֱ�����븺���������Ǹ���ǰΪ�����ţ������ɰѸ��Ŵ���Ϊ�����
}
 
void get_operator(){//��ȡ����
    oper[++oper_num] = c[p];
    while (oper_num > 1 && oper[oper_num-1] != '(' 
        && get_priority(oper_num) <= get_priority(oper_num-1)) calc(); 
}
 
int get_priority(int n){//���ص�ǰ�������ȼ���������󣬳˳����˷���Σ�����ǼӼ�
    if (oper[n] == '+' || oper[n] == '-') return 0;
    if (oper[n] == '*' || oper[n] == '/' || oper[n] == '^') return 1;
    return 2;
}