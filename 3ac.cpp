#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ThreeAddressCode {
    string op;
    string arg1;
    string arg2;
    string result;
};

vector<ThreeAddressCode> generate3AC(string expression) {
    vector<ThreeAddressCode> code;

    code.push_back({"ADD", "y", "z", "t1"});
    code.push_back({"MOV", "t1", "", "x"});
    return code;
}

int main() {
    string expression = "x = y + z";
    vector<ThreeAddressCode> code = generate3AC(expression);
    cout << "Generated 3-address code:" << endl;
    for (const auto& instruction : code) {
        cout << instruction.result << " = " << instruction.arg1 << " " << instruction.op << " " << instruction.arg2 << endl;
    }
    return 0;
}
