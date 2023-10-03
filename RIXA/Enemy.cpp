#include "Enemy.h"
#include <string>
#include <vector>

Enemy::Enemy(const std::string name, const std::string description)
{
	name_ = name;
	description_ = description; 
}


// getters
std::string Enemy::getName()
{
	return name_; 
}
std::string Enemy::getDescription()
{
	return description_; 
}
// setters
void Enemy::setName(const std::string name)
{
	name_ = name;
}
void Enemy::setDescription(const std::string description)
{
	description_ = description; 
}