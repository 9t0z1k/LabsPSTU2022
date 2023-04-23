#include "Pair.h"

Pair& Pair::operator=(const Pair& pair) {
    this->fNum = pair.fNum;
    this->sNum = pair.sNum;
    return *this;
}

Pair& Pair::operator=(const int& t) {
    this->fNum = t;
    this->sNum = t;
    return *this;
}

Pair Pair::operator*(Pair& pair) {
    Pair new_pair;
    new_pair.fNum = this->fNum * pair.fNum;
    new_pair.sNum = this->sNum * pair.sNum;
    return new_pair;
}

std::ostream& operator<<(std::ostream& out, const Pair& pair) {
    out << pair.fNum << " : " << pair.sNum;
    return out;
}

std::istream& operator>>(std::istream& in, Pair& pair) {
    in >> pair.fNum >> pair.sNum;
    return in;
}
