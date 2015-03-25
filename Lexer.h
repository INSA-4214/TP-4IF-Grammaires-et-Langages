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
         * D�cale la t�te de lecture d'un mot vers la droite
         */
        void shift();

        /**
         * Regarde le prochain symbole terminal sans d�placer la t�te de lecture
         */
        bool analyze();

        Symbole *getSymboleCourant();

    private:

        bool hasNext();
        void parse(std::string *filename);
        std::string m_str;
        std::string m_symboleCourantStr;
        Symbole * m_symboleCourant;
};

#endif // LEXER_H
