

class Solution {
public:
    
    string getHint(string secret, string guess) {
        int x=0,y=0;
        vector<int> v(1000,0);
        for(int i=0;i<secret.length();i++){
            int s=secret[i]-'0';
            int g=guess[i]-'0';
           if(s==g){
               y++;
           }
           else{
               if(v[s]<0) x++;
               if(v[g]>0) x++;
               v[s]++;
               v[g]--;
           }
        }
        return  to_string(y) +"A"+ to_string(x) +"B";
    }
};