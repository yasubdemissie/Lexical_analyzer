#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

void lexicalAnalyzer(const string& code) {
    vector<string> tokens;
    string currentToken;

    for (size_t i = 0; i < code.size(); ++i) {
        char c = code[i];

        if (isspace(c)) {
            continue;
        }

        if (isalpha(c)) {
            currentToken += c;
            while (i + 1 < code.size() && isalnum(code[i + 1])) {
                currentToken += code[++i];
            }
            if (currentToken == "int") {
                cout << "Token: Keyword, Value: " << currentToken << endl;
                tokens.push_back("Keyword: " + currentToken);
            } else {
                cout << "Token: Identifier, Value: " << currentToken << endl;
                tokens.push_back("Identifier: " + currentToken);
            }
            currentToken.clear();
        } else if (isdigit(c)) {
            currentToken += c;
            while (i + 1 < code.size() && isdigit(code[i + 1])) {
                currentToken += code[++i];
            }
            cout << "Token: Number, Value: " << currentToken << endl;
            tokens.push_back("Number: " + currentToken);
            currentToken.clear();
        } else if (c == '=') {
            cout << "Token: Operator, Value: " << c << endl;
            tokens.push_back("Operator: =");
        } else if (c == ';') {
            cout << "Token: Semicolon, Value: " << c << endl;
            tokens.push_back("Semicolon: ;");
        } else {
            cout << "Token: Unknown, Value: " << c << endl;
            tokens.push_back("Unknown: " + string(1, c));
        }
    }

    cout << "\nAll Tokens:\n";
    for (const auto& token : tokens) {
        cout << token << endl;
    }
}

int main() {
    string input = "int age = 25;";
    cout << "Analyzing Expression: \"" << input << "\"\n";
    lexicalAnalyzer(input);
    return 0;
}