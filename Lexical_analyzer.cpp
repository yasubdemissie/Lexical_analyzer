#include <iostream>
#include <string>
#include <cctype>

void lexicalAnalyzer(const std::string& code) {
    std::string currentToken;

    for (size_t i = 0; i < code.size(); ++i) {
        char c = code[i];

        if (std::isspace(c)) {
            continue;
        }

        if (std::isalpha(c)) {
            currentToken += c;
            while (i + 1 < code.size() && std::isalnum(code[i + 1])) {
                currentToken += code[++i];
            }
            if (currentToken == "int") {
                std::cout << "KEYWORD: " << currentToken << std::endl;
            } else {
                std::cout << "IDENTIFIER: " << currentToken << std::endl;
            }
            currentToken.clear();
        } else if (std::isdigit(c)) {
            currentToken += c;
            while (i + 1 < code.size() && std::isdigit(code[i + 1])) {
                currentToken += code[++i];
            }
            std::cout << "NUMBER: " << currentToken << std::endl;
            currentToken.clear();
        } else if (c == '=') {
            std::cout << "ASSIGNMENT_OP: =" << std::endl;
        } else if (c == ';') {
            std::cout << "SEMICOLON: ;" << std::endl;
        } else {
            std::cout << "UNKNOWN: " << c << std::endl;
        }
    }
}

int main() {
    std::string code = "int age = 25;";
    std::cout << "Tokens:" << std::endl;
    lexicalAnalyzer(code);

    return 0;
}
