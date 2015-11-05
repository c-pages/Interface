#ifndef UTILITAIRES_H
#define UTILITAIRES_H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <sstream>

// Since std::to_string doesn't work on MinGW we have to implement
// our own to support all platforms.
template <typename T>
std::string toString(const T& value);

#include <Utilitaires.inl>

#endif // UTILITAIRES_H
