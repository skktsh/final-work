#include <cstdlib>
#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>
#include <stdio.h>
using namespace std;

void interactiveMenu() {
    cout << "1. The 1st work + individual task." << endl;
    cout << "2. The 2nd work + individual task." << endl;
    cout << "3. The 3rd work + individual task." << endl;
    cout << "4. The 4th work + individual task." << endl;;
}

void fisrtTask() {
	cout << "Int: " << sizeof(int) << " byte" << endl;
	cout << "Short Int: " << sizeof(short int) << " byte" << endl;
	cout << "Long Int: " << sizeof(long int) << " byte" << endl;
	cout << "Float: " << sizeof(float) << " byte" << endl;
	cout << "Dpuble: " << sizeof(double) << " byte" << endl;
	cout << "Long Double: " << sizeof(long double) << " byte" << endl;
	cout << "Char: " << sizeof(char) << " byte" << endl;
	cout << "Bool: " << sizeof(bool) << " byte" << endl;


	int intNumber;
	cout << "Enter any integer number: ";
	cin >> intNumber;
	unsigned int intMask = 1 << (sizeof(int) * 8 - 1);

	for (int i = 1; i <= sizeof(int) * 8; i++)
	{
		putchar(intNumber & intMask ? '1' : '0');
		intMask >>= 1;
		if (i % 8 == 0 || i == 1) {
			cout << " ";
		}
	}
	cout << endl;

	cout << "Enter any float number: ";
	unsigned int floatMask = 1 << (sizeof(int) * 8 - 1);
	union {
		float floatNumber;
		int placeHolder;
	};
	cin >> floatNumber;

	for (int j = 1; j <= sizeof(float) * 8; j++)
	{
		putchar(placeHolder & floatMask ? '1' : '0');
		floatMask >>= 1;
		switch (j) {
		case 1:
			cout << " ";
			break;
		case 9:
			cout << " ";
			break;
		}
	}
	cout << endl;

	cout << "Enter any fractional number: ";
	unsigned int doubleMask = 1 << (sizeof(int) * 8 - 1);
	union {
		double doubleNumber;
		int arr[2];
	};
	cin >> doubleNumber;

	for (int z = 1; z >= 0; --z)
	{
		for (int k = 1; k <= sizeof(int) * 8; k++) {
			putchar(arr[z] & doubleMask ? '1' : '0');
			doubleMask >>= 1;
			if (z == 1 & (k == 1 || k == 12)) {
				cout << " ";
			}
		}
		doubleMask = 1 << (sizeof(int) * 8 - 1);
	}
}

void idz1() {
	bool yesAnswer = true;

	while (yesAnswer) {
		cout << "Choose a number type (1 - int, 2 - float, 3 - double, 4 - char): ";
		char typeAnswer;
		cin >> typeAnswer;

		if (typeAnswer == '1') {
			int intNumber;
			cout << "Enter any integer number: ";
			cin >> intNumber;

			unsigned int intMaskOld = 1 << (sizeof(int) * 8 - 1);
			cout << "The binary code of this number is ";
			for (int i = 1; i <= sizeof(int) * 8; i++) {
				putchar(intNumber & intMaskOld ? '1' : '0');
				intMaskOld >>= 1;
				if (i % 8 == 0 || i == 1) {
					cout << " ";
				}
			}
			cout << endl;

			cout << "How far left do you want to move single digits? ";
			int moveAnswerInt;
			cin >> moveAnswerInt;
			cout << "The modified binary code is ";
			intNumber <<= moveAnswerInt;
			unsigned int intMaskNew = 1 << (sizeof(int) * 8 - 1);
			for (int j = 1; j <= sizeof(int) * 8; j++) {
				putchar(intNumber & intMaskNew ? '1' : '0');
				intMaskNew >>= 1;
				if (j % 8 == 0 || j == 1) {
					cout << " ";
				}
			}
			cout << endl;
			cout << "Your new number is " << intNumber << endl;
		}


		if (typeAnswer == '2') {
			cout << "Enter any float number: ";
			union {
				float floatNumber;
				int placeHolder;
			};
			cin >> floatNumber;

			unsigned floatMaskOld = 1 << (sizeof(float) * 8 - 1);
			cout << "The binary code of this number is ";
			for (int k = 1; k <= sizeof(int) * 8; k++) {
				putchar(placeHolder & floatMaskOld ? '1' : '0');
				floatMaskOld >>= 1;
				switch (k) {
				case 1:
					cout << " ";
					break;
				case 9:
					cout << " ";
					break;
				}
			}
			cout << endl;

			cout << "How far left do you want to move single digits? ";
			int moveAnswerFloat;
			cin >> moveAnswerFloat;
			cout << "The modified binary code is ";
			placeHolder <<= moveAnswerFloat;
			unsigned int floatMaskNew = 1 << (sizeof(int) * 8 - 1);
			for (int z = 1; z <= sizeof(int) * 8; z++) {
				putchar(placeHolder & floatMaskNew ? '1' : '0');
				floatMaskNew >>= 1;
				switch (z) {
				case 1:
					cout << " ";
					break;
				case 9:
					cout << " ";
					break;
				}
			}
			cout << endl;
			cout << "Your new number is " << placeHolder << endl;
		}

		if (typeAnswer == '3') {
			cout << "Enter any double number: ";
			union {
				double doubleNumber;
				int doubleArr[2];
			};
			cin >> doubleNumber;

			unsigned doubleMaskOld = 1 << (sizeof(int) * 8 - 1);
			cout << "The binary code of this number is ";
			for (int a = 1; a >= 0; --a)
			{
				for (int b = 1; b <= sizeof(int) * 8; b++) {
					putchar(doubleArr[a] & doubleMaskOld ? '1' : '0');
					doubleMaskOld >>= 1;
					if (a == 1 & (b == 1 || b == 12)) {
						cout << " ";
					}
				}
				doubleMaskOld = 1 << (sizeof(int) * 8 - 1);
			}
			cout << endl;

			cout << "How far left do you want to move single digits? ";
			int moveAnswerDouble;
			cin >> moveAnswerDouble;
			cout << "The modified binary code is ";
			doubleArr[0] <<= moveAnswerDouble;
			doubleArr[1] <<= moveAnswerDouble;
			unsigned int doubleMaskNew = 1 << (sizeof(int) * 8 - 1);
			for (int c = 1; c >= 0; --c)
			{
				for (int d = 1; d <= sizeof(int) * 8; d++) {
					putchar(doubleArr[c] & doubleMaskNew ? '1' : '0');
					doubleMaskNew >>= 1;
					if (c == 1 & (d == 1 || d == 12)) {
						cout << " ";
					}
				}
				doubleMaskNew = 1 << (sizeof(int) * 8 - 1);
			}
			cout << endl;
		}

		if (typeAnswer == '4') {
			char charType;
			cout << "Enter any character: ";
			cin >> charType;

			unsigned char maskCharOld = 1 << (sizeof(char) * 8 - 1);
			cout << "The binary code of this character is ";
			for (int i = 1; i <= sizeof(char) * 8; i++) {
				putchar(charType & maskCharOld ? '1' : '0');
				maskCharOld >>= 1;
			}
			cout << endl;

			cout << "How far left do you want to move single digits? ";
			int moveAnswerChar;
			cin >> moveAnswerChar;
			cout << "The modified binary code is ";
			unsigned char maskCharNew = 1 << (sizeof(char) * 8 - 1);
			charType <<= 1;
			for (int j = 1; j <= sizeof(char) * 8; j++) {
				putchar(charType & maskCharNew ? '1' : '0');
				maskCharNew >>= 1;
			}
			cout << endl;

			cout << "Your new character is " << charType << endl;
		}

		else {
			cout << "Incorrect input. PLease, try again." << endl;
		}

		cout << "Do you want to continue? (Yes - 1; No - 2): ";
		char answer;
		cin >> answer;
		if (answer == '1') {
			yesAnswer = true;
		}
		else {
			yesAnswer = false;
		}
	}
}

