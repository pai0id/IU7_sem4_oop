/**
 * Project Untitled
 */


#include "BaseModel.hpp"

/**
 * BaseModel implementation
 */

BaseModel::BaseModel() {}

BaseModel::~BaseModel() {}

void BaseModel::Accept(std::shared_ptr<Visitor> v)
{
    (void) v;
};
