#include<math.h>

int NthRoot(int n, int m)
{
    // Write your code here.
    int l=1, r=(m)/2;
    int mid=-1;
    if(n==1) return m;
    if(m==1) return 1;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        double temp = pow(mid, n);
        // cout<<l<<" "<<mid<<" "<<r<<" "<<temp<<endl;
        if(temp==m) return mid;
        else if(temp>m) r=mid-1;
        else l=mid+1;
    }
    return -1;
}
