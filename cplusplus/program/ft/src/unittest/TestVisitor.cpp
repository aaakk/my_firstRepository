#include "ftport.h"
#include "visitor/ElemRepo.h"
#include "visitor/ElemVisitor.h"
#include "gtest/gtest.h"

namespace
{
    USING_NS_LIANG

    class DataListVisitor : public ElemVisitor
    {
    public:
        void visit(dataElem& elem)
        {
	    std::cout << elem << std::endl;
        }
    };

    std::list<std::string> testData = 
    {
        {"testElem1"},
        {"testElem2"}
    };
};

namespace
{
    class TestVisitor : public testing::Test
    {
    };
}

FT_LIANG_BEG

TEST_F(TestVisitor, test_visitor)
{
    USING_NS_LIANG
    ElemRepo reporitory(testData);
    DataListVisitor visitor;
    reporitory.acceptAll(visitor);
}

FT_LIANG_END


