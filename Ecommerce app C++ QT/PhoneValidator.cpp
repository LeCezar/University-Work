#include "PhoneValidator.h"

using namespace std;

PhoneException::PhoneException(std::vector<std::string> _errors): errors{_errors}
{
}

std::vector<std::string>PhoneException::getErrors() const
{
    return this->errors;
}

void PhoneValidator::validate(Phone & ph)
{
    vector<string> errors;
    if (ph.getQuantity() == 0)
        errors.push_back("TThe quantity can't be 0\n");

    // search for "www" or "http" at the beginning of the source string
    size_t posHttp = ph.getPhoto().find("https");
    if (posHttp == 0)
        errors.push_back("The image source must start with one of the following strings: \"http\"");

    if (errors.size() > 0)
        throw PhoneException(errors);
}
