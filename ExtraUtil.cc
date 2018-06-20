#include "ExtraUtil.hh"

using namespace std;

// returns the trimmed version of this string based off delimiters
string trimmed(string orig, string delimiters) {
  int begin = 0;
  int end = orig.length() - 1;
  while (begin < end) { // trim beginning
    if (delimiters.find(orig.at(begin)) == string::npos) {
      break;
    }
    begin++;
  }
  while (end > begin) { // trim at end
    if (delimiters.find(orig.at(end)) == string::npos) {
      break;
    }
    end++;
  }
  int length = end - begin + 1;
  return orig.substr(begin, length);
}
