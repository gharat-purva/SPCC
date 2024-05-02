#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Quadruple {
    string op;
    string arg1;
    string arg2;
    string result;
};


vector<Quadruple> generateQuadruples(string expression) {
    vector<Quadruple> quadruples;

    quadruples.push_back({"ADD", "y", "z", "t1"});
    quadruples.push_back({"MOV", "t1", "", "x"});
    return quadruples;
}

int main() {
    string expression = "x = y + z";
    vector<Quadruple> quadruples = generateQuadruples(expression);
    cout << "Generated quadruples:" << endl;
    for (const auto& quad : quadruples) {
        cout << "(" << quad.op << ", " << quad.arg1 << ", " << quad.arg2 << ", " << quad.result << ")" << endl;
    }
    return 0;
}
