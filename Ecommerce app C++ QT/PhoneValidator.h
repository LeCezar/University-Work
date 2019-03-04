#pragma once
#include <string>
#include "Phone.h"
#include <vector>

class PhoneException
{
private:
    std::vector<std::string> errors;

public:
    PhoneException(std::vector<std::string> _errors);
    std::vector<std::string> getErrors() const;
};

class PhoneValidator
{
public:
    PhoneValidator() {}
    static void validate(Phone& s);
};