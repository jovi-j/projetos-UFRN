#ifndef GRAAL_H
#define GRAAL_H

#include <utility>
using std::pair;
#include <iterator>
using std::distance;
#include <algorithm>
using std::sort;


/**
 * TODO: documentação no estilo doxygen
 */
template<class InputIt, class UnaryPredicate>
bool all_of(InputIt first, InputIt last, UnaryPredicate p)
{
    if (first == last && !p(*first))
        return false;

    for (; first != last; ++first)
        if (!p(*first))
            return false;
    return true;
}

/**
 * TODO: documentação no estilo doxygen
 */
template<class InputIt, class UnaryPredicate>
bool any_of(InputIt first, InputIt last, UnaryPredicate p)
{
    for (; first != last; ++first)
        if (p(*first))
            return true;
    return false;
}

/**
 * TODO: documentação no estilo doxygen
 */
template<class InputIt, class UnaryPredicate>
bool none_of(InputIt first, InputIt last, UnaryPredicate p)
{
    for (; first != last; ++first)
        if (p(*first))
            return false;
    return true;
}

#endif
