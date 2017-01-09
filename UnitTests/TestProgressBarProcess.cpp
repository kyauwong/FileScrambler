#include "TestProgressBarProcess.h"
#include "../Scrambler/ProgressBarProcess.h"


class MockProgressBarProcess: public ProgressBarProcess {
public:
    void SetTotal(size_t pTotal);
    void SetCurrent(size_t pCurrent);
    void AddStep();
    void AddSteps(size_t pSteps);
};

void MockProgressBarProcess::SetTotal(size_t pTotal){
    SetTotalSteps(pTotal);
}

void MockProgressBarProcess::SetCurrent(size_t pCurrent){
    SetCompletedSteps(pCurrent);
}

void MockProgressBarProcess::AddStep(){
    AddOneCompletedStep();
}

void MockProgressBarProcess::AddSteps(size_t pSteps) {
    AddCompletedSteps(pSteps);
}

void TestProgressBarProcess::TestInterface()
{
    MockProgressBarProcess pProcess;
    const size_t expectTotal = 1000;
    size_t expectCurrent = 5;
    auto percent = [&expectTotal, &expectCurrent]()->float{
        return 100.*expectCurrent/expectTotal;
    };

    auto checkResult=[&]() {
        QCOMPARE(pProcess.GetTotalSteps(), expectTotal);
        QCOMPARE(pProcess.GetCompletedSteps(), expectCurrent);
        QCOMPARE(pProcess.GetCompletedPercentage(), percent());
    };

    pProcess.SetTotal(expectTotal);
    pProcess.SetCurrent(expectCurrent);
    checkResult();
    QVERIFY(!pProcess.IsFinished());

    pProcess.AddStep();
    pProcess.AddStep();
    expectCurrent+=2;
    checkResult();
    QVERIFY(!pProcess.IsFinished());

    pProcess.AddSteps(23);
    expectCurrent+=23;
    checkResult();
    QVERIFY(!pProcess.IsFinished());
    pProcess.SetCurrent(expectTotal);
    QVERIFY(pProcess.IsFinished());
}
