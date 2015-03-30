/*
 * Lexer.h
 *
 *  Created on: 18 mars 2015
 *      Author: Romain
 */

#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <ios>
#include <string>

#include <boost/regex.hpp>
#include <boost/lexical_cast.hpp>

#include "Symbole.h"

class Lexer
{
    public:
        Lexer(std::string* filename);
        virtual ~Lexer();

        /**
         * Décale la tête de lecture d'un mot vers la droite
         */
        void shift();

        /**
         * Regarde le prochain symbole terminal sans déplacer la tête de lecture
         */
        bool analyze();

        int * getCurrPos();

        Symbole *getSymboleCourant();

    private:

        void parse(std::string *filename);
        bool hasNext();

        std::string m_str;
        std::string m_texteEntier;
        std::string m_debutTexte;
        std::string m_symboleCourantStr;
        Symbole * m_symboleCourant;
        int *m_pos = new int [2];
};

#endif // LEXER_H
