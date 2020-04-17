#ifndef INCLUDE_STANDARD_EXCEPTIONS_H_
#define INCLUDE_STANDARD_EXCEPTIONS_H_

#include <stdexcept>
#include <string>

namespace standard_exceptions {

    class ExceptionNotThrownException final : public std::runtime_error {
    public:
        explicit ExceptionNotThrownException(char const * message);

        explicit ExceptionNotThrownException(std::string const & message);
    };

    void cause_out_of_range();

    void cause_length_error();

    void cause_invalid_argument();

    void cause_bad_cast();

    void cause_bad_alloc();
} // namespace standard_exceptions

#endif // INCLUDE_STANDARD_EXCEPTIONS_H_
