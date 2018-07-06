#pragma once

#include "State.h"
#include "StateManager.h"






State::State()
{
	;	
}

State::State(StateManager * argpStateManager, sf::RenderWindow * argpRenderWindow)
{
	;
}

State::~State()
{
}

void State::requestPushState(StateDefinitions::States argStateToPush)
{
	//m_pStateManager->pushGameState();
	StateManager::PendingChange pushChange;
	pushChange.pendingAction = ActionDefinitions::Actions::PUSH;
	pushChange.stateID = argStateToPush;
	m_pStateManager->changesToApply.push_back(pushChange);
	
}


void State::requestPopState()
{
	StateManager::PendingChange popChange;
	popChange.pendingAction = ActionDefinitions::Actions::POP;
	m_pStateManager->changesToApply.push_back(popChange);
}

void State::requestClearState()
{
	StateManager::PendingChange clearChange;
	clearChange.pendingAction = ActionDefinitions::Actions::CLEAR;

	m_pStateManager->changesToApply.push_back(clearChange);
}


