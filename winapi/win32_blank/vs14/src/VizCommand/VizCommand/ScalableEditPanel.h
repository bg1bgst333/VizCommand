// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 独自のヘッダ
#include "ScalableEdit.h"	// スケーラブルエディットクラス
#include "EditPanel.h"	// エディットパネルクラス

// スケーラブルエディットパネルクラス
class CScalableEditPanel : public CEditPanel {

	// publicメンバ
	public:

		// メンバ変数
		int m_iLineHeight;	// 行の高さ.

		// メンバ関数
		virtual BOOL Create(int x, int y, int iWidth, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(このウィンドウ専用にカスタマイズされたもの.)
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.
		virtual void OnSize(UINT nType, int cx, int cy);	// ウィンドウのサイズが変更された時のハンドラOnSize.
		virtual void OnPaint();	// 画面描画の更新を要求された時.
		virtual int OnKeyDown(WPARAM wParam, LPARAM lParam);	// キーが押された時.
		virtual void OnSizeChild(HWND hWnd, int width, int height, HWND hChildWnd);	// 子ウィンドウのサイズが変更された時(独自メッセージ)

};
