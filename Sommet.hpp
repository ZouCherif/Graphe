#pragma once
#include "GElement.hpp"
#include <sstream>

template <typename T>
class Sommet : public GElement<T> {

public:
    int degre;
    Sommet(int clef, T v) : GElement<T>(clef, v), degre(0) {}

    operator std::string() const {
        std::ostringstream oss;
        
        if constexpr (std::is_same_v<T, std::string>) {
            oss << "Sommet - Clef : " + std::to_string(this->clef) + ", V : " + this->v + ", Degré : " + std::to_string(degre);
        }
        else {
            oss << "Sommet - Clef : " + std::to_string(this->clef) + ", V : " + std::to_string(this->v) + ", Degré : " + std::to_string(degre);
        }

        return oss.str();
    }

    friend std::ostream& operator<<(std::ostream& os, const Sommet<T>& s) {
        os << static_cast<std::string>(s);
        return os;
    }

};

