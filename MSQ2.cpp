/*SOLUTION: To solve this we need to first use a vector of size k and a temporary variable sum to 
check if the numbers form that sum, so first i have used a help function which has base conditions 
if sum is n and k is 0 it returns else it checks with all the possible combinations by putting those 
numbers and checking with n if it matches then we push back to our required vector<vector<int>> and
after calling the function we are popping back the ans because we are back tracking and evertime we 
push a vector in answer vector it should consist only one k sized number.

*/

class Solution {
public:
    void help(int ind,int sum,int n,vector<vector<int>>& res,vector<int>& ans,int k){
       if(sum==n && k==0){
           res.push_back(ans);
           return ;
       }
       if(sum>n) return;
       else{
           for(int i=ind;i<=9;i++)
           {
               if(i>n) break;
               ans.push_back(i);
               help(i+1,sum+i,n,res,ans,k-1);
               ans.pop_back();
           }
       }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<vector<int>> res;
       vector<int> ans;
       help(1,0,n,res,ans,k);
       return res;
    }
};