void quicksort(int* arr, int end, int begin) {
	int pivotElement;
	int start = begin;
	int finish = end;
	pivotElement = arr[(start + finish) / 2];
	while (start < finish) {
		while (arr[start] < pivotElement) start++;
		while (arr[finish] > pivotElement) finish--;
		if (start <= finish) {
			std::swap(arr[start], arr[finish]);
			start++;
			finish--;
		}
	}
	if (begin < finish) quicksort(arr, finish, begin);
	if (start < end) quicksort(arr, end, start);
}

int binarySearch(int arr[], int value, int start, int end) {
	if (end >= start) {
		int mid = start + (end - start) / 2;

		if (arr[mid] == value) {
			return mid;
		}

		if (arr[mid] > value) {
			return binarySearch(arr, value, start, mid - 1);
		}
		else {
			return binarySearch(arr, value, mid + 1, end);
		}
	}

	return -1;
}

int sorting(int arr[], int arrayLength, int value) {
	for (int i = 0; i < arrayLength; i++) {
		if (arr[i] == value) {
			return i;
		}
	}
}

void sortedArraySearch(int arr[], int arrayLength) {
	int maximum = arr[arrayLength - 1];
	int minimum = arr[0];
}

void unsortedArraySearch(int arr[], int arrayLength) {
	int maximum = arr[0];
	int minimum = arr[0];

	for (int i = 1; i < arrayLength; i++) {
		if (arr[i] > maximum) {
			maximum = arr[i];
		}
		if (arr[i] < minimum) {
			minimum = arr[i];
		}
	}
}

int arithmeticMeanSearchSortedArray(int arr[], int arrayLength) {
	int maximum = arr[arrayLength - 1];
	int minimum = arr[0];
	int arithmeticMean = (maximum + minimum) / 2;
	return arithmeticMean;
}

int arithmeticMeanSearchUnsortedArray(int arr[], int arrayLength) {
	int maximum = 0;
	int minimum = 100;

	for (int i = 0; i < arrayLength; i++) {
		if (arr[i] > maximum) {
			maximum = arr[i];
		}
		if (arr[i] < minimum) {
			minimum = arr[i];
		}
	}
	int arithmeticMean = (maximum + minimum) / 2;
	return arithmeticMean;
}

void indexSearch(int arr[], int arrayLength, int arithmeticMean) {
	int countSortedArr = 0;
	for (int i = 0; i < arrayLength - 1; i++) {
		if (arr[i] == arithmeticMean) {
			countSortedArr += 1;
		}
	}
}

void changingElements(int arr[], int index1, int index2) {
	std::swap(arr[index1], arr[index2]);
}

