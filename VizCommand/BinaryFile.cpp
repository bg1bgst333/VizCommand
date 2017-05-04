// ヘッダのインクルード
// 独自のヘッダ
#include "BinaryFile.h"	// バイナリファイルクラス

// "開く"のファイルダイアログを表示し, 選択されたファイル名を取得するメンバ関数GetOpenFileName.(スタティックメンバ関数.)
BOOL CBinaryFile::GetOpenFileName(LPTSTR lptszFileName, int nMax, LPCTSTR lpctszFilter, HWND hWnd, LPTSTR lptszExtension) {

	// 変数の初期化
	OPENFILENAME ofn = { 0 };							// OPENFILENAME構造体変数ofnを0で初期化.
	TCHAR tszFilter[1024] = { 0 };						// tszFilterを0で初期化.

	// ofnの設定
	ofn.lStructSize = sizeof(OPENFILENAME);				// OPENFILENAME構造体のサイズをセット.
	ofn.hwndOwner = hWnd;								// 指定されたhWndをセット.
	int len = _tcslen(lpctszFilter);					// lpctszFilterの長さを取得.
	_tcscpy_s(tszFilter, 1024, lpctszFilter);			// lpctszFilterをtszFilterにコピー.
	for (int i = len - 1; i >= 0; i--) {				// 後ろから'|'を'\0'に置き換える.
		if (tszFilter[i] == FITLER_DELIMITER_CHAR) {	// '|'だった場合.
			tszFilter[i] = _T('\0');					// tszFilter[i]に'|'を代入.
		}
	}
	ofn.lpstrFilter = tszFilter;						// tszFilterをセット.
	ofn.lpstrFile = lptszFileName;						// 指定されたlpctszFileNameをセット.
	ofn.nMaxFile = nMax;								// 指定されたnMaxをセット.
	ofn.Flags = OFN_FILEMUSTEXIST;						// ファイルが存在しないと決定できない.

	// "開く"ファイルダイアログの表示.
	if (!::GetOpenFileName(&ofn)) {						// GetOpenFileNameで"開く"ファイルダイアログを表示.

		// 選択しなかった場合.
		return FALSE;	// FALSEを返す.

	}

	// 拡張子を取得.
	_tcscpy_s(lptszExtension, 16, PathFindExtension(lptszFileName));	// PathFindExtensionで取得した拡張子をlptszExtensionにコピー.

	// 選択した場合.
	return TRUE;		// TRUEを返す.

}

// コンストラクタCBinaryFile()
CBinaryFile::CBinaryFile() {

	// メンバ変数の初期化
	m_hFile = NULL;	// m_hFileをNULLで初期化.
	m_pByte = NULL;	// m_pByteをNULLで初期化.
	ZeroMemory(m_tszFileName, sizeof(TCHAR) * 1024);	// ZeroMemoryでm_tszFileNameを0で埋める.
	m_hFind = INVALID_HANDLE_VALUE;	// INVALID_HANDLE_VALUEで初期化.

}

// デストラクタ~CBinaryFile()
CBinaryFile::~CBinaryFile() {

	// メンバ変数の終了処理
	FindClose();	// FindCloseで閉じる.
	ZeroMemory(m_tszFileName, sizeof(TCHAR) * 1024);	// ZeroMemoryでm_tszFileNameを0で埋める.
	if (m_pByte != NULL) {	// NULLでなければ.
		delete[] m_pByte;	// deleteでm_pByteを解放.
		m_pByte = NULL;		// m_pByteにNULLをセット.
	}
	if (m_hFile != NULL) {	// NULLでなければ.
		Close();			// 閉じる.
		m_hFile = NULL;		// m_hFileにNULLをセット.
	}

}

