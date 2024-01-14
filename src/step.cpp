#include "step.h"
#include "errors.h"
#include <limits>

TitleStep::TitleStep() {

}

void TitleStep::setup() {
    std::cout << "Enter title: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    std::cout << "Enter subtitle: ";
    std::cin.ignore();
    std::getline(std::cin, subtitle);
}

void TitleStep::run() {
    std::cout << "Title is: " << this->title << std::endl;
    std::cout << "Subtitle is: " << this->subtitle << std::endl;

    this->output = "Title: " + this->title + "\nSubtitle: " + this->subtitle;
}

std::string TitleStep::getTitle() {
    return this->title;
}

std::string TitleStep::getSubtitle() {
    return this->subtitle;
}

StepData TitleStep::getStepData() const {
    return "";
}

void TitleStep::runStep(std::vector<StepData> stepData) {
    this->run();
}

TextStep::TextStep(){

}

void TextStep::setup() {
    std::cout << "Enter title: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    std::cout << "Enter copy: ";
    std::cin.ignore();
    std::getline(std::cin, copy);
}

void TextStep::run() {
    std::cout << "Title is: " << this->title << std::endl;
    std::cout << "Copy is: " << this->copy << std::endl;

    this->output = "Title: " + this->title + "\nCopy: " + this->copy;
}

std::string TextStep::getTitle() {
    return this->title;
}

std::string TextStep::getCopy() {
    return this->copy;
}

StepData TextStep::getStepData() const {
    return "";
}

void TextStep::runStep(std::vector<StepData> stepData) {
    this->run();
}

TextInputStep::TextInputStep() {

}

void TextInputStep::setup() {
    std::cout << "Enter description: ";
    std::cin.ignore();
    std::getline(std::cin, description);
}

void TextInputStep::run() {
    std::cout << "Description: " << this->description << std::endl;
    std::cout << "Enter text: ";
    std::cin.ignore();
    std::getline(std::cin, textInput);

    this->output = "Description: " + this->description + "\nText: " + this->textInput;
}

std::string TextInputStep::getDescription() {
    return this->description;
}

std::string TextInputStep::getTextInput() {
    return this->textInput;
}

StepData TextInputStep::getStepData() const {
    return std::make_tuple(description, textInput);
}

void TextInputStep::runStep(std::vector<StepData> stepData) {
    this->run();
}

NumberStep::NumberStep() {

}

void NumberStep::setup() {
    std::cout << "Enter description: ";
    std::cin.ignore();
    std::getline(std::cin, description);
}

void NumberStep::run() {
    std::cout << "Enter number: ";
    if (!(std::cin >> number)) {
        // If input is not a valid float, throw an exception
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input

        this->output = InvalidNumberInput().what();
        throw InvalidNumberInput();
    }

    this->output = "Description: " + this->description + "\nNumber: " + std::to_string(this->number);
}

std::string NumberStep::getDescription() {
    return this->description;
}

float NumberStep::getNumber() {
    return this->number;
}

StepData NumberStep::getStepData() const {
    return this->number;  
}


void NumberStep::runStep(std::vector<StepData> stepData) {
    this->run();
}

template <typename T>
CalculusStep<T>::CalculusStep() {

}

template <typename T>
void CalculusStep<T>::setup() {
    std::cout << "Enter first step index: ";
    if (!(std::cin >> step1)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw InvalidStepFormat();
    }

    std::cout << "Enter second step index: ";
    if (!(std::cin >> step2)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw InvalidStepFormat();
    }
    
    inputOperation();
}

template <typename T>
void CalculusStep<T>::inputOperation() {
    std::cout << "Enter operation: ";
    std::cin >> operation;

    if (!(operation == "+" || operation == "-" || operation == "*" || operation == "/" ||
          operation == "min" || operation == "max")) {
        
        throw InvalidOperation();
    }
}

template <typename T>
void CalculusStep<T>::run() {
    //empty override for virtual function
}

template <typename T>
StepData CalculusStep<T>::getStepData() const {
    return std::make_tuple(step1, step2, operation);
}

template <typename T>
T CalculusStep<T>::performOperation(T operand1, T operand2, std::string operation) const {
    if (operation == "+") {
        return operand1 + operand2;
    } else if (operation == "-") {
        return operand1 - operand2;
    } else if (operation == "*") {
        return operand1 * operand2;
    } else if (operation == "/") {
        if (operand2 != 0) {
            return operand1 / operand2;
        } else {
            throw std::invalid_argument("Division by zero.");
        }
    } else if (operation == "min") {
        return std::min(operand1, operand2);
    } else if (operation == "max") {
        return std::max(operand1, operand2);
    }

    // Handle unsupported operations or return a default value
    throw std::invalid_argument("Unsupported operation: " + operation);
}

// Explicit instantiation of template class for required types
template class CalculusStep<int>;
template class CalculusStep<float>;

