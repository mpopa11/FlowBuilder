#ifndef STEP_H
#define STEP_H

#include <string>
#include <iostream>
#include <fstream>

class Step {
    public:
        virtual void setup() = 0;
        virtual void run() = 0;
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
};

class CalculusStep : public Step {
private:
    int step1;
    int step2;
    std::string operation;

public:
    void setup() override;
    void run() override;
    void run (Step* step1, Step* step2);
    CalculusStep();
    int getStep1();
    int getStep2();
    std::string getOperation();
};

class DisplayStep : public Step {
private:
    int step;

public:
    void setup() override;
    void run() override;
    void run(Step* step);
    DisplayStep();
    int getStep();
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
};

class EndStep : public Step {
public:
    void setup() override;
    void run() override;
    EndStep();
};

#endif
