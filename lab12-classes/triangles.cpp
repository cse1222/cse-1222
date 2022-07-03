/**
 * @file triangles.cpp
 * @author Conner Graham (connergraham888@gmail.com)
 * @brief This program represents an axis-aligned right triangle in the x-y plane as a Class. A
 * right triangle has a right angle (90-degree angle) and two sides adjacent to the right angle,
 * called legs. In addition, an axis-aligned right triangle has one leg parallel with the x-axis
 * and the other leg parallel with the y-axis. The location of the triangle is teh vertex that
 * connects teh two legs, called the bottom left vertex. This vertex is located at the right
 * angle and represented with the Class Point. The length of the triangle is the length of the
 * leg parallel with the x-axis. The height of the triangle is the length of the leg parallel
 * with the y-axis. The user will input the bottom left vertex along with the legth and height
 * in order to define and output the triangle. The program will then scale both the length and
 * height of the triangle by user-defined scale factors to define and output a new triangle.
 * @version 0.1
 * @date 2016-11-24
 * 
 * @copyright Copyright (c) 2016
 * 
 */

#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief Class to model an exact location in 2-dimensional space.
 * 
 */
class Point {
    private:
        double px;      // x-coordinate of (x,y) coordinate pair
        double py;      // y-coordinate of (x,y) coordinate pair

    public:
        // Member functions
        void setX(const double x);
        void setY(const double y);
        double getX() const;
        double getY() const;

        Point();    // default constructor
};

/**
 * @brief Construct a new Point object (default).
 * 
 */
Point::Point() {
    px = 0;
    py = 0;
}

/**
 * @brief Class to model an axis-aligned right triangle.
 * 
 */
class Triangle {
    private:
        Point blPoint;              // bottom left vertex (x,y) of a triangle
        double length, height;      // length (along x-axis) and height (along y-axis) of a triangle

    public:
        // Member functions
        void setBottomLeftX(const double x);
        void setBottomLeftY(const double y);
        void setLength(const double inLength);
        void setHeight(const double inHeight);

        Point getBottomLeft() const;
        Point getBottomRight() const;
        Point getTopLeft() const;
        double getLength() const;
        double getHeight() const;

        double perimeter() const;
        double hypotenuse() const;
        void scaleLength(const double sx);
        void scaleHeight(const double sy);
        void display() const;

        Triangle();    // default constructor
};

/**
 * @brief Construct a new Triangle object (default).
 * 
 */
Triangle::Triangle() {
    blPoint = Point();
    length = 0;
    height = 0;
}

/* FUNCTION PROTOTYPES */
void read_triangle(Triangle &tri);

int main() {
    Triangle tri;       // triangle object containing characteristics of a triangle
    double sx, sy;      // scale factors in x and y directions respectively

    /* Prompt the user for triangle information and fill Class Triangle object, tri */
    read_triangle(tri);

    /* Display triangle information */
    tri.display();

    /* Prompt and read scale factors to change length and height */
    cout << "Enter scale factor in x direction: ";
    cin >> sx;

    cout << "Enter scale factor in y direction: ";
    cin >> sy;

    /* Apply scale factors */
    tri.scaleLength(sx);
    tri.scaleHeight(sy);

    /* Display triangle information */
    tri.display();

    return 0;
}

/* FUNCTION DEFINITIONS */

/**
 * @brief Reads in defining characteristics of a Triangle object (vertex, length, height).
 * 
 * @param tri The Triangle object containing the triangle characteristics
 */
void read_triangle(Triangle &tri) {
    double bl_x, bl_y;
    double length, height;

    /* Prompt and read in triangle characteristics */
    cout << "Enter bottom left x coordinate: ", cin >> bl_x;
    cout << "Enter bottom left y coordinate: ", cin >> bl_y;
    cout << "Enter length: ", cin >> length;
    cout << "Enter height: ", cin >> height;

    /* Set the class attributes for the Triangle object based on the user input */
    tri.setBottomLeftX(bl_x);
    tri.setBottomLeftY(bl_x);
    tri.setLength(length);
    tri.setHeight(height);
}

/* CLASS MEMBER FUNCTION DEFINITIONS */

/**
 * @brief Sets the x-coordinate of the point location.
 * 
 * @param x The x-coordinate of (x,y) coordinate pair
 */
void Point::setX(const double x) {
    px = x;
}

/**
 * @brief Sets the y-coordinate of the point location.
 * 
 * @param y The y-coordinate of (x,y) coordinate pair
 */
void Point::setY(const double y) {
    py = y;
}

