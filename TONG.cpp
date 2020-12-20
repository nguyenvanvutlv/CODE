#include<bits/stdc++.h>
using namespace std;
int chuyenChuSangSo(char AB)
{
    return (int)(AB-'0');
}
int main()
{
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string A,B,C;
    int dem = 0;
    cin>>A>>B;

    if(A.size()<B.size())
    {
        swap(A,B);
    }
    long long Tong = A.size()-B.size();
    for(long long i = 0; i<Tong; i++)
    {
        B.insert(0,1,'0');
    }

    for(long long i = A.size()-1; i>=0; i--)
    {
        int du = chuyenChuSangSo(A[i])+chuyenChuSangSo(B[i])+dem;
        if(du<10)
        {
            C.insert(0,1,(char)(du+'0'));
            dem = 0;
        }
        else if(du>=10)
        {
            du-=10;
            C.insert(0,1,(char)(du+'0'));
            dem = 1;
        }
    }
    if(dem == 1) C.insert(0,1,'1');
    cout<<C;



}


