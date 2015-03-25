
#include "Lexer.h"

const boost::regex keyword("^(const |var |ecrire |lire ).*");
const boost::regex affect("^(:=).*");
const boost::regex single_operator("^(\\+|-|\\*|\\/|\\(|\\)|;|=|,)");
const boost::regex id("^([a-zA-Z][a-zA-Z0-9]*)");
const boost::regex number("([-+]?[0-9]*\\.?[0-9]+)");

Lexer::Lexer(std::istream * stream)
                     : m_stream(*stream)
{
}

bool Lexer::analyze() // regarde le prochain symbole terminal sans déplacer la tête de lecture
{
    if (m_str == "")
        getline(m_stream, m_str);

    boost::cmatch matches;

    if (regex_match(m_str.c_str(), matches, keyword)) {
        for (unsigned i = 0; i < matches.size(); i++) {
            std::cout << matches[i] << std::endl;
        }
        m_currentTokenStr = matches[1];
        switch (m_currentTokenStr[0]) {
            case 'c': m_currentToken = new Symbole(Symbole::cst); break;
            case 'v': m_currentToken = new Symbole(Symbole::var); break;
            case 'e': m_currentToken = new Symbole(Symbole::w); break;
            case 'l': m_currentToken = new Symbole(Symbole::r); break;
            default: break;
        }
    }
    else if (regex_match(m_str.c_str(), matches, affect)) {
        m_currentTokenStr = matches[1];
        m_currentToken = new Symbole(Symbole::aff);
    }
    else if (regex_match(m_str.c_str(), matches, single_operator)) {
        m_currentTokenStr = matches[1];
        switch (m_currentTokenStr[0]) {
            case '+': m_currentToken = new Symbole(Symbole::plus); break;
            case '-': m_currentToken = new Symbole(Symbole::moins); break;
            case '*': m_currentToken = new Symbole(Symbole::multi); break;
            case '/': m_currentToken = new Symbole(Symbole::divi); break;
            case '=': m_currentToken = new Symbole(Symbole::egal); break;
            case '(': m_currentToken = new Symbole(Symbole::parf); break;
            case ')': m_currentToken = new Symbole(Symbole::paro); break;
            case ',': m_currentToken = new Symbole(Symbole::virg); break;
            case ';': m_currentToken = new Symbole(Symbole::pv); break;
            default: break;
        }
    }
    else if (regex_match(m_str.c_str(), matches, id))
    {
        m_currentTokenStr = matches[1];
        m_currentToken = new Symbole(Symbole::idvar, m_currentTokenStr);
    }
    else if (regex_match(m_str.c_str(), matches, number)) {
        m_currentTokenStr = matches[1];
        double value = boost::lexical_cast<double>(m_currentTokenStr); // string to unsigned long long
        m_currentToken = new Symbole(Symbole::nb, value);
    }
    else
    {
        return false;
    }
    return true;
}

void Lexer::shift() // empile le prochain symbole terminal et déplace la tête de lecture sur le suivant
{
    unsigned int bufferSize = 30;
    // Vérifier qu'il y a un token après celui-là
    // Créer buffer (taille 30 par ex) et ajouter le flux dedans
    std::string buffer;
    while (buffer.size() < bufferSize)
    {
        //buffer +=
    }
    // Trouver le premier symbole terminal
    // Empiler le symbole et l'état associé
    // Retirer le symbole du buffer, les éventuels espaces après et ajouter des caractères pour ramener le buffer à la longueur 30
    // Vérifier si réduction, si oui alors dépiler
}


Lexer::~Lexer()
{
    //dtor
}
