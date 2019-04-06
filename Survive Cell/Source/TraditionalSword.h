#pragma once
#include "StdAfx.h"
#include "Weapon.h"
#include "SwordWave.h"
#include "Player.h"
#include "EquipedSlot.h"

class TraditionalSword:public Weapon{
	public:
		TraditionalSword();
		TraditionalSword(string tag, int x, int y, int width, int height, int pictureID);
	private:
		void LoadAni()override;							//載入動畫
		void ShowBitMap()override;						//顯示動畫
		void Picked()override;							//出發效果
		void SetXY(int hostX, int hostY, int playerCurrentAni, int  palyerAniNumber)override;	//當主角攻擊時改變武器的位置 因為會引想到特效的位置

		//TraditionalSword GetThisEquipment(); //提供Class:Equipment用
		
		SwordWave* wave = new SwordWave("SwordWave", x, y, 77, 70, IDB_0);
		enum ANI {
			ANI_IDLE = 0,
			ANI_LEFT,
			ANI_RIGHT
		};
};