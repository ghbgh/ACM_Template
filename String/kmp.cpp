
vector<int> pre_kmp(string & s) {
    vector<int> f;
    f.push_back(-1);
    int k = -1;
    for(int i = 0; i < s.size(); i++) {
        if(k == -1 || s[i] == s[k]) {
            k++;
            f.push_back(k);
        }else{
            k = f[k];
            i--;
        }
    }
    return f;
}

int kmp(string& text, string& pattern, vector<int>& f) {
    int i = 0, j = 0, c = 0;
    while(i < text.size()) {
        if(j == -1 || text[i] == pattern[j]) {
            i++; j++;
            if(j == pattern.size()) c++, j = f[j];
        }else{
            while(j != -1 && text[i] != pattern[j])
                j = f[j];
        }
    }
    return c;
}
