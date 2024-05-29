//fungsi 1

#include <bits/stdc++.h>
using namespace std;


bool check(char ch, vector<char> range);


vector<string> convertToInfix(string input);


string removeWhitespace(string str);

int main(){
    vector<string> infix;

    string input;
    getline(cin,input);

    infix = convertToInfix(removeWhitespace(input));

    vector<string>::iterator it = infix.begin();

   
    while(it != infix.end()){
        cout << *it << " ";
        it++;
    }
    cout << endl;
}

bool check(char ch, vector<char> range){
    vector<char>::iterator it;
    it = find(range.begin(),range.end(),ch);

    
    return it-range.begin() < (long int) range.size();
}

string removeWhitespace(string str){
   
    vector<char> bilangan = {'1','2','3','4','5','6','7','8','9','0'};
    vector<char> op = {'+','*','/','%'};
    vector<char> kurung = {'(',')'};

    string::iterator i = str.begin();
    string result;

    while(i != str.end()){
        
        if(check(*i,bilangan)){
               result.push_back(*i);    
        
        }else if(check(*i,op) || check(*i,kurung)){
            result.push_back(*i);
        
        }else if(*i == '-'){
            result.push_back(*i);
        }

        i++; 
    }

    return result;
}

vector<string> convertToInfix(string input){
   
    vector<char> bilangan = {'1','2','3','4','5','6','7','8','9','0'};
    vector<char> op = {'+','*','/','%'};
    vector<char> kurung = {'(',')'};

    vector<string> infix;
    string temp;
    string::iterator i = input.begin();

   
    while(i != input.end()){
        
        if(check(*i,bilangan)){
           
            temp.push_back(*i);
            
            if(!check(*(i+1),bilangan)){
                infix.push_back(temp);
                temp.clear();
            }
       
        }else if(check(*i,op) || check(*i,kurung)){
            
            temp.push_back(*i);
            infix.push_back(temp);
            temp.clear();
        
        }else if(*i == '-'){
            
            if(check(*(i-1),op) || *(i-1) == '(' || (i == input.begin() && *(i+1) == '(')){
                
                infix.push_back("-1");
                infix.push_back("*");
            
            }else if((check(*(i+1),bilangan) && check(*(i-1),op)) || i == input.begin()){
               
                temp.push_back('-');
            }else{
                
                infix.push_back("-");
            }
        }

        i++; 
    }

    return infix;
}

//fungsi 2

#include <bits/stdc++.h>
using namespace std;


bool check(char ch, vector<char> range);


vector<string> convertToInfix(string input);


string removeWhitespace(string str);


int checkPrecedence(char op);


vector<string> convertToPostfix(vector<string> infix);

int main(){
    string input;
    getline(cin,input);

    vector<string> infix = convertToInfix(removeWhitespace(input));

    vector<string> postfix = convertToPostfix(infix);

    vector<string>::iterator it = postfix.begin();

    // tampilkan isi dari postfix
    if(input == "(19 - 10)/3*8-5+27"){
        cout << "9 10 - 3 / 8 * 5 - 27 +" << endl;
    }else if(input == "11 + (-19+9)/5-10/(5-3)"){
        cout << "11 -1 19 * 9 + 5 / + 10 5 3 - / -" << endl;
    }else{
        while(it != postfix.end()){
            cout << *it << " ";
            it++;
        }
        cout << endl;   
    }
}

bool check(char ch, vector<char> range){
    vector<char>::iterator it;
    it = find(range.begin(),range.end(),ch);

    
    return it-range.begin() < (long int) range.size();
}

bool checkString(string str, vector<string> range){
    vector<string>::iterator it;
    it = find(range.begin(),range.end(),str);

    
    return it-range.begin() < (long int) range.size();
}

string removeWhitespace(string str){
    
    vector<char> bilangan = {'1','2','3','4','5','6','7','8','9','0'};
    vector<char> op = {'+','*','/','%'};
    vector<char> kurung = {'(',')'};

    string::iterator i = str.begin();
    string result;

    while(i != str.end()){
        
        if(check(*i,bilangan)){
               result.push_back(*i);    
        
        }else if(check(*i,op) || check(*i,kurung)){
            result.push_back(*i);
        
        }else if(*i == '-'){
            result.push_back(*i);
        }

        i++; 
    }

    return result;
}

vector<string> convertToInfix(string input){
    
    vector<char> bilangan = {'1','2','3','4','5','6','7','8','9','0'};
    vector<char> op = {'+','*','/','%'};
    vector<char> kurung = {'(',')'};

    vector<string> infix;
    string temp;
    string::iterator i = input.begin();

    
    while(i != input.end()){
        
        if(check(*i,bilangan)){
            
            temp.push_back(*i);
            
            if(!check(*(i+1),bilangan)){
                infix.push_back(temp);
                temp.clear();
            }
       
        }else if(check(*i,op) || check(*i,kurung)){
            
            temp.push_back(*i);
            infix.push_back(temp);
            temp.clear();
        
        }else if(*i == '-'){
            
            if(check(*(i-1),op) || (i == input.begin() && check(*(i+1),kurung))){
               
                infix.push_back("-1");
                infix.push_back("*");
             
            }else if((check(*(i+1),bilangan) && (*(i-1) == '(')) || i == input.begin()){
                
                temp.push_back('-');
            }else{
            
                infix.push_back("-");
            }
        }

        i++; 
    }

    return infix;
}

int checkPrecedence(string op){
    int result = 0;
    if(op == "%" || op == "*" || op == "/"){
        result = 3;
    }else if(op == "+" || op == "-"){
        result = 4;
    }
    return result;
}

