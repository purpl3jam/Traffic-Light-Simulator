#include "header.h"
#include "templates.h"

#include "TrafficLightSS.h"

#include <iostream>

using namespace std;


TrafficLightSS::TrafficLightSS(BaseEngine* pEngine, bool light)
	: DisplayableObject(pEngine)
{

	// Current and previous coordinates for the object - set them the same initially
	m_iCurrentScreenX = m_iPreviousScreenX = 450;
	m_iCurrentScreenY = m_iPreviousScreenY = 800;
	/*getXPos = m_iCurrentScreenX;
	getYPos = m_iCurrentScreenY;
	green = false;*/
	// The object coordinate will be the top left of the object
	m_iStartDrawPosX = 0;
	m_iStartDrawPosY = 0;
	// Record the ball size as both height and width
	m_iDrawWidth = 45;
	m_iDrawHeight = 10;
	// And make it visible
	SetVisible(true);
	green = false;
	time = 0;
}

TrafficLightSS::~TrafficLightSS(void)
{

}

void TrafficLightSS::Draw(void)
{
	if (green == true) {
		GetEngine()->DrawScreenRectangle(
			m_iCurrentScreenX, m_iCurrentScreenY,
			m_iCurrentScreenX + m_iDrawWidth - 1,
			m_iCurrentScreenY + m_iDrawHeight - 1,
			0x22ad0f);
		// This will store the position at which the object was drawn
		// so that the background can be drawn over the top.
		// This will then remove the object from the screen.
		StoreLastScreenPositionForUndraw();
	}
	else {
		GetEngine()->DrawScreenRectangle(
			m_iCurrentScreenX, m_iCurrentScreenY,
			m_iCurrentScreenX + m_iDrawWidth - 1,
			m_iCurrentScreenY + m_iDrawHeight - 1,
			0xaf0e0e);
		// This will store the position at which the object was drawn
		// so that the background can be drawn over the top.
		// This will then remove the object from the screen.
		StoreLastScreenPositionForUndraw();
	}

	/*GetEngine()->DrawScreenRectangle(
		m_iCurrentScreenX, m_iCurrentScreenY,
		m_iCurrentScreenX + m_iDrawWidth - 1,
		m_iCurrentScreenY + m_iDrawHeight - 1,
		0xaf0e0e);
	// This will store the position at which the object was drawn
	// so that the background can be drawn over the top.
	// This will then remove the object from the screen.
	StoreLastScreenPositionForUndraw();*/
}

void TrafficLightSS::DoUpdate(int iCurrentTime) {

	// Determine green time
	int modTime = time % 400;
	cout << modTime;
	if (modTime <= 200) {
		green = false;
	}
	else {
		green = true;
	}

	if (green == true) {
		GetEngine()->DrawScreenRectangle(
			m_iCurrentScreenX, m_iCurrentScreenY,
			m_iCurrentScreenX + m_iDrawWidth - 1,
			m_iCurrentScreenY + m_iDrawHeight - 1,
			0x22ad0f);
		// This will store the position at which the object was drawn
		// so that the background can be drawn over the top.
		// This will then remove the object from the screen.
		StoreLastScreenPositionForUndraw();
	}
	else {
		GetEngine()->DrawScreenRectangle(
			m_iCurrentScreenX, m_iCurrentScreenY,
			m_iCurrentScreenX + m_iDrawWidth - 1,
			m_iCurrentScreenY + m_iDrawHeight - 1,
			0xaf0e0e);
		// This will store the position at which the object was drawn
		// so that the background can be drawn over the top.
		// This will then remove the object from the screen.
		StoreLastScreenPositionForUndraw();
	}

	time++;
}
