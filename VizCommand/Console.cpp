// ヘッダのインクルード
// 独自のヘッダ
#include "Console.h"	// コンソールクラス

// ウィンドウクラス登録関数RegisterClass
BOOL CConsole::RegisterClass(HINSTANCE hInstance) {

	// ユーザコントロールとして登録.
	return CUserControl::RegisterClass(hInstance, _T("Console"));	// CUserControl::RegisterClassでウィンドウクラス"Console"を登録.

}

// コンストラクタ・デストラクタ
CConsole::CConsole() : CScalableEditBoxPanel() {

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
	tstring tstrCommand;	// コマンド文字列tstring型tstrCommand.
	HWND hSrc;	// 送信元ウィンドウハンドルHWND型hSrc.

	// コマンドとソースを取得.
	tstrCommand = (TCHAR *)wParam;	// wParamをTCHAR *型にキャストしてtstrCommandに格納.
	hSrc = (HWND)lParam;	// lParamをHWND型にキャストしてhSrcに格納.

	// コマンドの判別.
	if (tstrCommand == _T("hello")) {	// コマンド"hello".

		// OnHelloに任せる.
		OnHello(hSrc);	// hSrcを引数として渡して, OnHelloを呼ぶ.

	}

	// 成功なら0を返す.
	return 0;	// 0を返す.

}

// "Hello, world!"を出力する独自ハンドラ.
void CConsole::OnHello(HWND hSrc) {

	// "Hello, world!"を出力.
	SendMessage(hSrc, UM_RESPONSEMESSAGE, (WPARAM)_T("Hello, world!"), 0);	// UM_RESPONSEMESSAGEで"Hello, world!"を送る.

	// レスポンス終了.
	SendMessage(hSrc, UM_FINISHRESPONSE, 0, 0);	// UM_FINISHRESPONSEを送る.

}