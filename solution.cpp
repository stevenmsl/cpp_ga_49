#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol49;
using namespace std;

/*takeaways
  - use a hash table.
  - if two strings are anagrams, they will be identical after
    being sorted. We can use the sorted string as the key
    of the hash table
*/
vector<vector<string>> Solution::groupAnagrams(vector<string> &strs)
{
  auto result = vector<vector<string>>();
  auto indxs = unordered_map<string, vector<int>>();

  for (auto i = 0; i < strs.size(); i++)
  {
    /* need to make a copy as you don't want to
       alter the original string
     */
    auto c = strs[i];
    /* so that anagrams will have an identical key */
    sort(c.begin(), c.end());
    indxs[c].push_back(i);
  }

  for (auto &[_, val] : indxs)
  {
    result.push_back({});
    for (auto i : val)
      result.back().push_back(strs[i]);
  }

  return result;
}