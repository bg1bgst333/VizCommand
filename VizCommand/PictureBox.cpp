// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "PictureBox.h"	// ピクチャーボックスクラス

// コンストラクタCPictureBox()
CPictureBox::CPictureBox() {

	// 初期化
	m_hBitmap = NULL;		// m_hBitmapにNULLをセット.
	m_hMemDC = NULL;		// m_hMemDCにNULLをセット.
	m_iPictureWidth = 0;	// m_iPictureWidthに0をセット.
	m_iPictureHeight = 0;	// m_iPictureHeightに0をセット.

}

// デストラクタ~CPictureBox()
CPictureBox::~CPictureBox() {

	// 終了処理
	m_iPictureHeight = 0;	// m_iPictureHeightに0をセット.
	m_iPictureWidth = 0;	// m_iPictureWidthに0をセット.
	if (m_hMemDC != NULL) {
		DeleteDC(m_hMemDC);			// DelteDCでm_hMemDCを削除.
		m_hMemDC = NULL;			// m_hMemDCにNULLをセット.
	}
	if (m_hBitmap != NULL) {
		DeleteObject(m_hBitmap);	// DeleteObjectでm_hBitmapを削除.
		m_hBitmap = NULL;			// m_hBitmapにNULLをセット.
	}

}

// ウィンドウ作成関数Create(lpctszClassName省略)
BOOL CPictureBox::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウの作成.
	return CCustomControl::Create(_T("Static"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CCustomControl::Createでウィンドウを作成し, その戻り値をreturnで返す.

}

// 画像をロードする関数Load.
BOOL CPictureBox::Load(LPCTSTR lpctszFileName, int iWidth, int iHeight) {

	// 変数の宣言・初期化.
	HINSTANCE hInstance;	// アプリケーションインスタンスハンドルhInstance.
	BITMAP bitmap = { 0 };	// BITMAP構造体変数bitmap.

	// 幅と高さをメンバにセット.
	m_iPictureWidth = iWidth;	// m_iPictureWidthにiWidthをセット.
	m_iPictureHeight = iHeight;	// m_iPictureHeightにiHeightをセット.

	// インスタンスハンドルの取得.
	hInstance = (HINSTANCE)GetWindowLong(m_hWnd, GWLP_HINSTANCE);	// GetWindowLongでインスタンスハンドルを取得.

	// 画像のロード.(ひとまずビットマップのみ.)
	m_hBitmap = (HBITMAP)LoadImage(hInstance, lpctszFileName, IMAGE_BITMAP, m_iPictureWidth, m_iPictureHeight, LR_LOADFROMFILE);	// LoadImageでビットマップをロード.
	if (m_hBitmap == NULL) {	// NULLなら.

		// 失敗.
		return FALSE;	// 失敗なのでFALSEを返す.

	}

	// 画像から幅と高さを取得.
	GetObject(m_hBitmap, sizeof(BITMAP), &bitmap);	// GetObjectでビットマップ情報を取得.
	m_iPictureWidth = bitmap.bmWidth;	// m_iPictureWidthにbitmap.bmWidthをセット.
	m_iPictureHeight = bitmap.bmHeight;	// m_iPictureHeightにbitmap.bmHeightをセット.

	// 成功.
	return TRUE;	// 成功なのでTRUEを返す.

}

// 画像をセット(表示)する関数SetImage.
void CPictureBox::SetImage() {

	// 変数の宣言
	HDC hDC;	// デバイスコンテキストハンドルHDC型hDC.

	// デバイスコンテキストの取得.
	hDC = GetDC(m_hWnd);	// GetDCでデバイスコンテキストを取得.

	// メモリデバイスコンテキストの作成.
	m_hMemDC = CreateCompatibleDC(hDC);	// CreateCompatibleDCでメモリデバイスコンテキスト作成.

	// 画像をセットする.
	SendMessage(m_hWnd, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)m_hBitmap);	// SendMessageでSTM_SETIMAGEを送信することでm_hBitmapをセットする.

	// スクロールバーの位置(メンバ)の初期化.
	m_iHScrollPos = 0;
	m_iVScrollPos = 0;

	// デバイスコンテキストの解放.
	ReleaseDC(m_hWnd, hDC);	// ReleaseDCでデバイスコンテキスト解放.

}

