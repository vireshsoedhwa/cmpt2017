#include <iostream>
#include <string>
#include <regex>


int main()
{
    std::string hostinput;

    std::smatch match;

//    std::cout << "input Hostname:" << std::endl;
//    std::cin >> hostinput;
//    std::cout << "looking for Host: " << hostinput << std::endl;

    hostinput = "April.net16";

    //Regular expression for matching IP
    std::regex ippattern("^[[:digit:]]{1,3}.[[:digit:]]{1,3}.[[:digit:]]{1,3}.[[:digit:]]{1,3}$");
    //Regular expression for matching hostname
    std::regex hostpattern("^[[:alpha:]]{1,}.net[[:digit:]]{1,2}$");

    std::regex block("^([[:alpha:]]{1,}).net([[:digit:]]{1,2})$");

//    if (std::regex_match (hostinput,ippattern))
//        std::cout << "valid IP" << std::endl;
//
//    if (std::regex_match (hostinput,hostpattern))
//        std::cout << "valid hostname" << std::endl;


    if (std::regex_search(hostinput, match, block))
    {
        std::cout << "Match\n";
        std::cout << "match[0] = " << match[2] << std::endl;
    }



//    if (std::regex_match ("subject", std::regex("(sub)(.*)") ))
//    std::cout << "string literal matched\n";
//
//    const char cstr[] = "subject";
//    std::string s ("subject");
//    std::regex e ("(sub)(.*)");
//
//    if (std::regex_match (s,e))
//    std::cout << "string object matched\n";
//




//    if ( std::regex_match ( s.begin(), s.end(), e ) )
//    std::cout << "range matched\n";
//
//    std::cmatch cm;    // same as std::match_results<const char*> cm;
//    std::regex_match (cstr,cm,e);
//    std::cout << "string literal with " << cm.size() << " matches\n";
//
//    std::smatch sm;    // same as std::match_results<string::const_iterator> sm;
//    std::regex_match (s,sm,e);
//    std::cout << "string object with " << sm.size() << " matches\n";
//
//    std::regex_match ( s.cbegin(), s.cend(), sm, e);
//    std::cout << "range with " << sm.size() << " matches\n";
//
//    // using explicit flags:
//    std::regex_match ( cstr, cm, e, std::regex_constants::match_default );
//
//    std::cout << "the matches were: ";
//    for (unsigned i=0; i<cm.size(); ++i) {
//    std::cout << "[" << cm[i] << "] ";
//    }
//
//    std::cout << std::endl;


    return 0;
}
