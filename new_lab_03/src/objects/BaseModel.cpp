#include "BaseModel.h"

BaseModel::BaseModel() {}

BaseModel::~BaseModel() {}

void BaseModel::Add(std::shared_ptr<Object> obj) { (void) obj;}

void BaseModel::Remove(const iterator &it) { (void) it; }

BaseModel::iterator BaseModel::begin() { return iterator(); }

BaseModel::iterator BaseModel::end() { return iterator(); }

void BaseModel::accept(std::shared_ptr<Visitor> v) { (void) v; }

std::shared_ptr<Object> BaseModel::Clone() const { return nullptr;}
