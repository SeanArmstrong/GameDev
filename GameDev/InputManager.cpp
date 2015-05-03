#include "InputManager.h"


InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

int InputManager::getControlSet(){
	return controlSetTracker++;
}

bool InputManager::MovePlayerForward(const int playerControlSet){
	if (playerControlSet == ControlSets::WASD){ // WASD
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
			return true;
		}
	}
	else if (playerControlSet == ControlSets::ARROWS){ // Arrow Keys
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
			return true;
		}
	}
	return false;
}

bool InputManager::MovePlayerBackward(const int playerControlSet){
	if (playerControlSet == ControlSets::WASD){
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			return true;
		}
	}
	else if (playerControlSet == ControlSets::ARROWS){ // Arrow Keys
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
			return true;
		}
	}
	return false;
}

bool InputManager::MovePlayerLeft(const int playerControlSet){
	if (playerControlSet == ControlSets::WASD){ // WASD
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
			return true;
		}
	}
	else if (playerControlSet == ControlSets::ARROWS){ // Arrow Keys
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
			return true;
		}
	}
	return false;
}

bool InputManager::MovePlayerRight(const int playerControlSet){
	if (playerControlSet == ControlSets::WASD){ // WASD
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
			return true;
		}
	}
	else if (playerControlSet == ControlSets::ARROWS){ // Arrow Keys
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
			return true;
		}
	}
	return false;
}

bool InputManager::JumpPlayer(const int playerControlSet){
	if (playerControlSet == ControlSets::WASD){ // WASD
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
			return true;
		}
	}
	else if (playerControlSet == ControlSets::ARROWS){ // Arrow Keys
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)){
			return true;
		}
	}
	return false;
}