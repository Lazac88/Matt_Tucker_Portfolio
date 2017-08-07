/*
Date 8/10/16
Assignment: 2D RogueLike
Name: Matt Tucker
*/

#include "Dungeon.h"


Dungeon::Dungeon(int startRooms, Random^ random)
{
	rand = random;
	numRooms = startRooms;
	cellArray = gcnew array<Cell^, 2>(MAX_COLS, MAX_ROWS);			//Create cell array
	for (int col = 0; col < MAX_COLS; col++)
	{
		for (int row = 0; row < MAX_ROWS; row++)
		{
			Cell^ newCell = gcnew Cell();
			cellArray[col, row] = newCell;
		}
	}
	map = gcnew array<int, 2>(MAX_COLS, MAX_ROWS);					//Create the 2D int array that will be passed to the tilemap
	
}

void Dungeon::MakeRooms()
{
	Point startLocation;
	Point roomSize;

	for (int totalRooms = 0; totalRooms < numRooms; totalRooms++)		//Loop around for each room
	{
		Boolean freeSpace = false;

		while (!freeSpace)		//While the rooms overlap
		{
			bool overlap = false;
			int roomWidth = rand->Next(MIN_SIZE, MAX_SIZE);
			int roomHeight = rand->Next(MIN_SIZE, MAX_SIZE);
			roomSize = Point(roomWidth, roomHeight);
			int xLoc = rand->Next(0, MAX_COLS);
			int yLoc = rand->Next(0, MAX_ROWS);
			startLocation = Point(xLoc, yLoc);

			int rightWall = xLoc + roomWidth;
			if(rightWall >= MAX_COLS)
				{
					rightWall = MAX_COLS - 1;
				}
			int bottomWall = yLoc + roomHeight;
			if(bottomWall >= MAX_ROWS)
				{
					bottomWall = MAX_ROWS - 1;
				}

			for (int col = xLoc; col < rightWall; col++)										//Cycle through each cell of the new room using nested for loop
			{
				for (int row = yLoc; row < bottomWall; row++)
				{
					ECellType cellType = cellArray[col, row]->getCellType();
					if (cellType != ECellType::DIRT)
					{
						overlap = true;
					}
				}
			}
			if (!overlap)
				freeSpace = true;
		}

			Room^ newRoom = gcnew Room(roomSize, startLocation);		//Create a room to hold room details
			centrePointArray[totalRooms] = newRoom->getCentre();		//Hold rooms centre point in an array for corridor construction later
			addToCellArray(newRoom);									//Add room into my cell array
	} // end for
} // end makeRooms

void Dungeon::addToCellArray(Room^ newRoom)
{
	int xLoc = newRoom->getLocation().X;
	int yLoc = newRoom->getLocation().Y;
	int roomWidth = newRoom->getSize().X;
	int roomHeight = newRoom->getSize().Y;

	
	//Make the walls
	int rightWall = xLoc + roomWidth;

	//Patricia Assisted. Right wall was sometimes outside the number of columns. If so, set to the end column
	if (rightWall >= MAX_COLS)
	{
		rightWall = MAX_COLS - 1;
	}
	
	//Patricia Assisted. Bottom wall was sometimes outside the number of rows. If so, set to the end row
	int bottomWall = yLoc + roomHeight;
	if (bottomWall >= MAX_ROWS)		
	{
		bottomWall = MAX_ROWS - 1;
	}

	for (int x = xLoc; x <= (rightWall); x++)
	{
		if (x < MAX_COLS)
		{
			cellArray[x, yLoc]->setCellType(ECellType::WALL);				//Make top wall
			cellArray[x, bottomWall]->setCellType(ECellType::WALL);		//Make bottom wall
		}		
	}

	for (int y = yLoc; y <= (yLoc + roomHeight); y++)
	{
		if (y < MAX_ROWS)
		{
			cellArray[xLoc, y]->setCellType(ECellType::WALL);			//Make left wall		
			cellArray[rightWall, y]->setCellType(ECellType::WALL);			//Make right wall
		}		
	}

	//Make the floor

	for (int col = xLoc; col <= rightWall; col++)										//Cycle through each cell of the new room using nested for loop
	{
		for (int row = yLoc; row <= bottomWall; row++)
		{
			if (col < MAX_COLS && row < MAX_ROWS)		//Check that room is on the map
			{
				ECellType cellType = cellArray[col, row]->getCellType();
				if (cellType != WALL)																//If the cell is not a wall, make it a floor
				{
					cellArray[col, row]->setCellType(ECellType::FLOOR);
				}
			}			
		}
	}
}

//============================================================USED TO CLEAR CELL ARRAY===========================================================
void Dungeon::initialCellFill()
{
	for (int widthCols = 0; widthCols < MAX_COLS; widthCols++)
	{
		for (int heightRows = 0; heightRows < MAX_ROWS; heightRows++)
		{
			cellArray[widthCols, heightRows]->setCellType(ECellType::DIRT);
		}
	}
}
//================================================================================================================================================

