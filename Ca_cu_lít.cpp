/*--toilavu--*/
#include <iostream>
// calulation
#include <time.h>
using namespace std;
inline string Pow(string A,int n){
    string save;
    while(n > 0){
        save.insert(0,1,(char)((n%10) +'0'));
        n/=10;
    }
    int cnt[A.size()+save.size()] ={},dem =1;
    for(int i = 0;i<save.size();i++){
        int ans = dem;
        for(int j = 0;j<A.size();j++){
            cnt[ans]+= (int)(save[i]-'0')*(int)(A[j]-'0');
            ans++;
        }
        dem++;
    }
    //for(int i =0 ;i<A.size()+save.size();i++) cout <<cnt[i] << " ";
    for(int i = A.size()+save.size()-1;i>0;i--){
        int dp = cnt[i] % 10;
        cnt[i-1] += cnt[i] / 10;
        cnt[i] = dp;
    }

   // for(int i =0 ;i<A.size()+save.size();i++) cout <<cnt[i] << " ";
   string SS;
   if(cnt[0] != 0) SS = (char)(cnt[0] +'0');
   for(int i = 1;i<A.size()+save.size();i++){
       SS+=(char)(cnt[i] +'0');
   }
    return SS;
}
int main()
{   
    clock_t start,end;
    double duration;
    start = clock();
    string S = "1";
    for(int i = 1;i<=100000;i++) {
        S = Pow(S,i);
    }
   cout << "1000! = "<<S;
   
    end = clock();
    duration = ((double)(end-start)) / CLOCKS_PER_SEC;
    cout << endl<<"s : "<<duration;
}
