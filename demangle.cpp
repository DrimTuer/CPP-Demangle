#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cxxabi.h>


int main(int argc, char **argv){
    if( argc != 2 ||
        !strcmp(argv[1], "-h") ||
        !strcmp(argv[1], "--help"))
    {
        std::cout << "Usage: " << argv[0] << " {-h | --help | managled-name}" << std::endl;
        return 0;
    }

    int status;
    char *demangled_name;

    demangled_name = abi::__cxa_demangle(argv[1], NULL, 0, &status);

    switch(status){
    case 0:
        std::cout << demangled_name << std::endl;
        free(demangled_name);
        break;
    case -1:
        std::cout << "A memory allocation failiure occurred" << std::endl;
        break;
    case -2:
        std::cout << "The input is not a valid name under the C++ ABI mangling rules" << std::endl;
        break;
    case -3:
        std::cout << "One of the arguments is invalid" << std::endl;
        break;
    default:
        std::cout << "Unknow Error occurred" << std::endl;
        break;
    }

    return 0;
}

