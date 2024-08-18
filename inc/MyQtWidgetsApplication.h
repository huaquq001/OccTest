#pragma once

#include <QtWidgets/QMainWindow>
#include <Standard_Handle.hxx>
#include <V3d_Viewer.hxx>
#include <OpenGl_GraphicDriver.hxx>
#include <WNT_Window.hxx>
#include <V3d_View.hxx>
#include <AIS_InteractiveContext.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <TopoDs_Shape.hxx>
#include <AIS_Shape.hxx>

#include <qevent.h>

#include "OCC.h"

class MyQtWidgetsApplication : public QMainWindow
{
	Q_OBJECT

public:
	MyQtWidgetsApplication(QWidget* parent = nullptr);
	~MyQtWidgetsApplication();
protected:
	//重写绘图事件
	void paintEvent(QPaintEvent* event) override;
	//返回窗口绘图引擎
	QPaintEngine* paintEngine() const;

	enum Action3d
	{
		Action3d_Nothing,
		Action3d_Panning,//平移
		Action3d_Zooming,//缩放
		Action3d_Rotation//旋转
	};

	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void wheelEvent(QWheelEvent* event) override;


private:
	//Ui::QtWidgetsApplication1Class  ui;
	//定义查看器viewer 3D查看器
	Handle(V3d_Viewer) m_viewer;
	//视图
	Handle(V3d_View) m_view;
	//交互式上下文，管理一个或者多个viewer
	Handle(AIS_InteractiveContext) m_context;
	//window NT窗口
	Handle(WNT_Window) m_window;


	Standard_Integer m_x = 0;//记录鼠标平移坐标X
	Standard_Integer m_y = 0;//记录鼠标平移坐标y
	Action3d m_mode = Action3d_Nothing;//平移、缩放、旋转

	OCC occ;

};