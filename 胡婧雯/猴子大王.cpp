/*数组*/
/*
#include<stdio.h>
int main()
{
	int m,n,number,count=1;		//number记猴子剩余个数，count记当前报数
	int monkey[999];
	int t;						//t记数组下标
	int i;
	printf("请输入猴子个数 m 和报数 n ：");
	scanf("%d%d",&m,&n);
	number = m;
	for(i=0;i<m;i++)
		monkey[i]=i+1;
	t=0;
	while(number>1)
	{
		if(monkey[t]>0)
		{
			if(count!=n)
			{
				count++;
				t=(t+1)%m;		//实现数组下标加1，避免重新拐回去报数
			}
			else
			{
				monkey[t]=0;
				count=1;
				number--;
				t=(t+1)%m;
			}
		}
		else
		{
			t=(t+1)%m;
		}
	}
	for(i=0;i<m;i++)
	{
		if(monkey[i]>0)
			printf("猴子大王：%d\n",monkey[i]);
	}
	return 0;
}
*/
/*链表*/
/*
#include <iostream>
using namespace std;
struct Monkey
{
    int num;  //猴子的编号
    struct Monkey *next; //下一只猴子
};

int main()
{
    int m,n,i,j,king;
    Monkey *head, *p1,*p2;
    cout<<"请输入猴子个数m和报数n: ";
	 cin>>m>>n;
    if(n==1)
    { king=m;}
    else
    {  //建立猴子围成的圆圈
        p1=p2=new Monkey;
        head = p1;
        p1->num=1;
        for(i=1; i<m; i++)  //其余m-1只猴子
        {
            p1=new Monkey;  //p1是新增加的
            p1->num=i+1;
            p2->next=p1;
            p2=p1;          //p2总是上一只
        }
        p2->next=head;      //最后一只再指向第一只，成了一个圆圈
        //开始寻找猴大王
        p1=head;
        for(i=1; i<m; i++)  //循环m-1次，淘汰m-1只猴子
        {   //从p1开始，数n-1只就找到第n只了
            for(j=1; j<n-1; j++)  //先找到第n-1只，下一只将是被淘汰的
            p1=p1->next;    //指向剩余围成圈的

            //找到猴大王
            p2=p1->next;  //p2将被删除
            p1->next=p2->next;  //p2为空
            p1=p2->next;  //下一轮数猴的新起点
            delete p2;  //已不在链表，删除
        }
        king=p1->num;
        delete p1;
    }
    cout<<"猴子大王: ";
	cout<<king<<endl;
    return 0;
}
*/
