#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>

using namespace std;

// DID THIS IN DECEMBER

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1]={};
        for(int i=0;i<2*(n-1);i++)
        {
            int temp;
            cin>>temp;
            arr[temp]++;
        }
        int ans=1;
        for(int i=0;i<n+1;i++)
        {
            if(arr[i]>2)
            {
                ans+=arr[i]-2;
            }
        }
        // for(int i=0;i<n+1;i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
        ans=ans-(ans-1)/2;
        cout<<ans<<endl;
    }
    return 0;
}
