#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// already did this question in december
// used C at that time

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        long long n, k;
        scanf("%lld %lld", &n, &k);
        if(n<=k)
        {
            if(k%n==0)
                printf("%d\n", k/n);
            else printf("%d\n", (k/n)+1);
        }
        else
        {
            int x=n%k;
            if(x)
                x=k-(n%k);
            if(x%n==0)
                printf("%d\n", (x/n)+1);
            else
                printf("%d\n", (x/n)+2);
        }

    }
    return 0;
}
