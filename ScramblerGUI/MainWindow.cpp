#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
#include "../Scrambler/FileScrambler.h"
#include "License.h"
#include "About.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_mExitButton_clicked()
{
    QApplication::quit();
}

void MainWindow::on_mEncodeButton_clicked()
{
    if (!IsValidInput()) return;
    const auto defaultPath= ui->mFileEdit->text()+mEncodedFileExtension;
    const auto outputPath = QFileDialog::getSaveFileName(this, "", defaultPath);
    CallEncoding(outputPath, Encoding::ENCODE);
}

void MainWindow::on_mDecodeButton_clicked()
{
    if (!IsValidInput()) return;
    auto defaultPath= ui->mFileEdit->text();
    const auto extensionLength = mEncodedFileExtension.size();
    if (defaultPath.endsWith(mEncodedFileExtension, Qt::CaseInsensitive)
            && defaultPath.size()>extensionLength){
        const auto position = defaultPath.size()-extensionLength;
        defaultPath.remove( position, extensionLength);
    }

    const auto outputPath = QFileDialog::getSaveFileName(this, "", defaultPath);
    CallEncoding(outputPath, Encoding::DECODE);
}

void MainWindow::on_mFileButton_clicked()
{
    const auto file = QFileDialog::getOpenFileName(this);
    ui->mFileEdit->setText(file);
}

void MainWindow::BoxMessage(const QString &pMessage, const QString& pTitle)
{
    static QMessageBox box;
    box.setWindowTitle(pTitle);
    box.setText(pMessage);
    box.show();
}

bool MainWindow::IsValidInput()
{
    const std::string filePath = ui->mFileEdit->text().toStdString();
    const std::string keyword = ui->mKeyEdit->text().toStdString();

    QFileInfo file(filePath.data());

    bool result = true;

    static const QString errorTitle = tr("Error");
    if (keyword.empty()) {
        BoxMessage(tr("Keyword is empty."), errorTitle);
        result = false;
    }
    else if (filePath.empty()) {
        BoxMessage(tr("You must specify a valid file"), errorTitle);
        result = false;
    }
    else if (!file.exists()) {
        BoxMessage(tr("File could not be found:")+file.path() , errorTitle);
        result = false;
    }
    return result;
}

void MainWindow::CallEncoding(const QString &pOutputPath,
                              Encoding::Action pAction)
{
    if (!pOutputPath.size()) return;
    const auto inputPath=ui->mFileEdit->text();
    const auto keyword = ui->mKeyEdit->text();

    auto screen = new Encoding(this);
    screen->show();
    screen->Execute(inputPath, pOutputPath, keyword, pAction);
}

void MainWindow::on_actionLicense_triggered()
{
    auto screen = new License(this);
    screen->show();
}

void MainWindow::on_actionAbout_triggered()
{
    auto screen = new About(this);
    screen->show();
}
