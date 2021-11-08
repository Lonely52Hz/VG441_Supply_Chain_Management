#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;

int main() {
    int K = 1100;
    float h = 2.4;
    int s_idx = 0;
    int temp = 0;
    vector<int> demand = {108, 112, 123, 129, 147, 150, 156, 174, 189, 197, 202,
                          207, 228, 240, 242, 241, 266, 267, 270, 290, 303, 301,
                          329, 325, 345, 343, 367, 340, 337, 323, 325, 309, 305,
                          293, 273, 273, 252, 249, 243, 235, 226, 204, 204, 183,
                          175, 164, 162, 154, 145, 137, 112, 112};
    int num_period = demand.size();
    vector<float> theta(num_period + 1, 0);
    vector<int> s(num_period);
    vector<int> order_quantity(num_period);
    for (int i = num_period - 1; i >= 0; --i) {
        float minimum = INT_MAX;
        int idx;
        for (int j = i + 1; j <= num_period; ++j) {
            float t = K + theta[j];
            for (int q = i; q < j; ++q) {
                t += h * (q - i) * demand[q];
            }
            if (t < minimum) {
                minimum = t;
                idx = j;
            }
        }
        theta[i] = minimum;
        s[i] = idx + 1;
    }
    for (int i = 0; i < num_period; ++i) {
        if (i + 1 == s[s_idx]) {
            order_quantity[s_idx] = temp;
            temp = 0;
            s_idx = s[s_idx] - 1;
        }
        temp += demand[i];
    }
    order_quantity[s_idx] = temp;
    cout << "Index" << "    " << "Demand" << "    " << "Theta" << "       " << "S" << "      " << "Order Quantities" << endl;
    cout.setf(ios::fixed);
    for (int i = 1; i <= 7; ++i) {
        cout << i << "        " << demand[i - 1] << "       " << fixed << setprecision(1) << theta[i - 1] << "     " << s[i - 1] << "      " << order_quantity[i - 1] << endl;
    }
    for (int i = 8; i <= 9; ++i) {
        cout << i << "        " << demand[i - 1] << "       " << fixed << setprecision(1) << theta[i - 1] << "     " << s[i - 1] << "     " << order_quantity[i - 1] << endl;
    }
    for (int i = 10; i <= 39; ++i) {
        cout << i << "       " << demand[i - 1] << "       " << fixed << setprecision(1) << theta[i - 1] << "     " << s[i - 1] << "     " << order_quantity[i - 1] << endl;
    }
    for (int i = 40; i <= num_period; ++i) {
        cout << i << "       " << demand[i - 1] << "       " << fixed << setprecision(1) << theta[i - 1] << "      " << s[i - 1] << "     " << order_quantity[i - 1] << endl;
    }
    cout << num_period + 1 << "                 " << fixed << setprecision(0) << theta[num_period] << endl;
    cout << "\n";
    cout << "The optimal order quantities in each period are shown in the above table." << endl;
    cout << "The optimal total cost is $" << fixed << setprecision(1) << theta[0] << '.' << endl;
    return 0;
}