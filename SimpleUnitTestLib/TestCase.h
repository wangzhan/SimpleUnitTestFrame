// wangzhan.1985@gmail.com
#ifndef __TEST_CASE__
#define __TEST_CASE__

namespace SimpleUnitTest
{
    class CTestCase
    {
    public:
        CTestCase(const char *lpszTestCaseName) 
            : m_lpszTestCaseName(lpszTestCaseName) 
            , m_iTestResult(1)
        {}
        virtual ~CTestCase() {}

        virtual void Run() = 0;

        const char* GetTestCaseName() const
        {
            return m_lpszTestCaseName;
        }

        int GetResult() const
        {
            return m_iTestResult;
        }

        void SetResult(int iResult)
        {
            m_iTestResult = iResult;
        }

    protected:
        int m_iTestResult;
        const char *m_lpszTestCaseName;
    };
}

#define _TEST_CLASS_NAME(name) \
    name##_test

#define STEST(name) \
class _TEST_CLASS_NAME(name) : public SimpleUnitTest::CTestCase \
{ \
public: \
    _TEST_CLASS_NAME(name) (const char *lpszName) : CTestCase(lpszName) \
{} \
    virtual void Run(); \
private: \
    static CTestCase *m_pTestCase; \
}; \
    SimpleUnitTest::CTestCase* _TEST_CLASS_NAME(name)::m_pTestCase = \
    SimpleUnitTest::CUnitTest::GetInstance()->RegisterTestCase(new _TEST_CLASS_NAME(name)(#name)); \
    void _TEST_CLASS_NAME(name)::Run()

#define ASSERT_Q(m, n) \
{ \
if ((m) != (n))\
{ \
    SimpleUnitTest::CUnitTest::GetInstance()->GetCurrentTestCase()->SetResult(0); \
} \
}

#endif // !__TEST_CASE__
