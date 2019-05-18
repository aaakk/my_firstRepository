#include "ftport.h"
#include "gtest/gtest.h"
#include "template/Printer.hpp"
#include <iostream>

namespace
{
    class TestPrinter : public testing::Test
    {
    };
}

namespace
{
#define PRODUCEPRINTER(par)     class Printer##par \
    {\
        void doPrint()\
        {\
            std::cout << "print #par" << std::endl;\
        }\
    };\
}

TEST_T(TestPrinter, test_printer)
{
    PRODUCEPRINTER(A);
    PRODUCEPRINTER(B);
    PRODUCEPRINTER(C);
    Printer<PrinterA, PrinterB, PrinterC> printer;
    printer.doPrint();
}