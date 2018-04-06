#ifndef __MUTANT_STACK__
#define __MUTANT_STACK__

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    typedef std::stack<T> base;

  public:
    MutantStack() {}
    MutantStack(MutantStack const &m) : base(m) {}
    using base::operator=;
    ~MutantStack() {}

    typedef typename base::container_type::iterator iterator;
    iterator begin() { return base::c.begin(); }
    iterator end() { return base::c.end(); }
};

#endif