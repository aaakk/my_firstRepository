#include "ftport.h"
#include "gtest/gtest.h"
#include "template/Printer.hpp"
#include <iostream>
#include "template/asn/asn-struct.h"
#include "template/asn/structMsg.h"

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
    public:\
        void doPrint()\
        {\
            std::cout << "print #par" << std::endl;\
        }\
    };
}

TEST_F(TestPrinter, test_printer)
{
    USING_NS_LIANG;

    PRODUCEPRINTER(A);
    PRODUCEPRINTER(B);
    PRODUCEPRINTER(C);
    Printer<PrinterA, PrinterB, PrinterC> printer;
    printer.doPrint();
}

TEST_F(TestPrinter, test_printer)
{
    structList* ptr = __ALLOCMSG(structList, structElem, 2);
}