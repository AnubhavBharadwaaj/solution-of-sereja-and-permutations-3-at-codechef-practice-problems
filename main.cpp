#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fac(int a)
{
    int mul=1;
    for(int i=a;i>=1;i--)
    {
        mul=mul*a;
    }
    return mul;
}

int main()
{
    int i,t,count=0,q=0;
    cin>>t;
    int *head=new int[t+1];
    for(i=0;i<t;i++)
    {
        count=0;
        vector <int> v;
        int n,m,k=0,flag=0,crack=0;
        cin>>n>>m;
        for(int j=1;j<=n;j++)
        {
            v.push_back(j);
        }
        int *x=new int[m+1];
        int *val=new int[m+1];
        for(int j=0;j<m;j++)
        {
            cin>>x[j]>>val[j];
        }

        int c=fac(n);
        vector<int> v1[c+1];
        do
        {
            v1[k]=v;
            k++;
        }while(next_permutation(v.begin(),v.end()));
        if(m!=0)
        {
            for(int p=0;p<k;p++)
            {
                flag=0;
                for(int j=0;j<m;j++)
                {
                    for(int w=0;w<n;w++)
                    {
                        if(x[j]==(w+1)&&val[j]!=(v1[p])[w])
                        {
                            flag=1;
                        }
                    }
                }
                if(flag==0)
                {
                    for(int j=1;j<=n;j++)
                    {
                        int temp=(v1[p])[j-1];
                        for(int l=j+1;l<=n;l++)
                        {
                            if(temp>l&&(v1[p])[l-1]>j)
                            {
                                crack=1;
                            }
                        }
                    }
                }
                if(crack==1)
                {
                    count++;
                }
                crack=0;
            }
        }
        else{
        for(int p=0;p<k;p++)
        {
            for(int j=1;j<=n;j++)
            {
                int temp=(v1[p])[j-1];
                for(int l=j+1;l<=n;l++)
                {
                    if((v1[p])[l-1]>j&&temp>l)
                    {
                        crack=1;
                    }
                }
            }
            if(crack==1)
            {
                count++;
            }
            crack=0;
        }
        }
        head[q]=count;
        q++;
    }
    for(int j=0;j<q;j++)
    {
        cout<<(head[j]%2000000011)<<endl;
    }
    return 0;
}
