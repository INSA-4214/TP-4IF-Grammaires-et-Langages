/*
 * Symbole.cpp
 *
 *  Created on: 8 mars 2015
 *      Author: Huber
 */

#include "Symbole.h"


static const std::map<Symbole::Id, std::string> ID_NAMES = {
		{Symbole::D, "D"}, {Symbole::r, "lire"}, {Symbole::aff, ":="},
		{Symbole::plus, "+"}, {Symbole::moins, "-"}, {Symbole::cst, "const"},
		{Symbole::var, "var"}, {Symbole::parf, ")"}, {Symbole::pv, ";"},
		{Symbole::egal, "="}, {Symbole::w, "ecrire"}, {Symbole::D, "D"},
		{Symbole::multi, "*"}, {Symbole::divi, "/"},{Symbole::paro, "("},
		{Symbole::virg, ","}, {Symbole::var, ","}, {Symbole::nb, "num"},
		{Symbole::P, "P"}, {Symbole::Lv, "Lv"}, {Symbole::Lc, "Lc"},
		{Symbole::Li, "Li"}, {Symbole::I, "I"}, {Symbole::E, "E"}

};

Symbole::~Symbole() {
}
