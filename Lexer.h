/*
 * Lexer.h
 *
 *  Created on: 18 mars 2015
 *      Author: Romain
 */

#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <string>

#include <boost/regex.hpp>
#include <boost/lexical_cast.hpp>

#include "Symbole.h"

class Lexer
{
    public:
        Lexer(std::istream * stream);
        virtual ~Lexer();

        /**
         * Décale la tête de lecture d'un mot vers la droite
         */
        void shift();
    protected:
    private:

        /**
         * Regarde le prochain symbole terminal sans déplacer la tête de lecture
         */
        bool analyze();
        bool hasNext();
        std::istream& m_stream;
        std::string m_str;
        std::string m_symboleCourantStr;
        Symbole * m_symboleCourant;
};

#endif // LEXER_H
