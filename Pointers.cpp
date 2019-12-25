/* Samantha Casler
Last Modified 9/30/18 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double itemSalesCalc (double [], int [], const int);

int main ()
{
    // to dynamically allocate the arrays
    int *ids = nullptr;
    double *prices = nullptr;
    int *numberSold = nullptr;
    double *itemSales = nullptr;

    // Creating the pointers to point to the arrays
    int *idPointer = nullptr;
    double *pricesPointer = nullptr;
    int *numberSoldPointer = nullptr;
    double *itemSalesPointer = nullptr;

    //opening the input file with the product information
    ifstream fin;
    fin.open ("Project 4_Products_Input.txt");

    const int numProducts = 10;

    ids = new int[numProducts];
    prices = new double[numProducts];
    numberSold = new int[numProducts];
    itemSales = new double[numProducts];

    idPointer = ids;
    pricesPointer = prices;
    numberSoldPointer = numberSold;
    itemSalesPointer = itemSales;

    for (int count = 0; count < numProducts; count++)
    {
        fin >> *(idPointer + count);
        fin >> *(pricesPointer + count);
        fin >> *(numberSoldPointer + count);
    }

    for (int count = 0; count < numProducts; count++)
    {

        *(itemSalesPointer + count) = itemSalesCalc (prices, numberSold, count);
    }

    double totalSales = 0.0;
    int totalSold = 0;

    for (int count = 0; count < numProducts; count++)
    {
        totalSales += *(itemSalesPointer + count);

        totalSold += *(numberSoldPointer + count);

    }

    for (int count = 0; count < numProducts; count++)
    {
        cout << setw(20) << left << "Product ID: ";
        cout << *(idPointer + count) << endl;
        cout << setw(20) << left << "Unit Price: ";
        cout << setprecision(2) << fixed << "$" << *(pricesPointer + count) << endl;
        cout << setw(20) << left << "Quantities Sold: ";
        cout << *(numberSoldPointer + count) << endl;
        cout << setw(20) << left << "Sales: ";
        cout << setprecision(2) << fixed << "$" << *(itemSalesPointer + count) << endl << endl;
    }

    cout << endl << endl;
    cout << setw(20) << left << "Total Units Sold: ";
    cout << totalSold << endl;
    cout << setw(20) << left << "Total Sales of all Items: ";
    cout << "$" << totalSales << endl;

    fin.close();
    delete [] ids;
    delete [] prices;
    delete [] numberSold;
    delete [] itemSales;
    ids = nullptr;
    prices = nullptr;
    numberSold = nullptr;
    itemSales = nullptr;

    return 0;

}

double itemSalesCalc (double cost [], int quantity [], const int SIZE)
{
    double sales;

    sales = cost[SIZE] * quantity[SIZE];

    return sales;
}
