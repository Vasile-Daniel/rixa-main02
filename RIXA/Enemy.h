#include "main.h"


class Enemy
{
public:
	// constructors 
	Enemy(const std::string name, const std::string description);

	// getters
	std::string getName();
	std::string getDescription();
	// setters
	void setName(const std::string name);
	void setDescription(const std::string description);

	void UpdateEnemy();
	void UpdateTools(); 

private:
	std::string name_;
	std::string description_;
	
};

// DVD functions 
inline void Enemy::UpdateEnemy() {
	GameObject& obj_enemy = Play::GetGameObjectByType(TYPE_ENEMY);
	Play::SetSprite(obj_enemy, "coins_2", 0.25f);

	if (Play::RandomRoll(100) == 100) {
		int id = Play::CreateGameObject(TYPE_TOOL, { obj_enemy.pos.x, obj_enemy.pos.y }, 90, "bomb");
		GameObject& obj_tool = Play::GetGameObject(id);
		obj_tool.velocity = Point2f(Play::RandomRollRange(-1, 1) * 4, 4);
		obj_tool.rotSpeed = 0.2f;

		//Play::PlayAudio("tool");
	}

	Play::UpdateGameObject(obj_enemy);

	if (Play::IsLeavingDisplayArea(obj_enemy)) {
		obj_enemy.pos = obj_enemy.oldPos;
		obj_enemy.velocity.x = obj_enemy.velocity.x * -1;
	}

	Play::DrawObjectRotated(obj_enemy);
}

inline void Enemy::UpdateTools()
{
	GameObject& obj_angel = Play::GetGameObjectByType(GameObjectType::angel);
	std::vector<int> vTools = Play::CollectGameObjectIDsByType(TYPE_TOOL);

	for (int id : vTools) {
		GameObject& obj_tool = Play::GetGameObject(id);
		Play::UpdateGameObject(obj_tool);

		if (angelState != STATE_DEAD && Play::IsColliding(obj_tool, obj_angel)) {
			angelState = STATE_DEAD;
			//Play::StopAudioLoop("music");
			//Play::PlayAudio("die");
			obj_angel.pos = { -100,-100 };
		}

		if (Play::IsLeavingDisplayArea(obj_tool, Play::VERTICAL)) {
			obj_tool.pos = -obj_tool.oldPos;
			obj_tool.velocity.x *= -1;
		}

		Play::DrawObjectRotated(obj_tool);

		if (!Play::IsVisible(obj_tool))
			Play::DestroyGameObject(id);
	}

}
