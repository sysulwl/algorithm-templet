#include <stdio.h>
void swap(int a[], int i, int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}
int partition(int a[], int p, int r)
{
    int i = p;
    int j = r + 1;
    int x = a[p];
    while(1){
        while(i<r && a[++i]<x);
        while(a[--j]>x);
        if(i>=j) break;
        swap(a,i,j);
    }
    swap(a,p,j);//此处需要填写一句代码 
    return j;
}
void quicksort(int a[], int p, int r)
{
    if(p<r) //递归终止的条件 
{
        int q = partition(a,p,r); //q is a index , find q to do partition
        quicksort(a,p,q-1);  //left
        quicksort(a,q+1,r);  //right
    }
}  
int main()
{
    int i;
    int a[] = {5,13,6,24,2,8,19,27,6,12,1,17};
    int N = 12;
    quicksort(a, 0, N-1); //sort 
    for(i=0; i<N; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