void Dungeon::MakeCorridors()
{
	int roomJumps = centrePointArray->Length - 1;					//Length -1 so that we do not look for the room after the end of the array
	for (int numRooms = 0; numRooms < roomJumps; numRooms++)
	{
		Point^ firstRoom = centrePointArray[numRooms];				//Grab current room centrePoint and nextRoom centre point in array
		Point^ secondRoom = centrePointArray[numRooms + 1];

		int xDifference = secondRoom->X - firstRoom->X;
		int yDifference = secondRoom->Y - firstRoom->Y;


		//Make the horizontal leg of the corridor when xDiff is negative
		if(xDifference < 0)
			{
				for(int horizontal = 0; horizontal > xDifference; horizontal--)
					{
						int currColumn = firstRoom->X + horizontal; //Find current cell column
						if(currColumn < 0)		//Check current column is not less than 0 and off map
							{
								currColumn = 0;
							}
						if(currColumn >= MAX_COLS)	//Check current column is not past or equal to 80
							{
								currColumn= MAX_COLS - 1;
							}
						ECellType myCellType = cellArray[currColumn, firstRoom->Y]->getCellType();
						if(myCellType ==ECellType::WALL)
							{
								cellArray[currColumn, firstRoom->Y]->setCellType(ECellType::DOOR);
							}
						if(myCellType == ECellType::DIRT)
							{
								cellArray[currColumn, firstRoom->Y]->setCellType(ECellType::CORRIDOR);
							}
					}
			}
		else		//make horizontal leg of corridor when difference is positive
			{
				for (int horizontal = 0; horizontal < xDifference; horizontal++)
				{
					int currColumn = firstRoom->X + horizontal;							//Find current cell column
					if (currColumn < 0)			//Check current column is not less than 0 (off map)
					{
						currColumn = 0;
					}
				
					if (currColumn >= MAX_COLS)		//Check current column is not over or equal to MAX_COLS (80)
					{
						currColumn = MAX_COLS - 1;
					}
				
					ECellType myCellType = cellArray[currColumn, firstRoom->Y]->getCellType();
					if (myCellType == ECellType::WALL)		//If it is a wall, make it a door
					{
						cellArray[currColumn, firstRoom->Y]->setCellType(ECellType::DOOR);
					}

					if (myCellType == ECellType::DIRT)		//If it is dirt, make it floor
					{
						cellArray[currColumn, firstRoom->Y]->setCellType(ECellType::CORRIDOR);
					}
				}
			}
			//Make the vertical leg of the corridor when difference is negative
			if(yDifference < 0)
				{
					for(int vertical = 0; vertical > yDifference; vertical--)
						{
							int currRow = firstRoom->Y + vertical;
							if(cellArray[secondRoom->X, currRow]->getCellType() == ECellType::WALL)
								{
									cellArray[secondRoom->X, currRow]->setCellType(ECellType::DOOR);
								}
							if(cellArray[secondRoom->X, currRow]->getCellType() == ECellType::DIRT)
								{
									cellArray[secondRoom->X, currRow]->setCellType(ECellType::CORRIDOR);
								}
						}
				}
			else		//When yDiff is positive
				{

					for (int vertical = 0; vertical < yDifference; vertical++)
					{
						int currRow = firstRoom->Y + vertical;								//Find current cell row

						if (cellArray[secondRoom->X, currRow]->getCellType() == ECellType::WALL)		//If it is a wall, make it a door
						{
							cellArray[secondRoom->X, currRow]->setCellType(ECellType::DOOR);
						}
						if (cellArray[secondRoom->X, currRow]->getCellType() == ECellType::DIRT)		//If it is dirt, make it floor
						{
							cellArray[secondRoom->X, currRow]->setCellType(ECellType::CORRIDOR);
						}
					}//end for
				}//end else
			
	} //end numRooms

}//end MakeCorridors

void Dungeon::convertToIntMap()
{
	for (int col = 0; col < MAX_COLS; col++)
	{
		for (int row = 0; row < MAX_ROWS; row++)
		{
			if (cellArray[col, row]->getCellType() == ECellType::DIRT)				//if cell is dirt, make it 0
			{
				map[col, row] = 0;
			}
			else if (cellArray[col, row]->getCellType() == ECellType::FLOOR)		//if cell is floor, make it 1
			{
				map[col, row] = 1;
			}
			else if (cellArray[col, row]->getCellType() == ECellType::WALL)			//if cell is wall, make it 2
			{
				map[col, row] = 2;
			}
			else if (cellArray[col, row]->getCellType() == ECellType::DOOR)			//if cell is door, make it 3
			{
				map[col, row] = 3;													
			}
			else
			{
				map[col, row] = 5;
			}
		}
	}
}

void Dungeon::MakeDungeon(int startRooms)
{
	numRooms = startRooms;
	centrePointArray = gcnew array<Point>(numRooms);
	initialCellFill();
	MakeRooms();
	MakeCorridors();
	convertToIntMap();
}
