#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<map>
#include "person.h"
#include "license.h"



Person::Person(std::string name, unsigned int wealth): name{name}, wealth{wealth}{
    if(name.length() == 0)
        throw std::runtime_error("Name ist zu kurz");
    if(wealth < 0)
        throw std::runtime_error("Out if bouns");
}

void Person::work(std::string guild){
    if ((licenses.count(guild)) && licenses.at(guild)->valid()) {
        licenses.at(guild)->use();
        this->work(licenses.at(guild)->get_salary());
    } else {
        throw std::runtime_error("Kann nicht arbeiten mit dieser Lizenz");
    }

}

void Person::increase_wealth(unsigned int i){
    wealth = wealth + i;
}

std::string Person::get_name() const{
    return name;
}

bool Person::pay_fee(unsigned int i){
    if((i == 0) || (wealth < i))
        return false;
    else{
        wealth = wealth - i;
        return true;
    }
}

void Person::receive_license(std::unique_ptr<License> l){
    this->licenses[l->get_guildname()] = std::move(l);
}

void Person::transfer_license(std::string l,std::shared_ptr<Person> p ){
    if(this->licenses.count(l) == 0)
        throw std::runtime_error("Es gibt bereits keine Lizenz mit disem Namen");
    else{
        p->receive_license(std::move(this->licenses[l]));
        this->licenses.erase(l);
    }  
}

bool Person::eligible(std::string l) const{
    if((licenses.count(l)) && licenses.at(l)->valid())
        return true;
    else
        return false;
}


std::ostream& Person::print(std::ostream& o) const{
    o <<  name << ", " << wealth << " Coins, {";
    bool first{true};
    for(const auto& pair : licenses){
        if(first){
            o << *pair.second;
            first = false;
        }else
        o << ", " << *pair.second;
    }
    o << "}]";
    return o;
}

std::ostream& operator<<(std::ostream& o, const Person& p){
    return p.print(o);
}

Worker::Worker(std::string name, unsigned int wealth) : Person(name,wealth){}

void Worker::work(unsigned int i){
    Person::increase_wealth(i);
}

std::ostream& Worker::print(std::ostream& o) const{
    o << "[Worker ";
    return Person::print(o);
}

Superworker::Superworker(unsigned int fee, std::string name,unsigned int wealth) :  Person(name,wealth),fee{fee}{}

void Superworker::work(unsigned int i){
    Person::increase_wealth(i+fee);
}

std::ostream& Superworker::print(std::ostream& o) const{
    o << "[Superworker ";
    return Person::print(o);
}




