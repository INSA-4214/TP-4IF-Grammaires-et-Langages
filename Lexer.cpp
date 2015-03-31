
#include "Lexer.h"
#include<fstream>
#include<sstream>

using namespace std;

const boost::regex keyword("^(const|var|ecrire|lire).*");
const boost::regex affect("^(:=).*");
const boost::regex single_operator("^(\\+|-|\\*|\\/|\\(|\\)|;|=|,)");
const boost::regex id("^([a-zA-Z][a-zA-Z0-9]*)");
const boost::regex number("([-+]?[0-9]*\\.?[0-9]+)");

Lexer::Lexer(string* filename)
{
	parse(filename);
}

Symbole* Lexer::getSymboleCourant(){
	return m_symboleCourant;
}

void Lexer::parse(string* filename) {

	cout << "Parsing du fichier..." <<endl;
	ifstream t (filename->c_str());
	stringstream buffer;
	buffer << t.rdbuf();
	m_texteEntier = buffer.str();
	m_str = m_texteEntier;
	// On enlève les espaces au début du fichier
    m_str.erase(0, m_str.find_first_not_of(" \t\n\r\f\v"));
}

bool Lexer::analyze()
{

    boost::cmatch matches;
    string premierMot = m_str.substr(0, m_str.find_first_of(" \t\n\r\f\v"));
    if (regex_search(premierMot.c_str(), matches, keyword)) {
        m_symboleCourantStr = matches[1];
        switch (m_symboleCourantStr[0]) {
            case 'c': m_symboleCourant = new Symbole(Symbole::cst); break;
            case 'v': m_symboleCourant = new Symbole(Symbole::var); break;
            case 'e': m_symboleCourant = new Symbole(Symbole::w); break;
            case 'l': m_symboleCourant = new Symbole(Symbole::r); break;
            default: break;
        }
    }
    else if (regex_search(premierMot.c_str(), matches, affect)) {
    	m_symboleCourantStr = matches[1];
    	m_symboleCourant = new Symbole(Symbole::aff);
    }
    else if (regex_search(premierMot.c_str(), matches, single_operator)) {
    	m_symboleCourantStr = matches[1];
        switch (m_symboleCourantStr[0]) {
            case '+': m_symboleCourant = new Symbole(Symbole::plus); break;
            case '-': m_symboleCourant = new Symbole(Symbole::moins); break;
            case '*': m_symboleCourant = new Symbole(Symbole::multi); break;
            case '/': m_symboleCourant = new Symbole(Symbole::divi); break;
            case '=': m_symboleCourant = new Symbole(Symbole::egal); break;
            case '(': m_symboleCourant = new Symbole(Symbole::paro); break;
            case ')': m_symboleCourant = new Symbole(Symbole::parf); break;
            case ',': m_symboleCourant = new Symbole(Symbole::virg); break;
            case ';': m_symboleCourant = new Symbole(Symbole::pv); break;
            default: break;
        }
    }
    else if (regex_search(premierMot.c_str(), matches, id))
    {
    	m_symboleCourantStr = matches[1];
    	m_symboleCourant = new Symbole(Symbole::idvar, m_symboleCourantStr);
    }
    else if (regex_search(premierMot.c_str(), matches, number)) {
    	m_symboleCourantStr = matches[1];
        m_symboleCourant = new Symbole(Symbole::nb, m_symboleCourantStr);
    }
    else if (m_symboleCourant->getIdent() != Symbole::FILEEND)
    {
    	m_symboleCourantStr = m_str.substr(0, 1);
        cout << "Caractere ignore : \"" << m_symboleCourantStr << "\"" << endl;

        getCurrPos();

        cerr << "Erreur lexicale (" << m_pos[0] << ":" << m_pos[1] << ") caractere " << m_symboleCourantStr << endl;
        return false;
    }
    cout << "\"" << m_symboleCourantStr << "\"" << endl;
    return true;
}

void Lexer::shift() {

	if (!hasNext()) {
    	return;
    }

	if (!analyze()) {
    	return;
    }

	m_str=m_str.substr(m_symboleCourantStr.size());
	m_str.erase(0, m_str.find_first_not_of(" \t\n\r\f\v"));

}

bool Lexer::hasNext(){
	bool continuer = m_str.length() > 0;
	if (!continuer) {
		cout << "Reste a parser : \"" << m_str << "\"" << endl;
		m_symboleCourant = new Symbole(Symbole::FILEEND);
	}
	return continuer;
}

int * Lexer::getCurrPos() // On cherche la position du problème
{
	m_debutTexte = m_texteEntier.substr(0, m_texteEntier.size() - m_str.size()); // m_debutTexte + m_str = m_texteEntier
    int ligne = 1 + std::count(m_debutTexte.begin(), m_debutTexte.end(), '\n');

    while (m_debutTexte.find('\n') != std::string::npos)
    {
        m_debutTexte = m_debutTexte.substr(m_debutTexte.find('\n') + 1);
    }
    int colonne = 1 + m_debutTexte.size();

    m_pos[0] = ligne;
    m_pos[1] = colonne;

    return m_pos;
}

Lexer::~Lexer()
{
}
