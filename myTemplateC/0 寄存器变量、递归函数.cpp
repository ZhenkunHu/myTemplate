int fac(int x) {
    register int i,f=1;  //定义寄存器变量
    for(i=1;i<=x;i++)
        f*=i;
    return f;
}

int fac(int x) {  //递归函数
    int f;
    if(x==0 || x==1)
        f=1;
    else
        f=fac(x-1)*x;
    return f;
}
