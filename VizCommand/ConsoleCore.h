// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "ScalableEditBox.h"	// スカラブルエディットボックスクラス

// マクロの定義
#define GREATER_THAN _T(">")

// コンソールコアクラスCConsoleCore
class CConsoleCore : public CScalableEditBox {

	// publicメンバ
	public:

		// メンバ変数
		//TCHAR *m_ptszCommandString;	// 入力コマンド文字列を格納するバッファへのポインタTCHAR *型m_ptszCommandString.
		tstring m_tstrProfilePath;		// ホームフォルダ(CSIDL_PROFILE)のパスを格納するtstring型m_tstrProfilePath.
		tstring m_tstrCurrentPath;		// 現在のパスを格納するtstring型m_tstrCurrentPath.
		tstring m_tstrFormString;		// フォーム文字列(文字)を格納するtstring型m_tstrFormString.
		tstring m_tstrOutputFormString;	// 実際に出力するフォーム文字列を格納するtstring型m_tstrOutputFormString.
		long m_lStartPos;				// 入力開始位置を格納するlong型m_lStartPos.
		long m_lCurrentPos;				// 入力現在位置を格納するlong型m_lCurrentPos.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CConsoleCore();	// コンストラクタCConsoleCore()
		virtual ~CConsoleCore();	// デストラクタ~CConsoleCore()

		// メンバ関数
		virtual tstring GetProfilePath(HWND hWnd);	// ホームフォルダ(CSIDL_PROFILE)のパスを取得する関数GetProfilePath.
		virtual tstring GetOutputFormString();		// 出力フォーム文字列を取得する関数GetOutputFormString.
		virtual void PutConsole(tstring tstrString);	// コンソールに文字列を出力する関数PutConsole.
		virtual void ShowOutputForm();	// 出力フォームの出力.
		virtual int GetCommandString();		// 入力コマンド文字列の取得関数GetCommandString.(自前の内部バッファに読み込む.)]
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.
		virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);	// キーが押された時のハンドラOnKeyDown.
		virtual int OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);		// 文字キーが押された時のハンドラOnChar.

};