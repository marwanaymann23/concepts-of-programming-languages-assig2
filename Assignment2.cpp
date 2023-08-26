#include <iostream>
#include<cmath>
using namespace std;

// Value of pi to calculate area
double piNumber = 3.14159265358979323846;

struct ShapeVtable;

// Struct Shape holds its virtual table
struct Shape 
{
    ShapeVtable* vtable;
};

// Virtual table for the shape
struct ShapeVtable
{
    double (*GetArea) (Shape*); // Function to calculate the area of the shape
    void (*PrintInfo) (Shape*); // Function to print the info of the shape
};

// Function to calculate area of the shape
double GetArea(Shape* shape) 
{
    return shape->vtable->GetArea(shape);
}

// Function to print the info of the shape
void PrintInfo(Shape* shape)
{
    shape->vtable->PrintInfo(shape);
}


/* Start Circle */

// Struct Circle
struct Circle 
{
    Shape parent; // Object from shape (Parent)
    int radius; // radius of the circle
};

// Function to calculate area of the circle
double CircleArea(Circle* circle)
{
    return pow(circle->radius,2) * piNumber;
}
// Function to print the info of the circle
void CirclePrintInfo(Circle* circle)
{
    cout << "Radius = " << circle->radius << endl;
}
// Virtual table of the circle
ShapeVtable circle_vtable =
{
    (double (*) (Shape*)) CircleArea, // Type casting from derived to base class for getArea function 
    (void (*) (Shape*)) CirclePrintInfo // Type casting from derived to base class for PrintInfo function 
};
// Intializing method
void CircleInitialize(Circle* circle, int radius) {
    circle->parent.vtable = &circle_vtable; // Assign the virtual table of the derived class to the base class
    circle->radius = radius; // Assign the parameter to the radius of the circle
}
/* End Circle */


/* Start Rectangle */

// Struct Rectangle 
struct Rectangle
{
    Shape parent; // Object from shape (Parent)
    int width; // Width of the rectangle
    int height; // height of the rectangle
};
// Function to calculate area of the Rectangle
double RectangleArea(Rectangle* rectangle)
{
    return rectangle->width * rectangle->height;
}
// Function to print the info of the Rectangle
void RectanglePrintInfo(Rectangle* rectangle)
{
    cout << "Width = " << rectangle->width << " ,Height = " << rectangle->height << endl;
}
// Virtual table of the Rectangle
ShapeVtable rectangle_vtable =
{
    (double (*) (Shape*)) RectangleArea, // Type casting from derived to base class for getArea function 
    (void (*) (Shape*)) RectanglePrintInfo // Type casting from derived to base class for PrintInfo function 
};
// Intializing method
void RectangleInitialize(Rectangle* rectangle, int width, int height) {
    rectangle->parent.vtable = &rectangle_vtable; // Assign the virtual table of the derived class to the base class
    rectangle->width = width; // Assign the parameter to the width of the rectangle
    rectangle->height = height; // Assign the parameter to the height of the rectangle
}
/* End Rectangle */


/* Start Ellipse */

// Struct Ellipse
struct Ellipse
{
    Shape parent; // Object from shape (Parent)
    int a; // Radius 1 of the ellipse
    int b; // Radius 2 of the ellipse
};
// Function to calculate area of the Ellipse
double EllipseArea(Ellipse* ellipse)
{
    return ellipse->a * ellipse->b * piNumber;
}
// Function to print the info of the Ellipse
void EllipsePrintInfo(Ellipse* ellipse)
{
    cout << "Alpha = " << ellipse->a << " ,Beta = " << ellipse->b << endl;
}
// Virtual table of the Ellipse
ShapeVtable ellipse_vtable =
{
    (double(*) (Shape*)) EllipseArea, // Type casting from derived to base class for getArea function 
    (void(*) (Shape*)) EllipsePrintInfo // Type casting from derived to base class for PrintInfo function
};
// Intializing method
void EllipseInitialize(Ellipse* ellipse, int a, int b) {
    ellipse->parent.vtable = &ellipse_vtable; // Assign the virtual table of the derived class to the base class
    ellipse->a = a; // Assign the parameter to the first radius of the ellipse
    ellipse->b = b; // Assign the parameter to the second radius of the ellipse
}
/* End Ellipse */


int main()
{
    Circle circle;
    CircleInitialize(&circle, 10); // circle with radius 10
    Rectangle rectangle;
    RectangleInitialize(&rectangle, 3, 5); // rectangle with width 3 and height 5
    Ellipse ellipse;
    EllipseInitialize(&ellipse, 10, 12); // ellipse with radius 10, 12
    Shape* shapes[3];
    shapes[0] = (Shape*)&circle;
    shapes[1] = (Shape*)&rectangle;
    shapes[2] = (Shape*)&ellipse;
    double total_area = 0;
    int i;
    for (i = 0; i < 3; i++)
    {
        double d = GetArea(shapes[i]);
        total_area += d;
        PrintInfo(shapes[i]); // prints (cout) the radius if circle, width and height if rectangle, ... etc
    }

    cout << total_area << endl; // check if the value is correct
    return 0;
}
