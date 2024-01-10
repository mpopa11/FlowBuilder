#ifndef STEP_H
#define STEP_H

#include <string>
#include <iostream>
#include <fstream>
#include <variant>
#include <tuple>

using StepData = std::variant<int, std::string, float, std::tuple<int, int, std::string>,
                     std::tuple<int, std::string, std::string, std::string>>;

class Step {
    public:
        virtual void setup() = 0;
        virtual void run() = 0;
        virtual StepData getStepData() const = 0;
};

class TitleStep : public Step {
    private:
        std::string title;
        std::string subtitle;

    public:
        void setup() override;
        void run() override;
        TitleStep();
        std::string getTitle();
        std::string getSubtitle();
        StepData getStepData() const override;
};

class TextStep : public Step {
    private:
        std::string title;
        std::string copy;

    public:
        void setup() override;
        void run() override;
        TextStep();
        std::string getTitle();
        std::string getCopy();
        StepData getStepData() const override;
};

class TextInputStep : public Step {
    private:
        std::string description;
        std::string textInput;
    public:
        void setup() override;
        void run() override;
        TextInputStep();
        std::string getDescription();
        std::string getTextInput();
        StepData getStepData() const override;
};

class NumberStep : public Step {
private:
    std::string description;
    float number;

public:
    void setup() override;
    void run() override;
    NumberStep();
    std::string getDescription();
    float getNumber();
    StepData getStepData() const override;
};
template <typename T>
class CalculusStep : public Step {
private:
    int step1;
    int step2;
    std::string operation;

public:
    CalculusStep();

    void setup() override;
    void run() override;
    void run(Step* step1, Step* step2);
    StepData getStepData() const override;

private:
    T performOperation(T operand1, T operand2, std::string operation) const;
};
extern template class CalculusStep<int>;
extern template class CalculusStep<float>;

class DisplayStep : public Step {
private:
    int step;

public:
    void setup() override;
    void run() override;
    void run(Step* step);
    DisplayStep();
    int getStep();
    StepData getStepData() const override;
};

class TextFileStep : public Step {
private:
    std::string description;
    std::string filename;
    
public:
    void setup() override;
    void run() override;
    TextFileStep();
    std::string getDescription();
    std::string getFilename();
    std::string readFileContent();
    StepData getStepData() const override;
};

class CsvFileStep : public Step {
private:
    std::string description;
    std::string filename;
public:
    void setup() override;
    void run() override;
    CsvFileStep();
    std::string getDescription();
    std::string getFilename();
    std::string readFileContent();
    StepData getStepData() const override;
};

class OutputStep : public Step {
private:
    int step;
    std::string fileName;
    std::string text;
    std::string description;

public:
    void setup() override;
    void run() override;
    void run(Step* step);
    OutputStep();
    int getStep();
    std::string getFileName();
    std::string getText();
    std::string getDescription();
    StepData getStepData() const override;
};

class EndStep : public Step {
public:
    void setup() override;
    void run() override;
    StepData getStepData() const override;
    EndStep();
};

#endif
