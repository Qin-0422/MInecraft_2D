#include "Character.h"

Character::Character()
{

}
Character::Character( int health, int attackPower, int attackDistance_x,int attackDistance_y, int x, int y)
{
    m_Health =health;
    m_AttackPower= attackPower;
    m_AttackDistance_x = attackDistance_x;
    m_x = x;
    m_y = y;
    m_MoveSpeed = 10;
}

// 获取人物属性
int Character::getHealth() const
{
    return m_Health;
}

int Character::getAttackPower() const {
    return m_AttackPower;
}

int Character::getattackDistance_x() const {
    return m_AttackDistance_x;
}
int Character::getattackDistance_y() const {
    return m_AttackDistance_y;
}
int Character::getX() const {
    return m_x;
}

int Character::getY() const {
    return m_y;
}

// 设置人物属性
void Character::setHealth(int health)
{
    this->m_Health = health;
}

void Character::setAttackPower(int attackPower)
{
    this->m_AttackPower = attackPower;
}

void Character::setattackDistance_x(int attackDistance_x)
{
    this->m_AttackDistance_x = attackDistance_x;
}
void Character::setattackDistance_y(int attackDistance_y)
{
    this->m_AttackDistance_y = attackDistance_y;
}
void Character::setPosition(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
}





