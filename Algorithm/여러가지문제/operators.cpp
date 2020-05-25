#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.
void solve(double meal_cost, int tip_percent, int tax_percent) {
    double a = meal_cost * (double)tip_percent*0.01;
    double b = meal_cost * (double)tax_percent *0.01;
    meal_cost += a+b;
    int tmp = (int)meal_cost;
    if(meal_cost - (double)tmp > 0.49)
        cout << (int)meal_cost + 1;
    else
        cout << (int)meal_cost << endl;

}

int main()
{
    double meal_cost;
    cin >> meal_cost;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int tip_percent;
    cin >> tip_percent;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int tax_percent;
    cin >> tax_percent;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    solve(meal_cost, tip_percent, tax_percent);

    return 0;
}
