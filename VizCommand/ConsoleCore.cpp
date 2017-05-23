// ヘッダのインクルード
// 独自のヘッダ
#include "ConsoleCore.h"	// コンソールコアクラス
#include <shlobj.h>			// シェルオブジェクト.

// コンストラクタCConsoleCore()
CConsoleCore::CConsoleCore() : CScalableEditBox() {

	// メンバの初期化.
	m_tstrFormString = GREATER_THAN;	// フォーム文字列を">"に初期化.
	m_lStartPos = 0;	// 入力開始位置を0に初期化.
	m_ccmdCommand.Clear();	// コマンドのクリア.

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
// マイドキュメント(CSIDL_MYDOCUMENTS)のパスを取得する関数GetMyDocumentPath.
tstring CConsoleCore::GetMyDocumentPath(HWND hWnd){

	// 配列の宣言.
	TCHAR tszPath[1024];	// CSIDL_MYDOCUMENTSなパスを格納するtszPath.

	// マイドキュメントパスの取得.
	SHGetSpecialFolderPath(hWnd, tszPath, CSIDL_MYDOCUMENTS, FALSE);	// SHGetSpecialFolderPathでCSIDL_MYDOCUMENTSなパスを取得.

	// メンバに格納.
	m_tstrMyDocumentPath = tszPath;	// m_tstrMyDocumentPathにtszPathを格納.

	// マイドキュメントパスを返す.
	return m_tstrMyDocumentPath;	// m_tstrMyDocumentPathを返す.

}

// 指定されたパスを現在のパスとしてセットする関数SetCurrentPath.
void CConsoleCore::SetCurrentPath(tstring tstrPath){

	// 指定されたパスを現在のパスとしてセット.
	m_tstrCurrentPath = tstrPath;	// m_tstrCurrentPathをtstrPathにする.
	SetCurrentDirectory(m_tstrCurrentPath.c_str());	// SetCurrentDirectoryで現在のパスとしてm_tstrCurrentPath.c_str()をセット.

}

// 現在のパスを取得する関数GetCurrentPath.
tstring CConsoleCore::GetCurrentPath(){

	// 変数の初期化.
	TCHAR tszPath[1024] = { 0 };	// tszPath(要素数1024)を0で初期化.

	// 現在のパスを取得.
	GetCurrentDirectory(1024, tszPath);	// GetCurrentDirectoryで現在のパスを取得.
	m_tstrCurrentPath = tszPath;	// tszPathをm_tstrCurrentPathにセット.

	// パスを返す.
	return m_tstrCurrentPath;	// m_tstrCurrentPathを返す.

}

// 指定されたパスのフルパスを返す関数GetFullPath.
tstring CConsoleCore::GetFullPath(tstring tstrPath){
	
	// 変数の初期化
	TCHAR tszPath[1024] = { 0 };	// tszPath(要素数1024)を0で初期化.

	// フルパスを取得.
	GetFullPathName(tstrPath.c_str(), 1024, tszPath, NULL);	// GetFullPathNameでフルパスを取得.

	// tszPathを返す.
	return tstring(tszPath);	// tszPathをtstringに変換して返す.

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

	// 変数の初期化
	int iCount = 0;	// 改行の個数iCountを0に初期化.

	// 改行の数を数える.
	for (int i = 1; i < (int)tstrString.length(); i++) {
		if (tstrString.at(i - 1) == _T('\r') && tstrString.at(i) == _T('\n')) {

			// 変数の宣言
			int iHeight;	// 新しい高さiHeight.

			// 改行したら1行分大きくする.
			iHeight = m_iHeight + m_iLineHeight;	// 現在のウィンドウの高さに1行分の高さを足す.
			MoveWindow(3, iHeight);	// MoveWindowで高さを新しいiHeightにする.
			m_iLineCount++;		// 行数を増やす.

			// UM_SIZECHILDで子ウィンドウのサイズに合わせる.
			WPARAM wParam;
			wParam = MAKEWPARAM(m_iWidth, m_iHeight);
			SendMessage(GetParent(m_hWnd), UM_SIZECHILD, wParam, (LPARAM)m_hWnd);

			iCount++;

		}
	}

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

// 入力コマンド文字列の取得関数GetCommandString.
tstring CConsoleCore::GetCommandString() {

	// 変数の宣言
	unsigned int uiCommandStringLen;	// コマンド文字列の長さ.
	TCHAR *ptszCommandString;	// コマンド文字列へのポインタ.

	// いったん内部メモリを破棄.
	DestroyTextBuffer();

	// 文字列取得.
	GetWindowText();

	// コマンド文字列の切り出し.
	uiCommandStringLen = (unsigned int)m_iLen - (unsigned int)m_lStartPos;	// コマンド文字列は, 全体の長さ - 開始位置.
	ptszCommandString = new TCHAR[uiCommandStringLen + 1];	// コマンド文字列バッファ作成.
	_tcsncpy_s(ptszCommandString, uiCommandStringLen + 1, &m_ptszText[m_lStartPos], uiCommandStringLen);	// コマンド文字列部分だけコピー.
	ptszCommandString[uiCommandStringLen];	// NULL終端.

	// メンバにセット.
	m_tstrCommandString = ptszCommandString;	// m_tstrCommandStringにptszCommandStringをセット.

	// 解放.
	delete[] ptszCommandString;	// delete[]でptszCommandStringを解放.

	// 内部メモリを破棄.
	DestroyTextBuffer();

	// コマンド文字列を返す.
	return m_tstrCommandString;	// m_tstrCommandStringを返す.

}

// コマンドに対する処理を実行するウィンドウのウィンドウハンドルをセットする関数SetProcWindow.
void CConsoleCore::SetProcWindow(HWND hWnd) {

	// メンバにセット.
	m_hProcWnd = hWnd;	// m_hProcWndにhWndをセット.

}

// ウィンドウ作成時のハンドラOnCreate.
int CConsoleCore::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// 親クラスのOnCreateを呼ぶ.
	CScalableEditBox::OnCreate(hwnd, lpCreateStruct);	// CScalableEditBox::OnCreateを呼ぶ.

	// ホームフォルダ(マイドキュメントに変更.)の取得.
	//GetProfilePath(hwnd);	// GetProfilePathで取得.
	GetMyDocumentPath(hwnd);	// GetMyDocumentPathで取得.

	// 現在のパスとしてマイドキュメントをセット.
	SetCurrentPath(m_tstrMyDocumentPath);	// SetCurrentPathでm_tstrMyDocumentPathをセット.

	// 出力フォームを取得.
	GetOutputFormString();	// GetOutputFormStringで取得.

	// 出力フォームを出力.
	ShowOutputForm();	// ShowOutputFormで出力.

	// フォーカスをセット.
	::SetFocus(hwnd);	// SetFocusでフォーカスをセット.

	// 成功なので0を返す.
	return 0;

}

// キーが押された時のハンドラOnKeyDown.
int CConsoleCore::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {

	// 上キーが押された時.
	if (nChar == VK_UP) {	// VK_UPの時.
		// 上キーはとりあえず無効にして, 上に戻れなくする.
		return -1;	// -1を返すと入力キャンセルになる.
	}

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

	// リターンキーが押された時.
	if (nChar == VK_RETURN) {	// VK_RETURNの時.
		m_ccmdCommand.Clear();	// m_ccmdCommand.Clearでクリア.
		GetCommandString();	// GetCommandStringでコマンド文字列を取得.
		m_ccmdCommand.Set(m_tstrCommandString);	// m_ccmdCommand.Setでm_tstrCommandStringをm_ccmdCommandにセットしてパースしてもらう.
		//MessageBox(NULL, m_tstrCommandString.c_str(), _T("VizCommand"), MB_OK);	// メッセージボックスでコマンド文字列の表示.
		CScalableEditBox::OnKeyDown(nChar, nRepCnt, nFlags);	// CScalableEditBox::OnKeyDownを呼ぶことで, 1行増やして改行される.
		//PostMessage(m_hProcWnd, UM_CONSOLECORECOMMAND, (WPARAM)m_tstrCommandString.c_str(), (LPARAM)m_hWnd);	// UM_CONSOLECORECOMMANDでコマンド文字列をコマンドに対する処理を実行するウィンドウに送信.
		PostMessage(m_hProcWnd, UM_CONSOLECORECOMMAND, (WPARAM)&m_ccmdCommand, (LPARAM)m_hWnd);	// UM_CONSOLECORECOMMANDでコマンドオブジェクトをコマンドに対する処理を実行するウィンドウに送信.
	}

	// 通常は入力を有効にする.
	return 0;	// 0を返すと有効になる.

}

// マウス左ボタンが離された時のハンドラOnLButtonUp.
int CConsoleCore::OnLButtonUp(UINT nFlags, POINT pt) {

	// キャレットを表示する.
	ShowCaret(m_hWnd);	// ShowCaretでキャレットを表示する.

	// 現在位置が開始位置より前になるようにマウスでクリックされた場合, キャレットを強制的に開始位置に戻す.
	m_lCurrentPos = 0;	// m_lCurrentPosを0にセット.
	SendMessage(m_hWnd, EM_GETSEL, (WPARAM)&m_lCurrentPos, NULL);	// キャレットの位置を取得.
	if (m_lCurrentPos < m_lStartPos) {	// 開始位置より手前だったらキャレットの位置を再セット.
		SendMessage(m_hWnd, EM_SETSEL, (WPARAM)m_lStartPos, (LPARAM)m_lStartPos);	// キャレット位置をm_lStartPosに再セット.
	}

	// 入力は有効にする.
	return 0;	// 0を返すと有効になる.

}

// マウス左ボタンが離された時のハンドラOnLButtonDown.
int CConsoleCore::OnLButtonDown(UINT nFlags, POINT pt) {

	// キャレットを非表示にする.
	HideCaret(m_hWnd);	// HideCaretでキャレットを非表示にする.

	// 入力は有効にする.
	return 0;	// 0を返すと有効になる.

}

// ユーザ定義メッセージが発生した時のハンドラ.
void CConsoleCore::OnUserMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// switch-case文で振り分ける.
	switch (uMsg) {

		// レスポンスメッセージが来た時.
		case UM_RESPONSEMESSAGE:

			// UM_RESPONSEMESSAGEブロック
			{
		
				// OnResponseMessageに任せる.
				OnResponseMessage(wParam, lParam);	// OnResponseMessageに任せる.

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// レスポンスが終了した時.
		case UM_FINISHRESPONSE:

			// UM_FINISHRESPONSEブロック
			{

				// OnFinishResponseに任せる.
				OnFinishResponse(wParam, lParam);	// OnFinishResponseに任せる.

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// それ以外.
		default:

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

	}

	// 親クラスのユーザメッセージ処理.
	CScalableEditBox::OnUserMessage(uMsg, wParam, lParam);	// CScalableEditBox::OnUserMessageに任せる.

}

// レスポンスメッセージが来た時の独自ハンドラ.
void CConsoleCore::OnResponseMessage(WPARAM wParam, LPARAM lParam) {

	// 変数の宣言
	tstring tstrMessage;	// メッセージ文字列tstring型tstrMessage.

	// メッセージを取得.
	tstrMessage = (TCHAR *)wParam;	// wParamをTCHAR *型にキャストしてtstrMessageに格納.

	// メッセージを出力.
	PutConsole(tstrMessage);	// PutConsoleでtstrMessageを出力.

}

// レスポンスが終了した時の独自ハンドラ.
void CConsoleCore::OnFinishResponse(WPARAM wParam, LPARAM lParam) {

	// 出力フォームを出力.
	m_ccmdCommand.Clear();	// コマンドをクリア.
	ShowOutputForm();	// ShowOutputFormで出力.

}