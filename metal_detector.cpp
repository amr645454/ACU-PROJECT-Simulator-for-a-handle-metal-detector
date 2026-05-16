#include <iostream>
#include <string>
using namespace std;
// AMR , ROLE 1 , Natural Inheritance and Operator Overloading.
class Battery {
    private:
        int currentPwr;
        int maxPwr;
    public:
        Battery(){
            currentPwr = 100;
            maxPwr = 100; // for upgrading and to display like 30/100
        }
        Battery(int maxPower) {
            this->maxPwr = maxPower;
            currentPwr = maxPower;
        }
        int getcurrentPwr() {
            return currentPwr;
        }
        int getmaxPwr() {
            return maxPwr;
        }
        void upgrade(int extra){ //upgrade function
            maxPwr += extra;
            currentPwr = maxPwr;
            cout << " Battery Upgraded! Max Power is now: " << maxPwr << "\n";
        }
        void operator+(int charge){ //use like this battery + x , x is charge amount
            currentPwr += charge;
            if (currentPwr > maxPwr) currentPwr = maxPwr;
            cout << " Battery Charged! Current Power: " << currentPwr << "\n";
        }
        void operator-(int drain){ // same as above
            if (currentPwr < drain) {
                currentPwr = 0;
                throw runtime_error("Battery is completely dead!"); // exception handling test. yassmin should use catch.
            }
            currentPwr -= drain;
            cout << " Battery Drained! Current Power: " << currentPwr << "\n";
}
};
class Metal {
    protected:
        string name;
        double conductivity; // for signal calculation.
        int value;
    public:
        Metal() {name = "Unknown"; conductivity = 0.0; value = 0;}
        Metal(string name, double conductivity, int value){
            this->name = name;
            this->conductivity = conductivity;
            this->value = value;
        }
        virtual ~Metal() {}
        virtual void out() = 0; // polymorphism test , simple cout.
};
class PreciousMetal : public Metal {
    public:
        PreciousMetal() : Metal("Gold Coin", 180.0, 300) {} // for now only a defualt constructor , Eman can expand on it with different types.
        PreciousMetal(string name, double conductivity, int value) : Metal(name, conductivity, value) {} //to create different types
        // i think eman also handles signal calculation (polymorphism), it should be conductivity / distance. , if not i will add it here.
        void out() override {
            cout << "Shiny Gold !!!!\n";
        }
};
class JunkMetal : public Metal {
    public:
        JunkMetal() : Metal("Iron Nail", 40.0, 2) {}
        JunkMetal(string name, double conductivity, int value) : Metal(name, conductivity, value) {}
        void out() override {
            cout << "Trash.....:(\n";
        }
};
class RadioactiveMetal : public Metal {
    public:
        RadioactiveMetal() : Metal("Glowing Uranium Chunk", 999.9, 500) {}
        RadioactiveMetal(string name, double conductivity, int value) : Metal(name, conductivity, value) {}
        void out() override {
            cout << "Green???\n";
        }
};
int main (){
    return 0;
}
