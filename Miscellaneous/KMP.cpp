int KMP(const string A, const string B) {
    // Find B in A
    int m = A.size(),n = B.size();
    if(m==0 || n==0) return -1;
    vector<int> pref(n,0);
    pref[0]=0;
    int j;
    for(int i=1;i<n;i++) {
        j = pref[i-1];
        while(j>0 && B[i]!=B[j]) j = pref[j-1];
        if(B[i]==B[j]) j++;
        pref[i]=j;
    }
    j = 0;
    int i=0;
    while(i<m) {
        if(B[j]==A[i]) {
            i++; j++;
        }
        if(j==n) {
            return i-j;
        }
        else if(i<m && A[i]!=B[j]){
            if(j!=0) j = pref[j-1];
            else i=i+1;
        }
    }
    return -1;
}   