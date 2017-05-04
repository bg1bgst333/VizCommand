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
		tstring m_tstrProfilePath;		// ホームフォルダ(CSIDL_PROFILE)のパスを格納するtstring型m_tstrProfilePath.
		tstring m_tstrCurrentPath;		// 現在のパスを格納するtstring型m_tstrCurrentPath.
		tstring m_tstrFormString;		// フォーム文字列(文字)を格納するtstring型m_tstrFormString.
		tstring m_tstrOutputFormString;	// 実際に出力するフォーム文字列を格納するtstring型m_tstrOutputFormString.
		tstring m_tstrCommandString;	// コマンド文字列を格納するtstring型m_tstrCommandString.
		long m_lStartPos;				// 入力開始位置を格納するlong型m_lStartPos.
		long m_lCurrentPos;				// 入力現在位置を格納するlong型m_lCurrentPos.
		HWND m_hProcWnd;				// コマンドに対する処理を実行するウィンドウのウィンドウハンドルHWND型m_hProcWnd.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CConsoleCore();	// コンストラクタCConsoleCore()
		virtual ~CConsoleCore();	// デストラクタ~CConsoleCore()

		// メンバ関数
		virtual tstring GetProfilePath(HWND hWnd);	// ホームフォルダ(CSIDL_PROFILE)のパスを取得する関数GetProfilePath.
		virtual tstring GetOutputFormString();		// 出力フォーム文字列を取得する関数GetOutputFormString.
		virtual void PutConsole(tstring tstrString);	// コンソールに文字列を出力する関数PutConsole.
		virtual void ShowOutputForm();	// 出力フォームの出力.
		virtual tstring GetCommandString();		// 入力コマンド文字列の取得関数GetCommandString.
		virtual void SetProcWindow(HWND hWnd);	// コマンドに対する処理を実行するウィンドウのウィンドウハンドルをセットする関数SetProcWindow.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.
		virtual int OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);	// キーが押された時のハンドラOnKeyDown.
		virtual int OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);		// 文字キーが押された時のハンドラOnChar.
		virtual int OnLButtonUp(UINT nFlags, POINT pt);	// マウス左ボタンが離された時のハンドラOnLButtonUp.
		virtual int OnLButtonDown(UINT nFlags, POINT pt);	// マウス左ボタンが離された時のハンドラOnLButtonDown.
		virtual void OnUserMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);	// ユーザ定義メッセージが発生した時のハンドラ.
		virtual void OnResponseMessage(WPARAM wParam, LPARAM lParam);	// レスポンスメッセージが来た時の独自ハンドラ.
		virtual void OnFinishResponse(WPARAM wParam, LPARAM lParam);	// レスポンスが終了した時の独自ハンドラ.

};