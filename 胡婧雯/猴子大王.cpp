#include <stdio.h>
void king(int m,int n)
{
    int p[999];
    int i,j,t;
    for (i=0; i<m; i++)         //������ʼ���У���¼mֻ������Ȧ��
        p[i]=1;
    t=0;                       //�״α���������ʼλ��Ϊ0������1ֻ���ӿ�ʼ����Ϊ��ʹ��p[t]ǰtҪ��1
    printf("����˳��:");
    for (i=1; i<=m; i++)        //ѭ��Ҫִ��m�Σ���m������Ҫ��Ȧ
    {
        j=1;      // j���ڱ���
        while(j<=n)  //
        {
            t=(t+1)%m;        //����һֻ���ӣ��������ʱҪ�ۻ�ȥ��������%m
            if (p[t]==1) j++; //��ͬ��if (p[t]==1) j++;����q������Ȧ�У����λ�òű���
	}}
for(i=0;i<m;i++)
	{
		if(p[i]>0)
			printf("���Ӵ�����%d\n",p[i]);
	}
	return 0;
   
}

int main()
{
    int m,n;
    scanf("%d %d", &m, &n);
    king(m,n);
    return 0;
}