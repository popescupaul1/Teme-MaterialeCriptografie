#include "cripto_tools.hpp";
	
int main() 
{
	cout << a_la_b_mod_c(25, 28, 29) << endl;  //raspuns: 1
		
	cout << cmmdc(360, 294) << endl;  //raspuns: 6
	cout << cmmdc(1547, 560) << endl;  //raspuns: 7
		
	cout << invers(122, 343) << endl;  //raspuns: 211
		
	return 0;
}