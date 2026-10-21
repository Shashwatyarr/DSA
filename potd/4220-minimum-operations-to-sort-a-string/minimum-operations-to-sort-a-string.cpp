class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        if(is_sorted(s.begin(),s.end())) return 0;
        if(n==2) return -1;
        string s1=s;
        sort(s1.begin(),s1.end()-1);
        if(is_sorted(s1.begin(),s1.end())){
            return 1;
        }
        string s2=s;
        sort(s2.begin()+1,s2.end());
        if(is_sorted(s2.begin(),s2.end())){
            return 1;
        }
        char maxi=*max_element(s.begin(),s.end());
        char mini=*min_element(s.begin(),s.end());
        int mcount=count(s.begin(),s.end(),maxi);
        int mcnt=count(s.begin(),s.end(),mini);
        if(s.front()==maxi && mcount==1 && s.back()==mini && mcnt==1){
            return 3;
        }
        return 2;
    }
};