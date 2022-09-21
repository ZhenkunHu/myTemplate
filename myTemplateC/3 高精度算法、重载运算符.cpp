#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;

struct BigInteger {
    static const int BASE=100000000;
    static const int WIDTH=8;
    vector<int> s;

    BigInteger(long long num=0) {*this=num;}//���캯��

    BigInteger operator=(long long num) {//��ֵ�����
        s.clear();
        do {
            s.push_back(num%BASE);
            num/=BASE;
        }while(num>0);
        return *this;//��������Ϊ���ǽṹ�壬*this����������Լ�
    }

    BigInteger operator=(const string& str) {//��ֵ�����
        s.clear();
        int x,len=(str.length()-1)/WIDTH+1;//��ε���/��Ӱ�죬��-1֮��+1//��һ����ʽͳһ��8�ı����ͷǱ���
        for(int i=0;i<len;i++) {
            int end=str.length()-i*WIDTH;//��β����ʼ�и�
            int start=max(0,end-WIDTH);
            sscanf(str.substr(start,end-start).c_str(),"%d",&x);//��sscanf()��ȥ��ǰ��0//c_str()��stringת��Ϊchar�ַ���
            s.push_back(x);
        }
        return *this;
    }

    BigInteger operator+(const BigInteger& b) const {//��+�������ڿ��Լ���дһ��Ĭ�ϲ���
        BigInteger c;
        c.s.clear();
        for(int i=0,g=0;;i++) {//��ֹ����̫�����ˣ�����д��������
            if(g==0&&i>=s.size()&&i>=b.s.size()) break;//�޽�λ������BigIntegerʵ�����ѱ������//i>=size()��i>size()�����𣬻᲻����ǰ��0
            int x=g;//��λȫ��g
            if(i<s.size()) x+=s[i];
            if(i<b.s.size()) x+=b.s[i];
            c.s.push_back(x%BASE);//��Ȼ�ǵ�λ��ǰ�棬���оƬ�������㷨��ι�Ȼ��
            g=x/BASE;//�µĽ�λ
        }
        return c;
    }


    BigInteger operator-(const BigInteger& b) const {//���ռӷ�д�ļ�������Ҫע�����ֻ������ǰ��Ӹ���
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
                c.s.push_back(x%BASE);//��֤�����ʱ��-��
            else
                c.s.push_back(abs(x%BASE));

            g=x/BASE;
         }
        return c;
    }

    bool operator<(const BigInteger& b) const {
        if(s.size()!=b.s.size()) return s.size()<b.s.size();//���λ������
        for(int i=s.size()-1;i>=0;i--)//���λ����ȣ���Ϊ��λ��vetor��ǰ��
            if(s[i]!=b.s[i]) return s[i]<b.s[i];
        return false;//���
    }
    bool operator>(const BigInteger& b) const {return b<*this;}
    bool operator<=(const BigInteger& b) const {return !(b<*this);}
    bool operator>=(const BigInteger& b) const {return !(*this<b);}
    bool operator!=(const BigInteger& b) const {return b<*this||*this<b;}
    bool operator==(const BigInteger& b) const {return !(b<*this)&&!(*this<b);}
};

ostream& operator<<(ostream &out,const BigInteger& x) {//������Ĳ���(cout)(<<)(BigInteger)//��һ�㺯���Ĳ���
    out<<x.s.back();//ȥ�������λ��ǰ��0
    for(int i=x.s.size()-2;i>=0;i--) {
        char buf[20];//Ĭ��С��20λ��ʵ��������8λ
        sprintf(buf,"%08d",x.s[i]);//��Ϊsscanf()ȥ����ǰ��0����%08����ȥ
        for(int j=0;j<strlen(buf);j++) out<<buf[j];
    }
    return out;
}

istream& operator>>(istream& in,BigInteger& x) {
    string s;
    if(!(in>>s)) return in;
    x=s;//��ΪBigInteger���ַ����Ĺ��캯��
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