void secondTask() {
	const int arrayLength = 100;
	int unsortedArr[arrayLength];
	int sortedArr[arrayLength];
	int userAnswer;

	srand(time(0));
	std::cout << "The unsorted array is " << std::endl;
	for (int i = 0; i < arrayLength; i++) {
		unsortedArr[i] = rand() % 199 - 99;
		sortedArr[i] = rand() % 199 - 99;
		std::cout << unsortedArr[i] << " ";
	}
	for (int i = 0; i < arrayLength; i++) {
		sortedArr[i] = unsortedArr[i];
	}
	std::cout << std::endl;

	int end = arrayLength - 1, begin = 0;
	auto start = std::chrono::steady_clock::now();
	quicksort(sortedArr, end, begin);
	auto stop = std::chrono::steady_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	std::cout << "The sorted array is " << std::endl;
	for (int i = 0; i < arrayLength; i++) {
		std::cout << sortedArr[i] << " ";
	}
	std::cout << std::endl << "The time spent to sort the array is " << duration.count() << " ns\n";
	std::cout << std::endl;

	std::cout << "What do you want to do? (1 - to find maximum and minimum elements; 2 - to find an arithemtic mean and indexes of the elements that have the same value as arithemtic mean; 3 - to find elements that are lower/higher than your number; 4 - to find an index of your number in the array and to swap two indexes; 5. To exit task.) ";
	std::cin >> userAnswer;

	if (userAnswer == 1) {
		std::cout << "The maximum and minimum elements in the array are ";
		std::cout << sortedArr[arrayLength - 1] << ", " << sortedArr[0] << std::endl;

		auto startSortedSearch = std::chrono::steady_clock::now();
		sortedArraySearch(sortedArr, arrayLength);
		auto stopSortedSearch = std::chrono::steady_clock::now();
		auto durationSortedSearch = std::chrono::duration_cast<std::chrono::nanoseconds>(stopSortedSearch - startSortedSearch);
		std::cout << "The time spent to find the maximum and minimum element in the sorted array is " << durationSortedSearch.count() << " ns\n";

		auto startUnsortedSearch = std::chrono::steady_clock::now();
		unsortedArraySearch(unsortedArr, arrayLength);
		auto stopUnsortedSearch = std::chrono::steady_clock::now();
		auto durationUnsortedSearch = std::chrono::duration_cast<std::chrono::nanoseconds>(stopUnsortedSearch - startUnsortedSearch);
		std::cout << "The time spent to find the maximum and minimum element in the unsorted array is " << durationUnsortedSearch.count() << " ns\n";
		std::cout << std::endl;

		std::cout << "What do you want to do next? (1 - to find maximum and minimum elements; 2 - to find an arithemtic mean and indexes of the elements that have the same value as arithemtic mean; 3 - to find elements that are lower/higher than your number; 4 - to find an index of your number in the array and to swap two indexes; 5. To exit task.) ";
		std::cin >> userAnswer;
	}

	if (userAnswer == 2) {
		int arithmeticMean = arithmeticMeanSearchSortedArray(sortedArr, arrayLength);
		std::cout << "The arithmetic mean in an array is: " << arithmeticMean << std::endl;
		auto startArithmeticMeanSearchSorted = std::chrono::steady_clock::now();
		arithmeticMeanSearchSortedArray(sortedArr, arrayLength);
		auto stopArithmeticMeanSearchSorted = std::chrono::steady_clock::now();
		auto durationArithmeticMeanSearchSorted = std::chrono::duration_cast<std::chrono::nanoseconds>(stopArithmeticMeanSearchSorted - startArithmeticMeanSearchSorted);
		std::cout << "The time spent to find arithemtic mean in a sorted array is " << durationArithmeticMeanSearchSorted.count() << " ns\n";

		auto startArithmeticMeanSearchUnsorted = std::chrono::steady_clock::now();
		arithmeticMeanSearchUnsortedArray(sortedArr, arrayLength);
		auto stopArithmeticMeanSearchUnsorted = std::chrono::steady_clock::now();
		auto durationArithmeticMeanSearchUnsorted = std::chrono::duration_cast<std::chrono::nanoseconds>(stopArithmeticMeanSearchUnsorted - startArithmeticMeanSearchUnsorted);
		std::cout << "The time spent find arithemtic mean in an unsorted array is " << durationArithmeticMeanSearchUnsorted.count() << " ns\n";
		std::cout << std::endl;

		int countSortedArr = 0;
		std::cout << "The indexes of the elements that have the same value as arithemtic mean in the sorted array are ";
		for (int i = 0; i < arrayLength - 1; i++) {
			if (sortedArr[i] == arithmeticMean) {
				countSortedArr += 1;
				std::cout << i << " ";
			}
		}
		if (countSortedArr == 0) {
			std::cout << std::endl << "There are no elements that have the same value as the arithmetic mean.";
		}
		std::cout << std::endl;

		int countUnsortedArr = 0;
		std::cout << "The indexes of the elements that have the same value as arithemtic mean in the unsorted array are ";
		for (int i = 0; i < arrayLength - 1; i++) {
			if (unsortedArr[i] == arithmeticMean) {
				countUnsortedArr += 1;
				std::cout << i << " ";
			}
		}
		if (countUnsortedArr == 0) {
			std::cout << std::endl << "There are no elements that have the same value as the arithmetic mean.";
		}
		std::cout << std::endl;

		auto startIndexSearchSorted = std::chrono::steady_clock::now();
		indexSearch(sortedArr, arrayLength, arithmeticMean);
		auto stopIndexSearchSorted = std::chrono::steady_clock::now();
		auto durationIndexSearchSorted = std::chrono::duration_cast<std::chrono::nanoseconds>(stopIndexSearchSorted - startIndexSearchSorted);
		std::cout << "The overall time spent to find elements that have the same value as arithmetic mean and their amount in the sorted array is " << durationIndexSearchSorted.count() + durationArithmeticMeanSearchSorted.count() << " ns\n";

		auto startIndexSearchUnsorted = std::chrono::steady_clock::now();
		indexSearch(unsortedArr, arrayLength, arithmeticMean);
		auto stopIndexSearchUnsorted = std::chrono::steady_clock::now();
		auto durationIndexSearchUnsorted = std::chrono::duration_cast<std::chrono::nanoseconds>(stopIndexSearchUnsorted - startIndexSearchUnsorted);
		std::cout << "The overall time spent to find elements that have the same value as arithmetic mean and their amount in the sorted array is " << durationIndexSearchUnsorted.count() + durationArithmeticMeanSearchUnsorted.count() << " ns\n";
		std::cout << std::endl;

		std::cout << "What do you want to do next? (1 - to find maximum and minimum elements; 2 - to find an arithemtic mean and indexes of the elements that have the same value as arithemtic mean; 3 - to find elements that are lower/higher than your number; 4 - to find an index of your number in the array and to swap two indexes; 5. To exit task.) ";
		std::cin >> userAnswer;
	}

	if (userAnswer == 3) {
		std::cout << "Enter any number from -99 to 99: ";
		int lowerNumber;
		std::cin >> lowerNumber;
		int countLowerNumbers = 0;
		int indexLowerNumbers = 0;
		while (sortedArr[indexLowerNumbers] < lowerNumber) {
			countLowerNumbers++;
			indexLowerNumbers++;
		}
		std::cout << "The amount of elements that are lower than your number is " << countLowerNumbers << std::endl;

		std::cout << "Enter any number from -99 to 99: ";
		int higherNumber;
		std::cin >> higherNumber;
		int countHigherNumbers = 0;
		int indexHigherNumbers = 99;
		while (sortedArr[indexHigherNumbers] > higherNumber) {
			countHigherNumbers++;
			indexHigherNumbers--;
		}
		std::cout << "The amount of elements that are higher than your number is " << countHigherNumbers << std::endl;

		std::cout << "What do you want to do next? (1 - to find maximum and minimum elements; 2 - to find an arithemtic mean and indexes of the elements that have the same value as arithemtic mean; 3 - to find elements that are lower/higher than your number; 4 - to find an index of your number in the array and to swap two indexes; 5. To exit task) ";
		std::cin >> userAnswer;
	}

	if (userAnswer == 4) {
		int size = sizeof(sortedArr) / sizeof(sortedArr[0]);
		int value;
		std::cout << "Please, enter any number: ";
		std::cin >> value;

		int answer = binarySearch(sortedArr, value, 0, size - 1);

		if (answer == -1) {
			std::cout << "There's no such number in the array." << std::endl;
		}
		else {
			std::cout << "Your number's index in the array is " << answer << std::endl;
		}

		auto startComparisonBinarySearch = std::chrono::steady_clock::now();
		binarySearch(sortedArr, value, 0, size - 1);
		auto stopComparisonBinarySearch = std::chrono::steady_clock::now();
		auto durationComparisonBinarySearch = std::chrono::duration_cast<std::chrono::nanoseconds>(stopComparisonBinarySearch - startComparisonBinarySearch);
		std::cout << "The time spent to find the index of your number using binary search is " << durationComparisonBinarySearch.count() << std::endl;

		auto startComparisonLinearSearch = std::chrono::steady_clock::now();
		sorting(sortedArr, arrayLength, value);
		auto stopComparisonLinearSearch = std::chrono::steady_clock::now();
		auto durationComparisonLinearSearch = std::chrono::duration_cast<std::chrono::nanoseconds>(stopComparisonLinearSearch - startComparisonLinearSearch);
		std::cout << "The time spent to find the index of your number using linear search is " << durationComparisonLinearSearch.count() << std::endl;

		int durationDifference = durationComparisonBinarySearch.count() - durationComparisonLinearSearch.count();
		if (durationDifference < 0) {
			durationDifference *= -1;
		}
		std::cout << "The difference between binary search and linear search is " << durationDifference << std::endl;

		std::cout << "Enter two indexes from 0 to 99 " << std::endl;
		int index1, index2;
		std::cin >> index1 >> index2;

		auto startChangingElements = std::chrono::steady_clock::now();
		changingElements(sortedArr, index1, index2);
		auto stopChangingElements = std::chrono::steady_clock::now();
		auto durationChangingElements = std::chrono::duration_cast<std::chrono::nanoseconds>(stopChangingElements - startChangingElements);
		std::cout << "The time spent to swap the elements with the indexes you've entered is " << durationChangingElements.count() << " ns" << std::endl;

		std::cout << "The changed array is " << std::endl;
		for (int i = 0; i < arrayLength; i++) {
			std::cout << sortedArr[i] << " ";
		}

		std::cout << std::endl << "What do you want to do? (1 - to find maximum and minimum elements; 2 - to find an arithemtic mean and indexes of the elements that have the same value as arithemtic mean; 3 - to find elements that are lower/higher than your number; 4 - to find an index of your number in the array and to swap two indexes; 5. To exit task.) ";
		std::cin >> userAnswer;
	}
}

