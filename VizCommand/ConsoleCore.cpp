// ヘッダのインクルード
// 独自のヘッダ
#include "ConsoleCore.h"	// コンソールコアクラス

// コンストラクタCConsoleCore()
CConsoleCore::CConsoleCore() : CScalableEditBox() {

}

// デストラクタ~CConsoleCore()
CConsoleCore::~CConsoleCore() {

}

// 入力コマンド文字列の取得関数GetCommandString.(自前の内部バッファに読み込む.)
int CConsoleCore::GetCommandString() {

	// いったん内部メモリを破棄.
	DestroyTextBuffer();

	// 文字列取得.
	GetWindowText();

	return 0;

}

// キーが押された時のハンドラOnKeyDown.
void CConsoleCore::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {

	// リターンきーが押された時.
	if (nChar == VK_RETURN) {		// VK_RETURNの時.
		GetCommandString();	// コマンド文字列取得.
		MessageBox(NULL, m_ptszText, _T("VizCommand"), MB_OK);
	}

}