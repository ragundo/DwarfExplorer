#include "hexviewer_window.h"
#include "df_model.h"
#include "node.h"

using namespace rdf;


QHexViewer_Window::QHexViewer_Window(QWidget *parent, Qt::WindowFlags flags):
    QMainWindow(parent, flags)
{
	QToolBar *ptb = addToolBar("File");

//	QAction *pactOpen = ptb -> addAction("Open...");
//	pactOpen -> setShortcut(QKeySequence("Ctrl+O"));
//	connect(pactOpen, SIGNAL(triggered()), SLOT(slotOpen()));

//	QMenu *pmenu = menuBar() -> addMenu("&File");
//	pmenu -> addAction(pactOpen);
//	addAction (pactOpen);
//	pmenu -> addAction("Go to offset...", this, SLOT(slotToOffset())); 
//	pmenu -> addAction("About...", this, SLOT(slotAbout()));
//	pmenu -> addAction("Exit", this, SLOT(close()));

	m_hexview = new QHexView(this);
	setCentralWidget(m_hexview);

//	readCustomData();
}

QHexView* QHexViewer_Window::get_hexview()
{
    return m_hexview;
}
