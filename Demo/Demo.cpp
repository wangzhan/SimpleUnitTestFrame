// Demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\SimpleUnitTestLib\UnitTest.h"
#include "..\SimpleUnitTestLib\TestCase.h"

int _add(int a, int b)
{
    return a + b;
}

STEST(Demo1)
{
    ASSERT_Q(2, _add(1, 1));
}

STEST(Demo2)
{
    ASSERT_Q(1, _add(1, 1));
}

int _tmain(int argc, _TCHAR* argv[])
{
    RUN_ALL_TESTS();
	return 0;
}

