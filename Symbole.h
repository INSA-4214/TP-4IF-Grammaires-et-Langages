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
// 'OpePlus' = `+`
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
       r, aff, plus, moins, cst, var, parf, pv, egal, w, multi, divi, paro, virg, nb, idvar, FILEEND

   };

    Symbole(Symbole::Id id);
	Symbole(Symbole::Id id, std::string s ) : ident(id), str(s) {}

	virtual ~Symbole(){}

	void print();
    std::string getStr();
    Symbole::Id getIdent();


protected:
   Symbole::Id ident;
   std::string str;



};


#endif /* SYMBOLE_H_ */
