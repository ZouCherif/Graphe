#pragma once
#include "GElement.hpp"
#include <sstream>

template <typename S, typename T>
class Arete : public GElement<S> {

public:
    Sommet<T>* debut;
    Sommet<T>* fin;
    Arete(int clef, const S& v, Sommet<T>* debut, Sommet<T>* fin) : GElement<S>(clef, v), debut(debut), fin(fin) {
        if (debut) {
            debut->degre++;
        }
        if (fin) {
            fin->degre++;
        }
    }

    ~Arete() {
        if (debut) {
            debut->degre--;
        }
        if (fin) {
            fin->degre--;
        }
    }

    operator std::string() const {
        std::ostringstream oss;
        oss << "Arete - Clef : " + std::to_string(this->clef) 
            << ", Debut : " + std::to_string(debut->clef)
            << ", Fin : " + std::to_string(fin->clef);
        return oss.str();
    }

    friend std::ostream& operator<<(std::ostream& os, const Arete<S, T>& arete) {
        os << static_cast<std::string>(arete);
        return os;
    }

    bool estEgal(const Sommet<T>* s1, const Sommet<T>* s2) const {
        return (debut == s1 && fin == s2) || (debut == s2 && fin == s1);
    }

};

