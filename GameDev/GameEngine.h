#pragma once
#include "State.h"
#include <vector>

class State;

class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	void Initialise();
	void Cleanup();

	void ChangeState(State* state);
	void PushState(State* state);
	void PopState();

	void HandleEvents();
	void Update();
	void Draw();

	bool Running() { return m_running; }
	void Quit() { m_running = false; }

private:
	std::vector<State*> states;

	bool m_running;
};

