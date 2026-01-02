#include <iostream>
#include "tests_stack.h"

int main() 
{
    tests_stack::test_basic_operations();
    tests_stack::test_boundary_conditions();
    tests_stack::test_template_types();
    tests_stack::test_stress_sequential();
    tests_stack::test_randomized_operations();
    tests_stack::test_copy_and_assignment();
    tests_stack::test_large_scale();

    std::cout << "All Stack tests passed successfully.\n";
    return 0;
}
