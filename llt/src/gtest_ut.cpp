extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include "func.h"
}

#include <limits.h>
#include <mockcpp/mockcpp.hpp>
#include "gmock/gmock.h"
#include "gtest/gtest.h"

// using namespace std;
using namespace testing;

class GtestUt : public testing::Test
{
protected:
    void SetUp() override
    {
        std::cout << "--Gtest_Ut SetUP--" << std::endl;
    }

    void TearDown() override
    {
        std::cout << "--Gtest_Ut TearDown--" << std::endl;
    }
};

class Mock_FOO {
public:
    MOCK_METHOD1(mock_test_struct_func, int(struct test_t *test));
};

Mock_FOO mocker;

int mock_test_struct_func(struct test_t *test)
{
    return mocker.mock_test_struct_func(test);
}
int add_stub(int a, int b) {
    return 7;
}

TEST_F(GtestUt, ut_add_01)
{
    int ret;

    MOCKER(add).defaults().will(invoke(add_stub));
    //expect add_stub instead of add function
    ret = add(1, 2);
    EXPECT_EQ(3, ret);
}

TEST_F(GtestUt, ut_add_02)
{
    int ret;
    struct test_t test;

    test.a = 1;
    test.b = 1;

    MOCKER(multi)
    .expects(atMost(20))
    .will(returnValue(100));
    ret = add_struct(&test);
    EXPECT_EQ(ret, 100);
    GlobalMockObject::verify();
}

TEST_F(GtestUt, ut_add_03)
{
    int ret;
    struct test_t test;

    test.a = 10;
    test.b = 11;

    MOCKER(multi)
    .expects(atMost(20))
    .will(returnValue(20));
    ret = add_struct(&test);
    EXPECT_EQ(ret, 21);
    GlobalMockObject::verify();
}

TEST_F(GtestUt, ut_add_04)
{
    int ret;
    int a, b;
    struct test_t test;

    test.a = 10;
    test.b = 12;
    test.p_func = mock_test_struct_func;
    EXPECT_CALL(mocker, mock_test_struct_func(&test)).WillRepeatedly(Return(10));

    ret = test_struct_func(&test);
    EXPECT_EQ(ret, 10);
    GlobalMockObject::verify();
}

TEST_F(GtestUt, ut_add_05)
{
    int ret;
    int ex_value;

    ret = test_stub_func();
    EXPECT_EQ(ret, 1011);
}