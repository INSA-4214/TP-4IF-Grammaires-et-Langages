/*
 * Symbole.h
 *
 *  Created on: 8 mars 2015
 *      Author: Huber
 */

#ifndef SYMBOLE_H_
#define SYMBOLE_H_

#include <map>
#include <string>
// Symboles terminaux


// 'r' = lire
// 'aff' = affectation
// 'plus' = `+`
// 'moins' = `-`
// 'cst' = const
// 'var' = var
// 'parf' = `)`
// 'pv' = `;`
// 'egal' = `=`
// 'w' = ecrire
// 'multi' = `*`
// 'divi' = `/`
// 'paro' = `(`
// 'virg' = `,`
// 'var' = variable
// `nb` = nombre
//  idvar = id

// Symboles non-terminaux
// --------------------

// Pprim =P'
// 'P' = Program
// 'Lv' = Liste de variables
// 'Lc' = Liste de constantes
// 'Bd' = Bloc de declarations
// 'Bi' = Bloc d'nstructions
// 'D' = Declaration
// 'I' = Instruction
// 'E' = Expression

class Symbole {

public:
   enum Id {

       // Non-terminaux
       Pprim,P, Lv, Lc, Bd, Bi, D, I, E,
       // Terminaux
       r, aff, plus, moins, cst, var, parf, pv, egal, w, multi, divi, paro, virg, nb, idvar, ERR

   };

	Symbole(Symbole::Id id) : ident(id){}

	Symbole(Symbole::Id id, std::string s) : ident(id), str(s) {}

	Symbole(Symbole::Id id, double val) : ident(id), value(val) {}

	virtual ~Symbole(){}

	void print();

	operator Symbole::Id() const { return ident; }

	Symbole::Id ident;
	std::string str;
	double value;

    static const std::map<Symbole::Id, std::string> ID_NAMES;

};

#endif /* SYMBOLE_H_ */
