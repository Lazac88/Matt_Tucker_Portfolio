/*
Date 8/10/16
Assignment: 2D RogueLike
Name: Matt Tucker
*/
#include "Room.h"


Room::Room(Point roomSize, Point roomLocation)
{
	size = roomSize;
	roomLoc = roomLocation;
	int midX = roomLoc.X + (roomSize.X / 2);
	if(midX >= MAX_COLS)
		{
			midX = MAX_COLS - 1;
		}

	int midY = roomLoc.Y + (roomSize.Y / 2);
	if(midY >= MAX_ROWS)
		{
			midY = MAX_ROWS - 1;
		}
	centreRoom = Point(midX, midY);
}