template <typename T>
void CalculusStep<T>::runStep(std::vector<StepData> stepData) {
    if (std::holds_alternative<T>(stepData[0]) && std::holds_alternative<T>(stepData[1])) {
        T firstNumber = std::get<T>(stepData[0]);
        T secondNumber = std::get<T>(stepData[1]);
        std::cout << performOperation(firstNumber, secondNumber, operation) << std::endl;

        this->output = "First number: " + std::to_string(firstNumber) + "\nSecond number: " + std::to_string(secondNumber) + "\nOperation: " + operation;
    } else {
        // Handle the case where the variant types don't match your expectations.
        throw std::invalid_argument("Invalid step data type. Not a Number Type.");
    }
}

DisplayStep::DisplayStep() {

}

void DisplayStep::setup() {
    std::cout << "Enter step: ";
    if (!(std::cin >> step)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw InvalidStepFormat();
    }
}

void DisplayStep::run() {
    //empty override for virtual function
}

int DisplayStep::getStep() {
    return this->step;
}

StepData DisplayStep::getStepData() const {
    return step;
}

void DisplayStep::runStep(std::vector<StepData> stepData) {
    // Display the content if it's a TextInputStep
    if (std::holds_alternative<std::tuple<std::string, std::string>>(stepData[0])) {
        std::tuple<std::string, std::string> data = std::get<std::tuple<std::string, std::string>>(stepData[0]);
        std::cout << "Displaying TextInputStep Content: " << std::get<1>(data) << std::endl;
        this->output = "Step:" + std::to_string(step)  + "\nDisplaying TextInputStep Content: " + std::get<1>(data);
    }
    // Display content for file inputs
    else if (std::holds_alternative<std::tuple<std::string, std::string, std::string>>(stepData[0])) {
        std::tuple<std::string, std::string, std::string> data = std::get<std::tuple<std::string, std::string, std::string>>(stepData[0]);
        std::cout << "Displaying Text/CSV File  Content: " << std::get<2>(data) << std::endl;
        this->output = "Step:" + std::to_string(step)  + "\nDisplaying Text/CSV File  Content: " + std::get<2>(data);
    }
}

TextFileStep::TextFileStep() {
    filename = "files/";
}

bool TextFileStep::fileExists(std::string filename) {
    std::ifstream file(filename);
    return file.good();
}

void TextFileStep::setup() {
    std::cout << "Enter description: ";
    std::cin.ignore();
    std::getline(std::cin, description);
    std::cout << "Enter filename: ";
    std::string fileLocation;
    std::cin >> fileLocation;
    filename.append(fileLocation);
    if (!fileExists(filename)) {
        throw FileNotFound();
    }
}

void TextFileStep::run() {
    std::cout << "Description: " << this->description << std::endl;
    std::cout << "Filename: " << this->filename << std::endl;
    content = readFileContent();

    this->output = "Description: " + this->description + "\nFilename: " + this->filename + "\nContent: " + content;
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

StepData TextFileStep::getStepData() const {
    return std::make_tuple(description, filename, content);
}

void TextFileStep::runStep(std::vector<StepData> stepData) {
    this->run();
}

CsvFileStep::CsvFileStep() {
    filename = "files/";
}

bool CsvFileStep::fileExists(std::string filename) {
    std::ifstream file(filename);
    return file.good();
}

void CsvFileStep::setup() {
    std::cout << "Enter description: ";
    std::cin.ignore();
    std::getline(std::cin, description);
    std::cout << "Enter filename: ";
    std::string fileLocation;
    std::cin >> fileLocation;
    filename.append(fileLocation);
    if (!fileExists(filename)) {
        throw FileNotFound();
    }
}

void CsvFileStep::run() {
    std::cout << "Description: " << this->description << std::endl;
    std::cout << "Filename: " << this->filename << std::endl;
    content = this->readFileContent();

    this->output = "Description: " + this->description + "\nFilename: " + this->filename + "\nContent: " + content;
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

StepData CsvFileStep::getStepData() const {
    return std::make_tuple(description, filename, content);
}

void CsvFileStep::runStep(std::vector<StepData> stepData) {
    this->run();
}

OutputStep::OutputStep() {
    fileName = "files/";
}

void OutputStep::setup() {
    std::cout << "Enter step: ";
    if (!(std::cin >> step)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw InvalidStepFormat();
    }

    std::string fileLocation;
    std::cout << "Enter filename: ";
    std::cin >> fileLocation;
    fileName.append(fileLocation);

    std::cout << "Enter text: ";
    std::cin.ignore();
    std::getline(std::cin, text);

    std::cout << "Enter description: ";
    std::cin.ignore();
    std::getline(std::cin, description);
}

void OutputStep::run() {
    //empty override for virtual function
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

StepData OutputStep::getStepData() const {
    return std::make_tuple(step, fileName);
}

void OutputStep::runStep(std::vector<StepData> stepData) {
    //open file
    std::ofstream file(fileName);
    std::cout << "Writing to file: " << fileName << std::endl;

    file << "Text: " <<  text << std::endl;
    file << "Description: " << description << std::endl;
    file << "Step: " << step << std::endl;
    std::string outputStep = std::get<std::string>(stepData[0]);
    file << "Output: " << outputStep << std::endl;

    file.close();
}

EndStep::EndStep() {

}

void EndStep::setup() {
    //not implemented
}

void EndStep::run() {
    //not implemented
}

StepData EndStep::getStepData() const {
    return "";
}

void EndStep::runStep(std::vector<StepData> stepData) {
    this->run();
}
