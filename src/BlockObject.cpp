#include "header.h"

#include "BaseEngine.h"
#include "JPGImage.h"

#include "BlockObject.h"



BlockObject::BlockObject(TrafficLightEngine* pEngine, int startX, int startY)
	: DisplayableObject(pEngine),
	p_mainEngine(pEngine)
{
	// Get start position
	XStart = startX;
	YStart = startY;

	// Set current and previous coordinates for the object
	m_iCurrentScreenX = m_iPreviousScreenX = startX;
	m_iCurrentScreenY = m_iPreviousScreenY = startY;

	// The object coordinate will be the top left of the object
	m_iStartDrawPosX = 0;
	m_iStartDrawPosY = 0;

	// Set height and width of block
	m_iDrawWidth = 300;
	m_iDrawHeight = 300;

	// Make object visible
	SetVisible(true);

}


BlockObject::~BlockObject()
{
}

void BlockObject::Draw(void)
{
	// If all objects are invisible then don't draw
	if (!p_mainEngine->allVisible) {
		return;
	}
	else {
		// Draw block
		GetEngine()->DrawScreenRectangle(
			m_iCurrentScreenX - 1, m_iCurrentScreenY - 1,
			m_iCurrentScreenX + m_iDrawWidth,
			m_iCurrentScreenY + m_iDrawHeight,
			0xffffff);

	}
}