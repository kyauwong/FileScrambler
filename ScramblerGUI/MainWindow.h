#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Encoding.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void on_mExitButton_clicked();

    void on_mEncodeButton_clicked();

    void on_mDecodeButton_clicked();

    void on_mFileButton_clicked();

    void on_actionLicense_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
    void BoxMessage(const QString& pMessage, const QString& pTitle="");
    bool IsValidInput();
    void CallEncoding(const QString& pOutputPath, Encoding::Action pAction);
    const QString mEncodedFileExtension=".fsf";
};

#endif // MAINWINDOW_H
