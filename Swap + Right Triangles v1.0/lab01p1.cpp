/* Author: Michael Trinh
** Partner: Maxim Ruzmaykin
** CS256-01, Winter 2018
** Lab Assignment #1 Part #1
** Description:
**     Buys two items at a price+tax and prints receipt.
*/
#include <iostream>
#include <iomanip>
#include <string>

// Function for output formatting.
void output (std::ostream&, std::string, double);
// Main function
int main (int argc, char* argv[]) {
	// variables.
	double item1;
	double item2;

	std::cout << "Enter amount for item 1\n";
	std::cin >> item1;

	std::cout << "Enter amount for item 2\n";
	std::cin >> item2;
	std::cout << "\n";

	// compute subtotal and sales tax and
	// store values into local variables.
	double subTotal = item1 + item2;
	double tax = subTotal * 0.0825;

	output (std::cout, "Item 1: $", item1);
	output (std::cout, "Item 2: $", item2);
	std::cout << "\n";
	output (std::cout, "Sub Total: $", subTotal);
	output (std::cout, "Tax: $", tax);
	output (std::cout, "Total: $", subTotal + tax);
	return 0;
}

void output (std::ostream& writer, std::string tag, double value) {
	// configure output format
	writer << std::setprecision(2) << std::fixed;
	writer << tag << std::setw(7) << value << "\n";
}