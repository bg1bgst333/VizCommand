// ヘッダのインクルード
// 独自のヘッダ
#include "ConsoleCore.h"	// コンソールコアクラス
#include <shlobj.h>			// シェルオブジェクト.

// コンストラクタCConsoleCore()
CConsoleCore::CConsoleCore() : CScalableEditBox() {

	// メンバの初期化.
	m_tstrFormString = GREATER_THAN;	// フォーム文字列を">"に初期化.
	m_lStartPos = 0;	// 入力開始位置を0に初期化.

}

// デストラクタ~CConsoleCore()
CConsoleCore::~CConsoleCore() {

}

// ホームフォルダ(CSIDL_PROFILE)のパスを取得する関数GetProfilePath.
tstring CConsoleCore::GetProfilePath(HWND hWnd) {

	// 配列の宣言.
	TCHAR tszPath[1024];	// CSIDL_PROFILEなパスを格納するtszPath.

	// ホームフォルダパスの取得.
	SHGetSpecialFolderPath(hWnd, tszPath, CSIDL_PROFILE, FALSE);	// SHGetSpecialFolderPathでCSIDL_PROFILEなパスを取得.

	// メンバに格納.
	m_tstrProfilePath = tszPath;	// m_tstrProfilePathにtszPathを格納.

	// ホームフォルダパスを返す.
	return m_tstrProfilePath;	// m_tstrProfilePathを返す.

}

// 出力フォーム文字列を取得する関数GetOutputFormString.
tstring CConsoleCore::GetOutputFormString() {

	// 出力フォーム文字列は"現在のパス"+"フォーム文字列".
	m_tstrOutputFormString = m_tstrCurrentPath + m_tstrFormString;	// m_tstrOutputFormStringにm_tstrCurrentPathとm_tstrFormStringを連結したものを格納.

	// 出力フォーム文字列を返す.
	return m_tstrOutputFormString;	// m_tstrOutputFormStringを返す.

}

// コンソールに文字列を出力する関数PutConsole.
void CConsoleCore::PutConsole(tstring tstrString) {

	// 文字列を追加する.
	SendMessage(m_hWnd, EM_REPLACESEL, 0, (LPARAM)tstrString.c_str());	// EM_REPLACESELでtstrStringを追加する.(本来は置換だが, 0を指定したときは追加(挿入)したことになる.)

	// 入力位置の更新.
	SendMessage(m_hWnd, EM_GETSEL, (WPARAM)&m_lStartPos, NULL);	// EM_GETSELで選択していない場合は開始位置を取得できる.

}

// 出力フォームの出力.
void CConsoleCore::ShowOutputForm() {

	// 出力フォーム文字列を出力.
	PutConsole(m_tstrOutputFormString);	// PutConsoleでm_tstrOutputFormStringを出力.

}

// 入力コマンド文字列の取得関数GetCommandString.(自前の内部バッファに読み込む.)
int CConsoleCore::GetCommandString() {

	// いったん内部メモリを破棄.
	DestroyTextBuffer();

	// 文字列取得.
	GetWindowText();

	return 0;

}

// ウィンドウ作成時のハンドラOnCreate.
int CConsoleCore::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// 親クラスのOnCreateを呼ぶ.
	CScalableEditBox::OnCreate(hwnd, lpCreateStruct);	// CScalableEditBox::OnCreateを呼ぶ.

	// ホームフォルダの取得.
	GetProfilePath(hwnd);	// GetProfilePathで取得.

	// 現在のパスをホームフォルダに.
	m_tstrCurrentPath = m_tstrProfilePath;	// m_tstrCurrentPathをm_tstrProfilePathにする.

	// 出力フォームを取得.
	GetOutputFormString();	// GetOutputFormStringで取得.

	// 出力フォームを出力.
	ShowOutputForm();	// ShowOutputFormで出力.

	// 成功なので0を返す.
	return 0;

}

// キーが押された時のハンドラOnKeyDown.
int CConsoleCore::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {

	// 左キーが押された時.
	if (nChar == VK_LEFT) {	// VK_LEFTの時.
		m_lCurrentPos = 0;	// m_lCurrentPosを0にセット.
		SendMessage(m_hWnd, EM_GETSEL, (WPARAM)&m_lCurrentPos, NULL);	// キャレットの位置を取得.
		if (m_lCurrentPos <= m_lStartPos) {	// 開始位置より手前だったら入力キャンセルする.
			return -1;	// -1を返すと入力キャンセルになる.
		}
	}

	// 通常は入力を有効にする.
	return 0;	// 0を返すと有効になる.

}

// 文字キーが押された時のハンドラOnChar.
int CConsoleCore::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) {

	// バックスペースが押された時.
	if (nChar == VK_BACK) {	// VK_BACKの時.
		m_lCurrentPos = 0;	// m_lCurrentPosを0にセット.
		SendMessage(m_hWnd, EM_GETSEL, (WPARAM)&m_lCurrentPos, NULL);	// キャレットの位置を取得.
		if (m_lCurrentPos <= m_lStartPos) {	// 開始位置より手前だったら入力キャンセルする.
			return -1;	// -1を返すと入力キャンセルになる.
		}
	}

	// 通常は入力を有効にする.
	return 0;	// 0を返すと有効になる.

}