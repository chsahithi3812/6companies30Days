class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        if(n<=2){
           if(n==1) return 0;
           else return  *max_element(nums.begin(),nums.end()); 
        }
        int sum = 0, F = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += i * nums[i];
        }
        int mx = F;
        for (int i = n - 1; i > 0; i--) {
            F = F + sum - n * nums[i];
            mx = max(mx, F);
        }
        return mx;


    }
};