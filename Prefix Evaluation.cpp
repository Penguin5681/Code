#include <bits/stdc++.h>
#include <stack>
#include <cmath>

bool isOperand(char ch) {
    return isdigit(ch);
}

int PrefixSolve(std::string s) {
    std::stack<int> st;

    for (int i = s.length() - 1; i >= 0; i--) {
        if (isOperand(s[i])) {
            st.push(s[i] - '0');
        }
        else {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            switch (s[i]) {
                case '+': st.push(op1 + op2); break;
                case '-': st.push(op1 - op2); break;
                case '/': st.push(op1 / op2); break;
                case '^': st.push(pow(op1, op2)); break;
                case '*': st.push(op1 * op2); break;
            }
        }
    }
    return st.top();
}

signed main(void) {
    std::cout << PrefixSolve("-+7*45+20");
        
}
