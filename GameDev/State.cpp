#include "State.h"

void State::ChangeState(CoreEngine* engine, State* state){
	engine->ChangeState(state);
}