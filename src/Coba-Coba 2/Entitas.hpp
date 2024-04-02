#ifndef ENTITAS_HPP
#define ENTITAS_HPP

#include <string>

using namespace std;

class Entitas
{
public:
    virtual ~Entitas() {}
    virtual void Panen() = 0;
};

#endif
