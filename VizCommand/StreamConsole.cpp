// ヘッダのインクルード
// 独自のヘッダ
#include "StreamConsole.h"	// ストリームコンソールクラス
#include "StreamConsoleItemsPanel.h"	// ストリームコンソールアイテムズパネルクラス
#include "Console.h"	// コンソールクラス
#include "ListControlPanel.h"	// リストコントロールパネルクラス
#include "BinaryFile.h"	// バイナリファイルクラス
#include "Command.h"	// コマンドクラス

// ウィンドウクラス登録関数RegisterClass
BOOL CStreamConsole::RegisterClass(HINSTANCE hInstance) {

	// ウィンドウリストアイテムズパネルを登録.
	CWindowListItemsPanel::RegisterClass(hInstance);	// 子ウィンドウを登録.

	// ユーザコントロールとして登録.
	return CUserControl::RegisterClass(hInstance, _T("StreamConsole"));	// CUserControl::RegisterClassでウィンドウクラス"StreamConsole"を登録.

}

// コンストラクタCStreamConsole()
CStreamConsole::CStreamConsole() : CWindowListControl() {

	// メンバの初期化
	m_nId = 0;

}

// デストラクタ~CStreamConsole()
CStreamConsole::~CStreamConsole() {

}

// ウィンドウ作成関数Create
BOOL CStreamConsole::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ユーザコントロールで作成.
	return CUserControl::Create(_T("StreamConsole"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Createでウィンドウクラス"StreamConsole"なウィンドウを作成.

}

// ウィンドウ作成時のハンドラOnCreate.
int CStreamConsole::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ペンとブラシの作成.
	m_hPen = (HPEN)CreatePen(PS_SOLID, 1, RGB(0, 0, 0));		// 黒のペンを作成.
	m_hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));		// 黒のブラシを作成.

	// ウィンドウリストアイテムズパネルクラスの作成.
	//m_pWindowListItemsPanel = new CWindowListItemsPanel();	// CWindowListItemsPanelオブジェクトを作成し, ポインタをm_pWindowListItemsPanelに格納.
	m_pWindowListItemsPanel = new CStreamConsoleItemsPanel();	// CStreamConsoleItemsPanelオブジェクトを作成し, ポインタをm_pWindowListItemsPanelに格納.
	m_pWindowListItemsPanel->Create(_T(""), 0, 0, 0, m_iWidth, m_iHeight, hwnd, (HMENU)IDC_WINDOWLISTITEMSPANEL1, lpCreateStruct->hInstance);	// m_pWindowListItemsPanel->Createでウィンドウリストアイテムズパネルを作成.(親ウィンドウより小さめ.)

	// デフォルトアイテムの挿入.
	Insert(_T(""), m_nId, 100, lpCreateStruct->hInstance);	// Insertで0番目にウィンドウを挿入
	// デフォルトアイテムに子ウィンドウをセット.
	CWindowListItem *pItem = m_pWindowListItemsPanel->Get(m_nId);	// 0番目を取得.
	CConsole *pConsole = new CConsole();	// コンソールを生成.
	pConsole->SetProcWindow(hwnd);	// SetProcWindowで処理する場所をセット.
	pConsole->Create(_T(""), 0, 0, 0, pItem->m_iWidth, pItem->m_iHeight, pItem->m_hWnd, (HMENU)IDC_WINDOWLISTITEM_CHILD_ID_START + m_nId, lpCreateStruct->hInstance);	// コンソールのウィンドウを生成.
	pItem->m_mapChildMap.insert(std::make_pair(_T("Console"), pConsole));	// アイテムに子ウィンドウを挿入.
	m_nId++;

	// 成功なので0を返す.
	return 0;

}

