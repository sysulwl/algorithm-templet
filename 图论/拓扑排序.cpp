/*˼·����������
 �� STL �� set ���������Ϊ��Ľ�����Ա�֤ set ��ͷԪ��һ������С�ģ�Ȼ��Ѹý��ɾ�������������Ϊ��Ľ�㡣������queue��
����Ҳ������priority_queue<int, vector<int>, greater<int> > que;
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
int indeg[100001]; //��� 
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
            g[u].push_back(v); //u��v�б� 
            indeg[v]++;
        }
        for(int i = 1; i <= n; i++)
        {
            if(indeg[i] == 0)
            {
                s.insert(i);//set�Ĳ���
            }
        }
        while(!s.empty())
        {
            int u = *s.begin();//set��ȡֵ��
            printf("%d ", u);
            s.erase(s.begin());//ɾ����
            for(unsigned i = 0; i < g[u].size(); i++)
            {
                if(--indeg[g[u][i]] == 0)
                    s.insert(g[u][i]);
            }
        }
        printf("\n");
    }
}                 
