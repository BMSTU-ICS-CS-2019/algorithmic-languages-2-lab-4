#include <standard_exceptions.h>

ExceptionNotThrown::ExceptionNotThrown(std::string &&message) : message_(std::move(message)) {}
