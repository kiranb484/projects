#include <iostream>
#include <bits/stdc++.h>
#include <list>
using namespace std;

void printInColor(const std::string& input, const std::string& color) {
    // ANSI escape codes for colors
    std::string colorCode;

    if (color == "red") {
        colorCode = "\033[31m"; // Red
    } else if (color == "green") {
        colorCode = "\033[32m"; // Green
    } else if (color == "yellow") {
        colorCode = "\033[33m"; // Yellow
    } else if (color == "blue") {
        colorCode = "\033[34m"; // Blue
    } else if (color == "magenta") {
        colorCode = "\033[35m"; // Magenta
    } else if (color == "cyan") {
        colorCode = "\033[36m"; // Cyan
    } else if (color == "white") {
        colorCode = "\033[37m"; // White
    } else {
        colorCode = "\033[0m";  // Default color (reset)
    }

    // Desired total length of the output string
    const int totalLength = 120;

    // Calculate padding
    int padding = (totalLength - input.length()) / 2; // Padding on the left
    int remainingPadding = totalLength - input.length() - padding; // Padding on the right

    // Create the final string with padding
    std::string result = std::string(padding, '=') + input + std::string(remainingPadding, '=');

    // Print the colored result
    std::cout << endl;
    std::cout << colorCode << result << "\033[0m" << std::endl;
}

/**
 * Explains the usage of the pair data structure in C++ STL.
 *
 * This function demonstrates how to use the pair data structure to
 * store two values in a single object. It then prints the values
 * stored in the pair to the console.
 */
void explain_pair() {
    // Explain the usage of the pair data structure
    printInColor("Pair data structure", "green");
    // Create a pair with two strings
    cout << "Creating a pair with strings 'hello' and 'world'" << endl;
    pair<string, string> p("hello", "world");
    // Output the first and second elements of the pair
    cout << "Outputting the first and second elements of the pair" << endl;
    cout << p.first << " " << p.second << endl;
    return;
}

/**
 * Prints the elements of a vector of integers to the console.
 *
 * This function iterates over each element in the given vector and
 * prints them separated by a space. After printing all elements,
 * it outputs a newline character to move the cursor to the next line.
 *
 * @param v A reference to a vector of integers to be printed.
 */

void printV(vector<int> &v) {
    cout << "Vector Size: " << v.size() << endl;
    cout << "Vector Elements: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return;
}

/**
 * Prints the elements of a list of integers to the console.
 *
 * This function iterates over each element in the given list and
 * prints them separated by a space. After printing all elements,
 * it outputs a newline character to move the cursor to the next line.
 *
 * @param l A reference to a list of integers to be printed.
 */
void printLs(list<int> &l) {
    cout << "List Size: " << l.size() << endl;
    cout << "List Elements: ";
    for (auto it = l.begin(); it != l.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return;
}

/**
 * Explains the usage of the vector data structure in C++ STL.
 *
 * This function demonstrates how to create an empty vector and
 * how to add elements to it. It then prints the elements of the
 * vector to the console.
 */
void explain_vector() {
    // Print a title in green color
    printInColor("Vector data structure", "green");

    // Create an empty vector of integers and print its contents
    cout << "Creating an empty vector" << endl;
    vector<int> v;
    printV(v);

    // Add an element using push_back and print the updated vector
    cout << "Adding element 1 to the vector" << endl;
    v.push_back(1);
    printV(v);

    // Add another element using emplace_back and print the updated vector
    cout << "Adding element 2 to the vector" << endl;
    v.emplace_back(2);
    printV(v);

    // Creating a vector of size 3 with all elements initialized to 100
    vector<int> v1(3, 100);
    // printV(v1);
    v1.push_back(200);
    v1.push_back(300);

    // Iterators with vectors
    vector<int>::iterator it = v.begin();
    cout << "First element of the vector: " << *it << endl;
    it = v.end();
    cout << "vector.end() will return the address of the last element + 1: " << *it << endl;
    // it = v.back();
    cout << "vector.back() will return the last element: " << v1.back() << endl;

    // Erase an element
    cout << "Vector before erasing the last element" << endl;
    printV(v1);
    v1.erase(v1.end() - 1);
    // v1.pop_back(); // Same as above
    cout << "Vector after erasing the last element" << endl;
    printV(v1);

    // Insert an element
    cout << "Vector before inserting an element" << endl;
    printV(v1);
    v1.insert(v1.begin(), 1000);
    cout << "Vector after inserting an 1000 at start" << endl;
    printV(v1);

    // Clear the vector
    cout << "Vector before clearing the vector" << endl;
    printV(v1);
    v1.clear();
    cout << "Vector after clearing the vector" << endl;
    printV(v1);

    // Check if the vector is empty
    cout << "Is the vector empty? " << v1.empty() << endl;

    return;
}

/**
 * Explains the usage of the list data structure in C++ STL.
 *
 * This function demonstrates how to create a list and add
 * an element to it using the push_back function.
 */

void explain_list() {
    // Print a title in green color
    printInColor("List data structure", "green");

    // Create an empty list
    list<int> l;
    // Add an element to the list using push_back
    l.push_back(1);
    printLs(l);
    // Insert an element at the front of the list using push_front
    cout << "Inserting an element at the front" << endl;
    l.push_front(2);
    printLs(l);
    return;
}


/**
 * The main entry point for the program.
 *
 * This function prints nothing to the console and then returns 0
 * to indicate that the program has completed successfully.
 */
int main() {
    explain_pair();
    explain_vector();
    explain_list();
    return 0;
}
