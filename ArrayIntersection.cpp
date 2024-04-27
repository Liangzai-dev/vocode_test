#include<vector>
#include<unordered_set>
using namespace std;
class Solution{
    public:
    vector<int> ArrayIntersection(vector<int>&nums1,vector<int> &nums2){
        unordered_set<int> result_set;
        unordered_set<int> nums_set(nums1.begin(),nums1.end());

        for(int num:nums2){
            if(nums_set.find(num)!=nums_set.end()){
                //查找以值为 key 的元素，如果找到，则返回一个指向该元素的正向迭代器；反之，则返回一个指向容器中最后一个元素之后位置的迭代器（如果 end() 方法返回的迭代器）。
                //nums_set.end()返回的是指向nums_set最后一个元素的下一个位置的迭代器
                //如果nums_set中存在num，那么nums_set.find(num)返回的是指向num的迭代器，肯定是和nums_set.end()不相等的，所以这里是!=
                //如果nums_set中不存在num，那么nums_set.find(num)返回的是nums_set.end()，这个时候nums_set.end()和nums_set.end()相等，所以这里是==               
                result_set.insert(num);               
            }
        }
        return vector<int> (result_set.begin(),result_set.end());
    }
};
//目标：学习vector和unordered_set的用法