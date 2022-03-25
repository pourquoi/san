/******************************************************************************/
/* Classes surchargeant les classes wxWidgets                                 */
/* -SanDemo: cadre principal de l'interface graphique                         */
/* -CTimer: compteur affichant/animant la scène à interval régulier           */
/* -différents panneaux de modification de la scène(lumière, objet...)        */
/* -CtreeScene: arbre représentant la structure hiérarchique de la scène      */
/******************************************************************************/

#ifndef _WXMAINFRAME_H_
#define _WXMAINFRAME_H_

#include <wx/wx.h>
#include <wx/colordlg.h>
#include <wx/timer.h>
#include <wx/dcbuffer.h>
#include <wx/treectrl.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/menu.h>
#include <wx/spinctrl.h>
#include <wx/image.h>

#include "San.h"

using namespace San;

enum
{
	ID_DEFAULT = wxID_ANY,
	DIALOG_ADD_LIGHT = 0,
	DIALOG_ADD_LIGHT_AMBIANT,
	DIALOG_ADD_LIGHT_DIFFUSE,
	DIALOG_ADD_LIGHT_DIRX,
	DIALOG_ADD_LIGHT_DIRY,
	DIALOG_ADD_LIGHT_DIRZ,
	DIALOG_ADD_LIGHT_FADDINGEND,
	DIALOG_ADD_LIGHT_FADINGSTART,
	DIALOG_ADD_LIGHT_POSX,
	DIALOG_ADD_LIGHT_POSY,
	DIALOG_ADD_LIGHT_POSZ,
	DIALOG_ADD_LIGHT_SPECULAR,
	DIALOG_ADD_LIGHT_TYPE,
	DIALOG_ADD_OBJECT,
	DIALOG_ADD_OBJECT_AMBIANT,
	DIALOG_ADD_OBJECT_CHOOSE_PATH,
	DIALOG_ADD_OBJECT_DIFFUSE,
	DIALOG_ADD_OBJECT_DIRX,
	DIALOG_ADD_OBJECT_DIRY,
	DIALOG_ADD_OBJECT_DIRZ,
	DIALOG_ADD_OBJECT_MESH_PATH,
	DIALOG_ADD_OBJECT_MESH_TYPE,
	DIALOG_ADD_OBJECT_POSX,
	DIALOG_ADD_OBJECT_POSY,
	DIALOG_ADD_OBJECT_POSZ,
	DIALOG_ADD_OBJECT_SCALEX,
	DIALOG_ADD_OBJECT_SCALEY,
	DIALOG_ADD_OBJECT_SCALEZ,
	DIALOG_ADD_OBJECT_SPECULAR,
	DIALOG_CAMERA,
	DIALOG_CAMERA_FAR,
	DIALOG_CAMERA_FOV,
	DIALOG_CAMERA_NEAR,
	DIALOG_CAMERA_POSX,
	DIALOG_CAMERA_POSY,
	DIALOG_CAMERA_POSZ,
	DIALOG_CAMERA_TARGETX,
	DIALOG_CAMERA_TARGETY,
	DIALOG_CAMERA_TARGETZ,
	DIALOG_CAMERA_TYPE,
	MAIN_MENU_ABOUT,
	MAIN_MENU_ADDLIGHT,
	MAIN_MENU_ADDOBJECT,
	MAIN_MENU_CHANGECAMERA,
	MAIN_MENU_LOAD,
	MAIN_MENU_QUIT,
	MAIN_MENU_RENDERPROPS,
	MAIN_MENU_SAVE,
	MAIN_MENU_SHOWTREE,
	MAIN_MENU_REMOVEITEM,
	MAIN_RENDER_WINDOW,
	MENU,
	TREE_SCENE
};

/*
** compteur qui sert à rendre et animer la scène à intervals régulier
*/
class CTimer : public wxTimer
{
public:
	CTimer() : _elapsedTime(0.0) {}
	void Notify();

	void SetScene( CScene *scene ) { _scene = scene; }
	void SetWindow( wxWindow *win ) { _renderWindow = win; }

protected:
	sanLong _elapsedTime;
	CScene		*_scene;
	wxWindow	*_renderWindow;
};

class CRenderWindow : public wxWindow
{
public:
	CRenderWindow( wxWindow *parent, wxWindowID id );

	void OnKeyDown( wxKeyEvent &event );
private:
	DECLARE_EVENT_TABLE();
};

