#include"Stdafx.h"
#include <iostream>
#include "GameSystem.h"

vector<GameObject> GameSystem::gameObjectList;//初始化物件列表

GameSystem::GameSystem()
{
}

vector<GameObject>& GameSystem::GetAllGameObject()//取得所有物件
{
	return gameObjectList;
}

void GameSystem::AddGameObject(GameObject& obj)//增加遊戲物件
{
	gameObjectList.push_back(obj);
}

GameObject* GameSystem::GetGameObjectWithTag(string tag)//取得特定標籤的遊戲物件(單一個)
{
	for (auto i = gameObjectList.begin(); i != gameObjectList.end(); i++)
	{
		if (i->GetTag() == tag)
		{
			return &*i;
		}
	}
	return NULL;
}

vector<GameObject*> GameSystem::GetGameObjectsWithTag(string tag)//取得特定標籤的遊戲物件(多個)
{
	vector<GameObject*> targetObjects;
	for (auto i = gameObjectList.begin(); i != gameObjectList.end(); i++)
	{
		if (i->GetTag() == tag)
		{
			targetObjects.push_back(&*i);
		}
	}

	return targetObjects;
}

void GameSystem::MoveAllObject(int dx, int dy)//移動所有物件(用於改變螢幕看到的畫面)
{
	for (auto i : gameObjectList)
	{
		i.SetX(i.GetX() + dx);//移動到原本的x座標+dx的位置
		i.SetY(i.GetY() + dy);//移動到原本的y座標+dy的位置
	}
}

void GameSystem::SetAllObjectBitMapPosition()//設定所有物件圖片位置
{
	for (auto i : gameObjectList)
	{
		i.SetBitMapPosition();
	}
}

void GameSystem::ShowAllObject()//顯示所有物件
{
	for (auto i : gameObjectList)
	{
		i.ShowBitMap();
	}
}
