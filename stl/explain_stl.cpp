#include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

/**
 * Prints the input string in a specified color with padding.
 *
 * This function uses ANSI escape codes to print the given input string
 * in a specified color. The supported colors are red, green, yellow,
 * blue, magenta, cyan, and white. The input string is centered and
 * padded with '=' characters to achieve a total length of 120 characters.
 * If an unsupported color is specified, the default console color is used.
 *
 * @param input The string to be printed.
 * @param color The color in which to print the string. Supported colors
 *              are "red", "green", "yellow", "blue", "magenta", "cyan",
 *              and "white". If an unsupported color is provided, the
 *              default console color is used.
 */

void printInColor(const std::string &input, const std::string &color) {
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
    colorCode = "\033[0m"; // Default color (reset)
  }

  // Desired total length of the output string
  const int totalLength = 120;

  // Calculate padding
  int padding = (totalLength - input.length()) / 2; // Padding on the left
  int remainingPadding =
      totalLength - input.length() - padding; // Padding on the right

  // Create the final string with padding
  std::string result =
      std::string(padding, '=') + input + std::string(remainingPadding, '=');

  // Print the colored result
  std::cout << endl;
  std::cout << colorCode << result << "\033[0m" << std::endl;
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
 * Prints the elements of a set of integers to the console.
 *
 * This function iterates over each element in the given set and
 * prints them separated by a space. After printing all elements,
 * it outputs a newline character to move the cursor to the next line.
 *
 * @param s A reference to a set of integers to be printed.
 */

