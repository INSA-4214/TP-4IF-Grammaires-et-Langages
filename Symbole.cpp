/*
 * Symbole.cpp
 *
 *  Created on: 8 mars 2015
 *      Author: Huber
 */

#include "Symbole.h"
#include "boost/assign/list_of.hpp"

static const std::map<Symbole::Id, std::string> ID_NAMES = boost::assign::map_list_of (Symbole::idvar, "id")
		(Symbole::r, "lire") (Symbole::aff, ":=") (Symbole::plus, "+") (Symbole::moins, "-")
		(Symbole::cst, "const") (Symbole::var, "var") (Symbole::parf, ")") (Symbole::pv, ";")
		(Symbole::egal, "=") (Symbole::w, "ecrire") (Symbole::multi, "*") (Symbole::divi, "/")
		(Symbole::paro, "(") (Symbole::virg, ",") (Symbole::nb, "num") (Symbole::Bd, "Bd")
		(Symbole::P, "P") (Symbole::Lv, "Lv") (Symbole::Lc, "Lc") (Symbole::Bi, "Bi")
		(Symbole::I, "I") (Symbole::E, "E") (Symbole::D, "D") (Symbole::Pprim, "P'") ;
