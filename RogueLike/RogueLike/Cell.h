#pragma once

public enum ECellType { DIRT, FLOOR, WALL, DOOR, CORRIDOR};


//This class is used to hold data about a cell. It is future proofing the project in that I can add more data to a cell without ripping the dungeon apart.
ref class Cell
{
public:
	ECellType cellType;

public:
	Cell();

	void setCellType(ECellType cell) { cellType = cell; }
	ECellType getCellType() { return cellType; }
};

