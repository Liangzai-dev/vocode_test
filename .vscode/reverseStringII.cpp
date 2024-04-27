
//该题难点1：想到的通过字符串下标的方法来判断是否需要反转字符串，但是该方法适用于使用数组的情况，而不适用于使用字符串的情况
//这个题想到了利用i来做为判断的条件

//该题难点2：出现的情况比较多，但是只有三种情况，所以要想到这三种情况，然后分别处理就很麻烦，每次i+=2*k就很重要
#include<string>
#include<algorithm>
using namespace std;
#include<iostream>
string reverseStringII(string s,int k){
    for(int i=0;i<s.size();i+=2*k){
        if(i+k<=s.size()){
            //1、每计数2k个字符，就反转这2k个字符中的前k个字符
            //2、如果剩余字符大于等于k个但小于2k个，则将剩余字符中的前k个字符反转
            reverse(s.begin()+i,s.begin()+i+k);
        }else{
            //3、如果剩余字符少于k个，则将剩余字符全部反转
            reverse(s.begin()+i,s.end());
        }        
    }
    return s;
}

int main(){
    string firse_Name="cai";
    string last_Name="jiapeng";

    string s=reverseStringII(last_Name+firse_Name,2);

//核心就是这个运算符只是简单拼接起来，没有任何的运算，所以设置小数位数是没用的
    cout<<s<<endl;
}

