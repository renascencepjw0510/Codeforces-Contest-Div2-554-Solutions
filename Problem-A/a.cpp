#include<bits/stdc++.h>
typedef long long ll;
int main() {
    int n,m,x;
    scanf("%d%d",&n,&m);
    int cnta[2]= {0},cntb[2]= {0};
    for(int i=1; i<=n; ++i)scanf("%d",&x),++cnta[x&1];
    for(int i=1; i<=m; ++i)scanf("%d",&x),++cntb[x&1];
    printf("%d\n",std::min(cnta[0],cntb[1])+std::min(cnta[1],cntb[0]));
    return 0;
}
