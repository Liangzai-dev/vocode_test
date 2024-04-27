//问题1：构建哈希表的时候，为什么使用insert会报错
//问题2：哈希表中如何判断一个值是否在哈希表中
#include<vector>
#include<unordered_map>
using namespace std;
#include<iostream>

class Solution{
public:
    vector<int> twoSum(vector<int>&nums,int target){
        //创建一个哈希表，其中key是数组元素，value是数组元素的下标
        unordered_map<int,int>record;
        //遍历数组，对于每个元素nums[i],查找target-nums[i]是否在哈希表中
        for(int i=0;i<nums.size();i++){ 
            // if(record.find(target-nums[i])!=record.end()){
            //     return {record[target-nums[i]],i};//如果在返回两个元素的下标
            // }else{
            //     record[nums[i]]=i;//如果不在，将nums[i]插入哈希表
            // }

            //如果不在，将nums[i]插入哈希表
            if(record.find(target-nums[i])!=record.end()){
                return {record[target-nums[i]],i};
            }else{//如果在，返回两个元素的下标
                // record.insert(make_pair(nums[i],i));
                // record.insert(pair<int,int>(nums[i],i));
                record.insert({nums[i],i});
            }
        }
        return {}; // Add this line to fix the error
    }
};

int main(){
    vector<int>nums={2,5,11,15,7};
    int target=9;
    Solution s;
    vector<int>res=s.twoSum(nums,target);
    for(auto i:res){
        cout<<i<<endl;
    }
}


