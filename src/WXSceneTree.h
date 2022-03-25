/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Arbre de wxWidgets contenant les noeuds fils de la scène en respectant la  */
/* hiérarchie.
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#ifndef _WXSCENETREE_H_
#define _WXSCENETREE_H_

#include "wx/wx.h"
#include "wx/treectrl.h"
#include "SanStdHeaders.h"
#include "SanTypes.h"
#include "SanNode.h"

using namespace San;

enum
{
	TreeScene_Ctrl = 1000
};

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

protected:

private:
	DECLARE_EVENT_TABLE();
};

#endif