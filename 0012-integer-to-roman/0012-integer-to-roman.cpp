class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        int Value[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string Symbol[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        for(int i=0;num!=0;i++)
        {
            while(num>=Value[i])
            {
                ans+=Symbol[i];
                num-=Value[i];
            }
        }
        return ans;
    }
};