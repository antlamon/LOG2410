///////////////////////////////////////////////////////////
//  Torus.cpp
//  Implementation of the Class Torus
//  Created on:      25-oct.-2018 20:47:26
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "Torus.h"

Torus::Torus(const Point3D& pt, float rExt, float rInt)
	: PrimitiveAbs(pt)
{
	if (rExt < 0.0 || rInt < 0.0)
		throw std::range_error("Invalid parameter value for Torus. Must be larger than 0");

	if (rExt <=  rInt )
		throw std::range_error("Invalid parameter value for Torus. Outer radius must be bigger than inner radius");

	// A Completer...
	m_dimensions[0] = rExt;
	m_dimensions[1] = rInt;
}

Torus::~Torus() {
}

Torus * Torus::clone() const
{
	return new Torus(m_center, m_dimensions[0], m_dimensions[1]);
}

size_t Torus::getNbParameters() const {

	// A Completer...
	return 2;
}

PrimitiveParams Torus::getParameters() const
{
	// A Completer...
	PrimitiveParams params{ m_dimensions[0], m_dimensions[1] };
	return params;
}

void Torus::setParameter(size_t pIndex, float pValue) {
	if (pIndex < 0 || pIndex > 1)
		throw std::range_error("Invalid parameter index for Torus. Must be between 0 and 1");

	if (pValue < 0.0)
		throw std::range_error("Invalid parameter value for Torus. Must be larger than 0");

	// A Completer...
	m_dimensions[pIndex] = pValue;
}

std::ostream & Torus::toStream(std::ostream & o) const
{
	return o << "Torus:  center = " << m_center
		<< "; outer radius = " << m_dimensions[0]
		<< "; inner radius = " << m_dimensions[1] << ";";
}
