#include "header.h"
#include "templates.h"

#include "BlockObject1.h"



BlockObject1::BlockObject1(BaseEngine* pEngine)
	: DisplayableObject(pEngine)
{

	// Current and previous coordinates for the object - set them the same initially
		m_iCurrentScreenX = m_iPreviousScreenX = 0;
	m_iCurrentScreenY = m_iPreviousScreenY = 200;
	// The object coordinate will be the top left of the object
	m_iStartDrawPosX = 0;
	m_iStartDrawPosY = 0;
	// Record the ball size as both height and width
	m_iDrawWidth = 1000;
	m_iDrawHeight = 100;
	// And make it visible
	SetVisible(true);
}


BlockObject1::~BlockObject1(void)
{

}

void BlockObject1::Draw(void)
{
	GetEngine()->DrawScreenRectangle(
		m_iCurrentScreenX, m_iCurrentScreenY,
		m_iCurrentScreenX + m_iDrawWidth - 1,
		m_iCurrentScreenY + m_iDrawHeight - 1,
		0x000000);
	// This will store the position at which the object was drawn
	// so that the background can be drawn over the top.
	// This will then remove the object from the screen.
	StoreLastScreenPositionForUndraw();
}