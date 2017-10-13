struct myPoint{
	int x,y;
};
class Flood {
	bool vis[105][105];
	int dir[8]={-1,0,1,0,0,1,0,-1};
	bool raw(int x,int y,int n,int m,vector<vector<int> > map){
		if(0 <= x && x < n && 0 <= y && y < m && map[x][y] == 0 && !vis[x][y])
			return true;
		return false;
	}
public:
    int floodFill(vector<vector<int> > map, int n, int m) {
        memset(vis,0,sizeof(vis));
        int ans = 0;
        int t = 0;
        bool flag = false;
        myPoint temp;
        temp.x = 0 ; temp.y = 0;
        queue<myPoint> que1;
        que1.push(temp);
        vis[0][0] = 1;
        while( !que1.empty() && !flag)
        {
            stack<myPoint> sta;
        	t++;
            while(!que1.empty())
            {
                for(int i = 0 ; i < 7 ; i += 2) //四个方向
                {
        			int tempx = que1.front().x + dir[i];
        			int tempy = que1.front().y + dir[i+1];
        			if(raw(tempx,tempy,n,m,map))
              	    { //这是个合法，可以流动的矩阵点
                       
                        vis[tempx][tempy] = 1;
        				if(tempx == n - 1 && tempy == m - 1)
                        {
        					ans = t;
                            flag = true; 
        				}
        				myPoint x1; 
                        x1.x = tempx;
                        x1.y = tempy;
        				sta.push(x1); //下次搜索的节点先全部压入栈中
        			}
				}
                que1.pop();
        	}
            while(!sta.empty()){//栈中的节点全部放回队列中
                que1.push(sta.top());
                sta.pop();
            }
        }
        return t;
    }
};
