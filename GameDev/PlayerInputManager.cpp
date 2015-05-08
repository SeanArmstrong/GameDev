#include "PlayerInputManager.h"


PlayerInputManager::PlayerInputManager()
{
}


PlayerInputManager::~PlayerInputManager()
{
}

int PlayerInputManager::getControlSet(){
	return controlSetTracker++;
}

bool PlayerInputManager::MovePlayerForward(const int playerControlSet){
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

bool PlayerInputManager::MovePlayerBackward(const int playerControlSet){
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

bool PlayerInputManager::MovePlayerLeft(const int playerControlSet){
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

bool PlayerInputManager::MovePlayerRight(const int playerControlSet){
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

bool PlayerInputManager::JumpPlayer(const int playerControlSet){
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