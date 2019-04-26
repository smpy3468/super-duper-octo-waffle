#pragma once

//Door
//門
//繼承GameObject

#include "GameObject.h"

class Door :public GameObject
{
public:
	Door();
	Door(string tag, int x, int y, int width, int height);
	void Kicked();//被踢

	void SetBitMapPosition()override;
private:
	void Dead()override;
	
	void ShowBitMap()override;
	void LoadAni();//載入圖片
	bool isRuin;//是否被破壞
	CAnimation* ani;
};