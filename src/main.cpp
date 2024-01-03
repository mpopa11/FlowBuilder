#include <iostream>
#include <vector>
#include "flowManager.h"  // Assuming you have a header file for your steps

int main() {
    // Create steps
    TitleStep titleStep;
    TextStep textStep;
    TextInputStep textInputStep;
    NumberStep numberStep;
    CalculusStep calculusStep;
    DisplayStep displayStep;
    TextFileStep textFileStep;
    CsvFileStep csvFileStep;
    OutputStep outputStep;
    EndStep endStep;

    // Set up steps
    titleStep.setup();
    textStep.setup();
    textInputStep.setup();
    numberStep.setup();
    calculusStep.setup();
    displayStep.setup();
    textFileStep.setup();
    csvFileStep.setup();
    outputStep.setup();
    endStep.setup();

    // Create a flow
    Flow  flow("Test Flow");

    // Add steps to the flow
    flow.addStep(&titleStep);
    flow.addStep(&textStep);
    flow.addStep(&textInputStep);
    flow.addStep(&numberStep);
    flow.addStep(&calculusStep);
    flow.addStep(&displayStep);
    flow.addStep(&textFileStep);
    flow.addStep(&csvFileStep);
    flow.addStep(&outputStep);
    flow.addStep(&endStep);

    // Start the flow
    flow.start();

    return 0;
}
