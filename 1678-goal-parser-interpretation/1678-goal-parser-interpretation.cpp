class Solution {
public:
    string interpret(string command) {
        string res="";
        for(int i=0;i<command.length();){
            if(command[i]=='G'){
                i++;
                res+="G";
            }
            else if(command[i]=='(' and command[i+1]==')'){
                i+=2;
                res+="o";
            }
            else if(command[i]=='(' and command[i+1]=='a'){
                i+=4;
                res+="al";
            }
        }
        return res;
    }
};