#include "pch.h"
#include "CppUnitTest.h"
#include "../ChyrunSofialab11.4/ChyrunSofialab11.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest114
{
	TEST_CLASS(UnitTest114)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			int N = 3, s = 0;
			Price* p = new Price[N];
			p[0].cost = 9;
			p[1].cost = 27;
			p[2].cost = 99;
			t = (int)MinSerbal(p, N);
			Assert::AreEqual(t, 9);
		}
	};
}