void shellSort(int arr[], int size) {
	int interval = size / 2;
	for (interval; interval > 0; interval /= 2) {
		for (int i = interval; i < size; i++) {
			for (int j = i - interval; j >= 0; j -= interval) {
				if (arr[j + interval] >= arr[j]) {
					break;
				}
				else {
					int temp;
					temp = arr[j + interval];
					arr[j + interval] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
}

void idz2() {
	const int arrayLength = 50;
	int arr[arrayLength];

	srand(time(0));
	std::cout << "The unsorted array is " << std::endl;
	for (int i = 0; i < arrayLength; i++) {
		arr[i] = rand() % 199 - 99;
		std::cout << arr[i] << " ";
	}

	auto shellSortStart = std::chrono::steady_clock::now();
	shellSort(arr, arrayLength);
	auto shellSortStop = std::chrono::steady_clock::now();
	auto durationShellSort = std::chrono::duration_cast<std::chrono::nanoseconds>(shellSortStop - shellSortStart);

	std::cout << std::endl << "Sorted Output: \n";
	for (int i = 0; i < arrayLength; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl << "The time spent to sort the array with Shell Sort is " << durationShellSort.count() << " ns\n";

	int begin = 0, end = arrayLength - 1;
	auto quickSortStart = std::chrono::steady_clock::now();
	quicksort(arr, end, begin);
	auto quickSortStop = std::chrono::steady_clock::now();
	auto durationQuickSort = std::chrono::duration_cast<std::chrono::nanoseconds>(quickSortStop - quickSortStart);
	std::cout << "The time spent to sort the array with Quick Sort is " << durationQuickSort.count() << " ns\n";
}

void printMatrix(int* matrix, int size, int helper) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD destCoord;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			destCoord.X = j * 4 + 50;
			destCoord.Y = i + helper;
			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *(matrix + i * size + j) << " ";
		}
		cout << endl;
	}
}

void quicksort(int* matrix, int* end, int* begin) {
	int pivotElement;
	int* start = begin;
	int* finish = end;
	pivotElement = *(begin + (end - begin) / 2);
	while (start < finish) {
		while (*start < pivotElement) start++;
		while (*finish > pivotElement) finish--;
		if (start <= finish) {
			std::swap(*start, *finish);
			start++;
			finish--;
		}
	}
	if (begin < finish) quicksort(matrix, finish, begin);
	if (start < end) quicksort(matrix, end, start);
}

void fillSnake(int* matrix, int n) {
	int top = 0, bottom = n - 1, left = 0, right = n - 1;
	while (top <= bottom && left <= right) {
		for (int i = top; i <= bottom; i++) {
			int* num = matrix + i * n + left;
			*num = rand() % (n * n) + 1;
			printMatrix(matrix, n, 10);
			Sleep(200);
		}
		left++;

		for (int i = bottom; i >= top; i--) {
			int* num = matrix + i * n + left;
			*num = rand() % (n * n) + 1;
			printMatrix(matrix, n, 10);
			Sleep(200);
		}
		left++;
	}
}
void fillSpiral(int* matrix, int n) {
	int top = 0, bottom = n - 1, left = 0, right = n - 1;
	while (top <= bottom && left <= right) {
		for (int i = left; i <= right; i++) {
			*(matrix + top * n + i) = rand() % (n * n) + 1;
			printMatrix(matrix, n, 10);
			Sleep(200);
		}
		top++;

		for (int i = top; i <= bottom; i++) {
			*(matrix + i * n + right) = rand() % (n * n) + 1;
			printMatrix(matrix, n, 10);
			Sleep(200);
		}
		right--;


		for (int i = right; i >= left; i--) {
			*(matrix + bottom * n + i) = rand() % (n * n) + 1;
			printMatrix(matrix, n, 10);
			Sleep(200);
		}
		bottom--;

		for (int i = bottom; i >= top; i--) {
			*(matrix + i * n + left) = rand() % (n * n) + 1;
			printMatrix(matrix, n, 10);
			Sleep(200);
		}
		left++;
	}
	printMatrix(matrix, n, 10);
}
void swap_quarters_a(int* matrix, int N) {
	int* temp = new int[N * N];
	int middle = N / 2;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			*(temp + i * N + j) = *(matrix + i * N + j);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i < middle && j < middle) {
				*(matrix + i * N + j + middle) = *(temp + i * N + j);
			}
			else if (i < middle && j >= middle) {
				*(matrix + (i + middle) * N + j) = *(temp + i * N + j);
			}
			else if (i >= middle && j >= middle) {
				*(matrix + i * N + (j - middle)) = *(temp + i * N + j);
			}
			else {
				*(matrix + (i - middle) * N + j) = *(temp + i * N + j);
			}
		}
	}
	printMatrix(matrix, N, N + 15);
}
void swap_quarters_b(int* matrix, int N) {
	int* temp = new int[N * N];
	int middle = N / 2;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			*(temp + i * N + j) = *(matrix + i * N + j);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i < middle && j < middle) {
				*(matrix + (i + middle) * N + j + middle) = *(temp + i * N + j);
			}
			else if (i < middle && j >= middle) {
				*(matrix + (i + middle) * N + j - middle) = *(temp + i * N + j);
			}
			else if (i >= middle && j >= middle) {
				*(matrix + (i - middle) * N + j - middle) = *(temp + i * N + j);
			}
			else {
				*(matrix + (i - middle) * N + j + middle) = *(temp + i * N + j);
			}
		}
	}
	printMatrix(matrix, N, N + 15);
}
void swap_quarters_c(int* matrix, int N) {
	int* temp = new int[N * N];
	int middle = N / 2;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			*(temp + i * N + j) = *(matrix + i * N + j);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i < middle) {
				*(matrix + (i + middle) * N + j) = *(temp + i * N + j);
			}
			else {
				*(matrix + (i - middle) * N + j) = *(temp + i * N + j);
			}
		}
	}
	printMatrix(matrix, N, N + 15);
}

