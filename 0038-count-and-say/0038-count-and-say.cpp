class Solution {
public:
    string countAndSay(int n) {
        vector<string> CAS(31);
CAS[0] = "0";
  CAS[1] = "1";

  int i;
  for(i=2; i<=n; i++){
    string prv, ans;
    prv = CAS[i-1];
    ans = "";

    int j, n;
    n = prv.size();
    j=0;
    while(j<n){
      char cur = prv[j];
      int cnt=0;
      while (prv[j]==cur && j<n)
      {
        cnt++;
        j++;
      }
      
      ans = ans + (char)('0'+cnt) + cur;

    }


    CAS[i] = ans;
  }
      return CAS[n];
    }
};