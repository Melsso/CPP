#pragma once 

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
	public:
		Ice();
		~Ice();
		Ice(const Ice &cp);
		Ice &operator=(const Ice &cp);
		virtual AMateria*   clone() const;
		virtual void use(ICharacter &target);
};
