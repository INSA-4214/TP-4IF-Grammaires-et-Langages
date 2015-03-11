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
// 'var' = name of a variable
// `nb` = number (positive integer)

// Non-terminal symbols
// --------------------

// + `A ` = Axiom
// + `P ` = Program
// + `Ld` = List of declarations (may be empty)
// + `Li` = List of instructions (at least one)
// + `D ` = Declaration
// + `Lv` = List of variables (may be empty)
// + `Lc` = List of constants (may be empty)
// + `I ` = Instruction
// + `E ` = Expression

class Symbole {
public:

public:
   enum Id {
       // Non-terminals (see above)
       A, P, Ld, Li, D, Lv, Lc, I, E,
       // Terminals
       cst, var,
   };
	Symbole(int id) : ident(id){};
	Symbole() : ident(0){}
	virtual ~Symbole();
	void print();
	operator int() const { return ident; }

protected:
	int ident;

};

#endif /* SYMBOLE_H_ */
