#include "Sommet.hpp"
#include <iostream>
#include "GElement.hpp"
#include "AElement.hpp"
#include "Arete.hpp"



int main() {
    // AElement elem(123);
    // std::cout << "Affichage avec << : " << elem << std::endl;


    // GElement<int> elemG(123, 22);
    // std::cout << "Affichage avec << : " << elemG << std::endl;


    // Sommet<double> s1(3, 15.5);
    // std::cout << s1 << std::endl;
    // Sommet<std::string> s2(4, "SommetB");
    // std::cout << s2 << std::endl;


    Sommet<std::string> sommet1(1, "A");
    Sommet<std::string> sommet2(2, "B");
    Arete<char, std::string> arete(1, 'a', &sommet1, &sommet2);
    std::cout << "Affichage de l'arête : " << arete << std::endl;
    bool egal = arete.estEgal(&sommet1, &sommet2);
    std::cout << "L'arête relie les sommets 1 et 2 : " << (egal ? "true" : "false") << std::endl;


    return 0;
}