// ユーザ定義メッセージが発生した時のハンドラ.
void CStreamConsole::OnUserMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// switch-case文で振り分ける.
	switch (uMsg) {

		// 下へのスクロール要求が送られた時.
		case UM_REQUESTSCROLLBOTTOM:

			// UM_REQUESTSCROLLBOTTOMブロック
			{

				// OnRequestScrollBottomに任せる.
				OnRequestScrollBottom(uMsg, wParam, lParam);	// OnRequestScrollBottomに任せる.

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// CConsoleからCStreamConsole向けコマンドが送られた時.
		case UM_STREAMCOMMAND:

			// UM_STREAMCOMMANDブロック
			{

				// OnStreamCommandに任せる.
				OnStreamCommand(wParam, lParam);	// OnStreamCommandに任せる.

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// それ以外.
		default:

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

	}

}

// 下へのスクロール要求.
void CStreamConsole::OnRequestScrollBottom(UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// スクロール可能になった時.
	if (m_ScrollInfo.nMax > m_ScrollInfo.nPage + 1) {

		// 変数の初期化.
		int iTotalHeight = (int)wParam;

		// スクロール情報取得.
		m_ScrollInfo.fMask = SIF_POS | SIF_RANGE | SIF_PAGE;
		GetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo);

		// iTotalHeightを最大値にして, 位置も一番下にする.
		m_ScrollInfo.nMax = iTotalHeight + PADDING * 2;
		m_ScrollInfo.nPos = m_ScrollInfo.nMax - m_ScrollInfo.nPage;

		// スクロール情報設定.
		SetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo, TRUE);

		// アイテムズパネルの移動.
		m_pWindowListItemsPanel->MoveWindow(1, -m_ScrollInfo.nPos + PADDING);	// m_pWindowListItemsPanel->MoveWindowでy軸だけ変更.

	}

}

// CConsoleからStreamConsole向けコマンドが送られた時の独自ハンドラ.
int CStreamConsole::OnStreamCommand(WPARAM wParam, LPARAM lParam) {

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
	if (tstrCommandName == _T("list")) {	// コマンド"list".

		// OnListに任せる.
		OnList(wParam, lParam);	// OnListに任せる.

	}

	// 成功なので0を返す.
	return 0;

}

