/******************************************************************************/
/* Demo du moteur graphique avec une petite interface graphique utilisant la  */
/* la librairie wxWidgets. Gestion de la boucle principale également avec la  */
/* librairie.                                                                 */
/******************************************************************************/

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "wx/wx.h"
#include "wx/colordlg.h"

#include "San.h"

#include "MyRenderTarget.h"
#include "WXMainFrame.h"

using namespace San;

class SanApp : public wxApp
{
public:
	virtual bool OnInit();
	int OnExit();

protected:
	CTimer		_timer;
};

// callbacks du menu principal
BEGIN_EVENT_TABLE( SanDemo, wxFrame )
	EVT_SIZE( SanDemo::OnSize )
	EVT_MENU( MAIN_MENU_QUIT, SanDemo::OnQuit )
	EVT_MENU( MAIN_MENU_ADDLIGHT, SanDemo::OnAddLight )
	EVT_MENU( MAIN_MENU_ADDOBJECT, SanDemo::OnAddEntity )
	EVT_MENU( MAIN_MENU_REMOVEITEM, SanDemo::OnRemoveItem )
	EVT_MENU( MAIN_MENU_SHOWTREE, SanDemo::OnShowTree )
	EVT_MENU( MAIN_MENU_CHANGECAMERA, SanDemo::OnChangeCamera )
	EVT_MENU( MAIN_MENU_RENDERPROPS, SanDemo::OnRenderProps )
	EVT_MENU( MAIN_MENU_ABOUT, SanDemo::OnAbout )
	EVT_MENU( MAIN_MENU_LOAD, SanDemo::OnLoad )
	EVT_MENU( MAIN_MENU_SAVE, SanDemo::OnSave )
END_EVENT_TABLE()

// callback du panneau d'ajout de lumière
BEGIN_EVENT_TABLE( CDialogAddLight, wxDialog )
	EVT_BUTTON( DIALOG_ADD_LIGHT_AMBIANT, CDialogAddLight::OnButton )
	EVT_BUTTON( DIALOG_ADD_LIGHT_DIFFUSE, CDialogAddLight::OnButton )
	EVT_BUTTON( DIALOG_ADD_LIGHT_SPECULAR, CDialogAddLight::OnButton )
	EVT_RADIOBOX( DIALOG_ADD_LIGHT_TYPE, CDialogAddLight::OnModifyType )
END_EVENT_TABLE()

// callbacks du panneau d'ajout d'objet
BEGIN_EVENT_TABLE( CDialogAddObject, wxDialog )
	EVT_RADIOBOX( DIALOG_ADD_OBJECT_MESH_TYPE, CDialogAddObject::OnChangeType )
	EVT_BUTTON( DIALOG_ADD_OBJECT_AMBIANT, CDialogAddObject::OnButton )
	EVT_BUTTON( DIALOG_ADD_OBJECT_DIFFUSE, CDialogAddObject::OnButton )
	EVT_BUTTON( DIALOG_ADD_OBJECT_SPECULAR, CDialogAddObject::OnButton )
	EVT_BUTTON( DIALOG_ADD_OBJECT_CHOOSE_PATH, CDialogAddObject::OnButton )
END_EVENT_TABLE()

// callbacks du panneau de modification de la camèra
BEGIN_EVENT_TABLE( CDialogCamera, wxDialog )
END_EVENT_TABLE()

BEGIN_EVENT_TABLE( CRenderWindow, wxWindow )
	EVT_KEY_DOWN( CRenderWindow::OnKeyDown )
END_EVENT_TABLE()

// callbacks de l'arbre représentant la scène
BEGIN_EVENT_TABLE( CTreeScene, wxTreeCtrl)
	EVT_TREE_BEGIN_DRAG(TREE_SCENE, CTreeScene::OnBeginDrag)
    EVT_TREE_BEGIN_RDRAG(TREE_SCENE, CTreeScene::OnBeginRDrag)
    EVT_TREE_END_DRAG(TREE_SCENE, CTreeScene::OnEndDrag)
    EVT_TREE_BEGIN_LABEL_EDIT(TREE_SCENE, CTreeScene::OnBeginLabelEdit)
    EVT_TREE_END_LABEL_EDIT(TREE_SCENE, CTreeScene::OnEndLabelEdit)
    EVT_TREE_DELETE_ITEM(TREE_SCENE, CTreeScene::OnDeleteItem)

    EVT_TREE_SET_INFO(TREE_SCENE, CTreeScene::OnSetInfo)
    EVT_TREE_ITEM_EXPANDED(TREE_SCENE, CTreeScene::OnItemExpanded)
    EVT_TREE_ITEM_EXPANDING(TREE_SCENE, CTreeScene::OnItemExpanding)
    EVT_TREE_ITEM_COLLAPSED(TREE_SCENE, CTreeScene::OnItemCollapsed)
    EVT_TREE_ITEM_COLLAPSING(TREE_SCENE, CTreeScene::OnItemCollapsing)

    EVT_TREE_SEL_CHANGED(TREE_SCENE, CTreeScene::OnSelChanged)
    EVT_TREE_SEL_CHANGING(TREE_SCENE, CTreeScene::OnSelChanging)
    EVT_TREE_KEY_DOWN(TREE_SCENE, CTreeScene::OnTreeKeyDown)
    EVT_TREE_ITEM_ACTIVATED(TREE_SCENE, CTreeScene::OnItemActivated)

    EVT_CONTEXT_MENU(CTreeScene::OnContextMenu)
    EVT_TREE_ITEM_MENU(TREE_SCENE, CTreeScene::OnItemMenu)
    EVT_TREE_ITEM_RIGHT_CLICK(TREE_SCENE, CTreeScene::OnItemRClick)

    EVT_RIGHT_DOWN(CTreeScene::OnRMouseDown)
    EVT_RIGHT_UP(CTreeScene::OnRMouseUp)
    EVT_RIGHT_DCLICK(CTreeScene::OnRMouseDClick)
END_EVENT_TABLE()

IMPLEMENT_APP( SanApp );

bool SanApp::OnInit()
{
	// redirige la sortie standard pour le log
	freopen( "log.txt", "w", stdout );
	freopen( "log.txt", "w", stderr );

	// création du cadre principal
	SanDemo *frame = new SanDemo();

	_timer.SetScene( frame->GetScene() );
	_timer.SetWindow( frame->GetRenderWindow() );
	_timer.Start( 150 );

	frame->Show( true );

	SetTopWindow( frame );

	return TRUE;
}

int SanApp::OnExit()
{
	_timer.Stop();
	return 0;
}