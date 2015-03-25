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
        bool analyze();
        void shift();
    protected:
    private:
        std::istream& m_stream;
        std::string m_str;
        std::string m_currentTokenStr;
        Symbole * m_currentToken;
};

#endif // LEXER_H
