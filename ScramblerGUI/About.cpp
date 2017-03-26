#include "About.h"
#include "ui_About.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()
                   ^Qt::WindowCloseButtonHint
                   ^Qt::WindowContextHelpButtonHint);
}

About::~About()
{
    delete ui;
}
