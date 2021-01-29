# B. Neko Performs Cat Furrier Transform

## Problem

- time limit per test: 1 seconds
- memory limit per test: 256 megabytes
- input: standard input
- output: standard output

Cat Furrier Transform is a popular algorithm among cat programmers to create longcats. As one of the greatest cat programmers ever exist, Neko wants to utilize this algorithm to create the perfect longcat.

Assume that we have a cat with a number 𝑥. A perfect longcat is a cat with a number equal 2<sup>𝑚</sup>−1 for some non-negative integer 𝑚. For example, the numbers 0, 1, 3, 7, 15 and so on are suitable for the perfect longcats.

In the Cat Furrier Transform, the following operations can be performed on 𝑥:

- (Operation A): you select any non-negative integer 𝑛 and replace 𝑥 with 𝑥⊕(2<sup>𝑛</sup>−1), with ⊕ being a [bitwise XOR operator](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).
- (Operation B): replace 𝑥 with 𝑥+1.
The first applied operation must be of type A, the second of type B, the third of type A again, and so on. Formally, if we number operations from one in the order they are executed, then odd-numbered operations must be of type A and the even-numbered operations must be of type B.

Neko wants to produce perfect longcats at industrial scale, thus for each cat Neko only wants to perform at most 40 operations. Can you help Neko writing a transformation plan?

Note that it is **not required** to minimize the number of operations. You just need to use no more than 40 operations.

### Input

The only line contains a single integer 𝑥 (1≤𝑥≤10<sup>6</sup>).

### Output

The first line should contain a single integer 𝑡 (0≤𝑡≤40) — the number of operations to apply.

Then for each odd-numbered operation print the corresponding number 𝑛<sub>𝑖</sub> in it. That is, print ⌈𝑡/2⌉ integers 𝑛<sub>𝑖</sub> (0≤𝑛<sub>𝑖</sub>≤30), denoting the replacement 𝑥 with 𝑥⊕(2<sup>𝑛<sub>𝑖</sub></sup>−1) in the corresponding step.

If there are multiple possible answers, you can print any of them. It is possible to show, that there is at least one answer in the constraints of this problem.


### Examples

input1:

```text
39
```

output1:

```text
4
5 3 
```

input2:

```text
1
```

output2:

```text
0
```

input3:

```text
7
```

output3:

```text
0
```

### Note

In the first test, one of the transforms might be as follows: 39→56→57→62→63. Or more precisely:

1. Pick 𝑛=5. 𝑥 is transformed into 39⊕31, or 56.
2. Increase 𝑥 by 1, changing its value to 57.
3. Pick 𝑛=3. 𝑥 is transformed into 57⊕7, or 62.
4. Increase 𝑥 by 1, changing its value to 63=2<sup>6</sup>−1.

In the second and third test, the number already satisfies the goal requirement.


## Solution

// To be updated

[Source Code](/Problem-B/b.cpp)

```cpp
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
```
