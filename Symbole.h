/*
 * Symbole.h
 *
 *  Created on: 8 mars 2015
 *      Author: Huber
 */

#ifndef SYMBOLE_H_
#define SYMBOLE_H_

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

// Symboles non-terminaux
// --------------------

// 'P' = Program
// 'Lv' = Liste de variables
// 'Lc' = Liste de constantes
// 'Ld' = Liste de declarations
// 'Li' = Liste d'nstructions
// 'D' = Declaration
// 'I' = Instruction
// 'E' = Expression

class Symbole {

public:
   enum Id {

       // Non-terminaux
       P, Lv, Lc, Ld, Li, D, I, E,
       // Terminaux
       r, aff, plus, moins, cst, var, parf, pv, egal, w, multi, divi, paro, virg, var, nb

   };

	Symbole(int id) : ident(id){}

	virtual ~Symbole();

	void print();

	operator int() const { return ident; }

protected:
	int ident;

private:
    static const std::map<Symbole::Id, std::string> ID_NAMES;

};

#endif /* SYMBOLE_H_ */
