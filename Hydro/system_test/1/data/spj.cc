/**
 * @file spj.cc
 * @author Macesuted Kysic
 * @date 2021-02-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <string>

#include "testlib.h"

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    std::string s = ouf.readToken();
    if (s == "ok532124524657743124323")
        quitf(_ok, "Correct");
    else
        quitf(_wa, "Wrong Answer");
}
