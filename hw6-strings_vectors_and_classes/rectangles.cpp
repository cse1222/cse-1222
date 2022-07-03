/**
 * @file rectangles.cpp
 * @author Conner Graham (connergraham888@gmail.com)
 * @brief This program will create a list of axis-aligned rectangels defined in a 2D sapce. An
 * axis-aligned rectangle has two vertical sides (left and right) that are parallel to the y-axis
 * and two horizontal sides (top and bottom) that are parallel to the x-axis. Each reactangle is
 * defined by the (x,y) location of its bottom left corner, its length (along the x-axis), and
 * its height (along the y-axis). In the program, each rectangle will also have its own unique
 * name. After the description of each rectangle is input from the user and stored in a list
 * (vector of class Rectangle), the program will scale each rectangle by a factor of 3 about its
 * midpoint.
 * @version 0.1
 * @date 2016-12-02
 * 
 * @copyright Copyright (c) 2016
 * 
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * @brief Class to model an exact location in 2-dimensional space.
 * 
 */
class Point {
    private:
        double px;          // x-coordinate of (x,y) coordinate pair
        double py;          // y-coordinate of (x,y) coordinate pair

    public:
        // Member functions
        void setX(const double x);
        void setY(const double y);

        double getX() const;
        double getY() const;

        Point();        // default constructor;
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
 * @brief Class to model an axis-aligned rectangle.
 * 
 */
class Rectangle {
    private:
        string name;                    // name of Rectangle object
        Point blPoint;                  // bottom left point (x,y) of rectangle on Cartesian plane
        double length, height;          // length (along x-axis) and height (along y-axis) of rectangle

    public:
        // Member functions
        void setName(const string &inName);
        void setBottomLeft(const double x, const double y);
        void setDimensions(const double inLength, const double inHeight);

        string getName() const;
        Point getBottomLeft() const;
        double getLength() const;
        double getHeight() const;

        double area() const;
        double perimeter() const;
        Point midPoint() const;
        void scaleBy3();
        void display() const;

