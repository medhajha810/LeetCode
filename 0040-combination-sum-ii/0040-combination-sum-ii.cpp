class Solution {
public:

    void fun(vector<int>& candidates,int index,vector<int>&temp,int currsum,int target,vector<vector<int>>&res){
        if(currsum == target){
            res.push_back(temp);
            return;
        }
        if (currsum > target) return;

        for(int i = index ; i < candidates.size();i++){
            if(i > index && candidates[i] == candidates[i - 1]){
                continue;
            }
            temp.push_back(candidates[i]);
            fun(candidates,i+1,temp,currsum+candidates[i],target,res);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        sort(candidates.begin(), candidates.end());
        fun(candidates,0,temp,0,target,res);
        return res;
    }
};