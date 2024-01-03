#include "step.h"


TitleStep::TitleStep() {

}

void TitleStep::setup() {
    std::cout << "Enter title: ";
    std::cin >> title;

    std::cout << "Enter subtitle: ";
    std::cin >> subtitle;
}

void TitleStep::run() {
    std::cout << "Title is: " << this->title << std::endl;
    std::cout << "Subtitle is: " << this->subtitle << std::endl;
}

std::string TitleStep::getTitle() {
    return this->title;
}

std::string TitleStep::getSubtitle() {
    return this->subtitle;
}

TextStep::TextStep(){

}

void TextStep::setup() {
    std::cout << "Enter title: ";
    std::cin >> title;

    std::cout << "Enter copy: ";
    std::cin >> copy;
}

void TextStep::run() {
    std::cout << "Title is: " << this->title << std::endl;
    std::cout << "Copy is: " << this->copy << std::endl;
}

std::string TextStep::getTitle() {
    return this->title;
}

std::string TextStep::getCopy() {
    return this->copy;
}

TextInputStep::TextInputStep() {

}

void TextInputStep::setup() {
    std::cout << "Enter description: ";
    std::cin >> description;
}

void TextInputStep::run() {
    std::cout << "Description: " << this->description << std::endl;
    std::cout << "Enter text: ";
    std::cin >> textInput;
}

std::string TextInputStep::getDescription() {
    return this->description;
}

std::string TextInputStep::getTextInput() {
    return this->textInput;
}

NumberStep::NumberStep() {

}

void NumberStep::setup() {
    std::cout << "Enter description: ";
    std::cin >> description;
}

void NumberStep::run() {
    std::cout << "Enter number: ";
    std::cin >> number;
}

std::string NumberStep::getDescription() {
    return this->description;
}

float NumberStep::getNumber() {
    return this->number;
}

CalculusStep::CalculusStep() {

}

void CalculusStep::setup() {
    std::cout << "Enter first step: ";
    std::cin >> step1;

    std::cout << "Enter second step: ";
    std::cin >> step2;

    std::cout << "Enter operation: ";
    std::cin >> operation;
}

void CalculusStep::run() {
    //empty override to virtual function
}

void CalculusStep::run(Step* step1, Step* step2) {
    int firstNumber = dynamic_cast<NumberStep*>(step1)->getNumber();
    int secondNumber = dynamic_cast<NumberStep*>(step2)->getNumber();

    if (this->operation == "+") {
        std::cout << firstNumber + secondNumber << std::endl;
    } else if (this->operation == "-") {
        std::cout << firstNumber - secondNumber << std::endl;
    } else if (this->operation == "*") {
        std::cout << firstNumber * secondNumber << std::endl;
    } else if (this->operation == "/") {
        std::cout << firstNumber / secondNumber << std::endl;
    } else if (this->operation == "min") {
        std::cout << std::min(firstNumber, secondNumber) << std::endl;
    } else if (this->operation == "max") {
        std::cout << std::max(firstNumber, secondNumber) << std::endl;
    }
}

int CalculusStep::getStep1() {
    return this->step1;
}

int CalculusStep::getStep2() {
    return this->step2;
}

std::string CalculusStep::getOperation() {
    return this->operation;
}

DisplayStep::DisplayStep() {

}

void DisplayStep::setup() {
    std::cout << "Enter step: ";
    std::cin >> step;
}

void DisplayStep::run() {
    //empty override for virtual function
}

void DisplayStep::run(Step* step) {
    // Display the content if it's a TextInputStep
    TextInputStep* textInputStep = dynamic_cast<TextInputStep*>(step);
    if (textInputStep) {
        std::cout << "Displaying TextInputStep Content: " << textInputStep->getTextInput() << std::endl;
    }

    // Display the contents of the file if it's a TextFileStep
    TextFileStep* textFileStep = dynamic_cast<TextFileStep*>(step);
    if (textFileStep) {
        std::cout << "Displaying TextFileStep Content from File: " << textFileStep->readFileContent() << std::endl;
    }

    // Display the contents of the CSV file if it's a CsvFileStep
    CsvFileStep* csvFileStep = dynamic_cast<CsvFileStep*>(step);
    if (csvFileStep) {
        std::cout << "Displaying CsvFileStep Content from File: " << csvFileStep->readFileContent() << std::endl;
    }
}

int DisplayStep::getStep() {
    return this->step;
}

TextFileStep::TextFileStep() {

}

void TextFileStep::setup() {
    std::cout << "Enter description: ";
    std::cin >> description;
    std::cout << "Enter filename: ";
    std::cin >> filename;
}

void TextFileStep::run() {
    std::cout << "Description: " << this->description << std::endl;
    std::cout << "Filename: " << this->filename << std::endl;
}

std::string TextFileStep::readFileContent() {
    std::ifstream file(filename);
    std::string content;
    
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            content += line + "\n";
        }
        file.close();
    } else {
        content = "Unable to open file: " + filename;
    }

    return content;
}

std::string TextFileStep::getDescription() {
    return this->description;
}

std::string TextFileStep::getFilename() {
    return this->filename;
}

CsvFileStep::CsvFileStep() {

}

void CsvFileStep::setup() {
    std::cout << "Enter description: ";
    std::cin >> description;
    std::cout << "Enter filename: ";
    std::cin >> filename;
}

void CsvFileStep::run() {
    std::cout << "Description: " << this->description << std::endl;
    std::cout << "Filename: " << this->filename << std::endl;
}

std::string CsvFileStep::getDescription() {
    return this->description;
}

std::string CsvFileStep::getFilename() {
    return this->filename;
}

std::string CsvFileStep::readFileContent() {
    std::ifstream file(filename);
    std::string content;
    
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            content += line + "\n";
        }
        file.close();
    } else {
        content = "Unable to open file: " + filename;
    }

    return content;
}

OutputStep::OutputStep() {

}

void OutputStep::setup() {
    std::cout << "Enter step: ";
    std::cin >> step;

    std::cout << "Enter filename: ";
    std::cin >> fileName;

    std::cout << "Enter text: ";
    std::cin >> text;

    std::cout << "Enter description: ";
    std::cin >> description;
}

void OutputStep::run() {
    //empty override for virtual function
}

void OutputStep::run(Step* step) {
    std::cout << "Step: " << this->step << std::endl;
    std::cout << "Filename: " << this->fileName << std::endl;
    std::cout << "Text: " << this->text << std::endl;
    std::cout << "Description: " << this->description << std::endl;
}

int OutputStep::getStep() {
    return this->step;
}

std::string OutputStep::getFileName() {
    return this->fileName;
}

std::string OutputStep::getText() {
    return this->text;
}

std::string OutputStep::getDescription() {
    return this->description;
}

EndStep::EndStep() {

}

void EndStep::setup() {
    //not implemented
}

void EndStep::run() {
    //not implemented
}





