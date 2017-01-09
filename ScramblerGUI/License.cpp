#include "License.h"
#include "ui_License.h"

License::License(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::License)
{
    ui->setupUi(this);
}

License::~License()
{
    delete ui;
}
