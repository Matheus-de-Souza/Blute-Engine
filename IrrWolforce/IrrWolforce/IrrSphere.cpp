#include "IrrSphere.h"
#include <locale>

using namespace IrrWolforce;
using namespace core;

using namespace IrrWolforce;
using namespace core;
IrrSphere::IrrSphere(IMeshSceneNode *c){
	this->node = c;
}

void IrrSphere::setPosition(float x,float y ,float z)
{

	this->GameObject::setPosition(Vector(x,y,z));
	this->node->setPosition(vector3df(x,y,z));
}

void IrrSphere::setName(std::string* n){
	GameObject::setName(n);	
	locale loc;
	const collate<char>& coll = use_facet<collate<char>>(loc);
	this->node->setID(coll.hash(n->data(),n->data()+n->length()));
}