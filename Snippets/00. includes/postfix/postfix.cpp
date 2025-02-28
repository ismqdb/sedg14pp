/* ******************************************************************************** */

#include "./postfix.hpp"
#include "../../11. stack/11. stackA.hpp"

/* ******************************************************************************** */

std::string getPostfix(){
    char c;
    char *number;
    
    stackA<char> stack{};
    std::string output{};

    while(1){
        c = getchar();

        if(c == EOF || c == '\n')
            break;

        if(c == ' ' || c == '(')
            continue;

        if(c == ')'){
            output += (char)stack.top();
            stack.pop();
            output += ' ';
            continue;
        }

        if(c == '+' || c == '-' || c == '*' || c == '/'){
            stack.push(c);
            continue;
        }

        if(c >= '0' && c <= '9'){
            while(1){
                output += c;
                c = getchar();

                if(!isdigit(c)){
                    ungetc(c, stdin);
                    break;
                }
            }
            output += ' ';
        }
    }

    while(!stack.isEmpty()){
        output += (char)stack.top();
        stack.pop();
    }

    return output;
}

/* ******************************************************************************** */

template<typename Type, typename Func>
    Type calculate(Type a, Type b, Func f){
        return f(a, b);
    }

bool isOperator(char c){
    switch(c){
        case '+':
        case '-':
        case '*':
            return true;
        default:
            return false;
    }
}

/* ******************************************************************************** */

int evaluate(std::string& input){
    char c;
    int x;
    int sum = 0;

    int left, right;

    stackA<char> stack{};

    for(int i = 0; i < input.size(); i++){
        c = input[i];

        if(c == ' ')
            continue;

        x = 0;

        if(isOperator(c)){
            right = stack.top();
            stack.pop();
            left = stack.top();
            stack.pop();

            switch(c){
                case '+':
                    x = calculate(left, right, std::plus{});
                    break;

                case '-':
                    x = calculate(left, right, std::minus{});
                    break;

                case '*':
                    x = calculate(left, right, std::multiplies{});
                    break;
                
                case '/':
                    x = calculate(left, right, std::divides{});
                    break;

                default:
                    throw "Bad operator.";
            }
        } else 
            while(c>='0' && c<='9'){
                x = 10*x + (c-'0');
                i++;
                c = input[i];
            }

        stack.push(x);
    }

    int retValue = stack.top();
    stack.pop();
    return retValue;
}

/* ******************************************************************************** */

// (((3 + 6) * (2 - 4)) + 7)
// "3 6 + 2 4 - * 7 + "

void postfixDriver(){
    //std::string postfix = getPostfix();
    std::string postfix{"3 6 + 2 4 - * 7 + "};
    int result = evaluate(postfix);

    std::cout << result << '\n';
}

/* ******************************************************************************** */