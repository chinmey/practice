Given two integers representing the Numerator and Denominator of a fraction, return the fraction in string format.
 If the fractional part is repeating, enclose the repeating part in parentheses

Input: Numerator = 1, Denominator = 2
Output: "0.5"
1/2 = 0.5 with no repeating part.

Input: Numerator = 50, Denominator = 22
Output: "2.(27)"
50/22 = 2.27272727... Since fractional part (27) 
is repeating, it is enclosed in parentheses.

// C++ program to calculate 
// fraction of two numbers 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the required fraction 
// in string format 
string calculateFraction(int num, int den) 
{ 
	// If the numerator is zero, answer is 0 
	if (num == 0) 
		return "0"; 

	// If any one (out of numerator and denominator) 
	// is -ve, sign of resultant answer -ve. 
	int sign = (num < 0) ^ (den < 0) ? -1 : 1; 

	num = abs(num); 
	den = abs(den); 

	// Calculate the absolute part (before decimal point). 
	int initial = num / den; 

	// Output string to store the answer 
	string res; 

	// Append sign 
	if (sign == -1) 
		res += "-"; 

	// Append the initial part 
	res += to_string(initial); 

	// If completely divisible, return answer. 
	if (num % den == 0) 
		return res; 

	res += "."; 

	// Initialize Remainder 
	int rem = num % den; 
	map<int, int> mp; 

	// Position at which fraction starts repeating 
	// if it exists 
	int index; 
	bool repeating = false; 
	while (rem > 0 && !repeating) { 

		// If this remainder is already seen, 
		// then there exists a repeating fraction. 
		if (mp.find(rem) != mp.end()) { 

			// Index to insert parentheses 
			index = mp[rem]; 
			repeating = true; 
			break; 
		} 
		else
			mp[rem] = res.size(); 

		rem = rem * 10; 

		// Calculate quotient, append it to result and 
		// calculate next remainder 
		int temp = rem / den; 
		res += to_string(temp); 
		rem = rem % den; 
	} 

	// If repeating fraction exists, insert parentheses. 
	if (repeating) { 
		res += ")"; 
		res.insert(index, "("); 
	} 

	// Return result. 
	return res; 
} 

// Drivers Code 
int main() 
{ 
	int num = 50, den = 22; 
	cout << calculateFraction(num, den) << endl; 

	num = -1, den = 2; 
	cout << calculateFraction(num, den) << endl; 
	return 0; 
} 


