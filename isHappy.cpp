//知识点1：如何获取一个数的各个位数
//知识点2：知道什么情况下需要哈希表，本题一个关键点在于sum会多次出现，需要判断是否陷入循环
#include<iostream>
#include<unordered_set>
using namespace std;
class Solution{
    public:
    int getSum(int n){
        int sum=0;
        while(n){            
            //计算数值n的各个位数的平方和
            //1、计算n的各个位数
            sum+=(n%10)*(n%10);
            n=n/10;
        }
        return sum;
    }

    bool isHappy(int n){
        unordered_set<int> record;
        while(1){
            int sum=getSum(n);
            cout<<sum<<endl;
            if(sum==1){
                cout<<"该数是快乐数！"<<endl;
                return true;
            }//使用哈希表来存储出现过的sum，如果sum重复出现，则说明陷入了循环
            else if(record.find(sum)!=record.end()){
                cout<<"该数不是快乐数！"<<endl;
                return false;
            }else {
                record.insert(sum);
                n=sum;
            }
        }
    }
};

int main(){
    int num=565484866;
    Solution s;
    cout<<s.isHappy(num)<<endl;

}