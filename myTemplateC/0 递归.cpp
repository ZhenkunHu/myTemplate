//递归，从逻辑上看，从物理上看
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
