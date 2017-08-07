/*
Date 8/10/16
Assignment: 2D RogueLike
Name: Matt Tucker
*/

#pragma once
ref class GameConstants					//This is a classed used to collect all monster stats in one place
										//Can be used for other constants also
{
public:
	property int BlobAttack;
	property int SkellyAttack;
	property int GorkAttack;

	property int BlobStrength;
	property int SkellyStrength;
	property int GorkStrength;

	property int BlobDefence;
	property int SkellyDefence;
	property int GorkDefence;

	property int BlobEndurance;
	property int SkellyEndurance;
	property int GorkEndurance;

	property int BlobLuck;
	property int SkellyLuck;
	property int GorkLuck;

	property int BlobHealth;
	property int SkellyHealth;
	property int GorkHealth;

	property int BlobSpeed;
	property int SkellySpeed;
	property int GorkSpeed;

	property int BlobPoints;
	property int SkellyPoints;
	property int GorkPoints;

public:
	GameConstants();
};

