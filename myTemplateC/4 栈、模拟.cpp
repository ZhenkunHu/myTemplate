#include <bits/stdc++.h>
using namespace std;

stack<string> st;
vector<string> v;

int main() {
    string line;
    bool f1 = true, f2=true;
    string res;
    while(getline(cin,line)) {
        if(line == ".") break;
        for(int i=0;i<line.size();i++) {
            if(line[i]=='(') {
                v.push_back("(");
            }
            else if(line[i]=='[') {
                v.push_back("[");
            }
            else if(line[i]=='{') {
                v.push_back("{");
            }
            else if(line[i]=='/' && i+1 < line.size() && line[i+1] == '*') {
                v.push_back("/*");
                i++;//因为存了两个
            }
            else if(line[i]==')') {
                v.push_back(")");
            }
            else if(line[i]==']') {
                v.push_back("]");
            }
            else if(line[i]=='}') {
                v.push_back("}");
            }
            else if(line[i]=='*' && i+1 < line.size() && line[i+1] == '/') {
                v.push_back("*/");
                i++;//因为存了两个
            }
        }
    }

    for(int i=0;i<v.size();i++) {
        if(v[i]=="(" || v[i]=="[" || v[i]=="{" || v[i]=="/*"){
            st.push(v[i]);
        }
        else if(v[i]==")") {
            if( !st.empty() && st.top()=="(") {
                st.pop();
            }
            else if(st.empty()) {
                f1 = false;
                res=v[i];
                break;
            }
            else {
                f2 = false;
                res=st.top();
                break;
            }
        }
        else if(v[i]=="]") {
            if( !st.empty() && st.top()=="[") {
                st.pop();
            }
            else if(st.empty()) {
                f1 = false;
                res=v[i];
                break;
            }
            else {
                f2 = false;
                res=st.top();
                break;
            }
        }
        else if(v[i]=="}") {
            if( !st.empty() && st.top()=="{") {
                st.pop();
            }
            else if(st.empty()) {
                f1 = false;
                res=v[i];
                break;
            }
            else {
                f2 = false;
                res=st.top();
                break;
            }
        }
        else if(v[i]=="*/") {
            if( !st.empty() && st.top()=="/*") {
                st.pop();
            }
            else if(st.empty()) {
                f1 = false;
                res=v[i];
                break;
            }
            else {
                f2 = false;
                res=st.top();
                break;
            }
        }
    }

    if(!f1) {
        cout<<"NO"<<endl;
        cout<<"?-"<<res<<endl;
    }
    else if(!f2) {
        cout<<"NO"<<endl;
        cout<<res<<"-?"<<endl;
    }
    else {//如果到最后才出错
        if(st.empty()) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
            cout<<st.top()<<"-?"<<endl;
        }
    }
    return 0;
}
