// ヘッダのインクルード
// 独自のヘッダ
#include "StreamConsole.h"	// ストリームコンソールクラス
#include "Console.h"	// コンソールクラス

// ウィンドウクラス登録関数RegisterClass
BOOL CStreamConsole::RegisterClass(HINSTANCE hInstance) {

	// ウィンドウリストアイテムズパネルを登録.
	CWindowListItemsPanel::RegisterClass(hInstance);	// 子ウィンドウを登録.

	// ユーザコントロールとして登録.
	return CUserControl::RegisterClass(hInstance, _T("StreamConsole"));	// CUserControl::RegisterClassでウィンドウクラス"StreamConsole"を登録.

}

// コンストラクタCStreamConsole()
CStreamConsole::CStreamConsole() : CWindowListControl() {

}

// デストラクタ~CStreamConsole()
CStreamConsole::~CStreamConsole() {

}

// ウィンドウ作成関数Create
BOOL CStreamConsole::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ユーザコントロールで作成.
	return CUserControl::Create(_T("StreamConsole"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Createでウィンドウクラス"StreamConsole"なウィンドウを作成.

}

// ウィンドウ作成時のハンドラOnCreate.
int CStreamConsole::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ペンとブラシの作成.
	m_hPen = (HPEN)CreatePen(PS_SOLID, 1, RGB(0, 0, 0));		// 黒のペンを作成.
	m_hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));		// 黒のブラシを作成.

	// ウィンドウリストアイテムズパネルクラスの作成.
	m_pWindowListItemsPanel = new CWindowListItemsPanel();	// CWindowListItemsPanelオブジェクトを作成し, ポインタをm_pWindowListItemsPanelに格納.
	m_pWindowListItemsPanel->Create(_T(""), 0, 0, 0, m_iWidth, m_iHeight, hwnd, (HMENU)IDC_WINDOWLISTITEMSPANEL1, lpCreateStruct->hInstance);	// m_pWindowListItemsPanel->Createでウィンドウリストアイテムズパネルを作成.(親ウィンドウより小さめ.)

	// デフォルトアイテムの挿入.
	Insert(_T("0"), 0, 100, lpCreateStruct->hInstance);	// Insertで0番目にウィンドウを挿入

	// デフォルトアイテムに子ウィンドウをセット.
	CWindowListItem *pItem = m_pWindowListItemsPanel->Get(0);	// 0番目を取得.
	CConsole *pConsole = new CConsole();	// コンソールを生成.
	pConsole->Create(_T(""), 0, 0, 0, pItem->m_iWidth, pItem->m_iHeight, pItem->m_hWnd, (HMENU)IDC_WINDOWLISTITEM_CHILD_ID_START, lpCreateStruct->hInstance);	// コンソールのウィンドウを生成.
	pItem->m_mapChildMap.insert(std::make_pair(_T("Console"), pConsole));	// アイテムに子ウィンドウを挿入.

	// 成功なので0を返す.
	return 0;

}