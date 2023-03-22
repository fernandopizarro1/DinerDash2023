#pragma once

#include "Entity.h"
#include "Client.h"

class EntityManager {

public:
	Client* firstClient;
	void tick();
	void render();
	void addEntity(Entity *e);
	void addClient(Client *c);
	void checkLeavingClients();
	void removeLeavingClients();
	std::vector<Entity*> entities;
	int left = 0;

};