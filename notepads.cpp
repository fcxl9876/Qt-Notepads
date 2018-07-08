#include "notepads.h"
#include "newpage.h"

Notepads::Notepads(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(640,480);
    this->setWindowIcon(QIcon(":/new/prefix1/Images/logo.ico"));

    //实例化
    fileMenu = new QMenu(this);//this指当前窗口
    editMenu = new QMenu(this);
    helpMenu = new QMenu(this);
    //添加到菜单栏并命名
    fileMenu = menuBar()->addMenu("&File");
    editMenu = menuBar()->addMenu("&Edit");
    helpMenu = menuBar()->addMenu("&Help");

    newAct = new QAction("New",this);
    newAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
    newAct->setStatusTip("New File");
    newAct->setIcon(QIcon(":/new/prefix1/Images/newFile.png"));

    openAct = new QAction("Open",this);
    openAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    openAct->setStatusTip("Open File");
    openAct->setIcon(QIcon(":/new/prefix1/Images/openFile.png"));

    saveAct = new QAction("Save",this);
    saveAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
    saveAct->setStatusTip("Save File");
    saveAct->setIcon(QIcon(":/new/prefix1/Images/saveFile.png"));

    saveAsAct = new QAction("Save As...",this);
    saveAsAct->setShortcut(QKeySequence(Qt::Key_F6));
    saveAsAct->setStatusTip("Save As...");

    printAct = new QAction("Print",this);
    printAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_P));
    printAct->setStatusTip("Print");
    printAct->setIcon(QIcon(":/new/prefix1/Images/print.png"));

    exitAct = new QAction("Exit",this);
    exitAct->setShortcut(QKeySequence(Qt::ALT + Qt::Key_F4));
    exitAct->setStatusTip("Exit");
    exitAct->setIcon(QIcon(":/new/prefix1/Images/exit.png"));

    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    undoAct = new QAction("Undo",this);
    undoAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z));
    undoAct->setStatusTip("Undo");
    undoAct->setIcon(QIcon(":/new/prefix1/Images/undo.png"));

    redoAct = new QAction("Redo",this);
    redoAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y));
    redoAct->setStatusTip("Redo");
    redoAct->setIcon(QIcon(":/new/prefix1/Images/redo.png"));

    copyAct = new QAction("Copy",this);
    copyAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_C));
    copyAct->setStatusTip("Copy");
    copyAct->setIcon(QIcon(":/new/prefix1/Images/copy.png"));

    cutAct = new QAction("Cut",this);
    cutAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_X));
    cutAct->setStatusTip("Cut");
    cutAct->setIcon(QIcon(":/new/prefix1/Images/cut.png"));

    pasteAct = new QAction("Paste",this);
    pasteAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_V));
    pasteAct->setStatusTip("Paste");
    pasteAct->setIcon(QIcon(":/new/prefix1/Images/paste.png"));

    clearAct = new QAction("Clear",this);
    clearAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Delete));
    clearAct->setStatusTip("Clear");

    allAct = new QAction("Select All",this);
    allAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_A));
    allAct->setStatusTip("Select All");

    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    editMenu->addSeparator();
    editMenu->addAction(copyAct);
    editMenu->addAction(cutAct);
    editMenu->addAction(pasteAct);
    editMenu->addSeparator();
    editMenu->addAction(clearAct);
    editMenu->addAction(allAct);

    aboutAct = new QAction("About...",this);
    aboutAct->setShortcut(QKeySequence(Qt::Key_F1));
    aboutAct->setStatusTip("About...");
    aboutAct->setIcon(QIcon(":/new/prefix1/Images/about.png"));

    updateAct = new QAction("What's New?",this);
    updateAct->setShortcut(QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key_N));
    updateAct->setStatusTip("What's New?");

    helpMenu->addAction(aboutAct);
    helpMenu->addAction(updateAct);

    mainToolBar = addToolBar("ToolBar");
    mainToolBar->addAction(newAct);
    mainToolBar->addAction(openAct);
    mainToolBar->addAction(saveAct);
    mainToolBar->addSeparator();
    mainToolBar->addAction(printAct);
    mainToolBar->addSeparator();
    mainToolBar->addAction(undoAct);
    mainToolBar->addAction(redoAct);
    mainToolBar->addAction(copyAct);
    mainToolBar->addAction(cutAct);
    mainToolBar->addAction(pasteAct);
    mainToolBar->addSeparator();
    mainToolBar->addAction(aboutAct);
    mainToolBar->addSeparator();
    mainToolBar->addAction(exitAct);

    textEdit = new QTextEdit();
    textEdit->setFont(QFont("Lucida Console", 10));//设置默认字体：字体，字体大小
    setCentralWidget(textEdit);//设置文本区域为整个窗口的中央部件

    textInfo = new QLabel();
    textInfo->setText("Ready");//设置默认显示内容
    statusBar()->addPermanentWidget(textInfo);//添加到状态栏,在软件右下角
    connect(textEdit,SIGNAL(cursorPositionChanged()),this,SLOT(showTextInfo()));

    connect(undoAct,SIGNAL(triggered()),this,SLOT(slotUndo()));
    connect(redoAct,SIGNAL(triggered()),this,SLOT(slotRedo()));
    connect(copyAct,SIGNAL(triggered()),this,SLOT(slotCopy()));
    connect(cutAct,SIGNAL(triggered()),this,SLOT(slotCut()));
    connect(pasteAct,SIGNAL(triggered()),this,SLOT(slotPaste()));
    connect(clearAct,SIGNAL(triggered()),this,SLOT(slotClear()));
    connect(allAct,SIGNAL(triggered()),this,SLOT(slotAll()));

    connect(aboutAct,SIGNAL(triggered()),SLOT(actAboutAuthor()));

    connect(newAct,SIGNAL(triggered()),SLOT(slotNew()));
    connect(openAct,SIGNAL(triggered()),SLOT(slotOpen()));
    connect(saveAct,SIGNAL(triggered()),SLOT(slotSave()));
    connect(saveAsAct,SIGNAL(triggered()),SLOT(slotSaveAs()));
    connect(printAct,SIGNAL(triggered()),SLOT(slotPrint()));
    connect(exitAct,SIGNAL(triggered()),SLOT(quitApp()));

    connect(updateAct,SIGNAL(triggered()),SLOT(showNewPage()));
}

