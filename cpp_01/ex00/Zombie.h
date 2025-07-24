#pragma once

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>
#include "Zombie/Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif