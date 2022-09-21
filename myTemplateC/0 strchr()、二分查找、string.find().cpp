#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;

int zilie(string s,string ss)//子列模板//自己写的模式匹配不如课本上的具有一般性
{
	for(int i=0;i<ss.length();i++)
	{
		if(s[0]==ss[i])
		{
			int j=1;
			for(;j<s.length();j++)
			{
				if(s[j]!=ss[i+j]) break;
			}
			if(j==s.length()) return 1;
			else return 0;
		}
	}
	return 0;
}

int main()
{
    char s[100]="(11,ll)";
	int v;
	sscanf(&s[1],"%d",&v);
	cout<<v<<endl;
	cout<<strchr(s,',')+1<<endl;
	int z[10];
	for(int i=0;i<10;i++)
	    cin>>z[i];
	////////////////////////////////////////////////////////
	cout<<lower_bound(z,z+10,1)+2<<endl;
	cout<<upper_bound(z,z+5,1)+1<<endl;
	if(binary_search(z,z+5,1)) cout<<"find it."<<endl;
	//////////////////////////////////////////////////////////
	string name("Annaqijiashe");//子列模板
    int pos=name.find("Anna");
	if(pos==string::npos)
	cout<<"Anna not found!\n";
	else  cout<<"Anna found at pos:"<<pos<<endl;
    return 0;
}
