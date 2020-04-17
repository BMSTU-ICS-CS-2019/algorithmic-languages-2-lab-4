#include <iostream>

#include <raii.h>
#include <standard_exceptions.h>

int main() {
    std::cout
            << "1. <read>\n"
            << "2:" << std::endl;

    try {
        standard_exceptions::cause_out_of_range();
    } catch (standard_exceptions::ExceptionNotThrown const& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    std::cout << "\t2.1 Works as expected" << std::endl;

    try {
        standard_exceptions::cause_length_error();
    } catch (standard_exceptions::ExceptionNotThrown const& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    std::cout << "\t2.2 Works as expected" << std::endl;

    try {
        standard_exceptions::cause_invalid_argument();
    } catch (standard_exceptions::ExceptionNotThrown const& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    std::cout << "\t2.3 Works as expected" << std::endl;

    try {
        standard_exceptions::cause_bad_cast();
    } catch (standard_exceptions::ExceptionNotThrown const& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    std::cout << "\t2.4 Works as expected" << std::endl;

    try {
        standard_exceptions::cause_bad_alloc();
    } catch (standard_exceptions::ExceptionNotThrown const& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    std::cout << "\t2.5 Works as expected" << std::endl;

    return 0;
}
