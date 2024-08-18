#ifndef _H_OCC_H_
#define _H_OCC_H_

#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>

//QT


using namespace std;

class OCC
{
public:
	TopoDS_Shape MakeBottle(const Standard_Real myWidth, const Standard_Real myHeight, const Standard_Real myThickness);
	TopoDS_Shape FilletedBox(const Standard_Real a, const Standard_Real b, const Standard_Real c, const Standard_Real r);
};

#endif