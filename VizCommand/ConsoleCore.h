// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "ScalableEditBox.h"	// スカラブルエディットボックスクラス

// コンソールコアクラスCConsoleCore
class CConsoleCore : public CScalableEditBox {

	// publicメンバ
	public:

		// メンバ変数
		TCHAR *m_ptszCommandString;	// 入力コマンド文字列を格納するバッファへのポインタTCHAR *型m_ptszCommandString.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CConsoleCore();	// コンストラクタCConsoleCore()
		virtual ~CConsoleCore();	// デストラクタ~CConsoleCore()

		// メンバ関数
		virtual int GetCommandString();		// 入力コマンド文字列の取得関数GetCommandString.(自前の内部バッファに読み込む.)
		virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);	// キーが押された時のハンドラOnKeyDown.

};