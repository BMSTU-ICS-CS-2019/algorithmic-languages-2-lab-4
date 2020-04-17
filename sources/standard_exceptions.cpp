#include <standard_exceptions.h>

namespace standard_exceptions {

    ExceptionNotThrown::ExceptionNotThrown(std::string &&message) : message_(std::move(message)) {}
}
