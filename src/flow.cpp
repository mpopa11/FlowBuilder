#include "flow.h"

Flow::Flow(std::string name) {
    this->name = name;
    this->timesStarted = 0;
    this->timesFinished = 0;
    this->stepCount = 0;
    this->averageErrors = 0;
    
     std::chrono::system_clock::time_point creationTimestamp;
    creationTimestamp = std::chrono::system_clock::now();
    // Convert time_point to time_t
    std::time_t time = std::chrono::system_clock::to_time_t(creationTimestamp);

    // Convert time_t to string
    std::stringstream ss;
    ss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
    this->timestamp = ss.str();
}

void Flow::addStep(Step* step) {
    this->steps.push_back(step);
    this->stepCount++;
}

void Flow::start() {
    this->timesStarted++;
    std::vector<StepData> stepsData;
    bool retryCurrentStep = false;
    std::string skip;
    bool validInput = false;

    for (int i = 0; i < this->steps.size(); i++) {
       
            // Check if it's the last step (EndStep)
            bool isLastStep = (i == this->steps.size() - 1);

            if (isLastStep) {
                std::cout << "This is the EndStep" << std::endl;
                timesFinished++;
                return;
            } else {
                if (!retryCurrentStep) {
                    validInput = false;
                    while (!validInput) {
                        std::cout << "Do you want to skip this step? (y/n)" << std::endl;
                        std::cin >> skip;

                        if (skip == "y" || skip == "n") {
                            validInput = true;
                        } else {
                            std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
                        }
                    }
                }
            }

            if (skip == "y" && !isLastStep) {
                this->skipStep(i);
            } else {
                bool setupComplete = false;

                while (!setupComplete) {
                    //setupComplete = false;
                    try {
                        std::visit([&](auto&& data) {
                            using T = std::decay_t<decltype(data)>;
                            if constexpr (std::is_same_v<T, std::tuple<int, int, std::string>>) {
                                //Calculus step logic
                                int step1Index = std::get<0>(data);
                                int step2Index = std::get<1>(data);
                                std::string operation = std::get<2>(data);

                                if (step1Index > i || step2Index > i) {
                                    throw StepInPast();
                                }

                                Step* step1 = this->steps[step1Index];
                                Step* step2 = this->steps[step2Index];

                                //get stepdata for step1 and step 2
                                StepData step1Data = step1->getStepData();
                                StepData step2Data = step2->getStepData();

                               if (!std::holds_alternative<float>(step1Data) || !std::holds_alternative<float>(step2Data)) {
                                    throw NotNumberType();
                                }

                                float step1Value = std::get<float>(step1Data);
                                float step2Value = std::get<float>(step2Data);

                                // add stepdata to vector
                                stepsData.push_back(step1Data);
                                stepsData.push_back(step2Data);
                            } else if constexpr (std::is_same_v<T, int>) {
                                //Display

                                int stepIndex = data;

                                if (stepIndex > i) {
                                    throw StepInPast();
                                }

                                Step* step = this->steps[stepIndex];

                                //get stepdata for step
                                StepData stepData = step->getStepData();

                                if (!std::holds_alternative<std::tuple<std::string, std::string>>(stepData) &&
                                    !std::holds_alternative<std::tuple<std::string, std::string, std::string>>(stepData)) {
                                    throw InvalidStepFormat();
                                }

                                //add stepdata to vector
                                stepsData.push_back(stepData);
                            } else if constexpr (std::is_same_v<T, std::tuple<int, std::string>>) {
                                //output step logic

                                int stepIndex = std::get<0>(data);

                                if (stepIndex > i) {
                                    throw StepInPast();
                                }

                                Step* step = this->steps[stepIndex];

                                //get stepdata for step
                                StepData stepData = step->getOutput();

                                //add stepdata to vector
                                stepsData.push_back(stepData);
                            }
                        }, this->steps[i]->getStepData());

                        setupComplete = true; // Setup completed without errors
                    } catch (std::exception& e) {
                        std::cout << e.what() << std::endl;
                        std::cout << "Repair the Step and try again." << std::endl;
                        this->steps[i]->setup();
                    }
                }

                // run step, if error at runtime, ask user if they want to skip or retry
                try {
                    this->steps[i]->runStep(stepsData);
                } catch (std::exception& e) {
                    std::cout << e.what() << std::endl;
                    this->errorScreenCount[i]++;

                     validInput = false;

                    while (!validInput) {
                    std::cout << "Do you want to skip this step? (y/n)" << std::endl;
                    std::cin >> skip;

                    if (skip == "y" || skip == "n") {
                        validInput = true;
                    } else {
                        std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
                    }
                }
                    if (skip == "y") {
                        this->skipStep(i);
                        retryCurrentStep = false;
                    } else {
                       i--;
                       retryCurrentStep = true;
                    }
                }

                if (stepsData.size() > 0) {
                    stepsData.clear();
                }
            }
        }
    }

void Flow::checkData() {
    std::cout << "Flow: " << this->name << std::endl;
    std::cout << "Timestamp: " << this->timestamp << std::endl;
    std::cout << "Times started: " << this->timesStarted << std::endl;
    std::cout << "Times finished: " << this->timesFinished << std::endl;
    std::cout << "Step count: " << this->stepCount << std::endl;
    std::cout << "Skipped screen count: ";
    for (int i = 0; i < this->skippedScreenCount.size(); i++) {
        std::cout << this->skippedScreenCount[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Error screen count: ";
    for (int i = 0; i < this->errorScreenCount.size(); i++) {
        std::cout << this->errorScreenCount[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Average errors: " << this->averageErrors << std::endl;
}

std::string Flow::getName() {
    return this->name;
}

std::string Flow::getTimestamp() {
    return this->timestamp;
}

int Flow::getTimesStarted() {
    return this->timesStarted;
}

int Flow::getTimesFinished() {
    return this->timesFinished;
}

int Flow::getStepCount() {
    return this->stepCount;
}

std::vector<int>& Flow::getSkippedScreenCount() {
    return this->skippedScreenCount;
}

std::vector<int>& Flow::getErrorScreenCount() {
    return this->errorScreenCount;
}

float Flow::getAverageErrors() {
    return this->averageErrors;
}

void Flow::skipStep(int stepIndex) {
    std::cout << "Skipping step " << stepIndex << std::endl;
    this->skippedScreenCount[stepIndex]++;
}

void Flow::printSteps() {
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

Flow::~Flow() {
    for (Step* step : steps) {
        delete step;
    }
}