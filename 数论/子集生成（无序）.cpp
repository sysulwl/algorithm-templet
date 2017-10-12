#include<iostream>
using namespace std;
const string x="xABCDEFGHIJKLMN";
bool is[15];
int n;
void dfs(int dep)
{
    if(dep==n)
    {
        for(int i=1;i<=n;i++)
        {
            if(is[i]) cout<<x[i];
        }
        cout<<endl;
    }
    else
    {
        is[dep+1]=1;
        dfs(dep+1);
        is[dep+1]=0;
        dfs(dep+1); 
    }
} 
int main()
{
    
    cin>>n;
    if(n != 0)  
    {
        dfs(0);
    }
}    
