#pragma once
#include <iostream>

class AElement {
public:
    int clef;

    AElement(int clef) : clef(clef) {}

    operator std::string() const {
        return "AElement(clef=" + std::to_string(clef) + ")";
    }

    friend std::ostream& operator<<(std::ostream& os, const AElement& elem) {
        os << static_cast<std::string>(elem);
        return os;
    }
};
