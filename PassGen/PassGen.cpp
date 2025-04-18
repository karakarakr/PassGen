#define _CRT_NONSTDC_NO_WARNINGS
#include <iostream>

using std::cout, std::endl, std::cin;

const std::string generatePassword(
	int length = 8,
	bool addDigits = false,
	bool addSpecialChars = false
)
{
	srand((unsigned int)time(NULL));

	std::string passwd;
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	const char* digits = "0123456789";
	const char* symbols = "`~!@#$%^&*()_+=-\\|/?.,<>";

	if (addDigits) {
		alphabet.append(digits);
	}

	if (addSpecialChars) {
		alphabet.append(symbols);
	}

	delete[] digits;
	delete[] symbols;

	const size_t alphabetLength = alphabet.size();

	for (int i = 0; i < length; i++) 
	{
		int randomIndex = rand() % alphabetLength;
		passwd += alphabet[randomIndex];
	}

	return passwd;
}

int main()
{
	int length;
	bool addDigits = false;
	bool addSpecialChars = false;

	cout << "Enter the length of the password: ";
	cin >> length;

	if (length <= 0)
	{
		cout << "Invalid length. Please enter a positive integer." << endl;
		return 1;
	}

	cout << "Include digits? (1 for yes, 0 for no): ";
	cin >> addDigits;
	cout << "Include special characters? (1 for yes, 0 for no): ";
	cin >> addSpecialChars;

	const std::string password = generatePassword(length, addDigits, addSpecialChars);
	cout << "Generated password: " << password << endl;
	return 0;
    
}