#include<bits/stdc++.h>
using namespace std; 
//链接：https://www.nowcoder.com/practice/840eee05dccd4ffd8f9433ce8085946b?tpId=8&tqId=11075&tPage=5&rp=5&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking
//来源：牛客网
/*
思路就是，（以第一行最为开始）先求第一行的最大和，然后将第二行数据加到第一行，
再求此时的最大值，然后再将下一行加上去，求最大值......最终得到第一列到最后一列的最大值；
还要计算第二行到最后一行的最大和，第三行到最后一行的最大和；
*/
class SubMatrix {
public:
	int sumOfSubMatrix(vector<vector<int> > mat, int n) {
		if(n<=0) return 0;
		int maxVal = 0xffffffff;
		for(int i=0;i<n;i++) //枚举矩阵起始行 
		{
			vector<int> temp(mat[i]);
			maxVal=max(maxVal,helper(temp));//得到第一行的最大和
			for(int j=i+1;j<n;j++)//循环下面的n-1行，枚举矩阵的结束行 
			{
				for(int k=0;k<n;k++)//将行的n个元素加到上一行，然后计算最大和
				{
					temp[k]+=mat[j][k];
				}
				maxVal=max(maxVal,helper(temp));//依次0~k行的最大和
			}
		}
		return maxVal;
	}

	//求连续数组最大和，动态规划思想
	int helper(vector<int>& vec)//求一维数组最大和
	{
		int f=vec[0];
		int result=f;
		for(int i=1;i<vec.size();i++)
		{
			f=max(f+vec[i],vec[i]);
			result=max(result,f);
		}
		return result;
	}
};

