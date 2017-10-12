/*----------------------------������-----------------------------*/ 
#include<iostream> 
using namespace std;
class array {
    private:
    int elem[MAXN];
    public:
    int &operator[](int i) { return elem[i]; }
};
class heap {
    private:
    int n;
    array h;

    public:
    void clear() { n = 0; }
    int top() { return h[1]; }
    int size() { return n; }
    void push(int);
    void pop();
};

void heap::push(int num)
{
    n++;
    int k = n;
    h[k] = num;
    while (k > 1)
    {
        if (h[k] >= h[k / 2])
        return;
        else
        {
            swap(h[k], h[k / 2]);
            k /= 2;
        }
    }
}

void heap::pop()
{
    h[1] = h[n];
    n--;
    int k = 1;
    while (k < n)//kΪ�����±� 
    {
        if (k * 2 > n)  //  û���ӽڵ� 
            return;
        else if (k * 2 + 1 > n)  //û�����ӽڵ� 
        {
            if (h[k] > h[k * 2]) //˵�� k* 2==n��k�����ٴ����ˣ��Ѿ���ֹѭ�� 
                swap(h[k], h[k * 2]);
            else return; 
        }
        else
        {
            if (h[k] <= min(h[k * 2], h[k * 2 + 1]))//���϶ѵĹ��� 
                return;
            else
            {
                if (h[k * 2] < h[k * 2 + 1])
                    k = 2 * k;
                else
                    k = k * 2 + 1;
                swap(h[k], h[k / 2]);
            }
        }
    }
}                 
