#include <iostream>  
#include <cstdio>  
#include <cmath>  
#include <stack>  
#include <queue>  
using namespace std;  
string string1="error.";   
string string2="Divide 0.";   
int main(){  
    int priority[128]={0};//运算符优先级  
    priority['\0']=-1;  
    priority['+']=1;  
    priority['-']=1;  
    priority['*']=2;  
    priority['/']=2;  
    priority['%']=2;  
    priority['^']=3;  
    priority['(']=4;  
    priority[')']=5;  
    int t;  
    scanf("%d",&t);  
    for(int i=1;i<=t;i++){  
        stack<char> symbol;//转为后缀时存储符号  
        queue<int> num;//表达式中的数字。转化为后缀表达式不改变数字顺序  
        queue<char> anser;//后缀表达式  
        stack<int> calculation;//计算后缀表达式所用堆栈  
        char origin[1000]={0};//输入的原始数据  
        scanf("%s",origin);  
        vector<char> line(origin,origin+sizeof(origin)/sizeof(origin[0]));//输入的数据  
        stack<char> brack;//空格检查堆栈  
        stack<int> np;//储存括号正负性  
        int p=0;  
        while(line[p]!='\0'){//查错  
            if(priority[line[p]]==0){  
                if(line[p+1]=='('){goto err;}//数字后面不能有(  
            }  
            else if(line[p]=='('){  
                brack.push('(');  
                if(priority[line[p+1]]!=0&&line[p+1]!='-'&&line[p+1]!='('||(line[p+1]=='-'&&priority[line[p+2]]!=0&&line[p+2]!='(')){goto err;}//(后面不能有除了-和(之外的符号  
            }  
            else if(line[p]==')'){  
                if(priority[line[p+1]]==0||line[p+1]=='('){goto err;}//)后面不能有数字或(  
                if(brack.empty()){goto err;}  
                if(brack.top()=='('){brack.pop();}  
                else{goto err;}  
            }  
            else if((priority[line[p+1]]!=0&&line[p+1]!='-'&&line[p+1]!='(')||line[p+1]=='\0'||(line[p+1]=='-'&&priority[line[p+2]]!=0&&line[p+2]!='(')){//我也不知道这是在干什么，也许是在处理减号  
                goto err;  
            }  
            p++;  
        }  
        if(!brack.empty()){goto err;}  
  
        p=0;  
        while(line[p]!='\0'){//预处理，将表达式中的数字用字母n代替，数字按顺序存入num  
            if(line[p]=='-'&&priority[line[p+1]]==0&&(p==0||priority[line[p-1]]!=0&&line[p-1]!=')')){//负数  
                stack<int> number;  
                int q=0,temp=0;  
                if(line[p-1]==')'){  
                    p++;  
                    goto point;  
                }  
                line.erase(line.begin()+p);  
                  
                while(priority[line[p]]==0&&priority[line[p+1]]==0){  
                    number.push(line[p]-'0');  
                    line.erase(line.begin()+p);  
                }  
                number.push(line[p]-'0');  
                line[p]='n';  
                  
                while(!number.empty()){  
                    temp+=number.top()*pow(10,q);  
                    number.pop();  
                    q++;  
                }  
                num.push(-1*temp);  
                p++;  
            }  
            else if(line[p]=='-'&&line[p+1]=='('&&(p==0||(priority[line[p-1]]!=0&&line[p-1]!=')'))){//负的括号  
                line.erase(line.begin()+p);  
                np.push(-1);  
                p++;  
            }  
            else if(priority[line[p]]==0){//正数  
                point:;  
                stack<int> number;  
                while(priority[line[p]]==0&&priority[line[p+1]]==0){  
                    number.push(line[p]-'0');  
                    line.erase(line.begin()+p);  
                }  
                number.push(line[p]-'0');  
                line[p]='n';  
                int q=0,temp=0;  
                while(!number.empty()){  
                    temp+=number.top()*pow(10,q);  
                    number.pop();  
                    q++;  
                }  
                num.push(temp);  
                p++;  
            }  
            else if(line[p]=='('){//正括号  
                np.push(1);  
                p++;  
            }  
            else if(line[p]==')'){//括号结束，应用正负性  
                if(np.top()==-1){  
                    line.insert(line.begin()+p+1,'n');  
                    line.insert(line.begin()+p+1,'*');  
                    num.push(-1);  
                    np.pop();  
                    p+=3;  
                }  
                else{  
                    np.pop();  
                    p++;  
                }  
            }  
            else{  
                p++;  
            }  
        }  
  
        int a,b,c;  
  
        p=0;  
        while(1){//转为后缀  
            switch(priority[line[p]]){  
            case 0:  
                anser.push(line[p]);  
                break;  
            case 5:  
                while(symbol.top()!='('){  
                    anser.push(symbol.top());  
                    symbol.pop();  
                }  
                symbol.pop();  
                break;  
            case -1://结束  
                while(!symbol.empty()){  
                    anser.push(symbol.top());  
                    symbol.pop();  
                }  
                goto end;  
            default:  
                while(!symbol.empty()&&priority[symbol.top()]>=priority[line[p]]){  
                    if(line[p]=='^'){break;}  
                    if(symbol.top()=='('){break;}  
                    anser.push(symbol.top());  
                    symbol.pop();  
                }  
                symbol.push(line[p]);  
            }  
            p++;  
        }  
        end:;  
  
        while(!anser.empty()){//计算  
            if(anser.front()=='n'){  
                anser.pop();  
                calculation.push(num.front());  
                num.pop();  
            }  
            else{  
                b=calculation.top();  
                calculation.pop();  
                a=calculation.top();  
                calculation.pop();  
                switch(anser.front()){  
                case '+':  
                    c=a+b;  
                    /*calculation.push(c); 
                    anser.pop();*/  
                    break;  
                case '-':  
                    c=a-b;  
                    /*calculation.push(c); 
                    anser.pop();*/  
                    break;  
                case '*':  
                    c=a*b;  
                    /*calculation.push(c); 
                    anser.pop();*/  
                    break;  
                case '/':  
                    if(b==0){goto div0;}  
                    c=a/b;  
                    /*calculation.push(c); 
                    anser.pop();*/  
                    break;  
                case '%':  
                    c=a%b;  
                    /*calculation.push(c); 
                    anser.pop();*/  
                    break;  
                case '^':  
                    if(b<0){goto err;}  
                    c=pow(a,b);  
                    break;  
                }  
                    calculation.push(c);  
                    anser.pop();  
                 
                  
                  
            }  
        }  
        cout<<calculation.top()<<endl;  
        continue;  
        err:;  
        cout<<string1<<endl;  
        continue;  
        div0:;  
        cout<<string2<<endl;  
    }  
    return 0;  
}  
