#pragma once
#include "AElement.hpp"
#include <sstream>

template <typename T>
class GElement: public AElement{

public:
    T v;
     GElement(int clef, T v) : AElement(clef), v(v) {}

    operator std::string() const {
        std::ostringstream oss;
        
        if constexpr (std::is_same_v<T, std::string>) {
            oss << "Sommet - Clef : " + std::to_string(this->clef) + ", V : " + v;
        }
        else {
            oss << "Sommet - Clef : " + std::to_string(this->clef) + ", V : " + std::to_string(v);
        }

        return oss.str();
    }

    friend std::ostream& operator<<(std::ostream& os, const GElement& elem){
        os << static_cast<std::string>(elem);
        return os;
    }
};

