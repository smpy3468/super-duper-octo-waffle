#pragma once

//Player
//玩家
//繼承Character

#include "Character.h"
#include "Item.h"
#include "Weapon.h"
#include "PlayerEquipment.h"

class Player :public Character
{
public:
	Player();
	Player(string tag, int x, int y, int width, int height, int pictureID);

	//----------------按鍵相關---------------------//
	void SetIsMoveLeft(bool isMoveLeft);//設定是否向左移動
	void SetIsMoveRight(bool isMoveRight);//設定是否向右移動
	void SetIsGrounded(bool isGrounded);//設定是否在地上
	void SetIsJump(bool isJump);//設定是否按下跳躍
	void SetIsAttack(bool isAttack);//設定是否按下攻擊

	bool HasWeapon();//是否有武器
	
	//----------------動作相關---------------------//
	void Move();//按下按鍵移動
	void Fall();//下降
	void Jump();//跳躍
	void Interact();//互動
	void Move(int dx, int dy)override;//移動特定距離
	void Attack()override;//攻擊

	//----------------動畫相關---------------------//
	void ShowBitMap()override;//顯示動畫

	//-------------顯示玩家資訊------------------//
	void ShowInformation();//顯示玩家資訊
	
	//-------------系統相關------------------//
	void AddEquipment(Weapon* equiped);//增加裝備

private:
	bool isMoveLeft;//是否向左移動
	bool isMoveRight;//是否向右移動
	bool isJumpKeyDown;//是否按下跳躍
	bool isJump;//是否正在跳躍
	bool isFall;//是否正在下降
	bool isAttack;//是否正在攻擊

	int fallDisplacement;//下降位移量(移動到沒有地板的位置會用到)
	int originJumpDisplacement, jumpDisplacement;//跳躍位移量
	bool isGrounded;//是否在地上

	void Dead()override;//死亡時呼叫

	//---------------動畫相關---------------//
	void ShowWeapon();//顯示武器

	bool faceLR;//面向左邊或面向右邊
	const bool FACE_LEFT = true;//面向左邊
	const bool FACE_RIGHT = false;//面向右邊

	void LoadAni()override;//載入動畫
	int currentAni = 0;//目前動畫
	enum ANI
	{
		ANI_IDLE = 0,
		ANI_LEFT,
		ANI_RIGHT,
		ANI_ATTACK_LEFT,
		ANI_ATTACK_RIGHT,
		ANI_JUMP_LEFT,
		ANI_JUMP_RIGHT,
		ANI_GET_HIT_LEFT,
		ANI_GET_HIT_RIGHT
	};

	vector<PlayerEquipment*> equipments;//裝備
	PlayerEquipment* weapon;//武器

	//彥澤加的
	//Item* equipment;
	bool hasWeapon=false;
};