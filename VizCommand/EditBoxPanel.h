// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "UserControl.h"	// ユーザコントロールクラス
#include "EditBox.h"		// エディットボックスクラス

// エディットボックスパネルクラスCEditBoxPanel
class CEditBoxPanel : public CUserControl {

	// publicメンバ
	public:

		// publicメンバ変数
		CEditBox *m_pEditBox;	// CEditBox *型ポインタm_pEditBox.
		HMENU m_nId;	// HMENU型リソースID, m_nId.

		// publicメンバ関数
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass

		// コンストラクタ・デストラクタ
		CEditBoxPanel();	// コンストラクタCEditBoxPanel
		virtual ~CEditBoxPanel();	// デストラクタ~CEditBoxPanel()

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create
		virtual void Destroy();	// ウィンドウ破棄関数Destroy
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.
		virtual void OnSize(UINT nType, int cx, int cy);	// ウィンドウサイズが変更された時のハンドラOnSize.

};