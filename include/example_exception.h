#ifndef INCLUDE_EXAMPLE_EXCEPTION_H_
#define INCLUDE_EXAMPLE_EXCEPTION_H_

namespace example_exception {
    class ExampleException final : public std::runtime_error {
    public:
        explicit ExampleException(char const* message);

        explicit ExampleException(std::string const& message);
    };
} // namespace example_exception

#endif//INCLUDE_EXAMPLE_EXCEPTION_H_
