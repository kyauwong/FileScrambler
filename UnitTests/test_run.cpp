#include "TestCollector.h"
#include <iostream>

int main(int argc, char *argv[]) {
    const auto nFailedTests = TestCollector::RunAllTests(argc, argv);
    std::cout<<"Total failed tests: "<<nFailedTests<<std::endl;
    return nFailedTests;
}
