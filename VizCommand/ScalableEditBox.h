// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "EditBox.h"	// エディットボックスクラス

// スカラブルエディットボックスクラスCWindowListControl
class CScalableEditBox : public CEditBox {

	// publicメンバ
	public:

		// publicメンバ変数
		int m_iLineHeight;	// 1行の高さ.
		int m_iLineCount;	// 行数.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CScalableEditBox();	// コンストラクタCScalableEditBox()
		virtual ~CScalableEditBox();	// デストラクタ~CScalableEditBox()

		// メンバ関数
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.
		virtual int OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);	// キーが押された時のハンドラOnKeyDown.
		virtual void OnSize(UINT nType, int cx, int cy);	// ウィンドウサイズが変更された時のハンドラOnSize.

};