/**
 * @brief Gets the x-coordinate of the point location.
 * 
 * @return The x-coordinate of the point location.
 */
double Point::getX() const {
    return px;
}

/**
 * @brief Gets the y-coordinate of the point location.
 * 
 * @return The y-coordinate of the point location. 
 */
double Point::getY() const {
    return py;
}

/**
 * @brief Sets the x-coordinate of the bottom left vertex (x,y) of a triangle.
 * 
 * @param x The x-coordinate of (x,y) coordinate pair
 */
void Triangle::setBottomLeftX(const double x) {
    blPoint.setX(x);
}

/**
 * @brief Sets the y-coordinate of the bottom left vertex (x,y) of a triangle.
 * 
 * @param y The y-coordinate of (x,y) coordinate pair
 */
void Triangle::setBottomLeftY(const double y) {
    blPoint.setY(y);
}

/**
 * @brief Sets the length of a triangle (along x-axis).
 * 
 * @param inLength The length of a triangle
 */
void Triangle::setLength(const double inLength) {
    length = inLength;
}

/**
 * @brief Sets the height of a triangle (along y-axis).
 * 
 * @param inHeight The height of a triangle
 */
void Triangle::setHeight(const double inHeight) {
    height = inHeight;
}

/**
 * @brief Gets the (x,y) coordinates of the bottom left vertex of a triangle.
 * 
 * @return The bottom left vertex of the triangle. 
 */
Point Triangle::getBottomLeft() const {
    return blPoint;
}

/**
 * @brief Gets the (x,y) coordinates of the bottom right vertex of a triangle.
 * 
 * @return The bottom right vertex of the triangle.  
 */
Point Triangle::getBottomRight() const {
    Point brPoint;
    brPoint.setX(blPoint.getX() + length);
    brPoint.setY(blPoint.getY());
    return brPoint;
}

/**
 * @brief Gets the (x,y) coordinates of the top left vertex of a triangle.
 * 
 * @return The top left vertex of the triangle.  
 */
Point Triangle::getTopLeft() const {
    Point tlPoint;
    tlPoint.setX(blPoint.getX());
    tlPoint.setY(blPoint.getY() + height);
    return tlPoint;
}

/**
 * @brief Gets the length of a triangle (along y-axis).
 * 
 * @return The length of the triangle. 
 */
double Triangle::getLength() const {
    return length;
}

/**
 * @brief Gets the height of a triangle (along y-axis).
 * 
 * @return The height of the triangle.  
 */
double Triangle::getHeight() const {
    return height;
}

/**
 * @brief Computes the hypotenuse of a Triangle (side of the triangle opposite to the right
 * angle) object using the Pythagorean Theorem to compute the length.
 * 
 * @return The hypotenuse of the triangle.  
 */
double Triangle::hypotenuse() const {
    return (sqrt(length*length + height*height));
}

/**
 * @brief Computes the perimeter of the Triangle object by summing all three sides of the
 * triangle (sum = leq1 + le2 + hypotenuse).
 * 
 * @return The perimeter of the triangle.  
 */
double Triangle::perimeter() const {
    return (length + height + hypotenuse());
}

/**
 * @brief Computes the new value of the length as the current length weighted by the scale
 * factor in the x direction. Assume that the scale factor will be positive. Update the
 * length class attribute of the class Triangle.
 * 
 * @param sx Amount by which the x-axis attributes of the triangle will be scaled
 */
void Triangle::scaleLength(const double sx) {
    length *= sx;
}

/**
 * @brief Computes the new value of the height as the current height weighted by the scale
 * factor in the y direction. Assume that the scale factor will be positive. Update the
 * height class attribute of the class Triangle.
 * 
 * @param sy Amount by which the y-axis attributes of the triangle will be scaled
 */
void Triangle::scaleHeight(const double sy) {
    height *= sy;
}

/**
 * @brief Prints all information about the triangle.
 * 
 */
void Triangle::display() const {
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "Lower Left Vertex (" << getBottomLeft().getX() << ", " << getBottomLeft().getY() << ")" << endl;
    cout << "Top Left Vertex (" << getTopLeft().getX() << ", " << getTopLeft().getY() << ")" << endl;
    cout << "Bottom Right Vertex (" << getBottomRight().getX() << ", " << getBottomRight().getY() << ")" << endl;
    cout << "Dimensions (" << getLength() << ", " << getHeight() << ")" << endl;
    cout << "Hypotenuse = " << hypotenuse() << endl;
    cout << "Perimeter = " << perimeter() << endl;
    cout << "----------------------------------------" << endl;
    cout << endl;
}
