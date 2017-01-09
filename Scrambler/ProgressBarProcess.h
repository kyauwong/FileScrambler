#ifndef PROGRESSBARPROCESS_H
#define PROGRESSBARPROCESS_H

class ProgressBarProcess
{
public:
    ProgressBarProcess() = default;
    size_t GetCompletedSteps() const;
    size_t GetTotalSteps() const;
    float GetCompletedPercentage() const;
    bool IsFinished() const;


protected:
    void SetCompletedSteps(const size_t& pProgress);
    void SetTotalSteps(const size_t& pMaxProgress);
    void AddCompletedSteps(const size_t& pAdd);
    void AddOneCompletedStep();
private:
    size_t mTotalSteps=1;
    size_t mCompletedSteps = 0;
};

#endif // PROGRESSBARPROCESS_H
