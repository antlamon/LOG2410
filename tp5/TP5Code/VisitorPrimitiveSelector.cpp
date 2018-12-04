///////////////////////////////////////////////////////////
//  VisitorPrimitiveSelector.cpp
//  Implementation of the Class VisitorPrimitiveSelector
//  Created on:      07-nov.-2018 21:20:38
//  Original author: p482457
///////////////////////////////////////////////////////////

#include <exception>

#include "VisitorPrimitiveSelector.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Object3DComposite.h"
#include "TransformedObject3D.h"

VisitorPrimitiveSelector::VisitorPrimitiveSelector(PRIMITIVE_TYPE typ)
	: m_type(typ)
{
}

VisitorPrimitiveSelector::~VisitorPrimitiveSelector()
{
}

void VisitorPrimitiveSelector::visitCube(class Cube& cub)
{
	// A COMPLETER:
	// Verifier que la pile d'objets courants n'est pas vide
	// Verifier que le type de la primitive est bien celui recherchee
	// Si oui, ajouter la primitive dans les objets selectionnes
	if (!m_currentObjStack.empty())
		if (m_type == PRIMITIVE_TYPE::Cube_t)
			m_selectObjContainer.push_back(m_currentObjStack.back());
}

void VisitorPrimitiveSelector::visitCylinder(class Cylinder& cyl)
{
	// A COMPLETER:
	// Verifier que la pile d'objets courants n'est pas vide
	// Verifier que le type de la primitive est bien celui recherchee
	// Si oui, ajouter la primitive dans les objets selectionnes
	if (!m_currentObjStack.empty())
		if (m_type == PRIMITIVE_TYPE::Cylinder_t)
			m_selectObjContainer.push_back(m_currentObjStack.back());
}

void VisitorPrimitiveSelector::visitObjComposite(const Object3DComposite& comp)
{
	throw(std::invalid_argument("VisitorPrimitiveSelector cannot process const Objects"));
}

void VisitorPrimitiveSelector::visitObjComposite(class Object3DComposite& comp)
{
	// A COMPLETER:
	// Iterer sur les enfants du composite
	//		- Stocker l'enfant sur la pile des objets courants
	//		- Traiter l'enfant
	//		- Retirer l'enfant de sur la pile
	for (Object3DIterator it = comp.begin(); it != comp.end(); it++) {
		m_currentObjStack.push_back(it);	// on met l'iterator sur la pile d'objet courant
		it->accept(*this);					// on sélectionne la meilleure méthode de visite ici à l'aide du accept
		m_currentObjStack.pop_back();		// on retire l'iterator de la pile
	}
}

void VisitorPrimitiveSelector::visitPrimitive(const class PrimitiveAbs& prim)
{
	throw(std::invalid_argument("VisitorPrimitiveSelector cannot process const Objects"));
}

void VisitorPrimitiveSelector::visitPrimitive(class PrimitiveAbs& prim)
{
	// Type de primitive inconnue... cette primitive n'est pas selectionnee
}

void VisitorPrimitiveSelector::visitSphere(class Sphere& sph)
{
	// A COMPLETER:
	// Verifier que la pile d'objets courants n'est pas vide
	// Verifier que le type de la primitive est bien celui recherchee
	// Si oui, ajouter la primitive dans les objets selectionnes
	if (!m_currentObjStack.empty())
		if (m_type == PRIMITIVE_TYPE::Sphere_t)
			m_selectObjContainer.push_back(m_currentObjStack.back());
}

void VisitorPrimitiveSelector::visitTransformedObj(class TransformedObject3D& tobj)
{
	// A COMPLETER:
	// Deleguer le traitement a la primitive contenue dans le decorateur 
	tobj.accept(*this);
}

void VisitorPrimitiveSelector::getSelectObjects(Obj3DIteratorContainer & objContainer)
{
	// A COMPLETER:
	// Transferer les objets selectionnes du conteneur local au visiteur
	// vers le conteneur fourni en argument
	for (Obj3DIteratorContainer::iterator it = m_selectObjContainer.begin(); it != m_selectObjContainer.end(); it++)
		objContainer.push_back(*it);	// on ajoute l'objet à la fin du container local
}
