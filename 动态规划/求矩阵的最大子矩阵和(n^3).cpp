#include<bits/stdc++.h>
using namespace std; 
//���ӣ�https://www.nowcoder.com/practice/840eee05dccd4ffd8f9433ce8085946b?tpId=8&tqId=11075&tPage=5&rp=5&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking
//��Դ��ţ����
/*
˼·���ǣ����Ե�һ����Ϊ��ʼ�������һ�е����ͣ�Ȼ�󽫵ڶ������ݼӵ���һ�У�
�����ʱ�����ֵ��Ȼ���ٽ���һ�м���ȥ�������ֵ......���յõ���һ�е����һ�е����ֵ��
��Ҫ����ڶ��е����һ�е����ͣ������е����һ�е����ͣ�
*/
class SubMatrix {
public:
	int sumOfSubMatrix(vector<vector<int> > mat, int n) {
		if(n<=0) return 0;
		int maxVal = 0xffffffff;
		for(int i=0;i<n;i++) //ö�پ�����ʼ�� 
		{
			vector<int> temp(mat[i]);
			maxVal=max(maxVal,helper(temp));//�õ���һ�е�����
			for(int j=i+1;j<n;j++)//ѭ�������n-1�У�ö�پ���Ľ����� 
			{
				for(int k=0;k<n;k++)//���е�n��Ԫ�ؼӵ���һ�У�Ȼ���������
				{
					temp[k]+=mat[j][k];
				}
				maxVal=max(maxVal,helper(temp));//����0~k�е�����
			}
		}
		return maxVal;
	}

	//�������������ͣ���̬�滮˼��
	int helper(vector<int>& vec)//��һά��������
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

