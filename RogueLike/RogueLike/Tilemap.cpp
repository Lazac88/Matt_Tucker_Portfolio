/*
Date 8/10/16
Assignment: 2D RogueLike
Name: Matt Tucker
*/

#include "Tilemap.h"


Tilemap::Tilemap(TileList^ startTileList, Graphics^ startCanvas, int startMapRows, int startMapColumns, int newTileWidth, int newTileHeight)
{
	tileList = startTileList;
	canvas = startCanvas;
	mapCols = startMapColumns;
	mapRows = startMapRows;
	rand = gcnew Random();
	tileWidth = newTileWidth;
	tileHeight = newTileHeight;
	

	backgroundMap = gcnew array<int, 2>(startMapColumns, startMapRows);
	fogMap = gcnew array<int, 2>(startMapColumns, startMapRows);
}

//
void Tilemap::SetMapEntry(int col, int row, int tileIndex)
{
	fogMap[col, row] = tileIndex;
}

int Tilemap::GetMapEntry(int col, int row)
{
	return fogMap[col, row];
}

//Grabs a completed 2D array with the correct numbers in each spot
void Tilemap::setMapFromArray(array<int, 2>^ mapArray)
{
	backgroundMap = mapArray;
}

void Tilemap::DrawMap()
{
	for (int columns = 0; columns < mapCols; columns++)
	{
		for (int rows = 0; rows < mapRows; rows++)
		{
			int xPos = columns * tileWidth;
			int yPos = rows * tileHeight;
			int currentIndex = fogMap[columns, rows];

			Bitmap^ tileBitmap = tileList->getTileBitmap(currentIndex);
			Rectangle imageRect = Rectangle(xPos, yPos, tileWidth, tileHeight);
			canvas->DrawImage(tileBitmap, imageRect);
		}
	}
}

//Create Fresh Fog Map
void Tilemap::SetFogMap()
{
	for (int columns = 0; columns < mapCols; columns++)
	{
		for (int rows = 0; rows < mapRows; rows++)
		{
			fogMap[columns, rows] = 4;
		}
	}
}

//reveal background map
void Tilemap::ScanArea(int heroCol, int heroRow)
{
	int startScanX = heroCol - SCAN_SIZE;
	int startScanY = heroRow - SCAN_SIZE;
	int endScanX = heroCol + SCAN_BOX;
	int endScanY = heroRow + SCAN_BOX;
	if (startScanX < 0)
	{
		startScanX = 0;
	}
	if (startScanY < 0)
	{
		startScanY = 0;
	}
	if (endScanX >= mapCols)
	{
		endScanX = mapCols - 1;
	}
	if (endScanY >= mapRows)
	{
		endScanY = mapRows - 1;
	}

	for (int col = startScanX; col <= endScanX; col++)
	{
		for (int row = startScanY; row <= endScanY; row++)
		{
			fogMap[col, row] = backgroundMap[col, row];
		}
	}
}

//Sends the map number to the tileList, the tileList will return a bool if tile is walkable or not.
Boolean Tilemap::getIsWalkable(int col, int row)
{
	if (col < mapCols && row < mapRows)
	{
		int mapNumber = backgroundMap[col, row];
		Boolean walkable = tileList->getIsWalkable(mapNumber);
		return walkable;
	}
	else
	{
		return false;
	}
}


void Tilemap::LoadMapFromFile(String^ fileName)
{
	//Initialise the StreamReader
	sr = File::OpenText(fileName);

	//Will hold each line read from the file
	String^ currentLine = "";

	//Create an array to hold each index number
	array<String^>^ indexHolder = gcnew array<String^>(mapCols);

	//Counter to keep track of each row
	int rowTracker = 0;

	while (currentLine = sr->ReadLine())
	{
		//Put each index into a slot in the array
		indexHolder = currentLine->Split(',');

		//for loop to place each index into the map
		for (int columnNumber = 0; columnNumber < indexHolder->Length; columnNumber++)
		{
			int index = Convert::ToInt32(indexHolder[columnNumber]);
			SetMapEntry(columnNumber, rowTracker, index);
		}
		rowTracker++;
	}
}