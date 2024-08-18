#include "MyQtWidgetsApplication.h"//引用.h的头文件
#include "OccQt.h"

MyQtWidgetsApplication::MyQtWidgetsApplication(QWidget* parent)
	: QMainWindow(parent)
{
	resize(1000, 1000);

	//提供X server的连接，在window和Mac中不起作用
	Handle(Aspect_DisplayConnection) hAspect_DisplayConnect = new Aspect_DisplayConnection;
	//创建3D接口定义图形驱动
	Handle(OpenGl_GraphicDriver) driver = new OpenGl_GraphicDriver(hAspect_DisplayConnect);

	//该类的方法允许编辑、询问连接该类的其他参数（如视图、光）
	m_viewer = new V3d_Viewer(driver);
	m_view = m_viewer->CreateView();

	WId win_handle = winId();
	//在已有的窗口上创建窗口
	m_window = new WNT_Window((Aspect_Handle)win_handle);
	m_view->SetWindow(m_window);
	if (!m_window->IsMapped())
	{
		m_window->Map();//打开窗口
	}

	m_view->SetBackgroundColor(Quantity_NOC_WHITE);
	m_view->MustBeResized();
	m_viewer->SetDefaultLights();
	m_view->TriedronDisplay(Aspect_TOTP_LEFT_LOWER, Quantity_NOC_WHITE, 0.1, V3d_ZBUFFER);
	setAttribute(Qt::WA_PaintOnScreen);
	//交互式上下文

	m_context = new AIS_InteractiveContext(m_viewer);
	m_context->SetDisplayMode(AIS_Shaded, Standard_True);

	OccQt occQt;
	occQt.SetContext(m_context);
	//occQt.testCommon();
	//occQt.testFuse();
	//occQt.testCut();
	//occQt.makeLoft();
	occQt.makeRevol();
	//TopoDS_Shape boxShape = occ.MakeBottle(50, 70, 30);
	//TopoDS_Shape boxShape = occ.FilletedBox(100, 60, 80, 10);
	//TopoDS_Shape boxShape = OccQt::MakeBox(50, 70, 30);
	//TopoDS_Shape boxShape = OccQt::MakeSphere(50);
	//Quantity_Color color = Quantity_Color(0.52, 0.8, 1, Quantity_TOC_RGB);

	//TopAbs_ShapeEnum shapeEnbum = boxShape.ShapeType();

	//Handle(AIS_Shape) abox = new AIS_Shape(boxShape);

	//m_context->SetMaterial(abox, Graphic3d_NameOfMaterial::Graphic3d_NOM_DIAMOND, Standard_False);
	//m_context->SetColor(abox, color, Standard_False);

	//m_context->Display(abox, 1, 1, Standard_True);
	m_view->FitAll();

}

MyQtWidgetsApplication::~MyQtWidgetsApplication()
{}

void MyQtWidgetsApplication::paintEvent(QPaintEvent* event)
{
	m_view->Redraw();
}

QPaintEngine* MyQtWidgetsApplication::paintEngine() const
{
	return 0;
}
void MyQtWidgetsApplication::mousePressEvent(QMouseEvent* event)
{
	//平移 鼠标右键+shift
	if ((event->buttons() & Qt::RightButton))//&& (QApplication::keyboardModifiers() == Qt::ShiftModifier))
	{
		m_mode = Action3d_Panning;
		m_x = event->pos().x();
		m_y = event->pos().y();
	}
	else if (event->buttons() & Qt::MiddleButton)//旋转
	{
		m_mode = Action3d_Rotation;
		//开始旋转视图围绕屏幕轴
		m_view->StartRotation(event->pos().x(), event->pos().y());
	}
}
void MyQtWidgetsApplication::mouseReleaseEvent(QMouseEvent* event)
{
	m_mode = Action3d_Nothing;
}

void MyQtWidgetsApplication::mouseMoveEvent(QMouseEvent* event)
{
	switch (m_mode)
	{
	case MyQtWidgetsApplication::Action3d_Panning:
		m_view->Pan(event->pos().x() - m_x, m_y - event->pos().y());
		m_x = event->pos().x();
		m_y = event->pos().y();
		break;
	case MyQtWidgetsApplication::Action3d_Rotation:
		m_view->Rotation(event->pos().x(), event->pos().y());
		break;
	default:
		break;
	}
}
//缩放
//Zoom方法通过相邻两侧鼠标位置来判断缩小或者放大，以及缩放程度。鼠标滚轮event->angleDelta().y()会返回数值，以此模拟第二次鼠标位置
void MyQtWidgetsApplication::wheelEvent(QWheelEvent* event)
{
	//view->Zoom(0, 0, event->angleDelta().y(), 0);//固定点缩放
	//跟随鼠标位置进行缩放
	m_view->StartZoomAtPoint(event->position().x(), event->position().y());
	m_view->ZoomAtPoint(0, 0, event->angleDelta().y(), 0);

}