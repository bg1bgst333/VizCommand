// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "CustomControl.h"	// カスタムコントロールクラス

// エディットボックスクラスCEditBox
class CEditBox : public CCustomControl {

	// publicメンバ
	public:

		// メンバ変数
		TCHAR *m_ptszText;	// エディットボックスのテキストを格納するバッファへのポインタTCHAR *型m_ptszText.
		int m_iLen;	// エディットボックスのテキストの長さint型m_iLen.

		// コンストラクタ・デストラクタ
		CEditBox();	// コンストラクタCEditBox()
		virtual ~CEditBox();	// デストラクタ~CEditBox()

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(lpctszClassName省略)
		virtual void Destroy();	// ウィンドウ破棄関数Destroy
		virtual BOOL CreateTextBuffer();	// エディットボックスのテキストを格納するバッファ作成関数CreateTextBuffer.
		virtual void DestroyTextBuffer();	// エディットボックスのテキストを格納するバッファ破棄関数DestroyTextBuffer.
		virtual int GetWindowTextLength();	// エディットボックスのテキストの長さ取得関数GetWindowTextLength.
		virtual int GetWindowText();		// エディットボックスのテキストの取得関数GetWindowText.(自前の内部バッファに読み込む.)
		virtual void SetWindowText();		// エディットボックスのテキストの設定関数SetWindowText.(自前の内部バッファに格納されているものをセット.)

};