void swap_quarters_d(int* matrix, int N) {
	int* temp = new int[N * N];
	int middle = N / 2;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			*(temp + i * N + j) = *(matrix + i * N + j);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j < middle) {
				*(matrix + i * N + j + middle) = *(temp + i * N + j);
			}
			else {
				*(matrix + i * N + j - middle) = *(temp + i * N + j);
			}
		}
	}
	printMatrix(matrix, N, N + 15);
}
void enlarge_each_element(int* matrix, int N) {
	int enlarge_num;

	cout << "Enter any number: ";
	cin >> enlarge_num;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			*(matrix + i * N + j) += enlarge_num;
		}
	}
	printMatrix(matrix, N, N + 40);
}
void reduce_each_element(int* matrix, int N) {
	int reduce_num;

	cout << "Enter any number: ";
	cin >> reduce_num;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			*(matrix + i * N + j) -= reduce_num;
		}
	}
	printMatrix(matrix, N, N + 40);
}
void divide_each_element(int* matrix, int N) {
	int divide_num;

	cout << "Enter any number: ";
	cin >> divide_num;
	if (divide_num == 0) {
		cout << "You can not divide by zero" << endl;
		return;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			*(matrix + i * N + j) /= divide_num;
		}
	}
	printMatrix(matrix, N, N + 40);
}

