/* luoguP1908 */
/** 分治（归并排序） **/
/**
 *n个数，n<=5e5，每个数<=1e9
 *输出逆序对个数
 *归并排序，复杂度O(NlogN)
 **/
#include<cstdio>
using namespace std;
const int N=5e5;
int a[N+10],t[N+10];
int n;
long long ans;
template<class T>
void read(T& x){
    x=0;
    int f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    x*=f;
}
void merge_sort(int* x,int* y,int l,int r)
{
    if(l+1>=r) return;
    int m=l+((r-l)>>1),p=l,q=m,i=l;
    merge_sort(x,y,l,m);
    merge_sort(x,y,m,r);
    while(p<m||q<r)
        if(q>=r||(p<m&&x[p]<=x[q]))
            t[i++]=a[p++];
        else t[i++]=a[q++],ans+=m-p;
        //根据递归，左边的已经是有序序列，p之后的都与右边构成逆序对
    for(i=l;i<r;i++)
        a[i]=t[i];
}
int main()
{
    read(n);
    for(int i=0;i<n;i++)
        read(a[i]);
    merge_sort(a,t,0,n);
    printf("%lld",ans);
    return 0;
}
