cmake_minimum_required(VERSION 3.5.0)
include_directories(E:/3rdparty/OpenCASCADE-7.4.0-vc14-64/build/inc ./src ./inc)
include_directories(E:/3rdparty/OpenCASCADE-7.4.0-vc14-64/products/freetype-2.5.5-vc14-64/include)
link_directories(E:/3rdparty/OpenCASCADE-7.4.0-vc14-64/build/win64/vc14/libd)
link_directories(E:/3rdparty/OpenCASCADE-7.4.0-vc14-64/products/freetype-2.5.5-vc14-64/lib)

project(LamohCad VERSION 1.0.0)
#Qt5 
set(Qt6_DIR "E:/qt/6.5.3/msvc2019_64/lib/cmake/Qt6")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt6 COMPONENTS Core Widgets Quick REQUIRED) 

# List of available OpenCASCADE libraries for each module  每个模块中的库
set (FREETYPE_LIBRARIES freetype)
set (OpenCASCADE_FoundationClasses_LIBRARIES TKernel;TKMath)
set (OpenCASCADE_ModelingData_LIBRARIES TKG2d;TKG3d;TKGeomBase;TKBRep)
set (OpenCASCADE_ModelingAlgorithms_LIBRARIES TKGeomAlgo;TKTopAlgo;TKPrim;TKBO;TKShHealing;TKBool;TKHLR;TKFillet;TKOffset;TKFeat;TKMesh;TKXMesh)
set (OpenCASCADE_Visualization_LIBRARIES TKService;TKV3d;TKOpenGl;TKMeshVS)
set (OpenCASCADE_ApplicationFramework_LIBRARIES TKCDF;TKLCAF;TKCAF;TKBinL;TKXmlL;TKBin;TKXml;TKStdL;TKStd;TKTObj;TKBinTObj;TKXmlTObj;TKVCAF)
set (OpenCASCADE_DataExchange_LIBRARIES TKXSBase;TKSTEPBase;TKSTEPAttr;TKSTEP209;TKSTEP;TKIGES;TKXCAF;TKXDEIGES;TKXDESTEP;TKSTL;TKVRML;TKXmlXCAF;TKBinXCAF;TKRWMesh)
set (OpenCASCADE_Draw_LIBRARIES TKDraw;TKTopTest;TKViewerTest;TKXSDRAW;TKDCAF;TKXDEDRAW;TKTObjDRAW;TKQADraw)
# List of available OpenCASCADE libraries.所有的库
set (OpenCASCADE_LIBRARIES TKernel;TKMath;TKG2d;TKG3d;TKGeomBase;TKBRep;TKGeomAlgo;TKTopAlgo;TKPrim;TKBO;TKShHealing;TKBool;TKHLR;TKFillet;TKOffset;TKFeat;TKMesh;TKXMesh;TKService;TKV3d;TKOpenGl;TKMeshVS;TKCDF;TKLCAF;TKCAF;TKBinL;TKXmlL;TKBin;TKXml;TKStdL;TKStd;TKTObj;TKBinTObj;TKXmlTObj;TKVCAF;TKXSBase;TKSTEPBase;TKSTEPAttr;TKSTEP209;TKSTEP;TKIGES;TKXCAF;TKXDEIGES;TKXDESTEP;TKSTL;TKVRML;TKXmlXCAF;TKBinXCAF;TKRWMesh;TKDraw;TKTopTest;TKViewerTest;TKXSDRAW;TKDCAF;TKXDEDRAW;TKTObjDRAW;TKQADraw)
set(SOURCE_FILES
  "inc/Occ.h"
  "inc/MyQtWidgetsApplication.h"
  "inc/OccQt.h"
  "src/main.cpp"
  "src/Occ.cpp"
  "src/OccQt.cpp"
  "src/MyQtWidgetsApplication.cpp"
)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} 
                                      Qt6::Core Qt6::Widgets Qt6::Quick openGl32
                                      ${OpenCASCADE_ModelingData_LIBRARIES} 
                                      ${OpenCASCADE_ModelingAlgorithms_LIBRARIES} 
                                      ${OpenCASCADE_FoundationClasses_LIBRARIES} 
                                      ${OpenCASCADE_Visualization_LIBRARIES}
                                      ${FREETYPE_LIBRARIES})
									  