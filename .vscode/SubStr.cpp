/*使用i遍历文本串，j遍历模式串，其中i为文本串的下标，j为模式串的下标
核心思想：TEXT串中的i指针不回溯，j指针会根据next数组的值回溯。
回溯多少？因为next数组存储的是模式串中前缀和后缀相同的最大长度
例如模式串abcabd,当与TEXT串匹配时发现"d"与TEXT串中的字符不匹配，即当前 后缀"ab"的后一个字符与TEXT串中的字符不匹配，
那么模式串指针需要回溯到当前相对于前缀"ab"的后一个字符，即next[j]的位置，然后再与TEXT串中的字符比较*/

#include<iostream>
#include<string>
using namespace std;

//
void getNext(int *next,const string &s){
    //1、初始化
    int j=-1;
    next[0]=j;

    for(int i=1;i<s.size();i++){
        /*2、若遇到不匹配的字符，即TEXT串的字符和PATTERN串的字符不相等时，
        需要找到PATTERN串前一个字符的next值，即next[j]，将j回溯到next[j]，然后比较TEXT串中i指针和
        PATTERN串中next[j]位置的字符是否相等，相等就将j++的值赋给next[i]*/
        while(j>=0 && s[i]!=s[j+1]){
            j=next[j];
        }

        //3、处理前后缀相同的情况
        if(s[i]==s[j+1]){
            j++;
        }
        next[i]=j;
    }
}

int strStr(string haystack,string needle){
    
}


