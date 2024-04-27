#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solutuon{
    public:
        vector<int> intersection(vector<int>&nums1,vector<int>&nums2){
            unordered_set<int>result_set;
            unordered_set<int> nums_set(nums1.begin(),nums1.end());//q1:为什么要转换为unordered_set,而不是直接使用nums1,学习unordered_set的用法
            for(int num:nums2){//学习vector的遍历方法
                if(nums_set.find(num)!=nums_set.end()){
                    result_set.insert(num);
                }
            }
            return vector<int>(result_set.begin(),result_set.end());
        }
};

int main(){
    Solutuon solution;
    vector<int> nums1={1,2,2,1};
    vector<int> nums2={2,2};
    vector<int> result=solution.intersection(nums1,nums2);
    for(int num:result){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}