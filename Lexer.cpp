
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

void Lexer::parse(string* filename) {

	cout << "Parsing du fichier..." <<endl;
	ifstream t (filename->c_str());
	stringstream buffer;
	buffer << t.rdbuf();
	m_str = buffer.str();
	// On enl�ve les espaces au d�but du fichier
    m_str.erase(0, m_str.find_first_not_of(" \t\n\r\f\v"));
}

bool Lexer::analyze()
{

    boost::cmatch matches;
    string premierMot = m_str.substr(0, m_str.find_first_of(" \t\n\r\f\v"));
    cout << "\"" << premierMot << "\"" << endl;
    if (regex_search(premierMot.c_str(), matches, keyword)) {
        //for (unsigned i = 0; i < matches.size(); i++) {
        //    std::cout << matches[i] << std::endl;
        //}
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
            case '(': m_symboleCourant = new Symbole(Symbole::parf); break;
            case ')': m_symboleCourant = new Symbole(Symbole::paro); break;
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
        double value = boost::lexical_cast<double>(m_symboleCourantStr); // string to unsigned long long
        m_symboleCourant = new Symbole(Symbole::nb, value);
    }
    else
    {
    	cerr << "AIE !" << endl;
        return false;
    }
    return true;
}

void Lexer::shift() {

    if (!hasNext()) {
    	return;
    }

    m_str=m_str.substr(m_str.find_first_of(" \t\n\r\f\v"));
    m_str.erase(0, m_str.find_first_not_of(" \t\n\r\f\v"));
}

bool Lexer::hasNext(){
	return (m_str.length() > 0);
}

Lexer::~Lexer()
{
}
