#include <stdio.h>  
#include<iostream>  
using namespace std;  
long long a[1000010],b[1000010],ans;  
void merge(long long l,long long r)//������   
{  
    long long mid=(l+r)/2,i=0,j=0,k=0;  
    while (k<=r-l)//ѭ��kһ��һ���ܱ�֤������������պ�ȫ��ȡ��   
    {  
        if (l+i>mid) {b[k]=a[mid+1+j];j++;}//��һ���Ԫ����ȫ��ȡ����ֻ��ȡ�ڶ���   
        else if (mid+1+j>r) {b[k]=a[l+i];i++;}// �ڶ����Ԫ����ȫ��ȡ����ֻ��ȡ��һ��  
        else  
        {  
            if (a[l+i]>a[mid+1+j]){
				b[k]=a[mid+1+j];
				j++;
				ans=ans+mid-l-i+1; //���ans������Եĸ��� 
			}   
            else  {b[k]=a[l+i];i++;}//�Ƚϵ�ǰ�������е�һ��Ԫ�صĴ�С   
        }  
        k++;  
    }  
    for (i=l;i<=r;i++)  a[i]=b[i-l];  
}   
void mergesort(long long l,long long r)//���麯��   
{  
    if (l<r)  
    {  
        long long mid=(l+r)/2;  
        mergesort(l,mid);  
        mergesort(mid+1,r);//�ݹ�һֱ���飬�ϲ���   
        merge(l,r);//�������һ�κϲ�   
    }  
}  
int main()  
{  
    long long i,n;  
    while(scanf("%lld",&n)!=EOF)  
    {   
            ans=0;  
            for (i=0;i<n;i++)  
            scanf("%lld",&a[i]);  
            mergesort(0,n-1);  
            cout<<ans<<endl; //���ans �������  
    }  
     
}  
