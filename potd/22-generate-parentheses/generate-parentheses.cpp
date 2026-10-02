class Solution {
public:
    void para(int n,int cl,int cr,vector<string>& ans,string& temp){
        if(cl==n && cr==n){
            ans.push_back(temp);
            return;
        }
        if(cl<n){
            temp.push_back('(');
            para(n,cl+1,cr,ans,temp);
            temp.pop_back();
        }
        if(cr<cl){
            temp.push_back(')');
            para(n,cl,cr+1,ans,temp);
            temp.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
          vector<string> ans;
          string temp;
          int cl=0,cr=0;
          para(n,cl,cr,ans,temp);
          return ans;
    }
};