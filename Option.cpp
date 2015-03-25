#include <iostream>
#include <string>
#include "Lexer.h"
#define OPT_TRANSFORM "-o"
#define OPT_PRINT "-p"
#define OPT_STATIC "-a"
#define OPT_EXEC "-e"

using std::string;
using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char* argv[]) {

    bool transformActive = false;
    bool printActive = false;
    bool staticActive = false;
    bool execActive = false;
    string* fileName = NULL;

    for (int i = 1; i < argc; i++) {
        string* arg = new string(argv[i]);

        if (arg->compare(OPT_TRANSFORM) == 0) {
            transformActive = true;
            delete arg;
        } else if (arg->compare(OPT_PRINT) == 0) {
            printActive = true;
            delete arg;
        } else if (arg->compare(OPT_STATIC) == 0) {
            staticActive = true;
            delete arg;
        } else if (arg->compare(OPT_EXEC) == 0) {
            execActive = true;
            delete arg;
        } else {
            fileName = arg;
        }
    }
    if (fileName == NULL) {
        cerr << "Pas de fichier d'entrée fourni" << endl;
        return 1;
    }
        // LEXER
        // PARSER
    if (transformActive) {
        cout << "Transform (optimize) input" << endl;
        // TRANSFORM
    }
    if (printActive) {
        cout << "Print (transformed?) input" << endl;
        // PRINT
    }
    if (staticActive) {
        cout << "Analyse statique" << endl;
        // STATIC
    }
    if (execActive) {
        cout << "Execute" << endl;
        // EXEC
    }

    Lexer lexer = Lexer(fileName);
    while (lexer.analyze()) {
    	lexer.shift();
    }
    return 0;
}

