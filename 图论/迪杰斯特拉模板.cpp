//邻接矩阵Dijkstra,得开始学用邻接表的方式来处理单源最短路问题 可以把复杂度提高到O(ElgE)  
const int INF = 1000000;//定义无穷，注意不能太大，否则在更新结点过程中可能产生溢出  
int G[205][205];//100条边最多只有200个结点  
int dis[205];  
bool flag[205];  
int t,road,d,n;  
string start,end;  
int dijkstra(int a,int b)//Dijkstra处理从起点a到b的最短路  
{  
    memset(flag,0,sizeof(flag));   //是否能到达 
    for(int i = 0;i < n;++i)  
        dis[i] = (i == a ? 0 : INF);//初始化dis数组，起点应初始化为0，其他点为无穷大  
    for(int i = 0;i < n;++i)  
    {  
        int _min = INF,x = a;//对标号变量的初始化应该是起点a  
        for(int y = 0;y < n;++y)  
        {  
            if(!flag[y] && dis[y] < _min)//从未标号结点中选出dis最小的结点x  
            {  
                _min = dis[y];  
                x = y;  
            }  
        }  
        flag[x] = 1;//标记x  
        for(int y = 0;y < n;++y)  
            dis[y] = min(dis[y],dis[x] + G[x][y]);//更新从x出发到其他点的距离  
    }  
    if(flag[b])//如果终点是有标号结点，则证明a点到b点是连通的  
        return dis[b];//返回dis值  
    else return -1;  
}  
