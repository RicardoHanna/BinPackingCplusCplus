#include <iostream>
#include <vector>
#include <stack>
#include <functional>
#include <algorithm>
using namespace std;

typedef  stack<float>s;
int binPacking(vector<float>&v,vector<s>&s){
int c=0;
s.assign(v.size(),stack<float>());
float size;
for(int j=0;j<s.size();j++)
    s[j].push(1.0);

    for(int i=0;i<v.size();i++){
        for(int j=0;j<s.size();j++){
            if(s[j].top()>v[i]){
                size=s[j].top()-v[i];
                s[j].pop();
                s[j].push(v[i]);
                s[j].push(size);
                break;
            }
        }
    }

    for(int j=0;j<s.size();j++)
        if(s[j].size()>1)
        c++;

    return c;
}

int offlineFirstFit(vector<float>&v,vector<s>&s){
int N;
sort(v.begin(),v.end(),greater<float>());
N=binPacking(v,s);
return N;
}

void display(vector<s>&s){
cout<<"Bin content,each starting with sum: "<<endl;
for(int k=0;k<s.size();k++){
    if(s[k].empty())
break;
cout<<"bin #"<<k<<": ";
cout<<s[k].top()<<"  -   ";
s[k].pop();
while(!s[k].empty()){
    cout<<s[k].top()<<" ";
    s[k].pop();
}
cout<<endl;
}

}

int main()
{
    float arr[]={0.2,0.5,0.4,0.7,0.1,0.3,0.8};
    int n=sizeof(arr)/sizeof(float);
    int sum;
    vector<float>v(arr,arr+n);
    int N;
    vector<s>s;
    N=binPacking(v,s);
    //N=offlineFirstFit(v,s);
    cout<<"N= "<<N<<endl;
    display(s);
    return 0;

}
