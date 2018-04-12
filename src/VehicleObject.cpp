#include "header.h"
#include "templates.h"

#include "VehicleObject.h"



VehicleObject::VehicleObject(BaseEngine* pEngine, int startX, int startY)
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

VehicleObject::~VehicleObject(void)
{

}

void VehicleObject::Draw(void)
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

void VehicleObject::DoUpdate(int iCurrentTime)
{
	// Change position if player presses a key
	/*if (GetEngine()->IsKeyPressed(SDLK_UP))
		m_iCurrentScreenY -= 2;
	if (GetEngine()->IsKeyPressed(SDLK_DOWN))
		m_iCurrentScreenY += 2;
	if (GetEngine()->IsKeyPressed(SDLK_LEFT))
		m_iCurrentScreenX -= 2;
	if (GetEngine()->IsKeyPressed(SDLK_RIGHT))
		m_iCurrentScreenX += 2;

	if (m_iCurrentScreenX < 0)
		m_iCurrentScreenX = 0;
	if (m_iCurrentScreenX >= GetEngine()->GetScreenWidth() - m_iDrawWidth)
		m_iCurrentScreenX = GetEngine()->GetScreenWidth() - m_iDrawWidth;
	if (m_iCurrentScreenY < 0)
		m_iCurrentScreenY = 0;
	if (m_iCurrentScreenY >= GetEngine()->GetScreenHeight() - m_iDrawHeight)
		m_iCurrentScreenY = GetEngine()->GetScreenHeight() - m_iDrawHeight;*/

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