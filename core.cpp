#include<iostream> 
#include<string> 
#include <map> 
 
class Pizzeria 
{ 
public: 
    int rating_; 
    std::string name_; 
    Pizzeria() 
    { 
        rating_ = 0; 
        name_ = ""; 
    } 
    Pizzeria(int rating, std::string name) { 
 
        rating_ = rating; 
        name_ = name; 
    } 
    void getInfo() { 
        std::cout << name_; 
    } 
}; 
 
class Person { 
public: 
    int age_; 
    std::string name_, adress_; 
    bool  gender_; 
    Person() {} 
 
    Person(int age, std::string name, bool gender, std::string adress) { 
 
        age_ = age; 
        name_ = name; 
        gender_ = gender; 
        adress_ = adress; 
    } 
 
}; 
 
class Person_visit 
{ 
public: 
    int  person_id_, pizzeria_id_, data_; 
 
    Person_visit() { 
        data_ = pizzeria_id_ = person_id_ = 0; 
    } 
    Person_visit(int person_id, int pizzeria_id, int data) { 
 
        person_id_ = person_id; 
        pizzeria_id_ = pizzeria_id; 
        data_ = data; 
    } 
}; 
 
class Menu { 
public: 
    int  pizeria_id_, price_; 
    std::string pizza_name_; 
    Menu() { 
        pizeria_id_ = price_ = 0; 
        pizza_name_ = ""; 
    } 
    Menu(int pizeria_id, int price, std::string pizza_name) { 
 
        pizeria_id_ = pizeria_id; 
        price_ = price; 
        pizza_name_ = pizza_name; 
    } 
}; 
 
class Person_order { 
public: 
    int  person_id_, menu_id_; 
    Person_order() { 
        person_id_ = menu_id_ = 0; 
    } 
    Person_order(int person_id, int menu_id) 
    { 
        person_id_ = person_id; 
        menu_id_ = menu_id; 
    } 
 
    int Getperson_id() { 
        return person_id_; 
    } 
}; 
 
 
const int size = 6; 
 
 
int main() 
{ 
    Menu menus[size]{ 
        Menu(1,300,"4sira"), 
        Menu(4,3000,"BIGBIG"), 
        Menu(5,800,"ficus"), 
        Menu(3,450,"rarrar"), 
        Menu(0,500,"mor"), 
        Menu(1,1000,"GG"), 
    }; 
    Pizzeria pizzeris[size]{ 
        Pizzeria(10,"Bolol"), 
        Pizzeria(10,"Gargam"), 
        Pizzeria(10,"loc_vov"), 
        Pizzeria(10,"violet"), 
        Pizzeria(10,"har"), 
        Pizzeria(10,"fef"), 
    }; 
    Person persons[size]{ 
        Person(20,"Ivan",1,"Puchkino1"), 
        Person(20,"Vax",0,"Puchkino2"), 
        Person(20,"oleg",1,"Puchkino3"), 
        Person(20,"glf",0,"Puchkino4"), 
        Person(20,"teru",1,"Puchkino5"), 
        Person(20,"mari0",0,"Puchkino6") 
    }; 
    Person_visit person_visits[size]{ 
        Person_visit(1,4,24), 
        Person_visit(0,1,24), 
        Person_visit(4,5,24), 
        Person_visit(5,1,24), 
        Person_visit(2,5,24), 
        Person_visit(3,3,24), 
 
    }; 
    Person_order person_orders[size]{ 
        Person_order(2,5), 
        Person_order(2,5), 
        Person_order(2,0), 
        Person_order(4,0), 
        Person_order(2,2), 
        Person_order(0,1), 
    }; 
 
    std::map<int, int> mani; 
 
    //mani.insert(person_orders[0].person_id_, menus[person_orders[0].menu_id_].price_); 
    //mani.emplace( person_orders[0].Getperson_id(), 1); 
 
    std::map<int, int>::iterator it; 
    for (int i = 0, buf; i < size; i++) { 
 
        if (mani.find(person_orders[i].Getperson_id()) == mani.cend()) { 
 
            //std::cout << " 1111: id= " << (person_orders[i].Getperson_id()) << " i= " << i << " price: " << menus[(person_orders[i].menu_id_)].price_ << "\n"; 
 
            mani.emplace(person_orders[i].Getperson_id(), menus[(person_orders[i].menu_id_)].price_); 
 
 
        } 
        else 
        { 
            buf = mani[person_orders[i].Getperson_id()] + menus[(person_orders[i].menu_id_)].price_; 
 
            //std::cout << " 22222: id= " << person_orders[i].Getperson_id() << " pr: " << mani[person_orders[i].Getperson_id()] << " buf= " << buf << "\n"; 
 
            mani[person_orders[i].Getperson_id()] = buf; 
        } 
    } 
 
    int result = 0,id_result; 
 
 
    it = mani.begin(); 
 
    while (it != mani.end()) 
    { 
        if (result < it->second) { 
            result = it->second; 
            id_result = it->first; 
        } 
        it++; 
    }

std::cout<<" Potrachenno bolche vseh: "+ std::to_string(result) + " Id: " + std::to_string(id_result) + " name: "+ persons[id_result].name_ + '\n';

    return 0;
}
