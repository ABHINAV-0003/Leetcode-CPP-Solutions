#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int sol=0;
        int end=0;
        int farthest=0;
        for(int i=0;i<n-1;i++){
            farthest=max(farthest,i+nums[i]);
            if(farthest>=n-1){
                sol++;
                break;
            }
            if(end==i){
                sol++;
                end=farthest;
            }
        }
        return sol;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<Solution().jump(v);
    return 0;
}