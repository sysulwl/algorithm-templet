#include <stdio.h>  
#include<iostream>  
using namespace std;  
long long a[1000010],b[1000010],ans;  
void merge(long long l,long long r)//排序函数   
{  
    long long mid=(l+r)/2,i=0,j=0,k=0;  
    while (k<=r-l)//循环k一次一定能保证下列两组的数刚好全部取出   
    {  
        if (l+i>mid) {b[k]=a[mid+1+j];j++;}//第一组的元素已全部取出，只能取第二组   
        else if (mid+1+j>r) {b[k]=a[l+i];i++;}// 第二组的元素已全部取出，只能取第一组  
        else  
        {  
            if (a[l+i]>a[mid+1+j]){
				b[k]=a[mid+1+j];
				j++;
				ans=ans+mid-l-i+1; //这个ans是逆序对的个数 
			}   
            else  {b[k]=a[l+i];i++;}//比较当前两个组中第一个元素的大小   
        }  
        k++;  
    }  
    for (i=l;i<=r;i++)  a[i]=b[i-l];  
}   
void mergesort(long long l,long long r)//分组函数   
{  
    if (l<r)  
    {  
        long long mid=(l+r)/2;  
        mergesort(l,mid);  
        mergesort(mid+1,r);//递归一直分组，合并；   
        merge(l,r);//这是最后一次合并   
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
            cout<<ans<<endl; //这个ans 求逆序对  
    }  
     
}  
