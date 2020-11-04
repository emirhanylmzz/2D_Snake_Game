#pragma once
#include <iostream>
#include "glm.hpp"
#include <deque> 
#include <vector> 
struct Bait {
	glm::vec3 pos;
	bool check = true;
	void createBait();
	Bait(glm::vec3 pos);
};

class Snake {
private:
	std::vector<glm::vec3> pos;
	glm::vec3 head;
	glm::vec3 tail;
	int direction = 1;
public:
	Snake(glm::vec3 startPos);
	inline int getDirection() const { return direction; }
	inline void setDirection(const int i) { direction = i; }
	inline std::vector<glm::vec3> getPos() const { return pos; }
	inline glm::vec3 getPos(unsigned int index) const { return pos[index]; }
	void snakegrow(Bait& bait);
	inline glm::vec3 getHead() const { return head; }
	bool isGameOver() const;
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
};