// ウィンドウの描画を要求された時のハンドラOnPaint.
void CPictureBox::OnPaint() {

	// 変数の宣言
	HDC hDC;			// デバイスコンテキストハンドルHDC型hDC.
	PAINTSTRUCT ps;		// PAINTSTRUCT構造体変数ps.
	HBITMAP hOld;		// 以前のビットマップハンドルhOld.
	int iDrawWidth;		// 実際の描画幅.
	int iDrawHeight;	// 実際の描画高さ.

	// 描画開始.
	hDC = BeginPaint(m_hWnd, &ps);	// BeginPaintで描画開始.

	// ビットマップの選択.
	hOld = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);	// SelectObjectでm_hBitmapを選択.

	// ビット転送による描画.
	iDrawWidth = m_iWidth - SCROLLBAR_THICKNESS;	// 実際にはコントロール幅 - スクロールバーの厚さ.
	iDrawHeight = m_iHeight - SCROLLBAR_THICKNESS;	// 実際にはコントロール高さ - スクロールバーの厚さ.
	BitBlt(hDC, 0, 0, iDrawWidth, iDrawHeight, m_hMemDC, m_iHScrollPos, m_iVScrollPos, SRCCOPY);	// BitBltでm_hMemDCからhDCにビット転送することで描画される.

	// 古いビットマップを再選択して戻す.
	SelectObject(m_hMemDC, hOld);	// SelectObjectでhOldを選択.

	// スクロールバー設定.
	// 横
	ZeroMemory(&m_ScrollInfo, sizeof(SCROLLINFO));
	m_ScrollInfo.cbSize = sizeof(SCROLLINFO);	// サイズをセット.
	m_ScrollInfo.fMask = SIF_PAGE | SIF_RANGE;	// フラグをセット.
	m_ScrollInfo.nPage = iDrawWidth;	// 幅をセット.
	m_ScrollInfo.nMin = 0;	// 最小値をセット.
	m_ScrollInfo.nMax = m_iPictureWidth;	// 最大値をセット.
	SetScrollInfo(m_hWnd, SB_HORZ, &m_ScrollInfo, FALSE);	// SetScrollInfoでセット.
	// 縦
	ZeroMemory(&m_ScrollInfo, sizeof(SCROLLINFO));
	m_ScrollInfo.cbSize = sizeof(SCROLLINFO);	// サイズをセット.
	m_ScrollInfo.fMask = SIF_PAGE | SIF_RANGE;	// フラグをセット.
	m_ScrollInfo.nPage = iDrawHeight;	// 高さをセット.
	m_ScrollInfo.nMin = 0;	// 最小値をセット.
	m_ScrollInfo.nMax = m_iPictureHeight;	// 最大値をセット.
	SetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo, FALSE);	// SetScrollInfoでセット.

	// 描画終了.
	EndPaint(m_hWnd, &ps);	// EndPaintで描画終了.

}

