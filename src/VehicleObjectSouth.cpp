#include "header.h"
#include "templates.h"

#include "VehicleObjectSouth.h"
#include "TrafficLightSS.h"

#include <stdexcept>


VehicleObjectSouth::VehicleObjectSouth(BaseEngine* pEngine, int startX, int startY)
	: DisplayableObject(pEngine)
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
}

VehicleObjectSouth::~VehicleObjectSouth(void)
{

}

void VehicleObjectSouth::Draw(void)
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

void VehicleObjectSouth::DoUpdate(int iCurrentTime)
{

	DisplayableObject* TLSS;
	//TLSS = p_mainEngine->GetDisplayableObject(6);

	/********** EXTRA STUFF FOR COLLISIONS ********/

	// Iterate through the objects
	// We are looking for one which is too close to us
	/*DisplayableObject* pObject;
	for (int iObjectId = 6; (pObject = p_mainEngine->GetDisplayableObject(iObjectId)) != NULL;
		iObjectId++)
	{
		if (pObject == this) // This is us, skip it
			continue;
		// If you need to cast to the sub-class type, you must use dynamic_cast, see lecture 19
		// We are just using base class parts
		int iXDiff = pObject->GetXCentre() - m_iCurrentScreenX;
		int iYDiff = pObject->GetYCentre() - m_iCurrentScreenY;

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


			// Ensure that the object gets redrawn on the display, if something changed
			RedrawObjects();
			return;
		}
	}*/
	/********** END EXTRA STUFF FOR COLLISIONS********/
	
	//if (/*(m_iCurrentScreenX = TLSS->getXPos) && (m_iCurrentScreenY = TLSS->getYPos) &&*/ (TLSS->green != true)) {
		//m_iCurrentScreenX += 0;
		//m_iCurrentScreenY += 0;
	//}
	// Lane directions
	if (m_iCurrentScreenX < 490 && m_iCurrentScreenX == 460 && m_iCurrentScreenY < 1000 && m_iCurrentScreenY > 761) {
		m_iCurrentScreenY -= 2;
	}
	else if (m_iCurrentScreenX < 460 && m_iCurrentScreenX > 0 && m_iCurrentScreenY < 800 && m_iCurrentScreenY > 760) {
		m_iCurrentScreenX -= 2;
	}
	else if (m_iCurrentScreenX < 490 && m_iCurrentScreenX == 460 && m_iCurrentScreenY < 760 && m_iCurrentScreenY > 261) {
		m_iCurrentScreenY -= 2;
	}
	else if (m_iCurrentScreenX < 1000 && m_iCurrentScreenX > 460 && m_iCurrentScreenY < 740 && m_iCurrentScreenY > 700) {
		m_iCurrentScreenX += 2;
	}
	else if (m_iCurrentScreenX < 460 && m_iCurrentScreenX > 0 && m_iCurrentScreenY < 300 && m_iCurrentScreenY > 260) {
		m_iCurrentScreenX -= 2;
	}
	else if (m_iCurrentScreenX < 490 && m_iCurrentScreenX == 460 && m_iCurrentScreenY < 260 && m_iCurrentScreenY > 0) {
		m_iCurrentScreenY -= 2;
	}
	else if (m_iCurrentScreenX < 1000 && m_iCurrentScreenX > 460 && m_iCurrentScreenY < 240 && m_iCurrentScreenY > 200) {
		m_iCurrentScreenX += 2;
	}
	// Determine random direction
	else {
		direction = rand() % 100 + 1;
		if (direction < 40) {
			m_iCurrentScreenY -= 1;
		}
		else if (direction >= 40 && direction < 80) {
			m_iCurrentScreenY += 1;
		}
		else if (direction >= 80 && direction < 90) {
			m_iCurrentScreenX -= 1;
		}
		else if (direction >= 90) {
			m_iCurrentScreenX += 80;
			m_iCurrentScreenY -= 50;
		}
	}
		
	if (m_iCurrentScreenY < 0 || m_iCurrentScreenY > 1000 || m_iCurrentScreenX < 0 || m_iCurrentScreenX >= 1000) {
		m_iCurrentScreenY = YStart;
		m_iCurrentScreenX = XStart;
	}




	// Ensure that the object gets redrawn on the display, if something changed
	RedrawObjects();
}