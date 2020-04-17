#include <standard_exceptions.h>

#include <bitset>
#include <vector>

namespace standard_exceptions {

    ExceptionNotThrown::ExceptionNotThrown(std::string &&message) : message_(std::move(message)) {}

    const char *ExceptionNotThrown::what() const noexcept {
        return exception::what();
    }

    void cause_out_of_range() {
        std::vector<int> emptyVector = {};
        try {
            emptyVector.at(1);
        } catch (std::out_of_range const &) {
            return;
        }

        throw ExceptionNotThrown("std::out_of_range was not thrown");
    }

    void cause_length_error() {
        std::string emptyString;
        try {
            emptyString.resize(std::string::npos);
        } catch (std::length_error const &) {
            return;
        }

        throw ExceptionNotThrown("std::length_error was not thrown");
    }

    void cause_invalid_argument() {
        try {
            std::bitset<1>("r/woosh/");
        } catch (std::invalid_argument const &) {
            return;
        }

        throw ExceptionNotThrown("std::invalid_argument was not thrown");
    }

    void cause_bad_cast() {
        class Foo {
            virtual void foo(){};
        };
        class Bar {};
        Foo const foo;
        Foo const &fooReference = foo;
        try {
            dynamic_cast<Bar const &>(fooReference);
        } catch (std::bad_cast const &) {
            return;
        }

        throw ExceptionNotThrown("std::invalid_argument was not thrown");
    }

    void cause_bad_alloc() {
        std::vector<long long const *> pointers;// we don't need memory leaks
        try {
            while (true) pointers.push_back(new long long[SIZE_MAX >> 6]);
        } catch (std::bad_alloc const &) {
            for (const auto pointer : pointers) delete[] pointer;
            return;
        }

        for (const auto pointer : pointers) delete[] pointer;
        throw ExceptionNotThrown("std::bad_alloc was not thrown");
    }
} // namespace standard_exceptions
