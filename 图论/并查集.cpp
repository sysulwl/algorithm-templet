/*---------------------------使用并查集，寻找无向图中的联通块-------------------------------*/ 
#include<iostream>
#include<cstdio> 
#include<queue>
using namespace std;
bool grap[1005][1005] = {0};
 int father[1005]={0}; //节点编号 
 int find(int x)
 {
    if(father[x] == x) return x;
    else return father[x] = find(father[x]) ;
 }
int main()
{
    int n , m;
    int x, y;
    cin>>n>>m;
    for(int i  = 1 ; i <= n ;i++)
    {
        father[i] = i; //初始化每个节点的祖先结点是他自己 
    } 
    while(m--)
    {
        scanf("%d%d",&x,&y);
        int a = find(x);
        int b = find(y);
        if(a!=b) father[a] = b;
    }
    //cout<<father[5]<<"  "<<find(5)<<endl;
    int is[1005]  = {0};
    for(int i = 1; i <= n ;i++)
    {
        //cout<<find(i)<<endl;
        is[find(i)]++;
    }
    int ans =  0;
    for(int i = 1 ; i <= n ;i++)
    {
        //cout<<is[i] <<endl;
        if(is[i] != 0) ans++;
    }
    cout<<ans<<endl;
}     
