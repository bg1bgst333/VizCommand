// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <shlwapi.h>		// シェルAPI

// マクロの定義
#define FITLER_DELIMITER _T("|")
#define FITLER_DELIMITER_CHAR _T('|')
#define FILTER_END  _T("||")
#define FILTER_TEXT_BIN_FILE _T("バイナリファイル(*.bin)")
#define FILTER_RULE_BIN_FILE _T("*.bin")
#define FILTER_TEXT_ALL_FILE _T("すべてのファイル(*.*)")
#define FILTER_RULE_ALL_FILE _T("*.*")

// バイナリファイルクラスCBinaryFile
class CBinaryFile {

	// publicメンバ
	public:

		// publicメンバ変数
		TCHAR m_tszFileName[1024];	// ファイル名TCHAR型配列m_tszFileName
		HANDLE m_hFile;	// ファイルハンドルHANDLE型m_hFile
		BYTE *m_pByte;	// バイナリデータへのポインタBYTE *型m_pByte
		HANDLE m_hFind;	// ファイル検索ハンドルHANDLE型m_hFind
		WIN32_FIND_DATA m_wfdFindData;	// 検索データWIN32_FIND_DATA型m_wfdFindData

		// publicメンバ関数
		// スタティックメンバ関数
		static BOOL GetOpenFileName(LPTSTR lptszFileName, int nMax, LPCTSTR lpctszFilter, HWND hWnd, LPTSTR lptszExtension);	// "開く"のファイルダイアログを表示し, 選択されたファイル名を取得するメンバ関数GetOpenFileName.(スタティックメンバ関数.lptszExtensionに拡張子を返す.)

		// コンストラクタ・デストラクタ
		CBinaryFile();	// コンストラクタCBinaryFile()
		virtual ~CBinaryFile();	// デストラクタ~CBinaryFile()

		// メンバ関数
		BOOL Open(LPCTSTR lpctszFileName, DWORD dwDesiredAccess, DWORD dwCreationDisposition);	// ファイルの作成およびファイルを開く操作を行うメンバ関数Open.
		void Close();	// ファイルを閉じるメンバ関数Close.
		BOOL Write(BYTE *pBytes, UINT nCount);	// ファイルを書き込むメンバ関数Write.(pBytesは外部でバッファを持っている場合の書き込み対象バイト列.)
		BOOL GetSaveFileName(LPTSTR lptszFileName, int nMax, LPCTSTR lpctszFilter, HWND hWnd);	// "名前を付けて保存"のファイルダイアログを表示し, 選択されたファイル名を取得するメンバ関数GetSaveFileName.
		BOOL Read(BYTE *pBytes, UINT nCount);	// ファイルを読み込むメンバ関数Read.(pBytesは外部でバッファを持っている場合のバッファへのポインタ.)
		BOOL GetOpenFileName(LPTSTR lptszFileName, int nMax, LPCTSTR lpctszFilter, HWND hWnd);	// "開く"のファイルダイアログを表示し, 選択されたファイル名を取得するメンバ関数GetOpenFileName.
		DWORD GetFileSize(LPDWORD lpHigh);	// ファイルサイズの取得関数GetFileSize.
		HANDLE FindFirstFile(LPCTSTR lpctszFileName);	// 最初のファイル検索関数FindFirstFile.
		BOOL FindNextFile();	// 次のファイル検索関数FindNextFile.
		BOOL FindClose();	// 検索ハンドルを閉じる関数FindClose.

};