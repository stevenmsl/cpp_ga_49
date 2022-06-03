#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol49;

/*
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/

tuple<vector<string>, vector<vector<string>>>
testFixture1()
{
  auto input = vector<string>{"eat", "tea", "tan", "ate", "nat", "bat"};
  auto output = vector<vector<string>>{
      {"ate", "eat", "tea"}, {"nat", "tan"}, {"bat"}};
  return make_tuple(input, output);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.groupAnagrams(get<0>(f))) << endl;
}

main()
{
  test1();
  return 0;
}