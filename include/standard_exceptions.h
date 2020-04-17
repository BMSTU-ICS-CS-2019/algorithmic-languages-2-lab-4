#ifndef INCLUDE_STANDARD_EXCEPTIONS_H_
#define INCLUDE_STANDARD_EXCEPTIONS_H_

#include <stdexcept>
#include <string>

namespace standard_exceptions {
    class ExceptionNotThrown final : public std::exception {
    private:
        std::string message_;

    public:
        explicit ExceptionNotThrown(std::string &&message);

        const char *what() const noexcept override;
    };

    void cause_out_of_range();

    void cause_length_error();

    void cause_invalid_argument();

    void cause_bad_cast();

    void cause_bad_alloc();
} // namespace standard_exceptions

#endif// INCLUDE_STANDARD_EXCEPTIONS_H_
