class Solution {
public:
    int maxOperations(vector<int>& a, int k) {
        int ans=0;
        map<int,int>m;
        for(auto &i:a)m[i]++;
        for(auto &i:m){
            int p=i.first;
            int q=k-p;
            if(p==q){ans+=m[p]/2;m[p]=0;m[q]=0;}
            else if(q>0&&m[q]!=0){ans+=min(m[p],m[q]);m[p]=0;m[q]=0;}
        }
        return ans;
    }
};
