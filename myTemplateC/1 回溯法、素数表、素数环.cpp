#include<bits/stdc++.h>
using namespace std;

int n,A[50],isp[50],vis[50];

int is_prime(int n)
{
	if(n<=1) return 0;
	int m=floor(sqrt(n)+0.5);
	for(int i=2;i<=m;i++)
	    if(n%i==0) return 0;
	return 1;
}

//������
void dfs(int cur) {
    if(cur==n&&isp[A[0]+A[n-1]]) {//�ݹ�߽硣�����˲��Ե�һ���������һ����
        for(int i=0;i<n;i++) printf("%d ",A[i]);//��ӡ����
        printf("\n");
    }
    else
        for(int i=2;i<=n;i++) {//���Է���ÿ����i
            if(!vis[i]&&isp[i+A[cur-1]]) {//���iû���ù���������ǰһ����֮��Ϊ����
                A[cur]=i;
                vis[i]=i;//����ʹ�ñ�־
                dfs(cur+1);
                vis[i]=0;//�����־
            }
        }
}

int main() {
    scanf("%d",&n);
    for(int i=2;i<=n*2;i++) isp[i]=is_prime(i);//�������������ٺ����ж�
    memset(vis,0,sizeof(vis));
    A[0]=1;//���ʱ������1��ʱ������//��Ϊ��A[0]��ʼ�������Ǵ�1��ʼ
    dfs(1);
    return 0;
}
