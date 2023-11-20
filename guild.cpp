#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<stdexcept>
#include<set>
#include<algorithm>
#include<map>
#include "guild.h"
#include "license.h"
#include "person.h"


Guild::Guild(std::string name, unsigned fee, unsigned salary,
  const std::vector<std::shared_ptr<Person>>& members):name{name},
  fee{fee}, salary{salary} {

	if(name.empty())
		throw std::runtime_error("Name ist zu kurz");
	if(fee <= 0 ) 
		throw std::runtime_error("Zu kleine Zahlen");
  if(salary <= 0)  
    throw std::runtime_error("Zu kleine Zahlen");

   for(const auto& elem : members){
        if(this->members.count(elem->get_name()) == 0)
            this->members[elem->get_name()] = elem;
     		else
          throw std::runtime_error("Die Person ist schon vorhanden");
   }
  }


bool Guild::add_member(std::shared_ptr<Person> p ){
     if(this->members.count(p->get_name()) == 0){
         this->members[p->get_name()] = p;
        return true;
     }

    return false;
}


bool Guild::remove_member(std::string n) {
    if(members.count(n)){
        members.erase(n); 
        return true;
     }
     return false;
}


void Guild::grant_license(std::string n){
    if(members.count(n) == 0)
        throw std::runtime_error("Person ist kein Gieldenmitglied");
    
    if(this->members[n]->pay_fee(fee)){
        this->members[n]->receive_license(std::unique_ptr<License> { new License(name,salary)});
    }
    else
        throw std::runtime_error("Person kann den Gebuhr nicht leisten"); 

}


bool Guild::offer_job(std::shared_ptr<Person> p) const{
    
    if (members.count(p->get_name()))
    {
        p->work(salary*2);
        return true;
    } else {
       if (p->eligible(name)) {
           p->work(name);
           return true;
       }
    }
    return false;
}

std::ostream& Guild::print(std::ostream& o) const{
o << "[" << name << ", License fee: " << fee << ", Job salary: " << salary;
o << ", {";
bool erster{true};
for( const auto& st : members){
    if(erster){
        o << st.first;
        erster = false;
    }else
        o << ", " << st.first;
}
o << "}]";
return o;

}

std::ostream& operator<<(std::ostream& o, const Guild& g){
    return g.print(o);
}