void printSet(set<int> &s) {
  cout << "Set Size: " << s.size() << endl;
  cout << "Set Elements: ";
  for (auto it = s.begin(); it != s.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
  return;
}

/**
 * Prints the elements of a multiset of integers to the console.
 *
 * This function iterates over each element in the given multiset and
 * prints them separated by a space. After printing all elements,
 * it outputs a newline character to move the cursor to the next line.
 *
 * @param s A reference to a multiset of integers to be printed.
 */
void printMultiset(multiset<int> &s) {
  cout << "Multi Set Size: " << s.size() << endl;
  cout << "Multi Set Elements: ";
  for (auto it = s.begin(); it != s.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
  return;
}

/**
 * Prints the elements of an unordered set of integers to the console.
 *
 * This function iterates over each element in the given unordered set and
 * prints them separated by a space. After printing all elements,
 * it outputs a newline character to move the cursor to the next line.
 *
 * @param s A reference to an unordered set of integers to be printed.
 */
void printUnorderedSet(unordered_set<int> &s) {
  cout << "Unordered Set Size: " << s.size() << endl;
  cout << "Unordered Set Elements: ";
  for (auto it = s.begin(); it != s.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
  return;
}

/**
 * Prints the elements of a map of integers to the console.
 *
 * This function iterates over each element in the given map and
 * prints them separated by a space. After printing all elements,
 * it outputs a newline character to move the cursor to the next line.
 *
 * @param mp A reference to a map of integers to be printed.
 */
void printMap(map<int, int> &mp) {
  cout << "Map Size: " << mp.size() << endl;
  cout << "Map Elements: ";
  cout << "{";
  for (auto it = mp.begin(); it != mp.end(); it++) {
    cout << "{" << it->first << ", " << it->second << "} ";
  }
  cout << endl;
  return;
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
  cout << "vector.end() will return the address of the last element + 1: "
       << *it << endl;
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
 * Explains the usage of the stack data structure in C++ STL.
 *
 * This function demonstrates the basic operations of a stack, including
 * push, pop, size, and accessing the top element. It prints the process
 * of pushing elements onto the stack, displays the size and top element
 * of the stack, and illustrates popping the top element. The output is
 * printed to the console.
 */

void explain_stack() {
  printInColor("Stack data structure", "green");

  stack<int> st;

  cout << "Pushing elements {1, 2, 3, 4, 5} to the stack" << endl;
  st.push(1); // {1}
  st.push(2); // {1, 2}
  st.push(3); // {1, 2, 3}
  st.push(4); // {1, 2, 3, 4}
  st.push(5); // {1, 2, 3, 4, 5}

  cout << "Size of the stack: " << st.size() << endl;
  cout << "Top element of the stack: " << st.top() << endl;

  cout << "Popping the top element of the stack: " << endl;
  st.pop();
  cout << "Size of the stack: " << st.size() << endl;
  cout << "Top element of the stack: " << st.top() << endl;

  return;
}

/**
 * Explains the usage of the queue data structure in C++ STL.
 *
 * This function demonstrates the basic operations of a queue, including
 * push, pop, size, front, and back. It prints the process of pushing
 * elements onto the queue, displays the size, front, and back elements
 * of the queue, and illustrates popping the front element. The output
 * is printed to the console.
 *
 * @details
 * After pushing elements onto the queue, the function prints the size
 * of the queue, the front element (the element at the front of the
 * queue), and the back element (the element at the back of the queue).
 * It then pops the front element from the queue and prints the updated
 * size, front element, and back element of the queue.
 */
void explain_queue() {
  printInColor("Queue data structure", "green");

  // Create an empty queue
  queue<int> q;

  // Push elements onto the queue
  cout << "Pushing elements {1, 2, 3, 4, 5} to the queue" << endl;
  q.push(1); // {1}
  q.push(2); // {1, 2}
  q.push(3); // {1, 2, 3}
  q.push(4); // {1, 2, 3, 4}
  q.push(5); // {1, 2, 3, 4, 5}

  // Print the size, front, and back elements of the queue
  cout << "Size of the queue: " << q.size() << endl;
  cout << "Front element of the queue: " << q.front() << endl;
  cout << "Back element of the queue: " << q.back() << endl;

  // Pop the front element from the queue
  cout << "Popping the front element of the queue: " << endl;
  q.pop();
  cout << "Size of the queue: " << q.size() << endl;
  cout << "Front element of the queue: " << q.front() << endl;
  cout << "Back element of the queue: " << q.back() << endl;

  return;
}

/**
 * Explains the usage of the priority queue data structure in C++ STL.
 *
 * This function demonstrates the basic operations of a priority queue,
 * including pushing elements onto the queue, displaying the size and top
 * element of the queue, and popping the top element from the queue.
 * Additionally, it shows how to create a minimum priority queue and that it
 * stores data in ascending order. The output is printed to the console.
 *
 * @details
 * The function first creates an empty priority queue and pushes elements
 * {5, 4, 3, 2, 1} onto the queue. It then prints the size of the queue,
 * the top element of the queue, and then pops the top element from the queue.
 * It then prints the updated size, top element of the queue, and top element
 * of the minimum priority queue.
 */
void explain_priority_queue() {
  printInColor("Priority Queue data structure", "green");

  priority_queue<int> pq;
  cout << "Priority Queue stores data in descending order" << endl;
  pq.push(5);
  pq.push(4);
  pq.push(3);
  pq.push(2);
  pq.push(1);
  cout << "Priority Queue size: " << pq.size() << endl;
  cout << "Priority Queue top: " << pq.top() << endl;
  cout << "Popping the top element of the queue: " << endl;
  pq.pop();
  cout << "Priority Queue size: " << pq.size() << endl;
  cout << "Priority Queue top: " << pq.top() << endl;

  cout << "Minimum priority Queue stores data in ascending order" << endl;
  priority_queue<int, vector<int>, greater<int>> min_pq;
  min_pq.push(1);
  min_pq.push(2);
  min_pq.push(3);
  min_pq.push(4);
  min_pq.push(5);
  cout << "Priority Queue size: " << min_pq.size() << endl;
  cout << "Priority Queue top: " << min_pq.top() << endl;
  cout << "Popping the top element of the queue: " << endl;
  min_pq.pop();
  cout << "Priority Queue size: " << min_pq.size() << endl;
  cout << "Priority Queue top: " << min_pq.top() << endl;
  return;
}

/**
 * Explains the usage of the set data structure in C++ STL.
 *
 * This function demonstrates the basic operations of a set, including
 * insertion, searching, and counting. It prints the process of pushing
 * elements onto the set, displays the size of the set, iterates over
 * the elements of the set, and illustrates finding and counting elements
 * in the set. The output is printed to the console.
 */
void explain_set() {
  printInColor("Set data structure", "green");

  set<int> s;

  cout << "Set data structure stores unique elements in sorted fashion" << endl;
  cout << "Pushing elements {1, 3, 2, 2, 5, 4}" << endl;
  s.insert(1);
  s.insert(3);
  s.insert(2);
  s.insert(2);
  s.insert(5);
  s.insert(4);
  printSet(s);

  cout << "set.find(element) returns an iterator to the element if found else "
          "returns set.end()"
       << endl;
  cout << "set.count(element) returns 1 if the element is found else returns 0"
       << endl;
  return;
}

/**
 * Explains the usage of the multiset data structure in C++ STL.
 *
 * This function demonstrates how to use the multiset data structure
 * to store elements in a sorted manner, allowing duplicate elements.
 * It shows the insertion of elements into the multiset, counting the
 * occurrences of a specific element, and erasing all occurrences of
 * an element. The function prints the initial contents of the multiset,
 * the count of specific elements, and the contents after erasing an element.
 */

void explain_multiset() {
  printInColor("Multiset data structure", "green");

  multiset<int> ms;

  cout << "Multiset data structure stores elements in sorted fashion, elements "
          "does not have to be unique"
       << endl;
  cout << "Pushing elements {1, 3, 2, 2, 1, 5, 4}" << endl;
  ms.insert(1);
  ms.insert(3);
  ms.insert(2);
  ms.insert(2);
  ms.insert(1);
  ms.insert(5);
  ms.insert(4);
  printMultiset(ms);

  cout << "multiset.count(element) returns the count of the element" << endl;
  cout << "multiset.erase(element) will remove all occurances of <element>"
       << endl;
  cout << "multiset.erase(iterator) will remove the element pointed by the "
          "iterator"
       << endl;

  cout << "Count of 1: " << ms.count(1) << endl;
  cout << "Count of 2: " << ms.count(2) << endl;
  cout << "Erasing element 1" << endl;
  ms.erase(1);
  printMultiset(ms);
  cout << "Count of 1: " << ms.count(1) << endl;
  return;
}

/**
 * Explains the usage of the unordered set data structure in C++ STL.
 *
 * This function demonstrates the basic operations of an unordered set,
 * including the insertion of elements. It highlights that the unordered
 * set stores unique elements in no particular order. The function prints
 * the process of adding elements to the unordered set and displays the
 * contents of the set after the insertion. The output is printed to the
 * console.
 */

void explain_unorderedset() {
  printInColor("Unordered Set data structure", "green");

  unordered_set<int> s;

  cout << "Unordered set stores uniqueue elements in random order" << endl;
  cout << "Pushing elements {1, 3, 2, 2, 5, 4}" << endl;
  s.insert(1);
  s.insert(3);
  s.insert(2);
  s.insert(2);
  s.insert(5);
  s.insert(4);
  printUnorderedSet(s);
  return;
}

/**
 * Explains the usage of the map data structure in C++ STL.
 *
 * This function demonstrates the basic operations of a map, including
 * inserting elements. It highlights that the map stores key-value pairs,
 * where the key is unique and the elements are stored in sorted order.
 * The output is printed to the console.
 */
void explain_map() {
  printInColor("Map data structure", "green");

  map<int, int> mp;

  cout << "Map stores key value pairs, key must be unique and they are stored "
          "in sorted fashion"
       << endl;
  cout << "Pushing elements {{1, 10}, {3, 30}, {2, 20}, {2, 20}, {5, 50}, {4, "
          "40}}"
       << endl;
  mp.insert({1, 10});
  mp.insert({3, 30});
  mp.insert({2, 20});
  mp.insert({2, 20});
  mp.insert({5, 50});
  mp.insert({4, 40});
  printMap(mp);
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
  explain_stack();
  explain_queue();
  explain_priority_queue();
  explain_set();
  explain_multiset();
  explain_unorderedset();
  explain_map();
  return 0;
}
