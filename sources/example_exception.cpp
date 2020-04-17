#include <algorithm>
#include <example_exception.h>

namespace example_exception {

    ExampleException::ExampleException(char const * const message) : std::runtime_error(message) {}

    ExampleException::ExampleException(const std::string & message) : runtime_error(message) {}
} // namespace example_exception