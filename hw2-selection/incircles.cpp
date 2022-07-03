/**
 * @file incircles.cpp
 * @author Conner Graham (connergraham888@gmail.com)
 * @brief This program reads in the center coordinates and radii of three circles, Circ1,
 * Circ2, and Circ3, and reports the location of a query point relative to the circles.
 * The location can be one of eight possibilities: contained in Circ1, Circ2, and Circ3,
 * contained in Circ1 and Circ2, contained in Circ1 and Circ3, contained in Circ2 and
 * Circ3, contained in Circ1, contained in Circ2, contained in Circ3, not contained in
 * any circles.
 * @version 0.1
 * @date 2016-09-13
 * 
 * @copyright Copyright (c) 2016
 * 
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double r1, cx1, cy1;      // radius and (x,y) coordinates of center of circle 1
    double r2, cx2, cy2;      // radius and (x,y) coordinates of center of circle 2
    double r3, cx3, cy3;      // radius and (x,y) coordinates of center of circle 3
    double px, py;            // (x,y) coordinates of query point

    /* Prompt and read in the radius and (x,y) coordinates of the center of the three circles */
    cout << "Enter x and y coordinates of circle Circ1 (2 values): ", cin >> cx1 >> cy1;
    cout << "Enter radius of circle Circ1: ", cin >> r1;
    cout << "Enter x and y coordinates of circle Circ2 (2 values): ", cin >> cx2 >> cy2;
    cout << "Enter radius of circle Circ2: ", cin >> r2;
    cout << "Enter x and y coordinates of circle Circ3 (2 values): ", cin >> cx3 >> cy3;
    cout << "Enter radius of circle Circ3: ", cin >> r3;

    /* Prompt and read in the (x,y) coordinates of the query point */
    cout << "Enter x and y coordinates of query point (2 values): ", cin >> px >> py;

    /* Determine which circles the query point is in */
    bool inCirc1 = (sqrt(pow(px-cx1, 2) + pow(py-cy1, 2)) <= r1);
    bool inCirc2 = (sqrt(pow(px-cx2, 2) + pow(py-cy2, 2)) <= r2);
    bool inCirc3 = (sqrt(pow(px-cx3, 2) + pow(py-cy3, 2)) <= r3);

    /* Print messages for location of query point relative to the circles */
    if (inCirc1) {
        if (inCirc2) {
            if (inCirc3) {
                cout << "Circles Circ1, Circ2, and Circ3 contain point ";
            } else{
                cout << "Circles Circ1 and Circ2 contain point ";
            }
        } else if (inCirc3) {
            cout << "Circles Circ1 and Circ3 contain point ";
        } else {
            cout << "Circle Circ1 contains point ";
        }
    } else if (inCirc2) {
        if (inCirc3) {
            cout << "Circles Circ2 and Circ3 contain point ";
        } else {
            cout << "Circle Circ2 contains point ";
        }
    } else if (inCirc3) {
        cout << "Circle Circ3 contains point ";
    } else {
        cout << "None of the three circles contain point ";
    }
    cout << "(" << px << "," << py << ")." << endl;

    return 0;
}
