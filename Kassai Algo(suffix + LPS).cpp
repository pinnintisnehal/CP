class Solution {
private:
void build_LPS(vector<int>&suff_array , string s , vector<int>&LPS){
    int n = s.size();
    vector<int>rank(n);
    for(int i = 0;i < n; i++){
        rank[suff_array[i]] = i;
    }
    int k = 0;
    for(int i = 0;i < n; i++){
        if(rank[i] == n-1){
            k = 0;
            continue;
        }
        int j = suff_array[rank[i] + 1];
        while( i + k < n && j + k < n && s[i + k] == s[j + k]){
            k += 1;
        }
        LPS[rank[i]] = k;
        if(k > 0) k--;
    }
}
void build_Suffix(string s , vector<int>&suff_array){
    int n = s.size();
    vector<int>rank(n),temp(n);
    for(int i = 0;i < n; i++){
        suff_array[i] = i;
        rank[i] = s[i] - 'a';
    }
    for(int k = 1; k < n; k*=2){
         auto compare = [&](int a, int b) {
            if (rank[a] != rank[b])
                return rank[a] < rank[b];
            int ra = (a + k < n) ? rank[a + k] : -1;
            int rb = (b + k < n) ? rank[b + k] : -1;
            return ra < rb;
         };
         sort(suff_array.begin() , suff_array.end(), compare);
         temp[suff_array[0]] = 0;
         for(int i = 1; i < n; i++){
            temp[suff_array[i]] = temp[suff_array[i - 1]] + 
                         (compare(suff_array[i - 1] , suff_array[i]) ? 1 : 0);
         }
         rank = temp;
    }
}
