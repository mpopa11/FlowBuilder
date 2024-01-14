#ifndef STEP_H
#define STEP_H

#include <string>
#include <iostream>
#include <fstream>
#include <variant>
#include <tuple>
#include <vector>

using StepData = std::variant<int, std::string, float, std::tuple<int, int, std::string>,
                     std::tuple<std::string, std::string, std::string>, std::tuple<std::string, std::string>, 
                     std::tuple<int, std::string>>;

class Step {
    protected:
        std::string output;
    public:
        virtual void setup() = 0;
        virtual StepData getStepData() const = 0;
        virtual void runStep(std::vector<StepData> stepData) = 0;
        std::string getOutput() {
            return this->output;
        };

    private:
        virtual void run() = 0;
};

class TitleStep : public Step {
    private:
        std::string title;
        std::string subtitle;
        void run() override;

    public:
        void setup() override;
        TitleStep();
        std::string getTitle();
        std::string getSubtitle();
        StepData getStepData() const override;
        void runStep(std::vector<StepData> stepData) override;
};

class TextStep : public Step {
    private:
        std::string title;
        std::string copy;
        void run() override;

    public:
        void setup() override;
        TextStep();
        std::string getTitle();
        std::string getCopy();
        StepData getStepData() const override;
        void runStep(std::vector<StepData> stepData) override;
};

class TextInputStep : public Step {
    private:
        std::string description;
        std::string textInput;
        void run() override;
    
    public:
        void setup() override;
        TextInputStep();
        std::string getDescription();
        std::string getTextInput();
        StepData getStepData() const override;
        void runStep(std::vector<StepData> stepData) override;
};

class NumberStep : public Step {
private:
    std::string description;
    float number;
    void run() override;

public:
    void setup() override;
    NumberStep();
    std::string getDescription();
    float getNumber();
    StepData getStepData() const override;
    void runStep(std::vector<StepData> stepData) override;
};

template <typename T>
class CalculusStep : public Step {
    private:
        int step1;
        int step2;
        std::string operation;
        void run() override;T performOperation(T operand1, T operand2, std::string operation) const;
        void inputOperation();

    public:
        CalculusStep();
        void setup() override;
        void runStep(std::vector<StepData> stepData) override;
        StepData getStepData() const override;
};

extern template class CalculusStep<int>;
extern template class CalculusStep<float>;

class DisplayStep : public Step {
    private:
        int step;
        void run() override;

    public:
        void setup() override;
        DisplayStep();
        int getStep();
        StepData getStepData() const override;
        void runStep(std::vector<StepData> stepData) override;
};

class TextFileStep : public Step {
    private:
        std::string description;
        std::string filename;
        std::string content;
        void run() override;
        std::string readFileContent();
        bool fileExists(std::string filename);
        
    public:
        void setup() override;
        TextFileStep();
        std::string getDescription();
        std::string getFilename();
        StepData getStepData() const override;
        void runStep(std::vector<StepData> stepData) override;
        
};

class CsvFileStep : public Step {
    private:
        std::string description;
        std::string filename;
        std::string content;
        void run() override;
        std::string readFileContent();
        bool fileExists(std::string filename);

    public:
        void setup() override;
        CsvFileStep();
        std::string getDescription();
        std::string getFilename();
        StepData getStepData() const override;
        void runStep(std::vector<StepData> stepData) override;
};

class OutputStep : public Step {
    private:
        int step;
        std::string fileName;
        std::string text;
        std::string description;
        void run() override;

    public:
        void setup() override;
        OutputStep();
        int getStep();
        std::string getFileName();
        std::string getText();
        std::string getDescription();
        StepData getStepData() const override;
        void runStep(std::vector<StepData> stepData) override;
};

class EndStep : public Step {
    private:
        void run() override;
    public:
        void setup() override;
        StepData getStepData() const override;
        void runStep(std::vector<StepData> stepData) override;
        EndStep();
};

#endif
