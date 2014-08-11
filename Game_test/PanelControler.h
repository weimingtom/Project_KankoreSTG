#ifndef PANELCONTROLER_H
#define PANELCONTROLER_H

#include "sav_Admiral.h"
#include "GUIPanel.h"
#include "HomePanel.h"
#include "GamePanel.h"
#include "BuildPanel.h"
#include "EquipPanel.h"
#include "startPanel.h"
#include "ReplacePanel.h"

class PanelControler
{
public:
	void SetCurrentPanel(GUIPanel *_Panel);
	Admiral *GetAdmiral();
	GUIPanel *GetCurrentPanel();
private:
	Admiral *_UserData;
	GUIPanel *CurrentPanel;
};

#endif