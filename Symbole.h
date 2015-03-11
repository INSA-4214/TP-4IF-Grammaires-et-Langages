/*
 * Symbole.h
 *
 *  Created on: 8 mars 2015
 *      Author: Huber
 */

#ifndef SYMBOLE_H_
#define SYMBOLE_H_

class Symbole {
public:
	Symbole(int id) : ident(id){};
	Symbole() : ident(0){}
	virtual ~Symbole();
	void print();
	operator int() const { return ident; }
protected:
	int ident;
};

#endif /* SYMBOLE_H_ */
