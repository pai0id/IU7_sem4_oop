/**
 * Project Untitled
 */


#ifndef _VISITOR_H
#define _VISITOR_H

#include "../scene/CarcasModel.hpp"
#include "../scene/Camera.hpp"

template <typename... Types>
class Visitor;

template <typename Type>
class Visitor<Type>
{
public:
    virtual void visit(Type& t) = 0;
};

template <typename Type, typename... Types>
class Visitor<Type, Types...> : public Visitor<Types...>
{
public:
    using Visitor<Types...>::visit;
    virtual void visit(Type& t) = 0;
};

using ObjectVisitor = Visitor<class Camera, class CarcasModel>;

#endif //_VISITOR_H
