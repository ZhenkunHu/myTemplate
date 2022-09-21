#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;

struct BigInteger {
    static const int BASE=100000000;
    static const int WIDTH=8;
    vector<int> s;

    BigInteger(long long num=0) {*this=num;}//构造函数

    BigInteger operator=(long long num) {//赋值运算符
        s.clear();
        do {
            s.push_back(num%BASE);
            num/=BASE;
        }while(num>0);
        return *this;//或许是因为这是结构体，*this代表的是他自己
    }

    BigInteger operator=(const string& str) {//赋值运算符
        s.clear();
        int x,len=(str.length()-1)/WIDTH+1;//如何抵消/的影响，用-1之后+1//用一个公式统一了8的倍数和非倍数
        for(int i=0;i<len;i++) {
            int end=str.length()-i*WIDTH;//从尾部开始切割
            int start=max(0,end-WIDTH);
            sscanf(str.substr(start,end-start).c_str(),"%d",&x);//用sscanf()会去除前导0//c_str()把string转化为char字符串
            s.push_back(x);
        }
        return *this;
    }

    BigInteger operator+(const BigInteger& b) const {//把+放在类内可以减少写一个默认参数
        BigInteger c;
        c.s.clear();
        for(int i=0,g=0;;i++) {//终止条件太复杂了，所以写在了下面
            if(g==0&&i>=s.size()&&i>=b.s.size()) break;//无进位，两个BigInteger实例均已遍历完成//i>=size()与i>size()的区别，会不会有前导0
            int x=g;//进位全靠g
            if(i<s.size()) x+=s[i];
            if(i<b.s.size()) x+=b.s[i];
            c.s.push_back(x%BASE);//依然是低位在前面，类比芯片级联，算法层次果然高
            g=x/BASE;//新的进位
        }
        return c;
    }


    BigInteger operator-(const BigInteger& b) const {//仿照加法写的减法，需要注意的是只需在最前面加负号
        BigInteger c;
        c.s.clear();
        int MAX=max(s.size(),b.s.size());
        for(int i=0,g=0;;i++) {
            if(g==0&&i>=MAX)
                break;
            int x=g;
            if(i<s.size())
                x+=s[i];
            if(i<b.s.size())
                x-=b.s[i];

            if(i==MAX-1)
                c.s.push_back(x%BASE);//保证了输出时有-号
            else
                c.s.push_back(abs(x%BASE));

            g=x/BASE;
         }
        return c;
    }

    bool operator<(const BigInteger& b) const {
        if(s.size()!=b.s.size()) return s.size()<b.s.size();//如果位数不等
        for(int i=s.size()-1;i>=0;i--)//如果位数相等，因为低位在vetor的前面
            if(s[i]!=b.s[i]) return s[i]<b.s[i];
        return false;//相等
    }
    bool operator>(const BigInteger& b) const {return b<*this;}
    bool operator<=(const BigInteger& b) const {return !(b<*this);}
    bool operator>=(const BigInteger& b) const {return !(*this<b);}
    bool operator!=(const BigInteger& b) const {return b<*this||*this<b;}
    bool operator==(const BigInteger& b) const {return !(b<*this)&&!(*this<b);}
};

ostream& operator<<(ostream &out,const BigInteger& x) {//运算符的参数(cout)(<<)(BigInteger)//与一般函数的参数
    out<<x.s.back();//去掉了最高位的前导0
    for(int i=x.s.size()-2;i>=0;i--) {
        char buf[20];//默认小于20位，实际上最大就8位
        sprintf(buf,"%08d",x.s[i]);//因为sscanf()去掉了前导0，用%08加上去
        for(int j=0;j<strlen(buf);j++) out<<buf[j];
    }
    return out;
}

istream& operator>>(istream& in,BigInteger& x) {
    string s;
    if(!(in>>s)) return in;
    x=s;//因为BigInteger有字符串的构造函数
    return in;
}

int main() {
    BigInteger y=122;
    BigInteger x=y;
    BigInteger z=123;

    BigInteger a,b;
    cin>>a>>b;
    cout<<a+b<<endl;
    cout<<x-z<<endl;
    cout<<BigInteger::BASE<<endl;

    if(z>x) cout<<z<<">"<<x<<endl;
    return 0;
}