// ファイルの作成およびファイルを開く操作を行うメンバ関数Open.
BOOL CBinaryFile::Open(LPCTSTR lpctszFileName, DWORD dwDesiredAccess, DWORD dwCreationDisposition) {

	// ファイル名をメンバにセット.
	_tcscpy_s(m_tszFileName, 1024, lpctszFileName);	// _tcscpy_sで引数をメンバにコピー.(第2引数はWORD単位でのサイズ.)

	// ファイルを開く.
	m_hFile = CreateFile(m_tszFileName, dwDesiredAccess, 0, NULL, dwCreationDisposition, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFileでファイルm_tszFileNameを開く.
	if (m_hFile == INVALID_HANDLE_VALUE) {	// 失敗.
		return FALSE;	// FALSEを返す.
	}

	// 成功
	return TRUE;	// TRUEを返す.

}

// ファイルを閉じるメンバ関数Close.
void CBinaryFile::Close() {

	// ファイルを閉じる.
	CloseHandle(m_hFile);	// CloseHandleでm_hFileを閉じる.
	m_hFile = NULL;	// NULLをセット.

}

// ファイルを書き込むメンバ関数Write.(pBytesは外部でバッファを持っている場合の書き込み対象バイト列.)
BOOL CBinaryFile::Write(BYTE * pBytes, UINT nCount) {

	// 変数の初期化
	DWORD dwBytes = 0;	// DWORD型dwBytesを0で初期化.

	// pBytesを書き込む.
	return WriteFile(m_hFile, pBytes, nCount, &dwBytes, NULL);	// WriteFileでpBytesの内容を書き込む.

}

// "名前を付けて保存"のファイルダイアログを表示し, 選択されたファイル名を取得するメンバ関数GetSaveFileName.
BOOL CBinaryFile::GetSaveFileName(LPTSTR lptszFileName, int nMax, LPCTSTR lpctszFilter, HWND hWnd) {

	// 変数の初期化
	OPENFILENAME ofn = { 0 };							// OPENFILENAME構造体変数ofnを0で初期化.
	TCHAR tszFilter[1024] = { 0 };						// tszFilterを0で初期化.

	// ofnの設定
	ofn.lStructSize = sizeof(OPENFILENAME);				// OPENFILENAME構造体のサイズをセット.
	ofn.hwndOwner = hWnd;								// 指定されたhWndをセット.
	int len = _tcslen(lpctszFilter);					// lpctszFilterの長さを取得.
	_tcscpy_s(tszFilter, 1024, lpctszFilter);			// lpctszFilterをtszFilterにコピー.
	for (int i = len - 1; i >= 0; i--) {				// 後ろから'|'を'\0'に置き換える.
		if (tszFilter[i] == FITLER_DELIMITER_CHAR) {	// '|'だった場合.
			tszFilter[i] = _T('\0');					// tszFilter[i]に'|'を代入.
		}
	}
	ofn.lpstrFilter = tszFilter;						// tszFilterをセット.
	ofn.lpstrFile = lptszFileName;						// 指定されたlpctszFileNameをセット.
	ofn.nMaxFile = nMax;								// 指定されたnMaxをセット.
	ofn.Flags = OFN_OVERWRITEPROMPT;					// 上書き時のメッセージボックス表示.

	// "名前を付けて保存"ファイルダイアログの表示.
	if (!::GetSaveFileName(&ofn)) {						// GetSaveFileNameで"名前を付けて保存"ファイルダイアログを表示.

		// 選択しなかった場合.
		return FALSE;	// FALSEを返す.

	}

	// 選択した場合.
	return TRUE;		// TRUEを返す.

}

// ファイルを読み込むメンバ関数Read.(pBytesは外部でバッファを持っている場合のバッファへのポインタ.)
BOOL CBinaryFile::Read(BYTE * pBytes, UINT nCount) {

	// 変数の初期化
	DWORD dwBytes = 0;	// DWORD型dwBytesを0で初期化.

	// pBytesを読み込む.
	return ReadFile(m_hFile, pBytes, nCount, &dwBytes, NULL);	// ReadFileでpBytesに内容を読み込む.

}

// "開く"のファイルダイアログを表示し, 選択されたファイル名を取得するメンバ関数GetOpenFileName.
BOOL CBinaryFile::GetOpenFileName(LPTSTR lptszFileName, int nMax, LPCTSTR lpctszFilter, HWND hWnd) {

	// 変数の初期化
	OPENFILENAME ofn = { 0 };							// OPENFILENAME構造体変数ofnを0で初期化.
	TCHAR tszFilter[1024] = { 0 };						// tszFilterを0で初期化.

	// ofnの設定
	ofn.lStructSize = sizeof(OPENFILENAME);				// OPENFILENAME構造体のサイズをセット.
	ofn.hwndOwner = hWnd;								// 指定されたhWndをセット.
	int len = _tcslen(lpctszFilter);					// lpctszFilterの長さを取得.
	_tcscpy_s(tszFilter, 1024, lpctszFilter);			// lpctszFilterをtszFilterにコピー.
	for (int i = len - 1; i >= 0; i--) {				// 後ろから'|'を'\0'に置き換える.
		if (tszFilter[i] == FITLER_DELIMITER_CHAR) {	// '|'だった場合.
			tszFilter[i] = _T('\0');					// tszFilter[i]に'|'を代入.
		}
	}
	ofn.lpstrFilter = tszFilter;						// tszFilterをセット.
	ofn.lpstrFile = lptszFileName;						// 指定されたlpctszFileNameをセット.
	ofn.nMaxFile = nMax;								// 指定されたnMaxをセット.
	ofn.Flags = OFN_FILEMUSTEXIST;						// ファイルが存在しないと決定できない.

	// "開く"ファイルダイアログの表示.
	if (!::GetOpenFileName(&ofn)) {						// GetOpenFileNameで"開く"ファイルダイアログを表示.

		// 選択しなかった場合.
		return FALSE;	// FALSEを返す.

	}

	// 選択した場合.
	return TRUE;		// TRUEを返す.

}

// ファイルサイズの取得関数GetFileSize.
DWORD CBinaryFile::GetFileSize(LPDWORD lpHigh) {

	// ファイルサイズの取得.
	return ::GetFileSize(m_hFile, lpHigh);	// WindowsAPIのGetFileSizeでサイズを取得し, それを返す.

}

// 最初のファイル検索関数FindFirstFile.
HANDLE CBinaryFile::FindFirstFile(LPCTSTR lpctszFileName) {

	// 最初のファイルを検索.
	m_hFind = ::FindFirstFile(lpctszFileName, &m_wfdFindData);	// WindowsAPIのFindFirstFileでlpctszFileNameの条件に合う最初のハンドルを取得.
	return m_hFind;	// 検索ハンドルを返す.

}

// 次のファイル検索関数FindNextFile.
BOOL CBinaryFile::FindNextFile() {

	// 次のファイルを検索.
	return ::FindNextFile(m_hFind, &m_wfdFindData);	// WindowsAPIのFindNextFileで次のファイル情報を取得.

}

// 検索ハンドルを閉じる関数FindClose.
BOOL CBinaryFile::FindClose() {

	// 変数の初期化.
	BOOL bRet = FALSE;

	// ハンドルを閉じる.
	if (m_hFind != INVALID_HANDLE_VALUE) {
		bRet = ::FindClose(m_hFind);
		m_hFind = INVALID_HANDLE_VALUE;	// INVALID_HANDLE_VALUEで初期化.
	}

	// bRetを返す.
	return bRet;

}