void multiply_each_element(int* matrix, int N) {
	int multiply_num;

	cout << "Enter any number: ";
	cin >> multiply_num;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			*(matrix + i * N + j) *= multiply_num;
		}
	}
	printMatrix(matrix, N, N + 40);
}

void start(int* matrix, int size) {
	for (int j = 0; j < size; ++j) {
		for (int i = 0; i < size; ++i) {
			*(matrix + i * size + j) = 1;
		}
	}
}

void thirdTask() {
	srand(time(0));
	int size, answer, answerFill, answerBlockMove, answerNumber;
	cout << "Choose the size of a matrix (6, 8, 10): ";
	cin >> size;
	int* matrix = new int[size * size];
	bool flag = true;

	while (flag) {
		cout << "Choose how you want to fill the matrix: " << endl << "1. Spiral Pattern;" << endl << "2. Snake Pattern." << endl;
		cin >> answerFill;
		start(matrix, size);

		switch (answerFill) {
		case 1:
			fillSpiral(matrix, size);
			break;
		case 2:
			fillSnake(matrix, size);
			break;
		}

		cout << "Choose how you want to move blocks of the matrix: " << endl << "1. Square Pattern;" << endl << "2. Cross Pattern;" << endl << "3. Vertically; " << endl << "4. Horizontally." << endl;
		cin >> answerBlockMove;

		switch (answerBlockMove) {
		case 1:
			swap_quarters_a(matrix, size);
			break;
		case 2:
			swap_quarters_b(matrix, size);
			break;
		case 3:
			swap_quarters_c(matrix, size);
			break;
		case 4:
			swap_quarters_d(matrix, size);
			break;
		}

		quicksort(matrix, matrix + size * size - 1, matrix);
		printMatrix(matrix, size, size + 25);


		cout << "What do you want to do with the elements of the matix: " << endl << "1. To reduce each element;" << endl << "2. To enlarge each element;" << endl << "3. To multiply each element;" << endl << "4. To divide each element." << endl;
		cin >> answerNumber;

		switch (answerNumber) {
		case 1:
			reduce_each_element(matrix, size);
			break;
		case 2:
			enlarge_each_element(matrix, size);
			break;
		case 3:
			multiply_each_element(matrix, size);
			break;
		case 4:
			divide_each_element(matrix, size);
			break;
		}

		cout << "Do you want to continue with this task?: " << endl << "1. Yes; " << endl << "2. No" << endl;
		int continueAnswer;
		cin >> continueAnswer;

		switch (continueAnswer) {
		case 1:
			flag = true;
			break;
		case 2:
			flag = false;
			break;
		}
	}
}

int determinant(int* ptr, int det) {
	det = *ptr * (*(ptr + 4) * (*(ptr + 8)) - *(ptr + 5) * (*(ptr + 7))) - *(ptr + 1) * (*(ptr + 3) * (*(ptr + 8)) - *(ptr + 6) * (*(ptr + 5))) + *(ptr + 2) * (*(ptr + 3) * (*(ptr + 7)) - *(ptr + 4) * (*(ptr + 6)));
	return det;
}

void idz3() {
	srand(time(0));
	const int size = 3;
	int det = 0;

	int matrix[size][size];

	int* end = *matrix + size * size - 1;

	cout << "Your 3x3 matrix is " << endl;
	for (int* pr = *matrix; pr <= end; pr++) {
		*pr = rand() % 61 - 30;
		cout << *pr << "\t";

		if ((pr - *matrix + 1) % size == 0)
			cout << "\n";
	}
	cout << endl;
	int* ptr = *matrix;

	int answer = determinant(ptr, det);
	cout << "The determinant of the matrix is " << answer;
}

unsigned factArrayLength(char* stringArr) {
	int length = 0;

	while (stringArr[length]) {
		length++;
	}

	return length;
}

int deletePunctuation(char* arr, char character, char* modifiedArr) {
	int count = 0;
	int indexModifiedArr = 0;
	for (int i = 0; arr[i] != '\0'; i++) {
		if (arr[i] == character) {
			count++;
			if (count <= 1) {
				modifiedArr[indexModifiedArr] = arr[i];
				indexModifiedArr++;
			}
		}
		else {
			modifiedArr[indexModifiedArr] = arr[i];
			indexModifiedArr++;
			count = 0;
		}
		modifiedArr[indexModifiedArr] = '\0';
	}

	return 1;
}

