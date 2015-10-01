#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
class Rectangle {
public:
    int height, width;
    void Display() {
        cout << width << " " << height << endl;
    }
};
class RectangleArea: public Rectangle {
public:
    void Input() {
        scanf("%d %d", &(this->width), &(this->height));
    }
    void Display() {
        cout << (this->width) * (this->height) << endl;
    }
};
int main() {
      RectangleArea r_area;
      r_area.Input();
        Rectangle *r;
        r=&r_area;
        r->Display();
        r_area.Display();
    return 0;
}
