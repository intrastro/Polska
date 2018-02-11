#include "stack_lib.h"
#include "pol_lib.h"

int main ()
    {
    string in_string = "";
    std::getline(std::cin, in_string);

    string pol_string = translate_usual_to_pol (in_string);
    std::cout << pol_string << std::endl;

    int pol_mean = calculate_pol (pol_string);
    std::cout << pol_mean;
    }

