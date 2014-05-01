// wangzhan.1985@gmail.com
#ifndef __UNIT_TEST__
#define __UNIT_TEST__
#include <vector>

namespace SimpleUnitTest
{
    class CTestCase;

    class CUnitTest
    {
    private:
        CUnitTest();
        ~CUnitTest();

    public:
        static CUnitTest* GetInstance();

        CTestCase* RegisterTestCase(CTestCase *pTestCase);
        CTestCase* GetCurrentTestCase() const;
        int Run();
        void PrintEnd() const;

    private:
        int m_iResultTest;
        CTestCase *m_pCurrentTestCase;

        typedef std::vector<CTestCase*> TestCaseVector;
        typedef TestCaseVector::iterator TestCaseVectorIter;
        TestCaseVector m_vecTestCase;
    };
}

#define RUN_ALL_TESTS() \
    SimpleUnitTest::CUnitTest::GetInstance()->Run(); \
    SimpleUnitTest::CUnitTest::GetInstance()->PrintEnd();

#endif // !__UNIT_TEST__