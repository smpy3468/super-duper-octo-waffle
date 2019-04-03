#include"StdAfx.h"
#include"SwordWave.h"

SwordWave::SwordWave(string tag, int x, int y, int width, int height, int pictureID) :Effect(tag, x, y, width, height, pictureID) {
	tag = "SwordWave";
	LoadAni();
	SetBitMapPosition(); 
}

void SwordWave::ShowBitMap(int hostX, int hostY, int hostCurrentAni, int attackAniNumber) {
	if((attackAniNumber == 0)){
		SetXY(hostX, hostY, hostCurrentAni);

	}
	else if (attackAniNumber >= 1 && hostCurrentAni == ANI_ATTACK_LEFT) { //3�O���������A
		currentAni = ANI::ANI_SWORDWAVE_LEFT;
		x -= 10;																//��Wave������
		SetBitMapPosition();
		ani[currentAni]->OnMove();
		ani[currentAni]->OnShow();
		if (IsPlayerInRange(player, 0, 0, 0, 0) && ani[currentAni]->GetCurrentBitmapNumber() >= 2 && hit == 0) {
			player->DecreaseHP(1);
			hit = 1;
		}

	}
	else if (attackAniNumber >= 1 && hostCurrentAni == ANI_ATTACK_RIGHT) {//4�O�k�������A
		currentAni = ANI_SWORDWAVE_RIGHT;
		x += 10;																//��Wave���k��
		SetBitMapPosition();
		ani[currentAni]->OnMove();
		ani[currentAni]->OnShow();
		if (IsPlayerInRange(player, 0, 0, 0, 0) && ani[currentAni]->GetCurrentBitmapNumber() >= 0 && hit == 0) {
			player->DecreaseHP(1);
			hit = 1;
		}
	}
	else hit = 0;

}

void SwordWave::SetXY(int hostX, int hostY, int hostCurrentAni) {
	this->x = hostX + 80;
 	this->y = hostY + 85;

	//SetBitMapPosition();
}


/*void SwordWave::FlyAni(int waveX, int waveY, int) {

}*/


void SwordWave::LoadAni() {
	char* aniSwordWave_left[3] = { ".\\res\\swordwave_left_0.bmp", ".\\res\\swordwave_left_1.bmp", ".\\res\\swordwave_left_2.bmp" };
	AddAniBitMaps(aniSwordWave_left, ANI_SWORDWAVE_LEFT, 3);

	char* aniSwordWave_right[3] = { ".\\res\\swordwave_right_0.bmp", ".\\res\\swordwave_right_1.bmp",".\\res\\swordwave_right_2.bmp" };
	AddAniBitMaps(aniSwordWave_right, ANI_SWORDWAVE_RIGHT, 3);
}
