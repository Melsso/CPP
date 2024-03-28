#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {

}

Ice::~Ice() {

}


Ice::Ice(const Ice &cp) : AMateria("ice") {
	*this = cp;
}


Ice &Ice::operator=(const Ice &cp) {
	if (this != &cp) {
		this->type = cp.getType();
	}
	return *this;
}

AMateria* Ice::clone() const {
    return (new Ice(*this));
}

void Ice::use(ICharacter &target) {
	std::cout << "Ice: \"* shoots an ice bolt at " << target.getName() << " *\"" << std::endl;
}
