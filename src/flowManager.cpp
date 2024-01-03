#include "flowManager.h"
#include "step.h"

Flow* FlowManager::getFlow(std::string flowName) {
    for (int i = 0; i < this->flows.size(); i++) {
        if (this->flows[i]->getName() == flowName) {
            return this->flows[i];
        }
    }
    return NULL;
}

int FlowManager::getFlowIndex(std::string flowName) {
    for (int i = 0; i < this->flows.size(); i++) {
        if (this->flows[i]->getName() == flowName) {
            return i;
        }
    }
    return -1;
}

FlowManager::FlowManager() {

}

void FlowManager::addFlow() {
    std::string flowName;
    std::cout << "Enter flow name: ";
    std::cin >> flowName;
    Flow* flow = new Flow(flowName);
    this->flows.push_back(flow);

    int stepType = -1;

    while(stepType != 9) {
        this->printSteps();
        std::cin >> stepType;
        switch(stepType) {
            case 0: {
                TitleStep* step = new TitleStep();
                step->setup();
                flow->addStep(step);
                break;
            }
            case 1: {
                TextStep* step = new TextStep();
                step->setup();
                flow->addStep(step);
                break;
            }
            case 2: {
                TextInputStep* step = new TextInputStep();
                step->setup();
                flow->addStep(step);
                break;
            }
            case 3: {
                NumberStep* step = new NumberStep();
                step->setup();
                flow->addStep(step);
                break;
            }
            case 4: {
                CalculusStep* step = new CalculusStep();
                step->setup();
                flow->addStep(step);
                break;
            }
            case 5: {
                DisplayStep* step = new DisplayStep();
                step->setup();
                flow->addStep(step);
                break;
            }
            case 6: {
                TextFileStep* step = new TextFileStep();
                step->setup();
                flow->addStep(step);
                break;
            }
            case 7: {
                CsvFileStep* step = new CsvFileStep();
                step->setup();
                flow->addStep(step);
                break;
            }
            case 8: {
                OutputStep* step = new OutputStep();
                step->setup();
                flow->addStep(step);
                break;
            }
            case 9: {
                EndStep* step = new EndStep();
                step->setup();
                flow->addStep(step);
                break;
            }
            default: {
                std::cout << "Invalid step type" << std::endl;
                break;
            }
        }
    }
}

void FlowManager::runFlow(std::string flowName) {
    Flow* flow = this->getFlow(flowName);
    flow->start();
}

void FlowManager::checkData(std::string flowName) {
    Flow* flow = this->getFlow(flowName);
    flow->checkData();
}

void FlowManager::deleteFlow(std::string flowName) {
    int flowIndex = this->getFlowIndex(flowName);
    if (flowIndex != -1) {
        this->flows.erase(this->flows.begin() + flowIndex);
    }
}

void FlowManager::getTimestamp(std::string flowName) {
    Flow* flow = this->getFlow(flowName);
    std::cout << flow->getTimestamp() << std::endl;
}

void FlowManager::printSteps() {
    std::cout << "Available steps: " << std::endl;
    std::cout << "0. Title Step" << std::endl;
    std::cout << "1. Text Step" << std::endl;
    std::cout << "2. Text Input Step" << std::endl;
    std::cout << "3. Number Input Step" << std::endl;
    std::cout << "4. Calculus Step" << std::endl;
    std::cout << "5. Display Step" << std::endl;
    std::cout << "6. Text File Input Step" << std::endl;
    std::cout << "7. CSV File Input Step" << std::endl;
    std::cout << "8. Output Step" << std::endl;
    std::cout << "9. End Step" << std::endl;
    std::cout << "Select which step to add: " << std::endl;
}

void FlowManager::printFlows() {
    std::cout << "Available flows: " << std::endl;
    for (int i = 0; i < this->flows.size(); i++) {
        std::cout << this->flows[i]->getName() << std::endl;
    }
}

void FlowManager::runFlow() {
    std::string flowName;
    std::cout << "Enter flow name: ";
    std::cin >> flowName;
    this->runFlow(flowName);
}

void FlowManager::checkData() {
    std::string flowName;
    std::cout << "Enter flow name: ";
    std::cin >> flowName;
    this->checkData(flowName);
}

void FlowManager::deleteFlow() {
    std::string flowName;
    std::cout << "Enter flow name: ";
    std::cin >> flowName;
    this->deleteFlow(flowName);
}

void FlowManager::getTimestamp() {
    std::string flowName;
    std::cout << "Enter flow name: ";
    std::cin >> flowName;
    this->getTimestamp(flowName);
}

void FlowManager::flowMenu() {
    int option = -1;
    while (option != 0) {
        std::cout << "Flow Menu" << std::endl;
        std::cout << "1. Add flow" << std::endl;
        std::cout << "2. Run flow" << std::endl;
        std::cout << "3. Check data" << std::endl;
        std::cout << "4. Delete flow" << std::endl;
        std::cout << "5. Get timestamp" << std::endl;
        std::cout << "6. Print flows" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Select an option: ";
        std::cin >> option;
        switch(option) {
            case 1: {
                this->addFlow();
                break;
            }
            case 2: {
                this->runFlow();
                break;
            }
            case 3: {
                this->checkData();
                break;
            }
            case 4: {
                this->deleteFlow();
                break;
            }
            case 5: {
                this->getTimestamp();
                break;
            }
            case 6: {
                this->printFlows();
                break;
            }
            case 0: {
                break;
            }
            default: {
                std::cout << "Invalid option" << std::endl;
                break;
            }
        }
    }
}
