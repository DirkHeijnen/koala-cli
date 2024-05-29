#include <string>
#include "../../include/helpers/string_utils.hpp"

void replace(std::string& input, std::string value, std::string replaceValue) {
    size_t position = input.find(value);

    while (position != std::string::npos) {
        input.replace(position, value.size(), replaceValue);

        position = input.find(value, position + replaceValue.size());
    }
}