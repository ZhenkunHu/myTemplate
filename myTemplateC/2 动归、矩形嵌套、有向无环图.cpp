#include<bits/stdc++.h>
using namespace std;

struct date {
    int a,b,c;
}a[185];

void da_push(int k,int A,int B,int C) { //�Լ�д��push
    a[k].a=A;
    a[k].b=B;
    a[k].c=C;
}

bool cmp(date a,date b) {
    return a.a>b.a;
}

int main() {
    int n;
    int Case=1;
    while(scanf("%d",&n)==1&&n) {
        int num=0;
        for(int i=0;i<n;i++) {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            da_push(num++,x,y,z);
            da_push(num++,x,z,y);
            da_push(num++,y,x,z);
            da_push(num++,y,z,x);
            da_push(num++,z,x,y);
            da_push(num++,z,y,x);
        }

        int dp[185];//״̬
        n=n*6;
        sort(a,a+n,cmp);

        for(int i=0;i<n;i++) //��ʼ����ֵ����״̬ת�Ʒ��̵�else
            dp[i]=a[i].c;

        int ans=0;
        for(int i=0;i<n;i++) {
            //д��1���Ƚϼ��
            //int max_c=0;
            for(int j=i-1;j>=0;j--)//�ҵ�i��ש��������״̬
                if(a[j].a>a[i].a&&a[j].b>a[i].b&&dp[i]<dp[j]+a[i].c) //if(judge(a[j],a[i]) && dp[i] < dp[j] + 1)  dp[i] = dp[j] + 1; //����Ƕ������
                    dp[i]=dp[j]+a[i].c;

            //dp[i]+=max_c;//״̬ת�Ʒ��̵���ѧģ�ͺ�ʵ��ģ�ͣ��߼�������
            if(ans<dp[i]) ans=dp[i];//��ʱ��Ҫ�������ֵ����ʱ���ҵ����ֵ������ҪMax��ans
            /*
            //д��2����Ӧ����
            int max_c=0;
            for(int j=i-1;j>=0;j--)//�ҵ�i��ש��������״̬
                if(a[j].a>a[i].a&&a[j].b>a[i].b&&dp[j]>max_c) //if(judge(a[j],a[i]) && dp[i] < dp[j] + 1)  dp[i] = dp[j] + 1; //����Ƕ������
                    max_c=dp[j];

            dp[i]+=max_c;//״̬ת�Ʒ��̵���ѧģ�ͺ�ʵ��ģ�ͣ��߼�������
            if(ans<dp[i]) ans=dp[i];//��ʱ��Ҫ�������ֵ����ʱ���ҵ����ֵ������ҪMax��ans
            */
        }
        cout<<"Case "<<Case++<<": maximum height = "<<ans<<endl;
    }
    return 0;
}

/*
https://blog.csdn.net/Patrickpwq/article/details/79845987
https://www.jianshu.com/p/9c4fc496e287 //����Ƕ������
*/
