#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {

}

Cure::~Cure() {

}


Cure::Cure(const Cure &cp) : AMateria("cure") {
	*this = cp;
}


Cure &Cure::operator=(const Cure &cp) {
	if (this != &cp) {
		this->type = cp.getType();
	}
	return *this;
}

AMateria* Cure::clone() const {
    return (new Cure(*this));
}

void Cure::use(ICharacter &target) {
	std::cout << "Cure: \"* heals " << target.getName() << "'s wounds *\"" << std::endl;
}
