/*
一维-0，1背包问题 
题目:p1014 装箱问题
出处： http://codevs.cn/problem/1014/ 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxN = 32;
const int maxV = 20002;
int dp[maxV];
int v,n;
int w[maxN];
int main()
{
	while(cin>>v>>n)
	{
		memset(dp,0,sizeof(dp));
		for(int i = 1; i <= n ; i++) cin>>w[i];
		for(int i = 1; i <= n ;i++)
		{
			for(int j = v ; j >= 0; j--)
			{
				if(j >= w[i] && dp[j] < dp[j-w[i]] + w[i]) 
				dp[j] = dp[j-w[i]] + w[i];
			}
		} 
		cout<<v-dp[v]<<endl;
	}
} 
