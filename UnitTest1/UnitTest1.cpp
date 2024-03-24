#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab9.1/lab9.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestCalculateProgrammingGrades)
        {
            const int N = 3; 
            Student students[N];

            students[0] = { "John", 2, CS, 5, 5 };
            students[0].additional_grade.programming = 5;

            students[1] = { "Doe", 3, CS, 4, 4 };
            students[1].additional_grade.programming = 4;

            students[2] = { "Jane", 1, ME, 5, 5 };
            students[2].additional_grade.pedagogy = 3; 

            int count5 = 0, count4 = 0, count3 = 0;
            CalculateProgrammingGrades(students, N, count5, count4, count3);

            Assert::AreEqual(1, count5);
            Assert::AreEqual(1, count4);
            Assert::AreEqual(0, count3);
        }

        TEST_METHOD(TestCalculateInterest)
        {
            const int N = 3; 
            Student students[N];

            students[0] = { "John", 2, CS, 5, 5 };
            students[0].additional_grade.programming = 5;

            students[1] = { "Doe", 3, IT, 4, 3 };
            students[1].additional_grade.numerical_methods = 4; 

            students[2] = { "Jane", 1, ME, 4, 4 };
            students[2].additional_grade.pedagogy = 3;

            double interest = CalculateInterest(students, N);

            Assert::AreEqual(interest, 66.6667, 0.001);
        }

        TEST_METHOD(TestPrint)
        {
            const int N = 2;
            Student students[N];

            students[0].surname = "Doe";
            students[0].course = 1;
            students[0].physics_grade = 4;
            students[0].math_grade = 5;
            students[0].additional_grade.numerical_methods = 3;
            students[0].specialization = IT;

            students[1].surname = "Smith";
            students[1].course = 2;
            students[1].physics_grade = 5;
            students[1].math_grade = 4;
            students[1].additional_grade.numerical_methods = 5;
            students[1].specialization = CS;

            Print(students, N);
        }
	};
}