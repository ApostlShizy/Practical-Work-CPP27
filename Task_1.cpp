#include <iostream>
#include <cassert>
#include <cmath>

class Basic {
public:
    std::string color = "none";
    double center[2]{ 0,0 };
    double a = 0.;
    void getBasic() {
        std::cout <<"color : " << color<<std::endl;
        std::cout << "(Y - " << center[0] << ",X - " << center[1] << ") " << std::endl;
        std::cout << std::string(20, '-') + '\n';
    }
};

class Circle : public Basic {
public:
    Circle(double inA) {
        assert(inA > 0.);
        a = inA; /*radius*/
        color = "red";
        center[0] = inA;
        center[1] = inA;
    }
 
    void getInfo() {
        std::cout << '\n' + std::string(20, '-') + '\n';
        std::cout << "Round area : " << 3.1415 * pow(a, 2) << std::endl;
        std::cout << "Square circle : " << pow(a + a, 2) << std::endl;
        getBasic();       
    }
};

class Square : public Basic {    
public:
    double b = 0;
    Square(double inA) {
        assert(inA > 0.);
        a = inA; /*legnth*/
        b = inA; /*height*/
        color = "green";
        center[0] = inA / 2.;
        center[1] = inA / 2.;
    }
    void getInfo() {
        std::cout << '\n' + std::string(20, '-') + '\n';
        std::cout << "Square area : " << a * b << std::endl;
        getBasic();       
    }
};

class Triangle : public Basic {
public:
    Triangle(double inA) {
        assert(inA > 0.);
        a = inA; /*all tree side*/
        color = "blue";
        center[0] = (inA * sqrt(3) / 2.) / 2.;
        center[1] = inA / 2.;
    }

    void getInfo() {
        std::cout << '\n' + std::string(20, '-') + '\n';
        std::cout << "Triangle area : " << a * sqrt(3) / 4. << std::endl;
        std::cout << "Square triangle : " << a * (a * sqrt(3) / 2.) << std::endl;
        getBasic();        
    }
};

class Rectangle : public Basic {
    double b = 0.;
public:
    Rectangle(double inA, double inB) {
        assert(inA > 0.);
        assert(inB > 0.);
        a = inA; /*legnth*/
        b = inB; /*height*/
        color = "yelow";
        center[0] = inA / 2.;
        center[1] = inB / 2.;
    }

    void getInfo() {
        std::cout << '\n' + std::string(20, '-') + '\n';
        std::cout << "Retangle square : " << a * b << std::endl;
        getBasic();        
    }
};

int main() {
    std::string choice;
    while (choice != "exit") {
        double temp_a = 0.;
        double temp_b = 0.;
        std::cout << "\nMake choice\ncircle\nsquare\ntriangle\nrectangle\nEnter : ";
        std::cin >> choice;
        if (choice == "circle") {            
            std::cout << "\nEnter radius : ";
            std::cin >> temp_a;
            Circle temp_class (temp_a);
            temp_class.getInfo();           
        }
        else if (choice == "square") {            
            std::cout << "\nEnter length : ";
            std::cin >> temp_a;
            Square temp_class (temp_a);
            temp_class.getInfo();           
        }
        else if (choice == "triangle") {            
            std::cout << "\nEnter length : ";
            std::cin >> temp_a;
            Triangle temp_class (temp_a);
            temp_class.getInfo();           
        }
        else if (choice == "rectangle") {
            std::cout << "\nEnter length : ";
            std::cin >> temp_a;
            std::cout << "\nEnter height : ";
            std::cin >> temp_b;
            Rectangle temp_class (temp_a, temp_b);
            temp_class.getInfo();           
        }
        else if (choice != "exit") {
            std::cout << "\nInvalid choice !";
        }
    }
}