// 水平方向スクロールバーイベント時のハンドラOnHScroll.
void CPictureBox::OnHScroll(UINT nSBCode, UINT nPos) {

	// スクロール情報取得.
	m_ScrollInfo.fMask = SIF_POS;	// 位置だけ変更モード(これがないと, スクロールバーが元の位置に戻ってしまうので注意!こっちが前!)
	GetScrollInfo(m_hWnd, SB_HORZ, &m_ScrollInfo);	// マスクを設定してからGetScrollInfo.(こっちが後!)

	// スクロールバー処理.
	switch (nSBCode) {	// nSBCodeごとに振り分け.

		// 一番左
		case SB_LEFT:

			// 位置を最小値に.
			m_ScrollInfo.nPos = m_ScrollInfo.nMin;
			break;

		// 一番右
		case SB_RIGHT:

			// 位置を最大値に.
			m_ScrollInfo.nPos = m_ScrollInfo.nMax;
			break;

		// 1列左
		case SB_LINELEFT:

			// nPosが0でなければデクリメント.
			if (m_ScrollInfo.nPos > 0) {
				m_ScrollInfo.nPos--;
			}
			break;

		// 1列右
		case SB_LINERIGHT:

			// nPosが最大値-1でなければインクリメント.
			if (m_ScrollInfo.nPos < m_ScrollInfo.nMax - 1) {
				m_ScrollInfo.nPos++;
			}
			break;

		// 1ページ左
		case SB_PAGELEFT:

			// nPage分減らす.
			m_ScrollInfo.nPos -= m_ScrollInfo.nPage;
			break;

		// 1ページ右
		case SB_PAGERIGHT:

			// nPage分増やす.
			m_ScrollInfo.nPos += m_ScrollInfo.nPage;
			break;

		// つまみをドラッグ中.
		case SB_THUMBTRACK:

			// 引数のnPosをセット
			m_ScrollInfo.nPos = nPos;
			break;

		// つまみをドラッグ後.
		case SB_THUMBPOSITION:

			// 引数のnPosをセット
			m_ScrollInfo.nPos = nPos;
			break;

		// それ以外.
		default:

			break;

	}

	// スクロール情報設定.
	SetScrollInfo(m_hWnd, SB_HORZ, &m_ScrollInfo, TRUE);
	// メンバにもセット.
	m_iHScrollPos = m_ScrollInfo.nPos;
	// 無効領域を作成して画面の更新.
	InvalidateRect(m_hWnd, NULL, TRUE);	// InvalidateRectで無効領域作成.

}

// 垂直方向スクロールバーイベント時のハンドラOnVScroll.
void CPictureBox::OnVScroll(UINT nSBCode, UINT nPos) {

	// スクロール情報取得.
	m_ScrollInfo.fMask = SIF_POS;	// 位置だけ変更モード(これがないと, スクロールバーが元の位置に戻ってしまうので注意!こっちが前!)
	GetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo);	// マスクを設定してからGetScrollInfo.(こっちが後!)

	// スクロールバー処理.
	switch (nSBCode) {	// nSBCodeごとに振り分け.

		// 一番上
		case SB_TOP:

			// 位置を最小値に.
			m_ScrollInfo.nPos = m_ScrollInfo.nMin;
			break;

		// 一番下
		case SB_BOTTOM:

			// 位置を最大値に.
			m_ScrollInfo.nPos = m_ScrollInfo.nMax;
			break;

		// 1行上
		case SB_LINEUP:

			// nPosが0でなければデクリメント.
			if (m_ScrollInfo.nPos > 0) {
				m_ScrollInfo.nPos--;
			}
			break;

		// 1行下
		case SB_LINEDOWN:

			// nPosが最大値-1でなければインクリメント.
			if (m_ScrollInfo.nPos < m_ScrollInfo.nMax - 1) {
				m_ScrollInfo.nPos++;
			}
			break;

		// 1ページ上
		case SB_PAGEUP:

			// nPage分減らす.
			m_ScrollInfo.nPos -= m_ScrollInfo.nPage;
			break;

		// 1ページ下
		case SB_PAGEDOWN:

			// nPage分増やす.
			m_ScrollInfo.nPos += m_ScrollInfo.nPage;
			break;

		// つまみをドラッグ中.
		case SB_THUMBTRACK:

			// 引数のnPosをセット
			m_ScrollInfo.nPos = nPos;
			break;

		// つまみをドラッグ後.
		case SB_THUMBPOSITION:

			// 引数のnPosをセット
			m_ScrollInfo.nPos = nPos;
			break;

		// それ以外.
		default:

			break;

	}

	// スクロール情報設定.
	SetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo, TRUE);
	// メンバにもセット.
	m_iVScrollPos = m_ScrollInfo.nPos;
	// 無効領域を作成して画面の更新.
	InvalidateRect(m_hWnd, NULL, TRUE);	// InvalidateRectで無効領域作成.

}