int deleteElipsisMarks(char* arr, char character, char* modifiedArr, int factLength) {
	int count = 0;
	int indexModifiedArr = 0;
	for (int i = 0; i < factLength; i++) {
		if (arr[i] == character) {
			count++;
			if (count <= 3) {
				modifiedArr[indexModifiedArr] = arr[i];
				indexModifiedArr++;
			}
		}
		else {
			modifiedArr[indexModifiedArr] = arr[i];
			indexModifiedArr++;
			count = 0;
		}
		modifiedArr[indexModifiedArr + 1] = '\0';
	}

	return 1;
}

int changeLetterCase(char* arr, int factLength) {
	const int differenceBetweenLettersLatin = 32;

	if (arr[0] >= 97 and arr[0] <= 122)
		arr[0] -= differenceBetweenLettersLatin;

	for (int index = 1; index < factLength - 2; index++) {
		if (arr[index] == ' ' and arr[index - 1] == '.' and arr[index + 1] >= 97 and arr[index + 1] <= 122) {
			arr[index + 1] -= differenceBetweenLettersLatin;
		}

		if (arr[index] == ' ' and arr[index - 1] != '.' and arr[index + 1] >= 65 and arr[index + 1] <= 90) {
			arr[index + 1] += differenceBetweenLettersLatin;
		}

		if (arr[index] != ' ' and (arr[index - 2] != '.' and arr[index - 1] != '.') and arr[index] >= 65 and arr[index] <= 90)
			arr[index] += differenceBetweenLettersLatin;
	}
	return 1;
}

void changeToCapitalLetter(char* arr, int factLength) {
	const int differenceBetweenLettersLatin = 32;
	const int differenceBetweenLettersRussianSecondHalf = 80;

	for (int index = 1; index < factLength; index++) {
		if (arr[index] == ' ') {
			if (arr[index - 1] >= 97 && arr[index - 1] <= 122 or arr[index - 1] >= 160 && arr[index - 1] <= 175)
				arr[index - 1] = arr[index - 1] - differenceBetweenLettersLatin;
			if (arr[index - 1] >= 224 && arr[index - 1] <= 239)
				arr[index - 1] = arr[index - 1] - differenceBetweenLettersRussianSecondHalf;
		}
	}
}

void backwardArrayModification(char* arr, int factLength, char* backwardArray) {
	int index = 0;
	for (int i = factLength - 1; i > -1; i--) {
		backwardArray[index] = arr[i];
		index++;
		backwardArray[index + 1] = '\0';
	}
}

int linearSearch(char* stringArr, char* substringArr) {
	int factLengthStringArr = factArrayLength(stringArr);
	int factLengthSubstringArr = factArrayLength(substringArr);
	int count = 0;

	for (int i = 0; i <= factLengthStringArr - factLengthSubstringArr; i++) {
		int j;
		for (j = 0; j < factLengthSubstringArr; j++) {
			if (stringArr[i + j] != substringArr[j])
				break;
		}

		if (j == factLengthSubstringArr)
			count++;
	}

	return count;
}

int checkWordAmount(char* stringArr, int factLength) {
	bool check = true;
	int index = 0;
	int count = 0;

	for (index = 0; index < factLength; index++) {
		if (stringArr[index] == ' ') {
			if (count >= 10) {
				check = false;
				break;
			}
			count = 0;
		}
		else
			count++;
	}

	if (check != true)
		return -1;
}

int maximum(int numberOne, int numberTwo) {
	return (numberOne > numberTwo) ? numberOne : numberTwo;
}

void badCharacterHeuristic(char* stringArr, int size, int badCharacter[256]) {
	int i, index;

	for (i = 0; i < 256; i++)
		badCharacter[i] = -1;

	for (i = 0; i < size; i++) {
		index = stringArr[i];
		badCharacter[index] = i;
	}
}

int searchBoyerMoor(char* stringArr, char* substringArr) {
	int factLengthStringArr = factArrayLength(stringArr);
	int factLengthSubstringArr = factArrayLength(substringArr);

	int badCharacter[256];
	int count = 0;

	badCharacterHeuristic(substringArr, factLengthSubstringArr, badCharacter);

	int shift = 0;
	while (shift <= (factLengthStringArr - factLengthSubstringArr)) {
		int j = factLengthSubstringArr - 1;

		while (j >= 0 && substringArr[j] == stringArr[shift + j])
			j--;

		if (j < 0) {
			count++;
			shift += (shift + factLengthSubstringArr < factLengthStringArr) ? factLengthSubstringArr - badCharacter[stringArr[shift + factLengthSubstringArr]] : 1;
		}

		else {
			shift += maximum(1, j - badCharacter[stringArr[shift + j]]);
		}
	}

	return count;
}

