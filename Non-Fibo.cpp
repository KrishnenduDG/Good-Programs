#include<iostream>
#include<vector>

using namespace std;
vector<int>ans;

void non_fibo(int current_fibo,int next_fibo,int current_non_fibo,int target_size)
{
    if(target_size==ans.size())
    return;

    if(next_fibo==current_non_fibo)
    {
        non_fibo(next_fibo,current_fibo+next_fibo,next_fibo+1,target_size);
    }

    else
    {
        ans.push_back(current_non_fibo);
        non_fibo(current_fibo,next_fibo,++current_non_fibo,target_size);
    }
}

int main()
{
    non_fibo(3,5,4,30);

    for(int i:ans)
    cout<<i<<" ";

    return 0;
}