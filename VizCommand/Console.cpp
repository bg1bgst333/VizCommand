// ヘッダのインクルード
// 独自のヘッダ
#include "Console.h"	// コンソールクラス
#include "Command.h"	// コマンドクラス

// ウィンドウクラス登録関数RegisterClass
BOOL CConsole::RegisterClass(HINSTANCE hInstance) {

	// ユーザコントロールとして登録.
	return CUserControl::RegisterClass(hInstance, _T("Console"));	// CUserControl::RegisterClassでウィンドウクラス"Console"を登録.

}

// コンストラクタ・デストラクタ
CConsole::CConsole() : CScalableEditBoxPanel() {

}

// コンストラクタCConsole(tstring tstrDefaultCurrentPath)
CConsole::CConsole(tstring tstrDefaultCurrentPath) : CScalableEditBoxPanel() {

	// デフォルトカレントパスのセット.
	m_tstrDefaultCurrentPath = tstrDefaultCurrentPath;

}

// デストラクタ~CCConsole()
CConsole::~CConsole() {

}

// ウィンドウ作成関数Create
BOOL CConsole::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ユーザコントロールで作成.
	m_nId = hMenu;
	return CUserControl::Create(_T("Console"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, m_nId, hInstance);	// CUserControl::Createでウィンドウクラス"Console"なウィンドウを作成.

}

// ウィンドウ作成時のハンドラOnCreate.
int CConsole::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// 変数の宣言.
	CConsoleCore *pConsoleCore;	// CConsoleCore *型ポインタpConsoleCore.

	// 子エディットボックスの生成.
	pConsoleCore = new CConsoleCore();	// CConsoleCoreオブジェクトを作成し, ポインタをpConsoleCoreに格納.
	pConsoleCore->SetCurrentPath(m_tstrDefaultCurrentPath);	// デフォルトカレントパスのセット.
	m_pEditBox = pConsoleCore;	// m_pEditBoxにpConsoleCoreをセット.
	m_pEditBox->Create(_T(""), ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL /*| ES_AUTOVSCROLL*/, 0, 0, m_iWidth, m_iHeight, hwnd, m_nId + 100, lpCreateStruct->hInstance);	// m_pEditBox->Createでエディットボックス作成.

	// ConsoleCoreのコマンドに対する処理をこのウィンドウが実行するようにする.
	pConsoleCore->SetProcWindow(hwnd);	// pConsoleCore->SetProcWindowにhwndをセット.

	// 成功なので0を返す.
	return 0;

}

// ユーザ定義メッセージが発生した時のハンドラ.
void CConsole::OnUserMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// switch-case文で振り分ける.
	switch (uMsg) {

		// CConsoleCoreからメッセージが送られた時.
		case UM_CONSOLECORECOMMAND:

			// UM_CONSOLECORECOMMANDブロック
			{

				// OnConsoleCoreCommandに任せる.
				OnConsoleCoreCommand(wParam, lParam);	// OnConsoleCoreCommandに任せる.

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// それ以外.
		default:

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

	}

	// 親クラスのユーザメッセージ処理.
	CScalableEditBoxPanel::OnUserMessage(uMsg, wParam, lParam);	// CScalableEditBoxPanel::OnUserMessageに任せる.

}

