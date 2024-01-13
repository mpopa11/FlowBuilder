#ifndef FLOW_H
#define FLOW_H

#include "step.h"
#include "errors.h"
#include <vector>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

class Flow {
    private:
        std::vector<Step*> steps;
        std::string name;
        std::string timestamp;
        int timesStarted;
        int timesFinished;
        int stepCount;
        std::vector<int> skippedScreenCount;
        std::vector<int> errorScreenCount;
        float averageErrors;
        void skipStep(int stepIndex);
        void printSteps();
    public:
        Flow(std::string name);
        void addStep(Step* step);
        void start();
        void checkData();
        std::string getName();
        std::string getTimestamp();
        int getTimesStarted();
        int getTimesFinished();
        int getStepCount();
        std::vector<int>& getSkippedScreenCount();
        std::vector<int>& getErrorScreenCount();
        float getAverageErrors();
};

#endif