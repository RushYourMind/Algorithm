class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        
         string pre = strs[0];
         for(int i = 1, j; i < strs.size(); ++ i)
         {
             for(j = 0; j < pre.size() && j < strs[i].size(); ++ j)
                 if(pre[j] != strs[i][j])
                    break;
             pre = pre.substr(0, j);
         }
         return pre;
    }
};