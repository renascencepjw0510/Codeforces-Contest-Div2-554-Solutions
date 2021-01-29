# C. Neko does Maths

## Problem

- time limit per test: 1 seconds
- memory limit per test: 256 megabytes
- input: standard input
- output: standard output

Neko loves divisors. During the latest number theory lesson, he got an interesting exercise from his math teacher.

Neko has two integers 𝑎 and 𝑏. His goal is to find a non-negative integer 𝑘 such that the least common multiple of 𝑎+𝑘 and 𝑏+𝑘 is the smallest possible. If there are multiple optimal integers 𝑘, he needs to choose the smallest one.

Given his mathematical talent, Neko had no trouble getting Wrong Answer on this problem. Can you help him solve it?

Input
The only line contains two integers 𝑎 and 𝑏 (1≤𝑎,𝑏≤10<sub>9</sub>).

Output
Print the smallest non-negative integer 𝑘 (𝑘≥0) such that the lowest common multiple of 𝑎+𝑘 and 𝑏+𝑘 is the smallest possible.

If there are many possible integers 𝑘 giving the same value of the least common multiple, print the smallest one.

### Examples

input1:

```text
6 10
```

output1:

```text
2
```

input2:

```text
21 31
```

output2:

```text
9
```

input3:

```text
5 10
```

output3:

```text
0
```

### Note

In the first test, one should choose 𝑘=2, as the least common multiple of 6+2 and 10+2 is 24, which is the smallest least common multiple possible.

## Solution

// To be updated

[Source Code](/Problem-C/c.cpp)

```cpp
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
```
