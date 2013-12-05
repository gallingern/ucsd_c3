/*
 * StringUtility.h
 *
 * Created on: Nov 18, 2013
 * Author: Nathaniel Gallinger
 */

#ifndef STRINGUTILITY_H_
#define STRINGUTILITY_H_

#include <string>
using std::string;

#include <vector>
using std::vector;

namespace NathanielGallinger
{
  class StringUtility
  {
  public:
    string join(const vector<string> &str, char delim);
    vector<string> reverse(const vector<string> &str);
    vector<string> combine(const vector<string> &left, const vector<string> &right);
    vector<string> leftPad(const vector<string> &str, char pad);
  };
}

#endif /* STRINGUTILITY_H_ */

