#include "header.h"
#include "templates.h"

#include "VehicleObjectNorth.h"
#include "TrafficLightSS.h"

#include <stdexcept>
#include <sstream>
#include <iostream>

using namespace std;

VehicleObjectNorth::VehicleObjectNorth(TrafficLightEngine* pEngine, int startX, int startY)
	: DisplayableObject(pEngine)
	, p_mainEngine(pEngine)
{
	XStart = startX;
	YStart = startY;
	// Current and previous coordinates for the object - set them the same initially
	m_iCurrentScreenX = m_iPreviousScreenX = startX;
	m_iCurrentScreenY = m_iPreviousScreenY = startY;
	// The object coordinate will be the top left of the object
	m_iStartDrawPosX = 0;
	m_iStartDrawPosY = 0;
	// Record the ball size as both height and width
	m_iDrawWidth = 30;
	m_iDrawHeight = 30;
	// And make it visible
	SetVisible(true);

	green = true;
	individualTime = 0;
	nVehicleObject = true;
}

VehicleObjectNorth::~VehicleObjectNorth(void)
{

}

void VehicleObjectNorth::Draw(void)
{
	GetEngine()->DrawScreenOval(
		m_iCurrentScreenX, m_iCurrentScreenY,
		m_iCurrentScreenX + m_iDrawWidth - 1,
		m_iCurrentScreenY + m_iDrawHeight - 1,
		0xe87410);

	// This will store the position at which the object was drawn
	// so that the background can be drawn over the top.
	// This will then remove the object from the screen.
	StoreLastScreenPositionForUndraw();
}

void VehicleObjectNorth::DoUpdate(int iCurrentTime)
{


	/********** EXTRA STUFF FOR COLLISIONS **********/

	// Iterate through the objects
	// We are looking for one which is too close to us
	DisplayableObject* pObject;
	for (int iObjectId = 8; (pObject = p_mainEngine->GetDisplayableObject(iObjectId)) != NULL;
		iObjectId++)
	{
		if (pObject == this) // This is us, skip it
			continue;
		// If you need to cast to the sub-class type, you must use dynamic_cast, see lecture 19
		// We are just using base class parts
		if (pObject->green != true) {
			int iXDiff = pObject->GetXCentre() - (1.025*m_iCurrentScreenX);
			int iYDiff = pObject->GetYCentre() - (1.025*m_iCurrentScreenY);

			// Estimate the size - by re-calculating it
			int iTick = iCurrentTime / 20; // 1 per 20ms
			int iFrame = iTick % 30;
			int iSize = 10 + iFrame;
			if (iFrame > 15)
				iSize = 10 + (30 - iFrame);
			int iSizeOther = iSize; // Assume both the same size

									// Pythagorus' theorum:
			if (((iXDiff*iXDiff) + (iYDiff*iYDiff))
				< ((iSizeOther + iSize)*(iSizeOther + iSize)))
			{

				// Move us to 1,1 and set direction right
				m_iMapX = 1 + rand() % 13;
				m_iMapY = 1 + (rand() % 2) * 8;
				m_iDir = 1; // Face right
				m_oMover.Setup(
					m_iMapX * 50 + 25 + 25, //m_iCurrentScreenX,
					m_iMapY * 50 + 25 + 40, //m_iCurrentScreenY,
					m_iMapX * 50 + 25 + 25,
					m_iMapY * 50 + 25 + 40,
					iCurrentTime,
					iCurrentTime + 400 + rand() % 200);
				// Ask the mover where the object should be
				m_oMover.Calculate(iCurrentTime);
				//m_iCurrentScreenX = m_oMover.GetX();
				//m_iCurrentScreenY = m_oMover.GetY();

				// Increase individual wait time
				individualTime++;

				// Set North North red count
				if (pObject->tLNNObject == true) {
					//cout << 3;
					redNN = true;
				}
				else {
					redNN = false;
				}

				// Set South North red count
				if (pObject->tLSNObject == true) {
					//cout << 3;
					redSN = true;
				}
				else {
					redSN = false;
				}

				// Ensure that the object gets redrawn on the display, if something changed
				RedrawObjects();
				return;
			}
			// Neutralise reds once collision lost
			redNN = false;
			redSN = false;
		}
	}
	/********** END EXTRA STUFF FOR COLLISIONS **********/


	// Determine offscreen movement
	if (m_iCurrentScreenX >= 1300) {
		m_iCurrentScreenX -= 1;
	}
	else if (m_iCurrentScreenX >= 1100 && m_iCurrentScreenX <= 1300) {
		m_iCurrentScreenX = 510;
		m_iCurrentScreenY = 1;
	}
	else if (m_iCurrentScreenY < 0 || m_iCurrentScreenY >= 969 || m_iCurrentScreenX < 0 || (m_iCurrentScreenX > 1000 && m_iCurrentScreenX < 1100)) {
		m_iCurrentScreenY = YStart;
		m_iCurrentScreenX = XStart;
		individualTime = 0;
	}
	// Lane directions
	else if (m_iCurrentScreenX < 550 && m_iCurrentScreenX == 510 && m_iCurrentScreenY < 209 && m_iCurrentScreenY >= 0) {
		m_iCurrentScreenY += 2;
	}
	else if (m_iCurrentScreenX < 1000 && m_iCurrentScreenX > 550 && m_iCurrentScreenY < 240 && m_iCurrentScreenY > 200) {
		m_iCurrentScreenX += 2;
	}
	else if (m_iCurrentScreenX < 550 && m_iCurrentScreenX == 510 && m_iCurrentScreenY < 709 && m_iCurrentScreenY > 210) {
		m_iCurrentScreenY += 2;
	}
	else if (m_iCurrentScreenX < 450 && m_iCurrentScreenX > 0 && m_iCurrentScreenY < 300 && m_iCurrentScreenY > 260) {
		m_iCurrentScreenX -= 2;
	}
	else if (m_iCurrentScreenX < 460 && m_iCurrentScreenX >= 0 && m_iCurrentScreenY < 800 && m_iCurrentScreenY > 760) {
		m_iCurrentScreenX -= 2;
	}
	else if (m_iCurrentScreenX < 550 && m_iCurrentScreenX >= 510 && m_iCurrentScreenY < 969 && m_iCurrentScreenY >= 710) {
		m_iCurrentScreenY += 2;
	}
	else if (m_iCurrentScreenX <= 1000 && m_iCurrentScreenX > 510 && m_iCurrentScreenY < 740 && m_iCurrentScreenY > 700) {
		m_iCurrentScreenX += 2;
	} 
	// Determine random direction
	else {
		direction = rand() % 100 + 1;
		//cout << direction;
		//cout << "/";
		/*if (direction < 45) {
			m_iCurrentScreenY -= 1;
		}
		else */if (direction < 80) {
			m_iCurrentScreenY += 1;
		}
		else if (direction >= 80 && direction < 90) {
			m_iCurrentScreenX += 1;
		}
		else if (direction >= 90) {
			m_iCurrentScreenX -= 80;
			m_iCurrentScreenY += 60;
		}
	}

	// Clear North counter
	p_mainEngine->CopyBackgroundPixels(730, 0, 200, 100);


	// Ensure that the object gets redrawn on the display, if something changed
	RedrawObjects();
}