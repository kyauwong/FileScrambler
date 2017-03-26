#include "Encoding.h"
#include "ui_Encoding.h"

#include <thread>
#include <iostream>
#include <QThread>

Encoding::Encoding(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Encoding)
{
    ui->setupUi(this);
}

Encoding::~Encoding()
{
    delete ui;
}

void Encoding::Execute(const QString &pInputPath, const QString &pOutputPath,
                       const QString& pKeyword, Action pAction)
{
    ui->pushButton->setText(tr("Cancel"));
    auto data = ReadFile(pInputPath);
    FlipBytes(data, pKeyword);
    WriteFile(data, pOutputPath);
    ui->pushButton->setText(tr("Close"));
}

auto Encoding::ReadFile(const QString &pInput)-> BinaryData
{
    BinaryData result;
    FileScrambler::ReadFileBytes process;
    auto functionWrapper= [&]()->void{
            result = process.Read(pInput.toStdString());
    };
    RunWithProgressBar(ui->readBar, process, functionWrapper);
    return result;
}

void Encoding::FlipBytes(BinaryData &pData, const QString& pKeyword)
{
    FileScrambler::FlipBits process;
    const auto seeds = FileScrambler::StringToSeed(pKeyword.toStdString());
    auto randomFlipGen = FileScrambler::MersenneRandFlipGen(seeds);
    auto functionWrapper = [&]()->void {
            process.Encode(pData, randomFlipGen);
    };
    RunWithProgressBar(ui->encodeBar1, process, functionWrapper);
}

void Encoding::WriteFile(BinaryData &pData, const QString &pOutputPath)
{
    FileScrambler::WriteBytesToFile process;
    auto functionWrapper = [&]()->void {
            process.Write(pData, pOutputPath.toStdString());
    };
    RunWithProgressBar(ui->writeBar, process, functionWrapper);
}

class WorkThread:public QThread {
public:
    void SetThread(std::function<void()> pFunction) {
        mFunction = pFunction;
    }

protected:
    void run() override {
        mFunction();
    }

private:
    std::function<void()> mFunction;
};

void Encoding::RunWithProgressBar(QProgressBar *pBar,
                                 const ProgressBarProcess &pProcess,
                                 std::function<void()> pFunction)
{
    WorkThread thread;
    thread.SetThread(pFunction);
    thread.start();

    while(!pProcess.IsFinished()){
        if (1!=pBar->maximum()) {
            pBar->setValue(pProcess.GetCompletedSteps());
        }
        else {
            pBar->setMaximum(pProcess.GetTotalSteps());
        }
        QApplication::processEvents();
    }
    pBar->setMaximum(pProcess.GetTotalSteps());
    pBar->setValue(pBar->maximum());
    QApplication::processEvents();
}

