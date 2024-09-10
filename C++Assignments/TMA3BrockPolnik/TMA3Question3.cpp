/*
Brock Polnik
March 30 2023
3601365
TMA2Question3.cpp
*/

/*
Goal: be able to construct geometric shapes such as squares,circles,rectangles and triangles using only coordinates. 
	from theses shapes we can find distances, and perimeters/circumferences.

Each point is an (x,y) pair object.

Square/rectangles requires 4 points
Circles a origin and radius
Triangle 3 points

Each shape tries to inherit from a base class shape to the best of their abilites however circle tend to be to different so their methods must be overriden

Finds the perimeter,area,bounding box of any polygon and the cirumference,area, and bounding box of a circle.

Display() will print all essentially information of a shape


*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define PI 3.142857

using namespace std;


class Point{
 private:
    double x;
    double y;
 public:
    
    Point(double x, double y){
        setX(x);
        setY(y);
    }
    double getX(){
        return x;
    }
    double getY(){
        return y;
    }

    void setX(double i){
        x = i;
    }

    void setY(double i){
        y = i;
    }

   
    Point operator+(Point p){
        Point newPointer(0,0);
        newPointer.setX(this->getX()+p.getX());
        newPointer.setY(this->getY()+p.getY());
        return newPointer;
     
    }

    Point operator-(Point p){
        Point newPointer(0,0);
        newPointer.setX(this->getX()-p.getX());
        newPointer.setY(this->getY()-p.getY());
        return newPointer;
     

    }

    ostream &operator >> (ostream &out){
        return out << "(" << this->getX() << "," << this->getY() << ")";
    }
  
};

class Shape{
 public:
    
    vector <Point> pointsVector;//To hold the points of whatever ths shapes needs. By using an a vector over and array we make it easier 
    				//to have a container for shapes with different numbers of vertices without having to manually create a new one everytime.
    double getArea();//area
    double getPerimeter();//circumference
    vector <Point> getBoundingBox();//coordinatepoints of a bounding box
    void display();//display() the name and stored info of the class(Area,circumference, bounding box)

};

class Square : public Shape{
 public:
    Square(Point,Point,Point,Point);
    void display();
      
};

class Triangle : public Shape{
 public:
    Triangle(Point,Point,Point);
    void display();
};

class Circle : public Shape{
 public:
     double radius;

     Circle(Point,double);
     double getArea();
     double getCircumference();
     vector<Point> getBoundingBox();
     void display();
     double getRadius(){
        return radius;
     }

    void setRadius(double r){
        radius = r;
    }

};

Circle::Circle(Point p, double r){
    pointsVector.push_back(Point(p));
    setRadius(r);
}

double Circle::getArea(){
 
    double area = 0;
    area = PI * pow(getRadius(),2);
    //cout << "Area: " << area;
    return area;
}

double Circle::getCircumference(){

    double circumference = 0;
    circumference = 2 * PI * getRadius();
   // cout << "Circumference " << circumference;
    return circumference;
}

vector<Point> Circle::getBoundingBox(){
    double minX = 0;
    double minY = 0;
    double maxX = 0;
    double maxY = 0;

    maxX = pointsVector[0].getX()+getRadius();
    maxY = pointsVector[0].getY()+getRadius();
    minX = pointsVector[0].getX()-getRadius();
    minY = pointsVector[0].getY()-getRadius();
    
    vector<Point> temp;
    temp.push_back(Point(minX,minY));
    temp.push_back(Point(minX,maxY));
    temp.push_back(Point(maxX,maxY));
    temp.push_back(Point(maxX,minY));

    //cout << "The points are: " ;
    //temp[0] >> cout; temp[1] >> cout; temp[2] >> cout; temp[3] >> cout;
    return temp;
}


Square::Square(Point a, Point b,Point c, Point d){
    
    pointsVector.push_back(a);
    pointsVector.push_back(b);
    pointsVector.push_back(c);
    pointsVector.push_back(d);

}

Triangle::Triangle(Point a, Point b,Point c){
    
    pointsVector.push_back(a);
    pointsVector.push_back(b);
    pointsVector.push_back(c);

}


double Shape::getPerimeter(){
//Works for any polyon. Creates a line/vector by subtracting the vertices x and y coordinates from two points. ie)x = x1-x2 and y = y1-y2. We square then square root to
//ensure that the perimeter return is a positive value.

			
    double perimeter = 0; 
 
    for(int index = 0; index < pointsVector.size()-1; index++){
        perimeter += sqrt(pow(pointsVector[index+1].getX() - pointsVector[index].getX(),2)
                        + pow(pointsVector[index+1].getY() - pointsVector[index].getY(),2));
    }
    
    perimeter+= sqrt(pow(pointsVector[0].getX() - pointsVector[pointsVector.size()-1].getX(),2)
                        + pow(pointsVector[0].getY() - pointsVector[pointsVector.size()-1].getY(),2));

  //  cout << "The circumference/Perimeter is: " << circumference << "\n";
    return perimeter;

}


double Shape::getArea(){
//Works for any polyon,Used the shoelace formula A = 1/2 (x0y1 − x1y0 + . . . + xn−2yn−1 − xn−1yn−2 + xn−1y0 − x0yn−1)

    double area = 0;
 
    for (int index = 1; index <  pointsVector.size(); index++)
    {
        area += (pointsVector.at(index-1).getX() * pointsVector.at(index).getY()) - (pointsVector.at(index).getX() * pointsVector.at(index-1).getY()); 
        
    }

    area /=2;
    area = abs(area);
   // cout << "The area is " << area << "\n";   
    return area;

}

vector<Point> Shape::getBoundingBox(){
//Works for any polyon.Find min/max x and y to create bounding box.

    double minX = 0;
    double minY = 0;
    double maxX = 0;
    double maxY = 0;

    for(int index = 0; index < pointsVector.size(); index++){
        if (pointsVector[index].getX() >= maxX) maxX = pointsVector[index].getX();
        if (pointsVector[index].getX() <= minX) minX = pointsVector[index].getX();
        if (pointsVector[index].getY() >= maxX) maxY = pointsVector[index].getY();
        if (pointsVector[index].getY() <= minX) minY = pointsVector[index].getY();

    }

    vector<Point> temp;
    temp.push_back(Point(minX,minY));
    temp.push_back(Point(minX,maxY));
    temp.push_back(Point(maxX,maxY));
    temp.push_back(Point(maxX,minY));

    //cout << "The points are: " ;
    //temp[0] >> cout; temp[1] >> cout; temp[2] >> cout; temp[3] >> cout;
    return temp;
}


void Square::display(){//Displays all characteristics of a Square. Perimeter,area,bounding box, etc.
    cout << "I am a square \n";
    cout << "Points as entered: ";

    for(int index = 0;index < pointsVector.size(); index++){
        pointsVector[index] >> cout;
    }
    cout << "\n";
    cout<< "Perimeter: " << getPerimeter() << "\n";
    cout<< "Area : " << getArea() << "\n";
    cout << "Bounded by points in clockwise order: " ;

    vector<Point> temp = getBoundingBox();
    for(int index =0; index< temp.size();index++){
        temp[index] >> cout;
    }

    cout << "\n";
}

void Triangle::display(){//Displays all characteristics of a triangle. Perimeter,area,bounding box, etc.
    cout << "I am a Triangle \n";
    cout << "Points as entered: ";

    for(int index = 0;index < pointsVector.size(); index++){
        pointsVector[index] >> cout;
    }
    cout << "\n";
    cout<< "Perimeter: " << getPerimeter() << "\n";
    cout<< "Area : " << getArea() << "\n";
    cout << "Bounded by points in clockwise order: ";

    vector<Point> temp = getBoundingBox();
    for(int index =0; index<temp.size();index++){
        temp[index] >> cout;
    }

    cout << "\n";
}

void Circle::display(){//Displays all characteristics of the circle. radius, Perimeter,area,bounding box, etc.
    cout << "I am a Circle \n";
    cout << "Radius: " << getRadius();
    cout << " Center Point: ";
    pointsVector[0] >> cout;
    cout << "\n";
    cout<< "Perimeter: " << getCircumference() << "\n";
    cout<< "Area : " << getArea() << "\n";
    cout << "Bounded by points in clockwise order: " ;

    vector<Point> temp = getBoundingBox();
    for(int index =0; index< temp.size();index++){
        temp[index] >> cout;
    }

    cout << "\n";
}



int main(){

    Square square(Point(-12.5, -12.5),Point(12.5, -12.5),Point(12.5, 12.5), Point(-12.5, 12.5));
    Triangle triangle(Point(-8.66, 5), Point(21.32, 5), Point(1.83, 22.36));
    Circle circle(Point(0,0), 23);
    square.display();
    triangle.display();
    circle.display();

    return 0;

}
