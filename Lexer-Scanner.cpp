#include <iostream>
#include <regex>
#include <fstream>
#include <string>
#include <map>
using namespace std;

void lexer(string lexeme);

int main()
{
    // string for storing each line from input_scode.txt
    string table = "\nTokens\t\tLexemes\n------------------------\n";
    string lexeme;
    fstream myFile("input_scode.txt");
    cout << table;

    // looping for each line in the file, stopping when EOF
    while (getline(myFile, lexeme)) {
        lexer(lexeme);
    }

    myFile.close();
    cout << "\n\n\nPress Enter to close...";
    getchar(); 
}

// The function where all the magic happens.
void lexer (string lexeme) {

    //Regex for the lexemes, map matches for the results.
    map<string, string> lexemeMap{
    {"[0-9+.]+" , "NUMBER\t"},
    {"[a-z]+" , "IDENTIFIER"},
    {"[=+<]", "OPERATOR"},
    {"[(+)+>+;]", "SEPARATOR"},
    {"while", "KEYWORD"},
    {"int", "KEYWORD"} // We can add more keywords with additional entries. 
        };
    map<size_t, pair<string, string> > matches;

    // Tokenizes the lexemes using lexemeMap
    for (auto i = lexemeMap.begin(); i != lexemeMap.end(); ++i) {
        regex reg(i->first);
        auto words_begin = sregex_iterator(lexeme.begin(), lexeme.end(), reg);
        auto words_end = sregex_iterator();

        // Stores the tokens and lexemes in a new map
        for (auto j = words_begin; j != words_end; ++j)
            if (j->str() != " ") {
                matches[j->position()] = make_pair(j->str(), i->second);
            }
    }

    // Outputs the lexeme/token pair
    for (auto match = matches.begin(); match != matches.end(); ++match) {
        cout << match->second.second << " \t" << match->second.first << endl;
    }

    // Writes the lexeme/token pair to output.txt
    fstream outputFile;
    outputFile.open("output.txt", fstream::app); // appends the output file - doesn't erase the ccontents.
    outputFile << "\nTokens\t\tLexemes\n------------------------\n";

    for (auto match = matches.begin(); match != matches.end(); ++match) {
        outputFile << match->second.second << " \t" << match->second.first << endl;
    }
    outputFile.close();
}