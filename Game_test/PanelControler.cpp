#include "PanelControler.h"
PanelControler controler;
void PanelControler::SetCurrentPanel(GUIPanel *_Panel)
{
	if (CurrentPanel != NULL)
	{
		delete CurrentPanel;
		_Panel->Loading();
	}
	CurrentPanel = _Panel;
};
Admiral *PanelControler::GetAdmiral()
{
	if (!_UserData)
		_UserData = new Admiral();
	return _UserData;
};
GUIPanel *PanelControler::GetCurrentPanel(){return CurrentPanel;}