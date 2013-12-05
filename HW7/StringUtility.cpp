/*
 * StringUtility.cpp
 *
 * Created on: Nov 18, 2013
 * Author: Nathaniel Gallinger
 */

#include "StringUtility.h"

// Join Function
string
NathanielGallinger::StringUtility::join(const vector<string> &strVect, char delim)
{
  string retval;
  for (unsigned int idx = 0; idx < strVect.size(); idx++) {
    retval += strVect[idx];
    if ((idx + 1) < strVect.size())
      retval += delim;
  }
  return retval;
}

// Reverse Function
vector<string>
NathanielGallinger::StringUtility::reverse(const vector<string> &strVect)
{
  vector<string> retval; for (unsigned int idx = 0; idx < strVect.size(); idx++)
    retval.push_back(strVect[(strVect.size() - 1)- idx]);
  return retval;
}

// Combine Function
vector<string>
NathanielGallinger::StringUtility::combine(const vector<string> &left, const
    vector<string> &right)
{
  vector<string> retval;
  for (unsigned int idx = 0; idx < left.size(); idx++)
    for (unsigned int idx2 = 0; idx2 < right.size(); idx2++)
      retval.push_back(left[idx] + right[idx2]);
  return retval;
}

// Leftpad Function
vector<string>
NathanielGallinger::StringUtility::leftPad(const vector<string> &strVect, char pad)
{
  vector<string> retval;
  unsigned int maxSize = 0;
  // Find max size
  for (unsigned int idx = 0; idx < strVect.size(); idx++) {
    if (strVect[idx].size() > maxSize)
      maxSize = strVect[idx].size();
  }

  // Add padding
  for (unsigned int idx = 0; idx < strVect.size(); idx++) {
    retval.push_back("");
    retval[idx].insert(0, maxSize - strVect[idx].size(), pad);
    retval[idx] += strVect[idx];
  }
  return retval;
}
