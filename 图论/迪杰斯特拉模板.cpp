//�ڽӾ���Dijkstra,�ÿ�ʼѧ���ڽӱ�ķ�ʽ������Դ���·���� ���԰Ѹ��Ӷ���ߵ�O(ElgE)  
const int INF = 1000000;//�������ע�ⲻ��̫�󣬷����ڸ��½������п��ܲ������  
int G[205][205];//100�������ֻ��200�����  
int dis[205];  
bool flag[205];  
int t,road,d,n;  
string start,end;  
int dijkstra(int a,int b)//Dijkstra��������a��b�����·  
{  
    memset(flag,0,sizeof(flag));   //�Ƿ��ܵ��� 
    for(int i = 0;i < n;++i)  
        dis[i] = (i == a ? 0 : INF);//��ʼ��dis���飬���Ӧ��ʼ��Ϊ0��������Ϊ�����  
    for(int i = 0;i < n;++i)  
    {  
        int _min = INF,x = a;//�Ա�ű����ĳ�ʼ��Ӧ�������a  
        for(int y = 0;y < n;++y)  
        {  
            if(!flag[y] && dis[y] < _min)//��δ��Ž����ѡ��dis��С�Ľ��x  
            {  
                _min = dis[y];  
                x = y;  
            }  
        }  
        flag[x] = 1;//���x  
        for(int y = 0;y < n;++y)  
            dis[y] = min(dis[y],dis[x] + G[x][y]);//���´�x������������ľ���  
    }  
    if(flag[b])//����յ����б�Ž�㣬��֤��a�㵽b������ͨ��  
        return dis[b];//����disֵ  
    else return -1;  
}  
