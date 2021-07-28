#include<iostream>
#include<vector>

using namespace std;
vector<int>ans;

void non_fibo(int current_fibo,int next_fibo,int current_non_fibo,int target_size)
{

    // Boundary Condition for the Recursion to stop when the list_size has been fulfilled
    if(target_size==ans.size())
    return;

    // If current_non_fibo becomes equal to the next fibo, then we call the function by replacing the current_fibo with next_fibo and next_fibo is replaced by (current_fibo+next_fibo)
    if(next_fibo==current_non_fibo)
    {
        non_fibo(next_fibo,current_fibo+next_fibo,next_fibo+1,target_size);
    }

    // The Required Non-Fibo Number is pushed to the answer list and then function is called with [(current_non_fibo)+1] in place of current_non_fibo
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