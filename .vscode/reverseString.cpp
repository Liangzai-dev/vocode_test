#include <iostream>

using namespace std;
class Solution{
public:
    string reverseString(string s){
        int n=s.size();

        for (int i=0,j=s.size()-1;i<j;i++,j--){
            swap(s[i],s[j]);
        }
        return s;
    }
};

int main(){
    string s="hello";
    Solution sol;
    string reverse_s=sol.reverseString(s);
    cout<<reverse_s<<endl;
}