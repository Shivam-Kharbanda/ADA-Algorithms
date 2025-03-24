#include <iostream>
using namespace std;

int triangle_count(int n)
{
    if (n < 3) return 0;
    return (n * (n - 1) * (n - 2)) / 6;  
}

int main()
{
    int n, m;
    cout << "Enter total number of points (n): ";
    cin >> n;
    cout << "Enter collinear points (m): ";
    cin >> m;

    int valid = triangle_count(n);
    int not_valid = triangle_count(m);
    
    cout << "Total non-degenerate triangles: " << valid - not_valid << endl;
    return 0;
}
