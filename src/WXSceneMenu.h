#ifndef _WXSCENEMENU_H_
#define _WXSCENEMENU_H_

#include "wx/wx.h"
#include "wx/colordlg.h"
#include "SanTypes.h"
#include "SanLight.h"

using namespace San;

#define ID_DEFAULT wxID_ANY // Default

enum
{
	Dialog_Light_ChooseAmbiant,
	Dialog_Light_ChooseDiffuse,
	Dialog_Light_ChooseSpecular,
	Dialog_Light,
	Dialog_Light_ChangeType
};

/**
 * Class AddLightDialog
 */
class AddLightDialog : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();

	protected:
		wxStaticText* m_staticText9;
		wxStaticText* m_staticText8;
		wxStaticText* m_staticText10;
		wxButton* _btnOK;
		wxButton* _btnCancel;
	
	public:
		void OnButton( wxCommandEvent &event );
		void OnModifyType( wxCommandEvent &event );

		wxColour _ambiant;
		wxColour _diffuse;
		wxColour _specular;

		wxRadioBox* _btnType;
		wxBitmapButton* _btnAmbiantCol;
		wxBitmapButton* _btnDiffuseCol;
		wxBitmapButton* _btnSpecularCol;
		wxTextCtrl* _textPosX;
		wxTextCtrl* _textPosY;
		wxTextCtrl* _textPosZ;
		wxTextCtrl* _textDirX;
		wxTextCtrl* _textDirY;
		wxTextCtrl* _textDirZ;
		wxTextCtrl* _textRange1;
		wxTextCtrl* _textRange2;
		AddLightDialog( wxWindow* parent, int id = Dialog_Light, wxString title = wxT(""), wxPoint pos = wxDefaultPosition, wxSize size = wxSize( 444,468 ), int style = wxDEFAULT_DIALOG_STYLE );
	
};

class AddObjectDialog : public wxDialog
{
public:
	AddObjectDialog( wxWindow *parent );

	void OnButton( wxCommandEvent& event );

	wxSpinCtrl		*_specPower;
	wxTextCtrl		*_pos[3];
	wxTextCtrl		*_dir[3];
	wxSlider		*_scale;
private:
	DECLARE_EVENT_TABLE();
};

#endif