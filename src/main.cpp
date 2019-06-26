#include "sym.hpp"

namespace Options = boost::program_options;

int main(int argc, char *argv[])
{
    Options::options_description generic("Generic Options");
    generic.add_options()
        ("help", "Display this help menu and exit.")
        ("version", "Display program version information and exit.")
    ;

    Options::options_description exec("Execution Options");
    exec.add_options()
        ("verbose,v", "Display detailed information during program execution")
    ;

    Options::options_description config("Configuration Options");
    config.add_options()
        ("filename,F", Options::value<std::vector<std::string>>()->composing(), "Name of file(s) to compress")
    ;

    Options::options_description desc("Program Options");
    desc
        .add(generic)
        .add(exec)
        .add(config);
    
    Options::positional_options_description pos;
    pos.add("filename", -1);

    Options::variables_map vm;
    Options::store(
        Options::command_line_parser(argc, argv)
            .options(desc)
            .positional(pos)
            .run(),
        vm);
    Options::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << std::endl;

        return EXIT_SUCCESS;
    }

    if (vm.count("version")) {
        std::cout << "<Program Version Info>" << std::endl;

        return EXIT_SUCCESS;
    }

    // if (!vm.count("filename")) {
    //     // If no filename(s) was/were specified, notify the user and
    //     // exit with an error status.
    //     std::cerr << "No file(s) specified." << std::endl;

    //     return EXIT_FAILURE;
    // }

    // std::cout << "<Program Execution...>" << std::endl;

    // int a = boost::lexical_cast<int>(argv[1]);
    // int b = boost::lexical_cast<int>(argv[2]);

    // std::cout << a << "/" << b << std::endl;

    Fraction a(argv[1], argv[2]);
    std::cout << a << std::endl;

    Fraction b(argv[3], argv[4]);
    std::cout << b << std::endl;

    Fraction c = a + b;
    std::cout << c << std::endl;

    Fraction d = a * b;
    std::cout << d << std::endl;

    return EXIT_SUCCESS;
}
