#pragma once 

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
	public:
		Cure();
		~Cure();
		Cure(const Cure &cp);
		Cure &operator=(const Cure &cp);
		virtual AMateria*   clone() const;
		virtual void use(ICharacter &target);
};
