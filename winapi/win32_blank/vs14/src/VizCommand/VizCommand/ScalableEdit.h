// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 独自のヘッダ
#include "Edit.h"	// エディットクラス

// スケーラブルエディットコントロールクラス
class CScalableEdit : public CEdit {

	// publicメンバ
	public:

		// メンバ変数
		int m_iLineHeight;	// 行の高さ.
		int m_iExternalLeading;	// 行間.
		int m_iLineCount;	//行数.

		// メンバ関数
		virtual BOOL Create(int x, int y, int iWidth, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(このウィンドウ専用にカスタマイズされたもの.)
		virtual int OnKeyDown(WPARAM wParam, LPARAM lParam);	// キーが押された時.
		virtual void OnSizeChild(HWND hWnd, int width, int height, HWND hChildWnd);	// 子ウィンドウのサイズが変更された時(独自メッセージ)

};