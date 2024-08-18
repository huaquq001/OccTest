/*
*    Copyright (c) 2018 Shing Liu All Rights Reserved.
*
*           File : occQt.h
*         Author : Shing Liu(eryar@163.com)
*           Date : 2018-01-08 20:00
*        Version : OpenCASCADE7.2.0 & Qt5.7.1
*
*    Description : OpenCASCADE in Qt.
*/

#ifndef _H_OCCQT_H_
#define _H_OCCQT_H_


#include <AIS_InteractiveContext.hxx>
#include <TopoDS.hxx>

//! Qt main window which include OpenCASCADE for its central widget.
class OccQt
{
public:
    //! make cylindrical helix.
    void makeCylindricalHelix(void);

    //! make conical helix.
    void makeConicalHelix(void);

    //! make toroidal helix.
    void makeToroidalHelix(void);


    //! make box test.
    static TopoDS_Shape MakeBox(const Standard_Real dx, const Standard_Real dy, const Standard_Real dz);

    //! make cone test.
    void makeCone(void);

    //! make sphere test.
    static TopoDS_Shape MakeSphere(Standard_Real R);

    //! make cylinder test.
    void makeCylinder(void);

    //! make torus test.
    void makeTorus(void);

    //! fillet test.
    void makeFillet(void);

    //! chamfer test.
    void makeChamfer(void);

    //! test extrude algorithm.
    void makeExtrude(void);

    //! test revol algorithm.
    void makeRevol(void);

    //! test loft algorithm.
    void makeLoft(void);

    //! test boolean operation cut.
    void testCut(void);

    //! test boolean operation fuse.
    void testFuse(void);

    //! test boolean operation common.
    void testCommon(void);

    //! test helix shapes.
    void testHelix(void);

    void SetContext(Handle(AIS_InteractiveContext) context);
private:
    Handle(AIS_InteractiveContext) m_context;
};

#endif // OCCQT_H
