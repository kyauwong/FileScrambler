#include "ProgressBarProcess.h"

size_t ProgressBarProcess::GetCompletedSteps() const
{
    return mCompletedSteps;
}

size_t ProgressBarProcess::GetTotalSteps() const
{
    return mTotalSteps;
}

float ProgressBarProcess::GetCompletedPercentage() const
{
    return float(100.)*mCompletedSteps/mTotalSteps;
}

bool ProgressBarProcess::IsFinished() const
{
    return  mTotalSteps==mCompletedSteps;
}

void ProgressBarProcess::SetCompletedSteps(const size_t &pProgress)
{
    mCompletedSteps = pProgress;
}

void ProgressBarProcess::SetTotalSteps(const size_t &pMaxProgress)
{
    mTotalSteps = pMaxProgress;
}

void ProgressBarProcess::AddCompletedSteps(const size_t &pAdd)
{
    mCompletedSteps+=pAdd;
}

void ProgressBarProcess::AddOneCompletedStep()
{
    ++mCompletedSteps;
}
