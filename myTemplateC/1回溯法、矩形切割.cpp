#include<bits/stdc++.h>
using namespace std;

int Max;
void Count(int total,double Blong,double Bwide,double Slong,double Swide) {
    string mode1,mode2;
    //切割方式1：大矩形横向切割，小矩形纵向放置
    if(Blong>=Swide&&Bwide>=Slong) {
        total+=int(Blong/Swide);
        mode1=mode1+"1";
        Count(total,Blong,Bwide-Slong,Slong,Swide);
        total-=int(Blong/Swide);
        mode1=mode1.substr(0,mode1.size()-1);
    }
    else if(Max<total) {
        Max=total;
        mode2=mode1;
    }
    //切割方式2：大矩形横向切割，小矩形横向放置
    if(Blong>=Slong&&Bwide>=Swide) {
        total+=int(Blong/Slong);
        mode1=mode1+"2";
        Count(total,Blong,Bwide-Swide,Slong,Swide);
        total-=int(Blong/Slong);
        mode1=mode1.substr(0,mode1.size()-1);
    }
    else if(Max<total) {
        Max=total;
        mode2=mode1;
    }
    //切割方式3：大矩形纵向切割，小矩形纵向放置
    if(Blong>=Swide&&Bwide>=Slong) {
        total+=int(Bwide/Slong);
        mode1=mode1+"3";
        Count(total,Blong-Swide,Bwide,Slong,Swide);
        total-=int(Bwide/Slong);
        mode1=mode1.substr(0,mode1.size()-1);
    }
    else if(Max<total) {
        Max=total;
        mode2=mode1;
    }
    //切割方式4：大矩形纵向切割，小矩形横向放置
    if(Blong>=Slong&&Bwide>=Swide) {
        total+=int(Bwide/Swide);
        mode1=mode1+"4";
        Count(total,Blong-Slong,Bwide,Slong,Swide);
        total-=int(Bwide/Swide);
        mode1=mode1.substr(0,mode1.size()-1);
    }
    else if(Max<total) {
        Max=total;
        mode2=mode2;
    }
}

int main() {
    Max=-1;
    double Blong,Bwide,Slong,Swide;
    cout<<"请输入大矩形的长、宽和小矩形的长、宽："<<endl;
    cin>>Blong>>Bwide>>Slong>>Swide;
    Count(0,Blong,Bwide,Slong,Swide);
    cout<<"数量："<<Max<<" ";
cout<<"木板利用率："<<(Max*1.0*Slong*Swide)/(Blong*Bwide)<<endl;
    return 0;
}
