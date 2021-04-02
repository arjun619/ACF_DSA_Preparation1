#include <bits/stdc++.h>

using namespace std;
void printer(vector<int>arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n\n";
}
int find_area(vector<int>arr)
{
    //printer(arr);
    vector<int>nsr;
    vector<int>nsl;
    //int flag=0,flag1=0;
    vector<int>flag={0,0,0,0};
    vector<int>flag1={0,0,0,0};
    int indx;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i;j<arr.size();j++)
        {
            if (arr[i]>arr[j])
            {
                //flag=1;
                flag[i]=1;
                indx=j;
                break;
                //nsr.push_back(j);
            }

        }
         if (flag[i]==1)nsr.push_back(indx);
            else
            {
                nsr.push_back(arr.size()-1);
                //flag.push_back(0);
            }
    }
    for(int i=arr.size()-1;i>-1;i--)
    {
        for(int j=i;j>-1;j--)
        {
            if (arr[i]>arr[j])
            {
                //flag1=1;
                flag1[i]=1;
                indx=j;
                break;
                //nsl.push_back(j);
            }

        }
        if (flag1[i]==1)nsl.push_back(indx);
            else
            {
                nsl.push_back(0);
                //flag1.push_back(0);
            }
    }
    //printer(nsr);
    //printer(nsl);
    int maxarea=-1;
    printer(nsr);
    printer(nsl);
    for(int i=0;i<nsr.size();i++)
    {
        int length=arr[i];
        int temp1,temp2;
        if (flag[i]==1)temp1=nsr[i]-1;
        else
            temp1=nsr[i];
        if (flag1[i]==1)temp2=nsl[i]+1;
        else
            temp2=nsl[i];
        int width=temp1-temp2+1;
        if (length*width>maxarea)
            maxarea=length*width;
    }
    cout<<maxarea<<"\n";
    return maxarea;
}
int maxrectange(vector<vector<int>>arr)
{
    int n=arr.size();
    int m=arr[0].size();
    vector<int>temp(m,0);
    int maxarea=-1,cur_area=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if (arr[i][j]!=0)
                temp[j]+=arr[i][j];
            else
                temp[j]=0;
        }
        cur_area=find_area(temp);
        if (maxarea<cur_area)
            maxarea=cur_area;
    }
    return maxarea;

}
int main()
{
    vector<vector<int>>arr
    {
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1}
    };
    cout<<maxrectange(arr);
}

