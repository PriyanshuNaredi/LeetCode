class Solution {
public:
string result(string s)
{
        string temp="",ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                temp+=s[i];
            }
            else if(s[i]==' ' && temp!=""){
                ans=temp+" "+ans;
                temp="";
            }
            else{
                continue;
            }
        }
        if(temp!=""){
            ans=temp+" "+ans;
        }

        return ans.substr(0,ans.size()-1); // at last there is an emplty space present so we remeove it by  using str function
 
}
    string reverseWords(string s) {
        return result(s);
    }
};