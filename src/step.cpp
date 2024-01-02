#include "step.h"
#include <iostream>

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
    //Step* step1, Step* step2
    //implementation in flow class
    //need access to previous steps
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
    //implementation in flow class
    //need access to previous steps
}

int DisplayStep::getStep() {
    return this->step;
}

TextFileStep::TextFileStep() {

}

void TextFileStep::setup() {
    std::cout << "Enter description: ";
    std::cin >> description;
}

void TextFileStep::run() {
    std::cout << "Description: " << this->description << std::endl;
    std::cout << "Enter filename: ";
    std::cin >> filename;
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
}

void CsvFileStep::run() {
    std::cout << "Description: " << this->description << std::endl;
    std::cout << "Enter filename: ";
    std::cin >> filename;
}

std::string CsvFileStep::getDescription() {
    return this->description;
}

std::string CsvFileStep::getFilename() {
    return this->filename;
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
    //implementation in flow class,
    //need access to previous steps
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





