#include "player.h"

void Player::takeDamage(int damage){
	if (m_block >= damage)
	{
		m_block -= damage;
		damage = 0;
	}
	else
	{
		damage -= m_block;
		m_block = 0;
	}
	m_health -= damage;
}

void Player::addBlock(int amount) {
	m_block += amount;
}