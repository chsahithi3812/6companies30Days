
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         vector<int> in(numCourses,0);
        for(int i=0 ;i<prerequisites.size() ;i++)
        {
            in[prerequisites[i][0]]++;
        }
         queue<int> q;
        for(int i=0 ;i<in.size() ;i++)
        {
            if(in[i] == 0)
                q.push(i);
        }
       
       
        vector<int> ans;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(int i=0 ;i<prerequisites.size() ;i++)
            {
                if(prerequisites[i][1] == node)
                {
                    in[prerequisites[i][0]]--;
                    if(in[prerequisites[i][0]] == 0)
                    {
                        q.push(prerequisites[i][0]);
                    }
                }
            }
            ans.push_back(node);
        }
        if(in.size() == ans.size()) return true;
        return false; 
    }
};