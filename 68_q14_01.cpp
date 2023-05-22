#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> country = {"Brazil", "Croatia", "Mexico", "Cameroon",
                          "Spain", "Netherlands", "Chile", "Australia",
                          "Colombia", "Greece", "Cote d'Ivoire", "Japan",
                          "Uruguay", "Costa Rica", "England", "Italy",
                          "Switzerland", "Ecuador", "France", "Honduras",
                          "Argentina", "Bosnia and Herzegovina", "Iran",
                          "Nigeria", "Germany", "Portugal", "Ghana",
                          "USA", "Belgium", "Algeria", "Russia",
                          "Korea Republic"};

vector<bool> is_used(country.size(), false);
int max_depth = 0;

void search(string prev, int depth) {
  bool is_last = true;
  for (int i = 0; i < country.size(); i++) {
    if (country[i][0] == toupper(prev.back())) {
      if (!is_used[i]) {
        is_last = false;
        is_used[i] = true;
        search(country[i], depth + 1);
        is_used[i] = false;
      }
    }
  }
  if (is_last) {
    max_depth = max(max_depth, depth);
    return;
  }
}

int main() {
  for (int i = 0; i < country.size(); i++) {
    is_used[i] = true;
    search(country[i], 1);
    is_used[i] = false;
  }
  cout << max_depth << endl;
  return 0;
}