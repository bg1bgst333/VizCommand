// ヘッダのインクルード
// 独自のヘッダ
#include "ScalableEditBoxPanel.h"	// スカラブルエディットボックスパネルクラス

// ウィンドウクラス登録関数RegisterClass
BOOL CScalableEditBoxPanel::RegisterClass(HINSTANCE hInstance) {

	// ユーザコントロールとして登録.
	return CUserControl::RegisterClass(hInstance, _T("ScalableEditBoxPanel"));	// CUserControl::RegisterClassでウィンドウクラス"ScalableEditBoxPanel"を登録.

}

// ウィンドウクラス登録関数RegisterClass(背景ブラシ指定)
BOOL CScalableEditBoxPanel::RegisterClass(HINSTANCE hInstance, HBRUSH hBrush) {

	// ユーザコントロールとして登録.
	return CUserControl::RegisterClass(hInstance, _T("ScalableEditBoxPanel"), hBrush);	// CUserControl::RegisterClass(背景ブラシ指定)でウィンドウクラス"ScalableEditBoxPanel"を登録.

}

// コンストラクタCScalableEditBoxPanel()
CScalableEditBoxPanel::CScalableEditBoxPanel() : CEditBoxPanel() {

}

// デストラクタ~CScalableEditBoxPanel()
CScalableEditBoxPanel::~CScalableEditBoxPanel() {

}

// ウィンドウ作成関数Create
BOOL CScalableEditBoxPanel::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ユーザコントロールで作成.
	m_nId = hMenu;
	return CUserControl::Create(_T("ScalableEditBoxPanel"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, m_nId, hInstance);	// CUserControl::Createでウィンドウクラス"ScalableEditBoxPanel"なウィンドウを作成.

}

// ウィンドウ作成時のハンドラOnCreate.
int CScalableEditBoxPanel::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// 子エディットボックスの生成.
	m_pEditBox = new CScalableEditBox();	// CScalableEditBoxオブジェクトを作成し, ポインタをm_pEditBoxに格納.
	m_pEditBox->Create(_T(""), ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL | ES_AUTOVSCROLL, 0, 0, m_iWidth, m_iHeight, hwnd, m_nId + 100, lpCreateStruct->hInstance);	// m_pEditBox->Createでエディットボックス作成.

	// 成功なので0を返す.
	return 0;

}

// ウィンドウサイズが変更された時のハンドラOnSize.
void CScalableEditBoxPanel::OnSize(UINT nType, int cx, int cy) {

	// 実際のウィンドウサイズを格納.
	m_iWidth = cx;	// m_iWidthにcxをセット.
	m_iHeight = cy;	// m_iHeightにcyをセット.

#if 1

	// 子ウィンドウのリサイズ
	if (m_pEditBox != NULL) {
		//m_pEditBox->MoveWindow(PADDING, PADDING, m_iWidth - (PADDING * 2), m_iHeight - (PADDING * 2));
		m_pEditBox->MoveWindow(0, 0, m_iWidth, m_iHeight);
	}

#endif

}

// ユーザ定義メッセージが発生した時のハンドラ.
void CScalableEditBoxPanel::OnUserMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// switch-case文で振り分ける.
	switch (uMsg) {

		// 子から親へウィンドウサイズ変更の要求が発生した時.
		case UM_SIZECHILD:

			// UM_SIZECHILDブロック
			{

				// OnSizeChildに任せる.
				OnSizeChild(wParam, lParam);	// OnSizeChildに任せる.

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// それ以外.
		default:

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

	}

}

// 子から親へウィンドウサイズ変更の要求が発生した時の独自ハンドラ.
void CScalableEditBoxPanel::OnSizeChild(WPARAM wParam, LPARAM lParam) {

	// 変数の宣言.
	int iWidth;
	int iHeight;

	// 子ウィンドウのサイズを取得.
	iWidth = LOWORD(wParam);
	iHeight = HIWORD(wParam);

	// ウィンドウサイズの変更.
	HWND hWnd = (HWND)lParam;	// lParamは子ウィンドウのハンドル.
	HWND hParent = GetParent(hWnd);	// hParentがこのウィンドウ.(OnCreateの後なのでメンバに入ってない.)
	::MoveWindow(hParent, m_x, m_y, iWidth, iHeight, TRUE);	// 子ウィンドウと同じする.

	// UM_SIZECHILDで子ウィンドウのサイズに合わせる.
	WPARAM wp;
	wp = MAKEWPARAM(m_iWidth, m_iHeight);
	SendMessage(GetParent(hParent), UM_SIZECHILD, wp, (LPARAM)hParent);

}