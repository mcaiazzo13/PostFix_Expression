#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std; 
  
  int solve(int N, vector<string> V){
    int solution = 0;
    vector<int> stack(N);
    int x,y,z;
    for(int i=0;i<N;i++){
        // number found
        if(V.at(i) != "+" && V.at(i) != "-" && V.at(i) != "*"){ 
            x = stoi(V.at(i));
            cout << "x : " << x <<endl;
            stack.push_back(x);
        }else if(V.at(i) == "+"){ // symbol +
            x = stack.back();
            stack.pop_back();
            y = stack.back();
            stack.pop_back();
            z = x+y;
            stack.push_back(z);
        }else if(V.at(i) == "-"){ // symbol -
            x = stack.back();
            stack.pop_back();
            y = stack.back();
            stack.pop_back();
            z = x-y;
            stack.push_back(z);
        }else if(V.at(i) == "*"){ // symbol *
            x = stack.back();
            stack.pop_back();
            y = stack.back();
            stack.pop_back();
            z = x*y;
            stack.push_back(z);
        }
    }
    solution = stack.back();
    return solution;
  }

int main() {

    int N,i;
    cout << "Insert size :";
    cin >> N;
    if(N < 2 || N > 99){
        cout << "Error. Insert an N between 2 and 99"<<endl;
        exit(1);
    }
    vector<string> exp(N);
    cout << "Insert The expression with numbers and symbols : ";
    for(i=0;i<N;i++){
        cin >> exp[i];
    }

    cout << solve(N,exp);  
    return 0;  
}  







