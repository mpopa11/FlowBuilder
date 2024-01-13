#ifndef ERRORS_H
#define ERRORS_H

#include <stdexcept>

class InvalidMenuInput : public std::exception {
    public:
        const char* what() const noexcept override;
    };

class InvalidFlowName : public std::exception {
    public:
        const char* what() const noexcept override;
    };

class InvalidNumberInput : public std::exception {
    public:
        const char* what() const noexcept override;
    };

class InvalidStepFormat : public std::exception {
    public:
        const char* what() const noexcept override;
    };

class StepInPast : public std::exception {
    public:
        const char* what() const noexcept override;
    };

class InvalidOperation : public std::exception {
    public:
        const char* what() const noexcept override;
    };

class FileNotFound : public std::exception {
    public:
        const char* what() const noexcept override;
    };

#endif