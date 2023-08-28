/*Given a string str, a partitioning of the string is a palindrome partitioning
 if every sub-string of the partition is a palindrome. Determine the fewest cuts needed 
 for palindrome partitioning of the given string.
Example 1:

Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".
*/

#include <bits/stdc++.h>
using namespace std;

int static t[501][501];

class Solution{
public:

    bool isPalindrome(string s , int i ,int j){
        while(i<j){
            if(s[i] == s [j]){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }
    
    int solve( string s , int i , int j ){
        int mini = INT_MAX;
        if(i>=j){
            return  0;
        }   
        
        if(isPalindrome(s,i,j) == true){
            return t[i][j] = 0;
        }
        
        if(t[i][j]!=-1){
            return t[i][j];
        }
        int left,right;
        
        for(int k = i ; k<j ; k++){
            
            if(t[i][k]!=-1){
                left = t[i][k];
            }else{
                left = solve(s,i,k);
            }
            
            if(t[k+1][j]!=-1){
                right = t[k+1][j];
            }else{
                right = solve(s,k+1,j);
            }
            
            
            int temp = left + right +1;
            mini = min(mini , temp);
        }
        return t[i][j] = mini;
    }
    
    
    int palindromicPartition(string str)
    {
        memset(t,-1,sizeof(t));
        return solve(str,0,str.length()-1);
    }
    
};

int main(){ 
    string str;
    cin>>str;
    
    Solution ob;
    cout<<ob.palindromicPartition(str)<<"\n";

    return 0;
}