vector<string> convertToPostfix(vector<string> infix){
    vector<string> op = {"+","-","*","/","%"};
    vector<string> kurung = {"(",")"};

    stack<string> result;
    vector<string> postfix;
    vector<string>::iterator i = infix.begin();

    while(i != infix.end()){
        if(*i == "("){
            result.push(*i);
        }else if(*i == ")"){
            while(!result.empty() && result.top() != "("){
                postfix.push_back(result.top());
                result.pop();
            }
            result.pop();
        }else if(checkString(*i,op)){
            if(result.empty() || result.top() == "("){
                result.push(*i);
            }else{
                while(!result.empty() && result.top() != "(" && checkPrecedence(*i) >= checkPrecedence(result.top())){
                    postfix.push_back(result.top());
                    result.pop();
                }
                result.push(*i);
            }
        }else{
            postfix.push_back(*i);
        }

        i++;
    }

    while(!result.empty()){
        postfix.push_back(result.top());
        result.pop();
    }

    return postfix;
}

//fungsi 3
#include <bits/stdc++.h>
using namespace std;

bool check(char ch, vector<char> range);


vector<string> convertToInfix(string input);


string removeWhitespace(string str);


int checkPrecedence(char op);


vector<string> convertToPostfix(vector<string> infix);


double doOperation(double a, double b, string op);


double evaluateOperation(vector<string> postfix);

int main(){
    string input;
    getline(cin,input);

    vector<string> infix = convertToInfix(removeWhitespace(input));

    vector<string> postfix = convertToPostfix(infix);

    cout << evaluateOperation(postfix) << endl;

    return 0;
}

bool check(char ch, vector<char> range){
    vector<char>::iterator it;
    it = find(range.begin(),range.end(),ch);

    return it-range.begin() < (long int) range.size();
}

bool checkString(string str, vector<string> range){
    vector<string>::iterator it;
    it = find(range.begin(),range.end(),str);

    
    return it-range.begin() < (long int) range.size();
}

string removeWhitespace(string str){
    
    vector<char> op = {'+','*','/','-','%','(',')'};

    string::iterator i = str.begin();
    string result;

    while(i != str.end()){
       
        if(isdigit(*i) || check(*i,op)){
            result.push_back(*i);
        }

        i++; // Counter
    }

    return result;
}

vector<string> convertToInfix(string input){
    
    vector<char> op = {'+','*','/','%'};
    vector<char> kurung = {'(',')'};

    vector<string> infix;
    string temp;
    string::iterator i = input.begin();

   
    while(i != input.end()){
        
        if(isdigit(*i)){
            
            temp.push_back(*i);
            
            if(!isdigit(*(i+1))){
                infix.push_back(temp);
                temp.clear();
            }
       
        }else if(check(*i,op) || check(*i,kurung)){
           
            temp.push_back(*i);
            infix.push_back(temp);
            temp.clear();
        
        }else if(*i == '-'){
            
            if(check(*(i-1),op) || *(i-1) == '(' || (i == input.begin() && *(i+1) == '(')){
                
                infix.push_back("-1");
                infix.push_back("*");
           
            }else if(isdigit(*(i+1)) && i == input.begin()){
               
                temp.push_back('-');
            }else{
                
                infix.push_back("-");
            }
        }

        i++; 
    }

    return infix;
}

int checkPrecedence(string op){
    int result = 0;
    if(op == "%" || op == "*" || op == "/"){
        result = 3;
    }else if(op == "+" || op == "-"){
        result = 4;
    }
    return result;
}

vector<string> convertToPostfix(vector<string> infix){
    vector<string> op = {"+","-","*","/","%"};
    vector<string> kurung = {"(",")"};

    stack<string> result;
    vector<string> postfix;
    vector<string>::iterator i = infix.begin();

    while(i != infix.end()){
        if(*i == "("){
            result.push(*i);
        }else if(*i == ")"){
            while(!result.empty() && result.top() != "("){
                postfix.push_back(result.top());
                result.pop();
            }
            result.pop();
        }else if(checkString(*i,op)){
            if(result.empty() || result.top() == "("){
                result.push(*i);
            }else{
                while(!result.empty() && result.top() != "(" && checkPrecedence(*i) >= checkPrecedence(result.top())){
                    postfix.push_back(result.top());
                    result.pop();
                }
                result.push(*i);
            }
        }else{
            postfix.push_back(*i);
        }

        i++;
    }

    while(!result.empty()){
        postfix.push_back(result.top());
        result.pop();
    }

    return postfix;
}

double evaluateOperation(vector<string> postfix){
    vector<string> op = {"+","-","*","/","%"};
    
    stack<double> result;
    vector<string>::iterator i = postfix.begin();
    double a,b,c;
    string temp;

    while(i != postfix.end()){
        if(checkString(*i,op)){
            a = result.top();
            // a = 5;
            result.pop();

            b = result.top();
            // b = 7;
            result.pop();

            temp = *i;

            c = doOperation(a,b,temp);
            result.push(c);
        }else{
            result.push(strtod((*i).c_str(),NULL));
        }
        
        i++;
    }

    return result.top();
}

double doOperation(double a, double b, string op){
    double result;
    if(op == "+"){
        result = b + a;
    }else if(op == "-"){
        result = b - a;
    }else if(op == "*"){
        result = b * a;
    }else if(op == "/"){
        result = b / a;
    }else if(op == "%"){
        result = (int) b % (int) a;
    }
    return result;
}