/*
** Panneau d'ajout d'une lumière
*/
class CDialogAddLight : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();

	protected:
		void OnButton( wxCommandEvent &event );
		void OnModifyType( wxCommandEvent &event );

		wxStaticText* m_staticText4;
		wxBitmapButton* _buttonAmbiant;
		wxStaticText* m_staticText5;
		wxBitmapButton* _buttonDiffuse;
		wxStaticText* m_staticText6;
		wxBitmapButton* _buttonSpecular;
		wxStaticText* m_staticText7;
		wxStaticText* m_staticText8;
		wxStaticText* m_staticText9;
		wxStaticText* m_staticText10;
		wxStaticText* m_staticText11;
		wxStaticText* m_staticText12;
		wxStaticText* m_staticText13;
		wxStaticText* m_staticText14;
		wxButton* _buttonOK;
		wxButton* _buttonCancel;
	
	public:
		wxColour _ambiant;
		wxColour _diffuse;
		wxColour _specular;
		wxRadioBox* _radioboxType;
		wxTextCtrl* _textPosX;
		wxTextCtrl* _textPosY;
		wxTextCtrl* _textPosZ;
		wxTextCtrl* _textDirX;
		wxTextCtrl* _textDirY;
		wxTextCtrl* _textDirZ;
		wxTextCtrl* _textFadingStart;
		wxTextCtrl* _textFadingEnd;
		CDialogAddLight( wxWindow* parent, int id = -1, wxString title = wxT("Add a light"), wxPoint pos = wxDefaultPosition, wxSize size = wxSize( 403,334 ), int style = wxDEFAULT_DIALOG_STYLE|wxSUNKEN_BORDER );	
};

/*
** Panneau d'ajout d'un objet
*/
class CDialogAddObject : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();

	protected:
		wxButton* _buttonChoosePath;
		wxStaticText* m_staticText15;
		wxStaticText* m_staticText16;
		wxStaticText* m_staticText17;
		wxStaticText* m_staticText18;
		wxStaticText* m_staticText19;
		wxStaticText* m_staticText20;
		wxStaticText* m_staticText22;
		wxStaticText* m_staticText23;
		wxStaticText* m_staticText24;
		wxStaticText* m_staticText27;
		wxBitmapButton* _buttonAmbiant;
		wxStaticText* m_staticText28;
		wxBitmapButton* _buttonDiffuse;
		wxStaticText* m_staticText29;
		wxBitmapButton* _buttonSpecular;
		wxStaticText* m_staticText30;
		wxStaticText* m_staticText25;
		wxStaticText* m_staticText26;
		wxButton* _buttonOK;
		wxButton* _buttonCancel;
	
	public:
		void OnChangeType( wxCommandEvent& event );
		void OnButton( wxCommandEvent& event );

		wxRadioBox* _radioboxMeshType;
		wxTextCtrl* _textMeshPath;
		wxTextCtrl* _textPosX;
		wxTextCtrl* _textPosY;
		wxTextCtrl* _textPosZ;
		wxTextCtrl* _textDirX;
		wxTextCtrl* _textDirY;
		wxTextCtrl* _textDirZ;
		wxTextCtrl* _textScaleX;
		wxTextCtrl* _textScaleY;
		wxTextCtrl* _textScaleZ;
		wxTextCtrl* _textName;
		wxSpinCtrl* _spinPower;
		wxChoice* _choiceLightningType;
		wxChoice* _choiceMeshType;
		wxColour _ambiant;
		wxColour _diffuse;
		wxColour _specular;

		CDialogAddObject( wxWindow* parent, int id = -1, wxString title = wxT("Add an object"), wxPoint pos = wxDefaultPosition, wxSize size = wxSize( 499,480 ), int style = wxDEFAULT_DIALOG_STYLE );
	
};

/*
** Panneau d'ajout de modification de la caméra
*/
class CDialogCamera : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();

	protected:
		wxStaticText* m_staticText31;
		wxStaticText* m_staticText32;
		wxStaticText* m_staticText33;
		wxStaticText* m_staticText34;
		wxStaticText* m_staticText35;
		wxStaticText* m_staticText36;
		wxStaticText* m_staticText38;
		wxStaticText* m_staticText39;
		wxStaticText* m_staticText41;
		wxButton* m_button8;
		wxButton* m_button9;

		void OnModifyType( wxCommandEvent &event );
	
	public:
		wxRadioBox* _radioboxType;
		wxTextCtrl* _textPosX;
		wxTextCtrl* _textPosY;
		wxTextCtrl* _textPosZ;
		wxTextCtrl* _textTargetX;
		wxTextCtrl* _textTargetY;
		wxTextCtrl* _textTargetZ;
		wxTextCtrl* _textNear;
		wxTextCtrl* _textFar;
		wxTextCtrl* _textFOV;
		CDialogCamera( wxWindow* parent, int id = -1, wxString title = wxT(""), wxPoint pos = wxDefaultPosition, wxSize size = wxDefaultSize, int style = wxDEFAULT_DIALOG_STYLE );
	
};

