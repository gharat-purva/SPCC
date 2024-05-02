#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <unordered_set>
using namespace std;

// Token types
enum TokenType {
    KEYWORD,
    IDENTIFIER,
    SYMBOL,
    LITERAL,
    NUMBER,
    UNKNOWN
};

// Token structure
struct Token {
    TokenType type;
    string value;
};

// Function to tokenize input string
vector<Token> tokenize(string input) {
    vector<Token> tokens;
    regex keywordRegex("\\b(if|else|while|for|return)\\b");
    regex identifierRegex("[a-zA-Z_][a-zA-Z0-9_]*");
    regex symbolRegex("[\\+\\-\\*\\/\\=\\<\\>\\(\\)\\[\\]\\{\\};,]");
    regex literalRegex("\"[^\"]*\"");
    regex numberRegex("\\b[0-9]+\\b");
    
    smatch match;
    while (!input.empty()) {
        if (regex_search(input, match, keywordRegex)) {
            tokens.push_back({KEYWORD, match.str()});
        } else if (regex_search(input, match, identifierRegex)) {
            tokens.push_back({IDENTIFIER, match.str()});
        } else if (regex_search(input, match, symbolRegex)) {
            tokens.push_back({SYMBOL, match.str()});
        } else if (regex_search(input, match, literalRegex)) {
            tokens.push_back({LITERAL, match.str()});
        } else if (regex_search(input, match, numberRegex)) {
            tokens.push_back({NUMBER, match.str()});
        } else {
            // Handle unrecognized tokens
            // For simplicity, treat unrecognized characters as part of unknown tokens
            tokens.push_back({UNKNOWN, input.substr(0, 1)});
        }
        input = match.suffix();
    }
    
    return tokens;
}

// Function to print tokens
void printTokens(const vector<Token>& tokens) {
    unordered_set<TokenType> keywords = {KEYWORD};
    unordered_set<TokenType> symbols = {SYMBOL};
    unordered_set<TokenType> literals = {LITERAL};
    unordered_set<TokenType> numbers = {NUMBER};
    
    for (const Token& token : tokens) {
        cout << "Token: " << token.value << ", Type: ";
        if (keywords.count(token.type)) {
            cout << "Keyword";
        } else if (token.type == IDENTIFIER) {
            cout << "Identifier";
        } else if (symbols.count(token.type)) {
            cout << "Symbol";
        } else if (literals.count(token.type)) {
            cout << "Literal";
        } else if (numbers.count(token.type)) {
            cout << "Number";
        } else {
            cout << "Unknown";
        }
        cout << endl;
    }
}

int main() {
    string input = "if (x == 10) { return \"Hello, world!\"; }";
    vector<Token> tokens = tokenize(input);
    printTokens(tokens);
    return 0;
}
