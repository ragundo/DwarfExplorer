#include "hexviewer_window.h"
#include "df_model.h"
#include "node.h"
#include "MainWindow.h"
#include "QHexView/qhexview.h"
#include "QHexView/document/buffer/qmemorybuffer.h"

using namespace rdf;

extern std::string to_hex(uint64_t p_dec);

QHexViewer_Window::QHexViewer_Window(QWidget *parent, uint64_t p_address, char* p_data, std::size_t p_size) :
    QMainWindow(parent)
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

	QHexDocument *document = QHexDocument::fromMemory<QMemoryBuffer>(p_data, p_size);
	document->setBaseAddress(p_address);

	m_hexview = new QHexView(this);
	m_hexview->setDocument(document);
	m_hexview->setReadOnly(true);

	setCentralWidget(m_hexview);

	// Window tittle
	auto the_number = QString::fromStdString(to_hex(p_address));
	this->setWindowTitle("Memory viewer - " + the_number);

	MainWindow *mw = dynamic_cast<MainWindow*>(parent);
	bool ok = QObject::connect(mw, &MainWindow::resumed_signal, this, &QHexViewer_Window::on_MainWindow_resumed);

	//	readCustomData();
}

QHexView *QHexViewer_Window::get_hexview()
{
    return m_hexview;
}

void QHexViewer_Window::on_MainWindow_resumed()
{
	QString new_name = "OUTDATED -";
	auto name = this->windowTitle();
	new_name.append(name);
	this->setWindowTitle(new_name);

	//set_outdated();
}