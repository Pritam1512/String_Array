#include<bits/stdc++.h>
using namespace std;

int checkPall(string str,int i,int j)
{
    if(i<j)
    {

        if(str[i] != str[j])
            return 0;
        checkPall(str,i+1,j-1);
    }
    return 1;
}

int main()
{
    string str;
    cin >> str;
    int n = str.length();
    cout << checkPall(str,0,n-1);
}
