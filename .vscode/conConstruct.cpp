//1、如何遍历字符串，并将其字母映射到26个字母映射到0-25的数字上？
//2、如何判断记录结果的数组中是否有小于0的值？
#include <string>
#include<iostream>
using namespace std;

class Solution{
public:
    bool canConstruct(string ransomNote,string magazine){
        int record[26]={0};
        for(int i=0;i<magazine.size();i++){
            record[magazine[i]-'a']++;
        }

        //2、遍历ransomNote字符串，判断是否在magazine中出现
        for(int j=0;j<ransomNote.size();j++){
            record[ransomNote[j]-'a']--;

            //如果record中的值小于0，说明ransomNote中的某个字母出现的次数大于magazine中的次数
            if(record[ransomNote[j]-'a']<0){
                return false;
            }
        }
        return true;
    }
};

int main(){
    string ranSomNote="aasssdadss";

    string magazine="aabssadsasfasa";

    Solution s;
    bool res=s.canConstruct(ranSomNote,magazine);
    //使用cout打印两种结果
    //判断res的类型并打印结果
    res?cout<<"可以构造":cout<<"不能构造";    
}