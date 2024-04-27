#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution{
    public:
    vector<vector<int>> foursum(vector<int>&nums,int target){
        vector<vector<int>>result;
        #include<algorithm> // Include the <algorithm> header for the sort function

        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            //剪枝处理
            if(nums[i]>target && nums[i]>0) break;;
            //对nums[i]去重
            if(i>0 && nums[i]==nums[i-1] ) continue;
            for(int j=i+1;j<nums.size();j++){
                //二级剪枝处理
                if(nums[i]+nums[j]>target && nums[i]+nums[j]>0) break;
                int left=j+1;
                int right=nums.size()-1;
                if(j>i+1 && nums[j]==nums[j-1]) continue;//对nums[j]去重
                while(left<right){
                    
                    if((long)nums[i]+nums[j]+nums[left]+nums[right]>target){
                        right--;
                    }else if((long)nums[i]+nums[j]+nums[left]+nums[right]<target){
                        left++;
                    }else{
                        result.push_back({nums[i],nums[j],nums[left],nums[right]});
                        //对nums[left]和nums[right]去重
                        while(left<right && nums[left]==nums[left+1]) left++;
                        while(left<right && nums[right]==nums[right-1]) right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int>nums={1,0,-1,0,-2,2};
    vector<vector<int>>ans=s.foursum(nums,0);
    for(auto v:ans){
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}