Notepads::~Notepads()
{

}

void Notepads::showTextInfo(){
    QTextCursor textCursor = textEdit->textCursor();//获得鼠标光标
    int lineNum = textCursor.blockNumber();//行数
    int colNum = textCursor.columnNumber();//列数
    textInfo->setText(tr("Li:%1,Col:%2").arg(lineNum+1).arg(colNum));//显示在Label上，注意：行数是从0开始的
}

void Notepads::slotUndo(){
    textEdit->undo();
}

void Notepads::slotRedo(){
    textEdit->redo();
}

void Notepads::slotCopy(){
    textEdit->copy();
}

void Notepads::slotCut(){
    textEdit->cut();
}

void Notepads::slotPaste(){
    textEdit->paste();
}

void Notepads::slotClear(){
    textEdit->clear();
}

void Notepads::slotAll(){
    textEdit->selectAll();
}

void Notepads::actAboutAuthor(){
    QMessageBox::about(this,"About","This software was made By fcxl9876.\n\nVersion: Beta 2.0.1\nhttp://blog.fcxl9876.xin/");
}

bool Notepads::maybeSave(){
    if(textEdit->document()->isModified()){//判断文件是否被修改
        QMessageBox::StandardButtons result;
        result = QMessageBox::warning(this,"Waring","Do you want to save the file?",
                    QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

        if(result == QMessageBox::Cancel){//取消
            return false;
        }
        if(result == QMessageBox::Save){//保存
            return slotSave();
        }
        if(result == QMessageBox::Discard){//忽略，即不保存
            return true;
        }
    }else{
        return true;
    }
}

bool Notepads::slotSave(){
    if(currentFile.isEmpty()){
        return slotSaveAs();
    } else{
        return saveFile(currentFile);
        }
}

bool Notepads::slotSaveAs(){
    QString fileName =QFileDialog::getSaveFileName(this,tr("Save As"),
                                "/home/untitled",tr("Text Files (*.txt)"));
    if(fileName.isEmpty()){
        return false;
    }else{
        return saveFile(fileName);
    }
}

bool Notepads::saveFile(QString fileName){
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::critical(this,
                              "critical",
                              "cannot write file"
                              );
        return false;
    }else{
        QTextStream out(&file);
        out<<textEdit->toPlainText();
        setFileName(fileName);
        return true;
    }
}

void Notepads::slotNew(){
    if(maybeSave()){
        textEdit->clear();
        setFileName("");
    }
}

void Notepads::setFileName(QString fileName){
    currentFile = fileName;
    textEdit->document()->setModified(false);
    this->setWindowModified(false);
    fileName.isEmpty() ?
                this->setWindowFilePath("new.txt") :
                this->setWindowFilePath(fileName);
}

void Notepads::slotOpen(){
    if(maybeSave()){
        QString fileName = QFileDialog::getOpenFileName(this);
        if(!fileName.isEmpty()){
            loadFile(fileName);
        }
    }
}

//加载文件的函数
void Notepads::loadFile(QString fileName){
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::critical(this,
                              "critical",
                              "cannot read file"
                              );
    }else{
        QTextStream in(&file);
        textEdit->setText(in.readAll());
        setFileName(fileName);
    }
}

void Notepads::quitApp(){
    if(maybeSave()){
        qApp->closeAllWindows();//关闭所有窗口
    }
}

void Notepads::slotPrint(){
    // 创建打印机对象
    QPrinter printer;
    // 创建打印对话框
    QPrintDialog dlg(&printer, this);
    //如果编辑器中有选中区域，则打印选中区域
    if (textEdit->textCursor().hasSelection())
        dlg.addEnabledOption(QAbstractPrintDialog::PrintSelection);
    // 如果在对话框中按下了打印按钮，则执行打印操作
    if (dlg.exec() == QDialog::Accepted) {
        textEdit->print(&printer);
    }
}

void Notepads::closeEvent(QCloseEvent *e){
    if(maybeSave()){
        e->accept();
    }else{
       e->ignore();//忽略，直接关闭
    }
}

void Notepads::showNewPage(){
    newpage *np;
    np = new newpage;
    np->show();
}
