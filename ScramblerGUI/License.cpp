#include "License.h"
#include "ui_License.h"

License::License(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::License)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()
                   ^Qt::WindowCloseButtonHint
                   ^Qt::WindowContextHelpButtonHint);
}

License::~License()
{
    delete ui;
}
