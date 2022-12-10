#include "pch.h"
#include "CppUnitTest.h"
#include "../лаба 8.1.r/лаба 8.1.r.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace юніттест81r
{
	TEST_CLASS(юніттест81r)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char str[8] = "while";
			int i = 0;
			int t = Count(str, i);
			Assert::AreEqual(t, 1);
		}
	};
}
