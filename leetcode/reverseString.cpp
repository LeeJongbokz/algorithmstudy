class Solution {
public:
    void reverseString(vector<char>& s) {
        
        vector<char>temp;
        
        for(vector<char>::reverse_iterator iter=s.rbegin(); iter!=s.rend(); iter++){
             temp.push_back(*iter);
        }
        
        cout << '[';
    
        for(int i=0; i<temp.size(); i++){
            cout << '\"' << temp[i] << '\"';
            if(i != temp.size()-1){
                cout << ',';
            }
        }
        
        
        cout << ']';
        
    }
};
