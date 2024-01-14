#include "errors.h"

const char* InvalidMenuInput::what() const noexcept {
    return "Invalid input. Please enter a valid integer.";
}

const char* InvalidFlowName::what() const noexcept {
    return "Invalid flow name. Please enter a valid flow name.";
}

const char* InvalidNumberInput::what() const noexcept {
    return "Invalid input. Please enter float value.";
}

const char* InvalidStepFormat::what() const noexcept {
    return "Invalid step format. Please enter a valid step format.";
}

const char* StepInPast::what() const noexcept {
    return "Step in future. Please enter a valid step.";
}

const char* InvalidOperation::what() const noexcept {
    return "Invalid operation. Please enter a valid operation.";
}

const char* FileNotFound::what() const noexcept {
    return "File not found. Please enter a valid file name.";
}

const char* FlowNameTaken::what() const noexcept {
    return "Flow name taken. Please enter a different flow name.";
}

const char* NotNumberType::what() const noexcept {
    return "Not a number type.";
}

const char* DivideByZero::what() const noexcept {
    return "Division by zero impossible.";
}