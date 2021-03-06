#include<bits/stdc++.h>
using namespace std;

vector<int> z_val(string &a){
    int n = a.size();
    vector<int> z(n,0);
    int L = 0, R = 0;
    for(int i = 0; i < n ; ++i){
        if(i > R){
            L = R = i;
            while(R < n && a[R-L] == a[R])R++;
            z[i] = R-L; R--;
        }else{
            int k = i-L;
            if(z[k] < R-i+1)z[i]=z[k];
            else{
                L=i;
                while(R < n && a[R-L] == a[R])R++;
                z[i] = R-L; R--;
            }
        }
    }
    return z;
}

int main(){
    string a;
    cin >> a;
    auto z = z_val(a);
    int ans = 0;
    int n = a.size(),maxz=0;
    for(int i = 0; i < n; ++i){
        if(z[i] <= ans)continue;
        if(maxz >= n-i && z[i] == n-i){
            // printf("index = %d, char = %c, z[i] = %d\n",i,a[i],z[i]);
            ans = n-i; break;
        }
        maxz = max(maxz,z[i]);
    }
    if(ans == 0)cout << "Just a legend";
    else for(int i = 0; i < ans; ++i)cout << a[i];
}