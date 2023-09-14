#include <iostream>
using namespace std;

#if defined SPRING
#else
#define TEXT "spring"
#endif

int main()
{
	cout << TEXT;
}
