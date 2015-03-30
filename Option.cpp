#include <iostream>
#include <string>
#include <fstream>

#include "Lexer.h"
#include "Automate.h"

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
            cerr << "Erreur, veuillez specifier des arguments" << endl;
            cerr << "  Utilisation :" << endl;
            cerr << "    ../lut [-p] [-a] [-e] [-o] source.lt" << endl;
            cerr << "      [-p] affiche le code source reconnu" << endl;
            cerr << "      [-a] analyse le programme de maniere statique" << endl;
            cerr << "      [-e] execute interactivement le programme" << endl;
            cerr << "      [-o] optimise les expressions et instructions" << endl;
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
                cerr << "Erreur a l'ouverture du fichier ";
                cerr << *fileName << endl;
            }
            return 1;
        }
    }

    Lexer lexer = Lexer(fileName);
    Automate automate = Automate(&lexer);
    automate.lecture();

    if (transformActive) {
        cout << "Transform (optimize) input" << endl;
        // TRANSFORM
    }
    if (printActive) {
        cout << "Print (transformed?) input" << endl;
        automate.print();
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


    return 0;
}

