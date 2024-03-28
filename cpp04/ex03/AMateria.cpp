#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type) {

}

AMateria::AMateria() : type("") {

}

AMateria::AMateria(const AMateria &cp) {
	*this = cp;
}

AMateria::~AMateria() {

}

std::string const & AMateria::getType() const{
	return this->type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "AMateria: \"* has no spell to fire at " << target.getName() << " *\"" << std::endl;
}
