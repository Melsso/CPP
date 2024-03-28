#pragma once

#include "ICharacter.hpp"

class ICharacter;

class Character : public ICharacter {
	private:
		std::string name;
		AMateria *inventory[4];
	public:
		Character(const std::string &name);
		~Character();
		Character(const Character &cp);
		Character &operator=(const Character &cp);

		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};
