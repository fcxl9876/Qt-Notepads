#ifndef NOTEPADS_H
#define NOTEPADS_H

#include "newpage.h"
#include <QMainWindow>
#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QTextEdit>
#include <QLabel>
#include <QStatusBar>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QCloseEvent>
#include <QApplication>
#include <QPrinter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QFileDialog>
#include <QFileInfo>

#pragma execution_character_set("utf-8")

class Notepads : public QMainWindow
{
    Q_OBJECT
public:
    Notepads(QWidget *parent = 0);
    ~Notepads();
    bool maybeSave();
    bool saveFile(QString fileName);
    void setFileName(QString fileName);
    void loadFile(QString fileName);
    void closeEvent(QCloseEvent *e);

public slots:
    void showTextInfo();
    void slotUndo();
    void slotRedo();
    void slotCopy();
    void slotCut();
    void slotPaste();
    void slotClear();
    void slotAll();
    void actAboutAuthor();
    bool slotSave();
    bool slotSaveAs();
    void slotNew();
    void slotOpen();
    void slotPrint();
    void quitApp();
    void showNewPage();

private:
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;

    QAction *newAct; //新建
    QAction *openAct; //打开
    QAction *saveAct; //保存
    QAction *saveAsAct; //另存为
    QAction *printAct; //打印
    QAction *exitAct; //退出

    QAction *undoAct; //撤销
    QAction *redoAct; //重做
    QAction *copyAct; //复制
    QAction *cutAct; //剪切
    QAction *pasteAct; //粘贴
    QAction *clearAct; //清空
    QAction *allAct; //全选

    QAction *aboutAct; //关于
    QAction *updateAct; //更新

    QToolBar *mainToolBar;

    QTextEdit *textEdit;

    QLabel *textInfo;

    QString currentFile;
};

#endif // NOTEPADS_H
