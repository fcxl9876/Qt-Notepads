#ifndef NEWPAGE_H
#define NEWPAGE_H

#include <QMainWindow>
#include <QWidget>
#include <QTextEdit>
#include <QString>

#pragma execution_character_set("utf-8")

class newpage : public QMainWindow
{
    Q_OBJECT
public:
    newpage(QWidget *parent = 0);
    ~newpage();

private:
    QTextEdit *textbox;

};

#endif // NEWPAGE_H