// "list"コマンドの独自ハンドラ.
int CStreamConsole::OnList(WPARAM wParam, LPARAM lParam) {

	// 変数の宣言
	//tstring tstrCommand;	// コマンド文字列tstring型tstrCommand.
	HWND hSrc;	// 送信元ウィンドウハンドルHWND型hSrc.
	CCommand *pCommand;	// コマンドオブジェクトポインタpCommand.
	tstring tstrCurrentPath;	// カレントパスtstrCurrentPath.

	// コマンドとソースを取得.
	pCommand = (CCommand *)wParam;	// wParamをCCommand *型にキャストしてpCommandに格納.
	tstring tstrCommandName = pCommand->GetCommandName();	// pCommand->GetCommandNameでコマンド名を取得し, tstrCommandNameに格納.
	hSrc = (HWND)lParam;	// lParamをHWND型にキャストしてhSrcに格納.

	// パスの取得.
	tstring tstrPath = pCommand->GetParam(1);	// 1番目がパスなので, pCommand->GetParam(1)で1番目のパスを取得.
	{	// 一時的にブロックをつくる.
		CWindowListItem *pItem = m_pWindowListItemsPanel->Get(m_nId - 1);	// m_nId - 1番目を取得.
		CConsole *pConsole = (CConsole *)pItem->m_mapChildMap[_T("Console")];	// pConsoleを取り出す.
		CConsoleCore *pConsoleCore = (CConsoleCore *)pConsole->m_pEditBox;	// pConsoleCoreを取り出す.
		tstrCurrentPath = pConsoleCore->GetCurrentPath();	// pConsoleCore->GetCurrentPathをtstrCurrentPathに格納.
		if (tstrPath == _T("")) {	// 空文字列の場合.
			pConsoleCore->GetCurrentPath();	// GetCurrentPathで現在のパスを取得.
			tstrPath = pConsoleCore->m_tstrCurrentPath;	// m_tstrCurrentPathを取り出してtstrPathに格納.
		}
		else {	// 空でない場合は相対パスだった場合に絶対パスに変換する.
			tstring newPath = pConsoleCore->GetFullPath(tstrPath);	// pConsoleCore->GetFullPathでフルパスに変換したものをnewPathに代入.
			tstrPath = newPath;	// newPathをtstrPathに代入.
		}
	}

#if 0
	// コマンドと引数のパース.
	LPTSTR next;
	tstring command;
	tstring pattern;
	tstring path;
	TCHAR *ptszCommand = new TCHAR[tstrCommand.length() + 1];
	_tcscpy_s(ptszCommand, tstrCommand.length() + 1, tstrCommand.c_str());
	TCHAR *p = _tcstok_s(ptszCommand, _T(" ."), &next);
	command = p;
	pattern = next;
	path = next;
	pattern = pattern + _T("\\*");
	delete[] ptszCommand;
#endif

	// 検索パターンの組み立て.
	tstring tstrPattern = tstrPath;
	tstrPattern = tstrPattern + _T("\\*");

	// 次のアイテムの挿入.
	HINSTANCE hInstance = (HINSTANCE)GetWindowLong(m_hWnd, GWL_HINSTANCE);	// インスタンスハンドルを取得.
	Insert(_T(""), m_nId, 300, hInstance);	// Insertで1番目にウィンドウを挿入

	// リストコントロールを作成.
	tstring filename;
	tstring fullpath;
	CWindowListItem *pItem = m_pWindowListItemsPanel->Get(m_nId);	// 1番目を取得.
	CListControlPanel *pListControlPanel = new CListControlPanel();	// リストコントロールパネルを生成.
	pListControlPanel->Create(_T(""), 0, 0, 0, pItem->m_iWidth, pItem->m_iHeight, pItem->m_hWnd, (HMENU)IDC_WINDOWLISTITEM_CHILD_ID_START + m_nId, hInstance);	// リストコントロールパネルのウィンドウを生成.
	CBinaryFile *pBinaryFile = new CBinaryFile();	// CBinaryFileオブジェクトを作成し, pBinaryFileにポインタを格納.
	if (pBinaryFile->FindFirstFile(tstrPattern.c_str()) == INVALID_HANDLE_VALUE) {
		delete pBinaryFile;	// 削除.
		return -1;
	}
	filename = pBinaryFile->m_wfdFindData.cFileName;
	fullpath = tstrPath + _T("\\");
	fullpath = fullpath + filename;
	SHFILEINFO sfi;
	LV_ITEM item;
	HIMAGELIST hImageList = ImageList_Create(32, 32, ILC_COLOR24, 24, 0);
	ListView_SetImageList(pListControlPanel->m_pListControl->m_hWnd, hImageList, LVSIL_NORMAL);
	int i = 0;
	while (true) {
		if (!pBinaryFile->FindNextFile()) {
			break;
		}
		filename = pBinaryFile->m_wfdFindData.cFileName;
		fullpath = tstrPath + _T("\\");
		fullpath = fullpath + filename;
		if (filename != _T(".") && filename != _T("..")) {
			::SHGetFileInfo(fullpath.c_str(), 0, &sfi, sizeof(SHFILEINFO), SHGFI_ICON | SHGFI_LARGEICON);
			ImageList_AddIcon(hImageList, sfi.hIcon);
			ListView_SetImageList(pListControlPanel->m_pListControl->m_hWnd, hImageList, LVSIL_NORMAL);
			item.mask = LVIF_TEXT | LVIF_IMAGE;
			TCHAR t[1024];
			_tcscpy_s(t, filename.c_str());
			item.pszText = t;
			item.iItem = i;
			item.iSubItem = 0;
			item.iImage = i;
			ListView_InsertItem(pListControlPanel->m_pListControl->m_hWnd, &item);
			i++;
		}
	}
	pBinaryFile->FindClose();
	delete pBinaryFile;	// 削除.
	pItem->m_mapChildMap.insert(std::make_pair(_T("ListControlPanel"), pListControlPanel));	// アイテムに子ウィンドウを挿入.
	m_nId++;

	// デフォルトアイテムの挿入.
	Insert(_T(""), m_nId, 100, hInstance);	// Insertで0番目にウィンドウを挿入
	// デフォルトアイテムに子ウィンドウをセット.
	CWindowListItem *pItem2 = m_pWindowListItemsPanel->Get(m_nId);	// 0番目を取得.
	CConsole *pConsole = new CConsole(tstrCurrentPath);	// コンソールを生成.
	pConsole->SetProcWindow(m_hWnd);	// SetProcWindowで処理する場所をセット.
	pConsole->Create(_T(""), 0, 0, 0, pItem2->m_iWidth, pItem2->m_iHeight, pItem2->m_hWnd, (HMENU)IDC_WINDOWLISTITEM_CHILD_ID_START + m_nId, hInstance);	// コンソールのウィンドウを生成.
	pItem2->m_mapChildMap.insert(std::make_pair(_T("Console"), pConsole));	// アイテムに子ウィンドウを挿入.
	m_nId++;

	// 成功なのでTRUEを返す.
	return 0;

}