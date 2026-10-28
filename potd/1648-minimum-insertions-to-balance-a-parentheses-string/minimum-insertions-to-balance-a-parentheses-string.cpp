class Solution {
public:
    int minInsertions(string s) {
        stack<int> st;
        int n=s.size();
        int prev=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]==')') {
                if(!prev){
                    prev=1;
                    ans++;
                    if(st.empty()) ans++;
                    else st.pop();
                    continue;
                }
                else{
                    prev=0;
                    ans--;
                }
            }
            else if(s[i]=='('){ st.push('(');if(prev)prev=0;}
        }
        ans+=2*st.size();
        return ans;
    }
};