class Solution {
private:
void computeLPS(int m , string pat , vector<int>&lps){
    int len = 0, i = 1;
    while(i < m){
        if(pat[len] == pat[i]) {
            lps[i] = len + 1;
            i += 1;
            len += 1;
        }
        else if(len != 0) {
            len = lps[len - 1];
        }
        else {
            lps[i] = 0;
            i += 1;
        }
    }
}
private:
bool kmp(string txt , string pat){
    int n = txt.size();
    int m = pat.size();
    vector<int>lps(m, 0);
    computeLPS(m, pat ,lps);
    int i = 0,j = 0;
    while(i < n){
        if(txt[i] == pat[j]) {
            i += 1;
            j += 1;
        }
        else {
            if(j != 0) {
                j = lps[j - 1];
            }
            else {
                i += 1;
            }
        }
        if(j == m){
            return true;
        }
    }
    return false;
}
