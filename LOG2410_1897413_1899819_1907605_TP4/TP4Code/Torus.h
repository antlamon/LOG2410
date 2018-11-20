///////////////////////////////////////////////////////////
//  Torus.h
//  Implementation of the Class Torus
//  Created on:      25-oct.-2018 20:47:26
//  Original author: p482457
///////////////////////////////////////////////////////////


#if !defined(EA_3CECD1D8_30C2_440c_AB86_B25404795AAF__INCLUDED_)
#define EA_3CECD1D8_30C2_440c_AB86_B25404795AAF__INCLUDED_

#include "PrimitiveAbs.h"

class Torus : public PrimitiveAbs
{

public:
	Torus(const Point3D& pt, float r, float ht);
	virtual ~Torus();
	virtual Torus* clone() const;

	virtual size_t getNbParameters() const;
	virtual PrimitiveParams getParameters() const;
	virtual void setParameter(size_t pIndex, float pValue);

private:
	virtual std::ostream& toStream(std::ostream& o) const;

	float m_dimensions[2];
};
#endif // !defined(EA_3CECD1D8_30C2_440c_AB86_B25404795AAF__INCLUDED_)

