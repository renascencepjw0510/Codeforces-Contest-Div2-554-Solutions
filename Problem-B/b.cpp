#include<bits/stdc++.h>
typedef long long ll;

int main() {
    int x;
    scanf("%d",&x);
    std::vector<int> ans;
    if(!(x&1)) ans.push_back(0),++x;
    int mx=19;
    for(int i=19; ~i; i--) if(x>>i&1) {
            mx=i;
            break;
        }
    for(int i=mx; ~i; i--) {
        if(!(x>>i&1)) ans.push_back(i+1),x^=(1<<i+1)-1,++x;
    }
    printf("%d\n",ans.size()<<1);
    for(auto x:ans) printf("%d ",x);
    return 0;
}
