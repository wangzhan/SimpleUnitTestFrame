#include "stdafx.h"
#include "UnitTest.h"
#include "ConsoleColor.h"
#include "TestCase.h"

namespace SimpleUnitTest
{
    CUnitTest::CUnitTest()
        : m_iResultTest(1)
        , m_pCurrentTestCase(0)
    {
    }

    CUnitTest::~CUnitTest()
    {
        for (TestCaseVectorIter iter = m_vecTestCase.begin();
            iter != m_vecTestCase.end(); ++iter)
        {
            delete *iter;
        }
        m_vecTestCase.clear();
    }

    CUnitTest* CUnitTest::GetInstance()
    {
        static CUnitTest instance;
        return &instance;
    }

    CTestCase* CUnitTest::RegisterTestCase(CTestCase *pTestCase)
    {
        if (pTestCase != 0)
        {
            m_vecTestCase.push_back(pTestCase);
        }
        return pTestCase;
    }

    CTestCase* CUnitTest::GetCurrentTestCase() const
    {
        return m_pCurrentTestCase;
    }

    int CUnitTest::Run()
    {
        for (TestCaseVectorIter iter = m_vecTestCase.begin();
            iter != m_vecTestCase.end(); ++iter)
        {
            std::cout << GREEN_COLOR << "begin run " << (*iter)->GetTestCaseName()
                << std::endl;

            m_pCurrentTestCase = *iter;
            (*iter)->Run();
            if ((*iter)->GetResult() == 0)
            {
                m_iResultTest = 0;

                std::cout << RED_COLOR << "end run failed " << (*iter)->GetTestCaseName()
                    << std::endl;
            }
            else
            {
                std::cout << GREEN_COLOR << "end run success " << (*iter)->GetTestCaseName()
                    << std::endl;
            }
        }
        return m_iResultTest;
    }

    void CUnitTest::PrintEnd() const
    {
        std::cout << WHITE_COLOR << "press any key to continue ... " << std::endl;
        getchar();
    }
}