        Rectangle();        // default constructor;
};

/**
 * @brief Construct a new Rectangle object (default).
 * 
 */
Rectangle::Rectangle() {
    name = "NoName";
    blPoint = Point();
    length = 0;
    height = 0;
}

/* FUNCTION PROTOTYPES */
void print_welcome_banner();
bool read_rectangle_name(const string &prompt, const string &errorInvalid, const string &errorName, string &input, const vector<Rectangle> &rectangles);
void read_coordinates(const string &prompt, double &x, double &y);
void read_dimensions(const string &prompt, double &length, double &height);
void add_rectangle(const string &name, const double x, const double y, const double length, const double height, vector<Rectangle> &rectangles);
void print_rectangles(const vector<Rectangle> &rectangles);

int main() {
    /* Print the program welcome banner */
    print_welcome_banner();

    /* Define messages for prompts and errors during data validation from user */
    string prompt = "Enter the name of the first rectangle: ";
    string errorInvalid = "Invalid input. Type 'rec' followed by the name or 'stop' if done.";
    string errorName = "This name is already being used!";

    /* Prompt, read, and validate the rectangle name from the user */
    string input;
    vector<Rectangle> rectangles;
    while (!read_rectangle_name(prompt, errorInvalid, errorName, input, rectangles)) {
        cout << "Try again! ";
    }

    /* Check that the user didn't enter 'stop' */
    if (input != "stop") {
        string name;
        double blx, bly;
        double length, height;

        /* Extract the rectangle name from the user input */
        name = input.substr(4);

        /* Prompt and read the bottom left corner and dimensions of the rectangle */
        read_coordinates("Enter " + name + "'s bottom left x any y coords: ", blx, bly);
        read_dimensions("Enter " + name + "'s length and height: ", length, height);

        /* Add the new rectangle to the list */
        add_rectangle(name, blx, bly, length, height, rectangles);
    }

    /* Prompt and read in the rest of the rectangles until the user enters 'stop' */
    prompt = "Enter the name of the next rectangle: ";
    while (input != "stop") {
        cout << endl;
        cout << "Thank you! ";

        /* Prompt, read, and validate the rectangle name from the user */
        cin.ignore(256, '\n');      // used to clear buffer due to mixing of cin and getline input methods
        while (!read_rectangle_name(prompt, errorInvalid, errorName, input, rectangles)) {
            cout << "Try again! ";
        }

        /* Check that the user didn't enter 'stop' */
        if (input != "stop") {
            string name;
            double blx, bly;
            double length, height;

            /* Extract the rectangle name from the user input */
            name = input.substr(4);

            /* Prompt and read the bottom left corner and dimensions of the rectangle */
            read_coordinates("Enter " + name + "'s bottom left x any y coords: ", blx, bly);
            read_dimensions("Enter " + name + "'s length and height: ", length, height);

            /* Add the new rectangle to the list */
            add_rectangle(name, blx, bly, length, height, rectangles);
        }
    }

    /* Check that the user entered at least one rectangle */
    if (rectangles.size() > 0) {
        print_rectangles(rectangles);
    } else {
        cout << "You have no rectangles in your list." << endl;
    }

    return 0;
}

/* FUNCTION DEFINITIONS */

/**
 * @brief Prints the program welcome banner.
 * 
 */
void print_welcome_banner() {
    cout << "Welcome! Create your own list of rectangles." << endl;
    cout << "You will be asked to provide information about each rectangle in your list by name." << endl;
    cout << "Type the word 'stop' for the rectangle name when you are done." << endl;
    cout << endl;
}

/**
 * @brief Prompts and reads in the name of a rectangle or the word 'stop' and validates this user
 * input. The user will enter the name for a rectangle by typing the keyword 'rec' followed by a 
 * single space and then the name. If the user types stop, then this indicates that the user does
 * not want to enter any more rectangles.
 * 
 * @param prompt The prompt to display to the user
 * @param errorInvalid The error message to display if input syntax is invalid
 * @param errorName The error message to display if entered name is already in use
 * @param input The string that will pass back the user input for the name
 * @param rectangles The vector of rectangles containing all rectangles entered so far
 * @return True if the input was valid, false otherwise.
 */
bool read_rectangle_name(const string &prompt, const string &errorInvalid, const string &errorName, string &input, const vector<Rectangle> &rectangles) {
    /* Prompt and read in user input for rectangle name */
    cout << prompt;
    getline(cin, input);

    /* Check if the user ented a valid syntax for the name */
    if (input == "stop") {
        return true;
    } else if (input.substr(0, 4) == "rec ") {
        for (int i = 0; i < rectangles.size(); i++) {
            /* Extract the rectangle name from the user input */
            if (input.substr(4) == rectangles[i].getName()) {
                cout << errorName << endl;
                return false;
            }
        }
        return true;
    } else {
        cout << errorInvalid << endl;
        return false;
    }
}

/**
 * @brief Prompt and read in the (x,y) coordinates of a point in 2D space.
 * 
 * @param prompt The prompt to display to the user
 * @param x The x-coordinate of (x,y) coordinate pair
 * @param y The y-coordinate of (x,y) coordinate pair
 */
void read_coordinates(const string &prompt, double &x, double &y) {
    cout << prompt, cin >> x >> y;
}

/**
 * @brief Prompt and read in the dimensions (length and height) of an object.
 * 
 * @param prompt The prompt to display to the user
 * @param length The length dimension of an object
 * @param height The height dimension of an object
 */
void read_dimensions(const string &prompt, double &length, double &height) {
    cout << prompt, cin >> length >> height;
    while (length <= 0 || height <= 0) {
        cout << "Invalid input. Dimensions must be positive." << endl;
        cout << prompt, cin >> length >> height;
    }
}

/**
 * @brief Add a new rectangle to the end of the list of rectangles.
 * 
 * @param name The name of the rectangle
 * @param x The x-coordinate of the bottom left corner of the rectangle
 * @param y The y-coordinate of the bottom left corner of the rectangle
 * @param length The length of the rectangle
 * @param height The height of the rectangle
 * @param rectangles The vector of rectangles containing all rectangles entered so far
 */
void add_rectangle(const string &name, const double x, const double y, const double length, const double height, vector<Rectangle> &rectangles) {
    Rectangle rec;

    /* Set the attributes for the new rectangle */
    rec.setName(name);
    rec.setBottomLeft(x, y);
    rec.setDimensions(length, height);

    /* Add the Rectangle object to the end of the list */
    rectangles.push_back(rec);
}

/**
 * @brief Prints all information about the rectangles in the list.
 * 
 * @param rectangles The vector of rectangles containing all rectangles entered
 */
void print_rectangles(const vector<Rectangle> &rectangles) {
    /* Print the number of rectangles in the list */
    cout << endl;
    cout << "You have " << rectangles.size() << " rectangle(s) in your list." << endl;
    cout << endl;

    /* Print information for all rectangles in the list */
    for (int i = 0; i < rectangles.size(); i++) {
        Rectangle rec = rectangles[i];
        /* Print current rectangle information */
        cout << "Rectangle '" << rec.getName() << "': ";
        rec.display();

        /* Sclae the current rectangle by 3 */
        rec.scaleBy3();

        /* Print scaled rectangle information */
        cout << "After scale by 3: ";
        rec.display();

        if (i < rectangles.size()-1) {
            cout << endl;
        }
    }
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
 * @brief Sets the name of the rectangle.
 * 
 * @param inName 
 */
void Rectangle::setName(const string &inName) {
    name = inName;
}

/**
 * @brief Sets the (x,y) coordinates of the bottom left corner of the rectangle.
 * 
 * @param x The x-coordinate of (x,y) coordinate pair
 * @param y The y-coordinate of (x,y) coordinate pair
 */
void Rectangle::setBottomLeft(const double x, const double y) {
    blPoint.setX(x);
    blPoint.setY(y);
}

/**
 * @brief Sets the dimensions (length and height) of the rectangle.
 * 
 * @param inLength The length dimension of a rectangle
 * @param inHeight The height dimension of a rectangle
 */
void Rectangle::setDimensions(const double inLength, const double inHeight) {
    length = inLength;
    height = inHeight;
}

/**
 * @brief Gets the name of the rectangle.
 * 
 * @return The name of the rectangle. 
 */
string Rectangle::getName() const {
    return name;
}

/**
 * @brief Gets the bottom left corner of the rectangle.
 * 
 * @return The bottom left corner of the rectangle. 
 */
Point Rectangle::getBottomLeft() const {
    return blPoint;
}

/**
 * @brief Gets the length of the rectangle along the x-axis.
 * 
 * @return The length of the rectangle. 
 */
double Rectangle::getLength() const {
    return length;
}

/**
 * @brief Gets the height of the rectangle along the y-axis.
 * 
 * @return The height of the rectangle.  
 */
double Rectangle::getHeight() const {
    return height;
}

/**
 * @brief Calculates the area of the rectangle (A = l x h).
 * 
 * @return The area of the rectangle.  
 */
double Rectangle::area() const {
    return (length * height);
}

/**
 * @brief Calculates the perimeter of the rectangle (P = 2l x 2h).
 * 
 * @return The perimeter length of the rectangle.  
 */
double Rectangle::perimeter() const {
    return (2*length + 2*height);
}

/**
 * @brief Determines the midpoint (x,y) of the rectangle.
 * 
 * @return The midpoint of the rectangle.  
 */
Point Rectangle::midPoint() const {
    Point midPoint;
    midPoint.setX(blPoint.getX() + (length / 2));
    midPoint.setY(blPoint.getY() + (height / 2));
    return midPoint;
}

/**
 * @brief Scales the rectangle by a factor of 3 about its midpoint.
 * 
 */
void Rectangle::scaleBy3() {
    /* Set the new location of the bottom left point of the sclaed rectangle */
    blPoint.setX(blPoint.getX() - length);
    blPoint.setY(blPoint.getY() - height);

    /* Scale the dimensions of the rectangle */
    length *= 3;
    height *= 3;
}

/**
 * @brief Print all information about a Rectangle object.
 * 
 */
void Rectangle::display() const {
    cout << "Location is (" << blPoint.getX() << ", " << blPoint.getY() << "), ";
    cout << "Length is " << length << ", ";
    cout << "Height is " << height << ", ";
    cout << "Area is " << area() << ", ";
    cout << "Perimeter is " << perimeter() << ", ";
    cout << "Midpoint is located at (" << midPoint().getX() << ", " << midPoint().getY() << ")";
    cout << endl;
}