// CConsoleCoreから送られたメッセージを処理する独自ハンドラ.
int CConsole::OnConsoleCoreCommand(WPARAM wParam, LPARAM lParam) {

	// 変数の宣言
	//tstring tstrCommand;	// コマンド文字列tstring型tstrCommand.
	CCommand *pCommand;	// コマンドオブジェクトポインタpCommand.
	HWND hSrc;	// 送信元ウィンドウハンドルHWND型hSrc.

	// コマンドとソースを取得.
	//tstrCommand = (TCHAR *)wParam;	// wParamをTCHAR *型にキャストしてtstrCommandに格納.
	pCommand = (CCommand *)wParam;		// wParamをCCommand *型にキャストしてpCommandに格納.
	hSrc = (HWND)lParam;	// lParamをHWND型にキャストしてhSrcに格納.

#if 0
	// コマンドと引数のパース.
	LPTSTR next;
	tstring command;
	TCHAR *ptszCommand = new TCHAR[tstrCommand.length() + 1];
	_tcscpy_s(ptszCommand, tstrCommand.length() + 1, tstrCommand.c_str());
	TCHAR *p = _tcstok_s(ptszCommand, _T(" ."), &next);
	command = p;
	delete[] ptszCommand;
#endif

	// コマンドの判別.
	tstring tstrCommandName = pCommand->GetCommandName();	// pCommand->GetCommandNameでコマンド名を取得し, tstrCommandNameに格納.
	if (tstrCommandName == _T("hello")) {	// コマンド"hello".

		// OnHelloに任せる.
		OnHello(hSrc);	// hSrcを引数として渡して, OnHelloを呼ぶ.

	}
	else if (tstrCommandName == _T("list")) {	// コマンド"list"

		// StreamConsoleに投げる.
		SendMessage(m_hProcWnd, UM_STREAMCOMMAND, (WPARAM)pCommand, (LPARAM)m_hWnd);	// UM_STREAMCOMMANDでコマンド文字列をコマンドに対する処理を実行するウィンドウに送信.

	}
	else if (tstrCommandName == _T("walk")) {	// コマンド"walk"

		// OnWalkに任せる.
		OnWalk(hSrc, pCommand);	// OnWalkにpCommandを渡す.

	}
	else if (tstrCommandName == _T("view")) {	// コマンド"view"

		// StreamConsoleに投げる.
		SendMessage(m_hProcWnd, UM_STREAMCOMMAND, (WPARAM)pCommand, (LPARAM)m_hWnd);	// UM_STREAMCOMMANDでコマンド文字列をコマンドに対する処理を実行するウィンドウに送信.

	}
	else {	// コマンドが見つからない.

		// コマンドが見つからないエラー.
		OnErrorCommandNotFound(hSrc);	// hSrcを引数として渡して, OnErrorCommandNotFoundを呼ぶ.

	}

	// 成功なら0を返す.
	return 0;	// 0を返す.

}

// "Hello, world!"を出力する独自ハンドラ.
void CConsole::OnHello(HWND hSrc) {

	// "Hello, world!"を出力.
	SendMessage(hSrc, UM_RESPONSEMESSAGE, (WPARAM)_T("Hello, world!\r\n"), 0);	// UM_RESPONSEMESSAGEで"Hello, world!"を送る.

	// レスポンス終了.
	SendMessage(hSrc, UM_FINISHRESPONSE, 0, 0);	// UM_FINISHRESPONSEを送る.

}

// フォルダ移動する独自ハンドラ.
void CConsole::OnWalk(HWND hSrc, CCommand *pCommand){

	// パスの取得.
	tstring tstrPath = pCommand->GetParam(1);	// 1番目がパスなので, pCommand->GetParam(1)で1番目のパスを取得.
	CConsoleCore *pConsoleCore = (CConsoleCore *)m_pEditBox;	// pConsoleCoreを取り出す.
	if (tstrPath == _T("")) {	// 空文字列の場合.
		tstrPath = pConsoleCore->GetMyDocumentPath(hSrc);	// pConsoleCore->GetMyDocumentPathでマイドキュメントパスを取得し, それをtstrPathに格納.
	}
	else {
		tstring newPath = pConsoleCore->GetFullPath(tstrPath);	// pConsoleCore->GetFullPathでフルパスに変換したものをnewPathに代入.
		tstrPath = newPath;	// newPathをtstrPathに代入.
	}
	pConsoleCore->SetCurrentPath(tstrPath);	// pConsoleCore->SetCurrentPathでtstrPathをセット.
	pConsoleCore->GetOutputFormString();	// pConsoleCore->GetOutputFormStringでフォームの再生成.

	// レスポンス終了.
	SendMessage(hSrc, UM_FINISHRESPONSE, 0, 0);	// UM_FINISHRESPONSEを送る.

}

// コマンドが見つからない時のエラー用独自ハンドラ.
void CConsole::OnErrorCommandNotFound(HWND hSrc) {

	// "Error: Command not found!"を出力.
	SendMessage(hSrc, UM_RESPONSEMESSAGE, (WPARAM)_T("Error: Command not found!\r\n"), 0);	// UM_RESPONSEMESSAGEで"Error: Command not found!"を送る.

	// レスポンス終了.
	SendMessage(hSrc, UM_FINISHRESPONSE, 0, 0);	// UM_FINISHRESPONSEを送る.

}

// コマンドに対する処理を実行するウィンドウのウィンドウハンドルをセットする関数SetProcWindow.
void CConsole::SetProcWindow(HWND hWnd) {

	// メンバにセット.
	m_hProcWnd = hWnd;	// m_hProcWndにhWndをセット.

}