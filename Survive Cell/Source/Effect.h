#include "StdAfx.h"
#include "GameObject.h"
#include "GameSystem.h"
#include "Player.h"

class Effect :public GameObject{
public:
	Effect(string tag, int x, int y, int width, int height, int pictureID);
	
	void SetHit(int hit);														//設定是否有打中(每一組動畫只能造成一次傷害)
	virtual void ShowBitMap(int hostX, int hostY, int hostCurrentAni, int attackAniNumber);				//顯示動畫特效

	
protected:
	void AddAniBitMaps(char* pic[], int aniType, int picCount);					//增加多張動畫圖片
	void AddAniBitMap(char* pic, int aniType);									//增加動畫圖片
	void SetBitMapPosition()override;											//設定動畫左上角
	bool IsObjectInRange(GameObject* obj, int right_fix, int left_fix, int up_fix, int down_fix);    //判斷動畫與物件是否重疊
	//bool IsObjectInRange(Monster* obj, int right_fix, int left_fix, int up_fix, int down_fix);


	Player* player = GameSystem::GetGameObjectWithTag<Player>("Player");	
	int currentAni = 0;															//現在執行哪個動畫	(左邊:0, 右邊:1)
	bool isHit = false;																//每一次的火焰只能造成一次傷害
	const int ANI_ATTACK_LEFT = 3, ANI_ATTACK_RIGHT = 4;						//E攻擊動畫

	virtual void SetXY(int hostX, int hostY, int hostCurrentAni);					//隨著擁有者移動 設定XY
	virtual void LoadAni();														//載入動畫
	vector<CAnimation*> ani;													//動畫集
	void EffectAttackMonster(int attackDamage);

	bool CanMoveLeft(int perDisplacement);//可以向左移動，perDisplacement:每次的位移量是多少
	bool CanMoveRight(int perDisplacement);//可以向右移動
	bool CanMoveUp(int perDisplacement);//可以向上移動
	bool CanMoveDown(int perDisplacement);//可以向下移動
};
