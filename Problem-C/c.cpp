#include<bits/stdc++.h>
typedef long long ll;
int a,b;
ll k=0,ans;
void work(int i) {
    ll p,A,B;
    p=(a-1)/i+1,A=p*i;
    p=(b-1)/i+1,B=p*i;
    ll w=A/std::__gcd(A,B)*B;
    if(w<ans) ans=w,k=A-a;
    else if(w==ans) k=std::min(k,A-a);
}
int main() {
    scanf("%d%d",&a,&b);
    if(a>b) std::swap(a,b);
    int c=b-a;
    ans=1ll*a*b/std::__gcd(a,b);
    for(int i=1; 1ll*i*i<=c; i++)
        if(c%i==0) {
            work(i);
            if(1ll*i*i!=c) work(c/i);
        }
    printf("%lld\n",k);
    return 0;
}
