#ifndef ENCODING_H
#define ENCODING_H

#include <QMainWindow>
#include "FileScrambler.h"
#include <functional>

class QProgressBar;

namespace Ui {
class Encoding;
}

class Encoding : public QMainWindow
{
    Q_OBJECT

public:
    explicit Encoding(QWidget *parent = 0);
    ~Encoding();

    enum Action{ENCODE, DECODE};
    void Execute(const QString& pInputPath, const QString& pOutputPath,
                 const QString& pKeyword, Action pAction);

private:
    Ui::Encoding *ui;

    typedef FileScrambler::BinaryData BinaryData;
    void RunWithProgressBar(QProgressBar* pBar,
                           const ProgressBarProcess& pProcess,
                           std::function<void()> pFunction);

    BinaryData ReadFile(const QString& pInput);
    void FlipBytes(BinaryData& pData, const QString& pKeyword);
    void WriteFile(BinaryData& pData, const QString& pOutputPath);
};

#endif // ENCODING_H
