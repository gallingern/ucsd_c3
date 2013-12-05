/*
 * hw7.cpp
 *
 * Created on: Nov 18, 2013
 * Author: Nathaniel Gallinger
 */

#include "StringUtility.h"

#include <iostream>
using std::cout;

int main()
{
  // Sample input string
  vector<string> input; input.push_back("The");
  input.push_back("quick");
  input.push_back("brown");
  input.push_back("fox");
  input.push_back("jumps");
  input.push_back("over");
  input.push_back("the");
  input.push_back("lazy");
  input.push_back("dog");

  // Test join
  cout << "== Testing Join ==\n";
  char delim = ',';
  NathanielGallinger::StringUtility string_util;
  string test1 = string_util.join((const vector<string>)input, delim);
  cout << test1 << "\n";

  // Test reverse
  cout << "== Testing reverse ==\n";
  vector<string> test2 = string_util.reverse((const vector<string>)input);
  for (unsigned int idx = 0; idx < test2.size(); idx++)
    cout << test2[idx] << "\n";

  // Test combine
  cout << "== Testing combine ==\n";
  vector<string> left;
  left.push_back("Mr.");
  left.push_back("Mrs.");
  vector<string> right;
  right.push_back("Jones");
  right.push_back("Smith");
  right.push_back("Williams");
  vector<string> test3 = string_util.combine((const vector<string>)left,
      (const vector<string>)right);
  for (unsigned int idx = 0; idx < test3.size(); idx++)
    cout << test3[idx] << "\n";

  // Test leftPad
  cout << "== Testing leftPad ==\n";
  char pad = '*';
  vector<string> test4 = string_util.leftPad((const vector<string>)input, pad);
  for (unsigned int idx = 0; idx < test4.size(); idx++)
    cout << test4[idx] << "\n";
}
