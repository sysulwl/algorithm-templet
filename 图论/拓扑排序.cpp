/*思路：拓扑排序
 用 STL 的 set ，插入入度为零的结点后可以保证 set 的头元素一定是最小的，然后把该结点删掉继续插入入度为零的结点。不能用queue。
或者也可以用priority_queue<int, vector<int>, greater<int> > que;
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
vector<int> g[100001];
set<int> s;
int indeg[100001]; //入度 
int n, m;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        memset(g, 0, sizeof(g));
        memset(indeg, 0, sizeof(indeg));
        int u, v;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            g[u].push_back(v); //u到v有边 
            indeg[v]++;
        }
        for(int i = 1; i <= n; i++)
        {
            if(indeg[i] == 0)
            {
                s.insert(i);//set的插入
            }
        }
        while(!s.empty())
        {
            int u = *s.begin();//set的取值。
            printf("%d ", u);
            s.erase(s.begin());//删除。
            for(unsigned i = 0; i < g[u].size(); i++)
            {
                if(--indeg[g[u][i]] == 0)
                    s.insert(g[u][i]);
            }
        }
        printf("\n");
    }
}                 
