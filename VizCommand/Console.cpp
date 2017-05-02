// ヘッダのインクルード
// 独自のヘッダ
#include "Console.h"	// コンソールクラス

// ウィンドウクラス登録関数RegisterClass
BOOL CConsole::RegisterClass(HINSTANCE hInstance) {

	// ユーザコントロールとして登録.
	return CUserControl::RegisterClass(hInstance, _T("Console"));	// CUserControl::RegisterClassでウィンドウクラス"Console"を登録.

}

// コンストラクタ・デストラクタ
CConsole::CConsole() : CScalableEditBoxPanel() {

}

// デストラクタ~CCConsole()
CConsole::~CConsole() {

}

// ウィンドウ作成関数Create
BOOL CConsole::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ユーザコントロールで作成.
	m_nId = hMenu;
	return CUserControl::Create(_T("Console"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, m_nId, hInstance);	// CUserControl::Createでウィンドウクラス"Console"なウィンドウを作成.

}

// ウィンドウ作成時のハンドラOnCreate.
int CConsole::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// 子エディットボックスの生成.
	m_pEditBox = new CConsoleCore();	// CConsoleCoreオブジェクトを作成し, ポインタをm_pEditBoxに格納.
	m_pEditBox->Create(_T(""), ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL /*| ES_AUTOVSCROLL*/, 0, 0, m_iWidth, m_iHeight, hwnd, m_nId + 100, lpCreateStruct->hInstance);	// m_pEditBox->Createでエディットボックス作成.

	// 成功なので0を返す.
	return 0;

}