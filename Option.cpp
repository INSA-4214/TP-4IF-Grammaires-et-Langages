#include <iostream>
#include <string>
#include <fstream>

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
        std::ofstream fic_err("stderr", std::ios::out | std::ios::trunc);

        if (fic_err)
        {
            fic_err << "Erreur, veuillez specifier des arguments" << endl;
            fic_err << "  Utilisation :" << endl;
            fic_err << "    ../lut [-p] [-a] [-e] [-o] source.lt" << endl;
            fic_err << "      [-p] affiche le code source reconnu" << endl;
            fic_err << "      [-a] analyse le programme de maniere statique" << endl;
            fic_err << "      [-e] execute interactivement le programme" << endl;
            fic_err << "      [-o] optimise les expressions et instructions" << endl;
        }
        return 1;
    }
    else {
        std::ifstream fichier(fileName->c_str(), std::ios::in);

        if (!fichier)
        {
            std::ofstream fic_err("stderr", std::ios::out | std::ios::trunc);

            if (fic_err)
            {
                fic_err << "Erreur a l'ouverture du fichier ";
                fic_err << fileName << endl;
            }
            return 1;
        }
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

