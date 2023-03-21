// Modified By: Ali Mortada

#include <iostream>
#include <vector>
using namespace std;

int main() {
   int numInputs, lowerBound, upperBound;
   int input;
   vector<int> list;

   
   // Get number of inputs, then put inputs into a vector
   cin >> numInputs;
   for (int i = 0; i < numInputs; i++) {
      cin >> input;
      list.push_back(input);
   }
   
   // Get lower and upper bounds from input
   cin >> lowerBound >> upperBound;
   
   // If number in the list is between bounds, output it
   for (int i = 0; i < list.size(); i++) {
      if (list.at(i) >= lowerBound && list.at(i) <= upperBound) {
        // If item is not last item, put a comma after it
        if (i != list.size() - 1) {
            cout << list.at(i) << ",";
        } else { // If item is last item, output it without a comma after
            cout << list.at(i);
        }
      }
   }
   
   cout << endl;

   return 0;
}
