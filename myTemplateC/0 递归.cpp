//�ݹ飬���߼��Ͽ����������Ͽ�
#include<Stdio.h>
void fun(int n)
{
    if (n==1)
    {
        putchar('A');
        return;
    }
    fun(n-1);
    putchar('A'+n-1);
    fun(n-1);
}
int main()
{
    int n;
    scanf("%d", &n);
    if (n<1) return -1;
    fun(n);
    printf("\n");
    return 0;
}
