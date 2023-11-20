#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<map>
#include "license.h"



License::License(std::string name,unsigned int salary):name{name},salary{salary}{
   counter = 0;
   if(name.empty())
      throw std::runtime_error("Name ist zu kurz");
   if(salary <= 0)
      throw std::runtime_error("Gehalt ist zu klein");
}

std::string License::get_guildname() const{
   return name;
}

unsigned int License::get_salary() const {
   return salary;
}

bool License::valid() const{
   if(counter <= 3)
      return true;
   else
      return false;
}


bool License::use() {
   if(valid()){
	   counter++;
	   return true;
   }
   else
	   return false;
}

 std::ostream& License::print(std::ostream& o) const{
		o << "[License for " << name << ", Salary: " << salary << ", Used: " << counter << "]";
		return o;
  }

std::ostream& operator<<(std::ostream& o, const License& l){
		return l.print(o);
}

