#include <iostream>

#include <cstring>
#include <example_exception.h>
#include <raii.h>
#include <standard_exceptions.h>

int main() {
    std::cout
            << "========== Exceptions ==========\n"
               "1) Docs successfully read\n"
               "2 / 3)"
            << std::endl;

    try {
        standard_exceptions::cause_out_of_range();
    } catch (standard_exceptions::ExceptionNotThrownException const & e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    std::cout << "\t2.1 / 3) Works as expected" << std::endl;

    try {
        standard_exceptions::cause_length_error();
    } catch (standard_exceptions::ExceptionNotThrownException const & e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    std::cout << "\t2.2 / 3) Works as expected" << std::endl;

    try {
        standard_exceptions::cause_invalid_argument();
    } catch (standard_exceptions::ExceptionNotThrownException const & e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    std::cout << "\t2.3 / 3) Works as expected" << std::endl;

    try {
        standard_exceptions::cause_bad_cast();
    } catch (standard_exceptions::ExceptionNotThrownException const & e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    std::cout << "\t2.4 / 3) Works as expected" << std::endl;

    try {
        standard_exceptions::cause_bad_alloc();
    } catch (standard_exceptions::ExceptionNotThrownException const & e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    std::cout << "\t2.5 / 3) Works as expected" << std::endl;

    std::cout << "\t4 / 5):" << std::endl;
    {
        enum Status { UNCAUGHT,
                      WRONG_MESSAGE,
                      CAUGHT } status = UNCAUGHT;
        try {
            throw example_exception::ExampleException("Let magic happen");
        } catch (example_exception::ExampleException const & e) {
            status = ((strcmp(e.what(), "Let magic happen")) == 0 ? CAUGHT : WRONG_MESSAGE);
        }
        switch (status) {
            case UNCAUGHT: {
                std::cerr << "example_exception::ExampleException was not thrown";
                return 1;
            }
            case WRONG_MESSAGE: {
                std::cerr << "example_exception::ExampleException was thrown but contained wrong message";
                return 1;
            }
            case CAUGHT: {
                std::cout << "\t4 / 5) Works as expected" << std::endl;
                break;
            }
        }
    }

    std::cout
            << "========== RAII =========="
            << std::endl;
    {
        int const * danglingPointer;
        {
            raii::RaiiUnfriendly raiiUnfriendly;
            danglingPointer = raiiUnfriendly.unsafePointer();
            std::clog << "Value of raiiUnfriendly: " << raiiUnfriendly.value() << std::endl;
        }
        delete[] danglingPointer;
    }
    std::cout
            << "1) Should have passed"
            << std::endl;

    {
        raii::RaiiFriendly raiiFriendly;
        std::clog << "Value of raiiFriendly: " << raiiFriendly.value() << std::endl;
    }
    std::cout
            << "2) Should have passed"
            << std::endl;

    return 0;
}