void fourthTask() {
	int const approximateLength = 100;
	char stringArr[approximateLength];
	char finalModification[approximateLength];
	int factLengthFinal, checkCorrectness = 1;

	cout << "Enter your string (!NOTE Your string mast contain 1 to 50 words, and each of them should consist of 1 to 10 letters and/or numbers; the string should end in \".\")" << endl;
	cin.ignore();
	cin.getline(stringArr, approximateLength);
	cin.sync();

	int factLengthString = factArrayLength(stringArr);

	char modifiedArrSpaces[approximateLength];
	deletePunctuation(stringArr, ' ', modifiedArrSpaces);

	char modifiedArrCommas[approximateLength];
	deletePunctuation(modifiedArrSpaces, ',', modifiedArrCommas);

	char modifiedArrExclamationMark[approximateLength];
	deletePunctuation(modifiedArrCommas, '!', modifiedArrExclamationMark);

	char modifiedArrQuestionMark[approximateLength];
	deletePunctuation(modifiedArrExclamationMark, '?', modifiedArrQuestionMark);

	char modifiedArrSlash[approximateLength];
	deletePunctuation(modifiedArrQuestionMark, '/', modifiedArrSlash);

	char modifiedArrColon[approximateLength];
	deletePunctuation(modifiedArrSlash, ':', modifiedArrColon);

	char modifiedArrSemicolon[approximateLength];
	deletePunctuation(modifiedArrColon, ';', modifiedArrSemicolon);

	char modifiedArrRoundBracketLeft[approximateLength];
	deletePunctuation(modifiedArrSemicolon, '(', modifiedArrRoundBracketLeft);

	char modifiedArrRoundBracketRight[approximateLength];
	deletePunctuation(modifiedArrRoundBracketLeft, ')', modifiedArrRoundBracketRight);

	char modifiedArrSquareBracketLeft[approximateLength];
	deletePunctuation(modifiedArrRoundBracketRight, '[', modifiedArrSquareBracketLeft);

	char modifiedArrSquareBracketRight[approximateLength];
	deletePunctuation(modifiedArrSquareBracketLeft, ']', modifiedArrSquareBracketRight);


	char modifiedArrDash[approximateLength];
	deletePunctuation(modifiedArrSquareBracketRight, '-', modifiedArrDash);

	char modifiedArrQuotationMarks[approximateLength];
	deletePunctuation(modifiedArrDash, '\"', modifiedArrQuotationMarks);

	int factLength = factArrayLength(modifiedArrSlash);
	deleteElipsisMarks(modifiedArrSlash, '.', finalModification, factLength);

	factLengthFinal = factArrayLength(finalModification);
	int checkWords = checkWordAmount(finalModification, factLengthFinal);

	changeLetterCase(finalModification, factLengthFinal);


	cout << "Your fixed array looks like: " << endl << finalModification << endl;

	char backwardArray[approximateLength];
	backwardArrayModification(finalModification, factLengthFinal, backwardArray);
	cout << "Your string backwards looks like: " << endl << backwardArray << endl;

	changeToCapitalLetter(backwardArray, factLengthFinal);
	cout << "The backward string with the first letter of each word being turned into a capital one looks like: " << endl << backwardArray << endl;

	cout << "What substring do you want to do find in your string: " << endl;
	char substringArr[approximateLength];
	cin.getline(substringArr, approximateLength);
	cin.sync();

	cout << "Linear Search: " << endl;
	int countLinearSearch = linearSearch(finalModification, substringArr);
	cout << "The amount of times your substring can be found in the string is " << countLinearSearch << endl;

	cout << "Boyer-Moor Search: " << endl;
	int countBoyerMoor = searchBoyerMoor(finalModification, substringArr);
	cout << "The amount of times your substring can be found in the string is " << countBoyerMoor << endl;
}

int main()
{
	interactiveMenu();
	int workNumber, newNumber;
	bool flag = true;
	cin >> workNumber;
	newNumber = workNumber;


	while (true) {
		switch (workNumber) {
		case 1:
			system("cls");
			flag = true;
			while (flag) {
				cout << endl << "What do you want to see?: " << endl << "1. The 1st work; " << endl << "2. Individual task." << endl << "3. To see another task." << endl;
				int answerFirstWork;
				cin >> answerFirstWork;

				switch (answerFirstWork) {
				case 1:
					system("cls");
					fisrtTask();
					flag = false;
					break;
				case 2:
					system("cls");
					idz1();
					flag = false;
					break;
				case 3:
					system("cls");
					cout << "What task do you want to see? " << endl;
					cin >> workNumber;
					flag = false;
					break;
				}
			}
			break;
		case 2:
			system("cls");
			flag = true;

			while (flag) {
				cout << endl << "What do you want to see?: " << endl << "1. The 2nd work; " << endl << "2. Individual task." << endl << "3. To see another task." << endl;
				int answerSecondWork;
				cin >> answerSecondWork;

				switch (answerSecondWork) {
				case 1:
					system("cls");
					secondTask();
					flag = false;
					break;
				case 2:
					system("cls");
					idz2();
					flag = false;
					break;
				case 3:
					system("cls");
					cout << "What task do you want to see? " << endl;
					cin >> workNumber;
					flag = false;
					break;
				}
			}
			break;
		case 3:
			system("cls");
			flag = true;

			while (flag) {
				cout << endl << "What do you want to see?: " << endl << "1. The 3rd work; " << endl << "2. Individual task." << endl << "3. To see another task." << endl;
				int answerThirdWork;
				cin >> answerThirdWork;

				switch (answerThirdWork) {
				case 1:
					system("cls");
					thirdTask();
					flag = false;
					break;
				case 2:
					system("cls");
					idz3();
					flag = false;
					break;
				case 3:
					system("cls");
					cout << "What task do you want to see? " << endl;
					cin >> workNumber;
					flag = false;
					break;
				}
			}
			break;
		case 4:
			system("cls");
			flag = true;

			while (flag) {
				cout << endl << "What do you want to see?: " << endl << "1. The 4th work; " << endl << "2. To see another task" << endl;
				int answerFourthWork;
				cin >> answerFourthWork;

				switch (answerFourthWork) {
				case 1:
					system("cls");
					fourthTask();
					flag = false;
					break;
				case 2:
					system("cls");
					cout << "What task do you want to see? " << endl;
					cin >> workNumber;
					flag = false;
					break;
				}
			}
			break;
		}
	}
}