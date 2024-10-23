#pragma once

#include <ostream>
#include <vector>
#include <optional>

template<typename T>
std::ostream& operator<<(std::ostream& os, std::optional<T> opt) {
    if (opt.has_value()) {
        os << opt.value();
    } else {
        os << "null";
    }
    return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "{";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ",";
        }
    }
    os << "}";
    return os;
}
