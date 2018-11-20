///////////////////////////////////////////////////////////
//  Torus.cpp
//  Implementation of the Class Torus
//  Created on:      25-oct.-2018 20:47:26
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "Torus.h"

Torus::Torus(const Point3D& pt, float r1, float r2)
	: PrimitiveAbs(pt)
{
	if (r1 < 0.0 || r2 < 0.0)
		throw std::range_error("Invalid parameter value for Torus. Must be larger than 0");

	// A Completer...
	m_dimensions[0] = r1;
	m_dimensions[1] = r2;
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
	int outerRadius,
		innerRadius;
	if (m_dimensions[0] >= m_dimensions[1]) {
		outerRadius = m_dimensions[0];
		innerRadius = m_dimensions[1];
	}
	else {
		outerRadius = m_dimensions[1];
		innerRadius = m_dimensions[0];
	}
	return o << "Torus:  center = " << m_center
		<< "; outer radius = " << outerRadius
		<< "; inner radius = " << innerRadius << ";";
}
