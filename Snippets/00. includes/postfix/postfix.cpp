/* ******************************************************************************** */

#include "./postfix.hpp"
#include "../../11. stack/11. stackA.hpp"

/* ******************************************************************************** */

std::string getPostfix(){
    i8 c;
    i8 *number;
    
    stackA<i8> stack{};
    std::string output{};

    while(1){
        c = getchar();

        if(c == EOF || c == '\n')
            break;

        if(c == ' ' || c == '(')
            continue;

        if(c == ')'){
            output += (i8)stack.top();
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
        output += (i8)stack.top();
        stack.pop();
    }

    return output;
}

/* ******************************************************************************** */

template<typename Type, typename Func>
    Type calculate(Type a, Type b, Func f){
        return f(a, b);
    }

bool isOperator(i8 c){
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

i32 evaluate(std::string& input){
    i8 c;
    i32 x;
    i32 sum = 0;

    i32 left, right;

    stackA<i8> stack{};

    for(i32 i = 0; i < input.size(); i++){
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

    i32 retValue = stack.top();
    stack.pop();
    return retValue;
}

/* ******************************************************************************** */

// (((3 + 6) * (2 - 4)) + 7)
// "3 6 + 2 4 - * 7 + "

none postfixDriver(){
    //std::string postfix = getPostfix();
    std::string postfix{"3 6 + 2 4 - * 7 + "};
    i32 result = evaluate(postfix);

    std::cout << result << '\n';
}

/* ******************************************************************************** */