#ifndef FLOW_MANAGER_H
#define FLOW_MANAGER_H

#include "flow.h"
#include <vector>

class FlowManager {
private:
    std::vector<Flow*> flows;
    void printSteps();
    Flow* getFlow(std::string flowName);
    int getFlowIndex(std::string flowName);
    void runFlow(std::string flowName);
    void checkData(std::string flowName);
    void deleteFlow(std::string flowName);
    void getTimestamp(std::string flowName);
    

public:
    FlowManager();
    void flowMenu();
    void addFlow();
    void runFlow();
    void checkData();
    void deleteFlow();
    void getTimestamp();
    void printFlows();
    ~FlowManager();
};

#endif