/*
** structure contenue par certains noeuds de l'arbre ci-dessous
*/
class CTreeItemData : public wxTreeItemData
{
public:
	CTreeItemData( CNode *node ) : _node( node ) {};
	~CTreeItemData()
	{
	}

	CNode * GetNode()	{ return _node; }
private:
	CNode *_node;
};

/*
** Arbre représentant la scène
*/
class CTreeScene : public wxTreeCtrl
{
	public:
		CTreeScene();

		CTreeScene( wxWindow *parent, const wxWindowID &id,
					const wxPoint &pos, const wxSize &size,
					long style );

		virtual ~CTreeScene();

		void AddSceneNode( CNode *node );
		void RefreshList( CScene *scene );
		void RemoveSelection();

	protected:
		void OnBeginDrag(wxTreeEvent& event);
		void OnBeginRDrag(wxTreeEvent& event);
		void OnEndDrag(wxTreeEvent& event);
		void OnBeginLabelEdit(wxTreeEvent& event);
		void OnEndLabelEdit(wxTreeEvent& event);
		void OnDeleteItem(wxTreeEvent& event);
		void OnContextMenu(wxContextMenuEvent& event);
		void OnItemMenu(wxTreeEvent& event);
		void OnGetInfo(wxTreeEvent& event);
		void OnSetInfo(wxTreeEvent& event);
		void OnItemExpanded(wxTreeEvent& event);
		void OnItemExpanding(wxTreeEvent& event);
		void OnItemCollapsed(wxTreeEvent& event);
		void OnItemCollapsing(wxTreeEvent& event);
		void OnSelChanged(wxTreeEvent& event);
		void OnSelChanging(wxTreeEvent& event);
		void OnTreeKeyDown(wxTreeEvent& event);
		void OnItemActivated(wxTreeEvent& event);
		void OnItemRClick(wxTreeEvent& event);

		void OnRMouseDown(wxMouseEvent& event);
		void OnRMouseUp(wxMouseEvent& event);
		void OnRMouseDClick(wxMouseEvent& event);

	private:
		void AddNodeRec( CNode* node, wxTreeItemId parent, CNode *nsel );

		DECLARE_EVENT_TABLE();
};


/*
** panneau des propriétés de rendu
*/
class CRenderDialog : public wxDialog
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxStaticText* m_staticText2;
		wxStaticText* m_staticText3;
		wxStaticText* m_staticText4;
		wxButton* _buttonOK;
		wxButton* _buttonCancel;
	public:
		CRenderDialog( wxWindow* parent, int id = -1, wxString title = wxT(""), wxPoint pos = wxDefaultPosition, wxSize size = wxDefaultSize, int style = wxDEFAULT_DIALOG_STYLE );
		wxTextCtrl* _texteWidth;wxTextCtrl* _texteHeight;
		wxTextCtrl* _texteComponents;
		wxChoice* _choiceOperation;		
};


/*
** Fenêtre principale
*/
class SanDemo : public wxFrame
{
	private:
		void Resize();

		DECLARE_EVENT_TABLE();
	
	protected:
		wxMenuBar* _menuBar;

		void OnSize( wxSizeEvent &event );

		// callback de la fenêtre de rendu
		void OnKeyDown( wxKeyEvent &event );

		// callbacks du menu file
		void OnLoad( wxCommandEvent& event );
		void OnSave( wxCommandEvent& event );
		void OnQuit( wxCommandEvent& event );

		// callbacks du menu scène
		void OnAddLight( wxCommandEvent& event );
		void OnAddEntity( wxCommandEvent& event );
		void OnChangeCamera( wxCommandEvent& event );
		void OnRemoveItem( wxCommandEvent& event );
		void OnShowTree( wxCommandEvent& event );

		// callbacks du menu render
		void OnRenderProps( wxCommandEvent& event );

		// callbacks du menu help
		void OnAbout( wxCommandEvent& event );

		CTimer		*_timer;
		CScene		*_scene;
		CTreeScene	*_sceneTree;
		CRenderWindow *_renderWindow;
	
	public:
		SanDemo( wxWindow* parent=NULL, int id = -1, wxString title = wxT("SanDemo"), wxPoint pos = wxDefaultPosition, wxSize size = wxSize( 800,600 ), int style = wxDEFAULT_FRAME_STYLE|wxMAXIMIZE|wxTAB_TRAVERSAL );

		CScene * GetScene() { return _scene; }
		wxWindow * GetRenderWindow() { return _renderWindow; }
	
};

#endif