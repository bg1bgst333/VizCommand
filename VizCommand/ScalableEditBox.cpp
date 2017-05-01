// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "ScalableEditBox.h"	// スカラブルエディットボックスクラス

// コンストラクタCScalableEditBox()
CScalableEditBox::CScalableEditBox() : CEditBox() {

	// 初期化.
	m_iLineHeight = 0;	// 1行分の高さを0に初期化.
	m_iLineCount = 0;	// 行数を0に初期化.

}

// デストラクタ~CScalableEditBox()
CScalableEditBox::~CScalableEditBox() {

	// 終了処理.
	m_iLineHeight = 0;	// 1行分の高さを0にセット.
	m_iLineCount = 0;	// 行数を0にセット.

}

// ウィンドウ作成時のハンドラOnCreate.
int CScalableEditBox::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// 変数の宣言
	HDC hDC;		// デバイスコンテキストハンドルHDC型hDC.
	HFONT hFont;	// フォントハンドルHFONT型hFont.
	HFONT hOldFont;	// 選択前のフォントハンドルHFONT型hOldFont.
	TEXTMETRIC tm;	// フォント情報を持つTEXTMETRIC構造体変数tm.

	// 高さの調整
	hDC = GetDC(hwnd);	// GetDCでデバイスコンテキストハンドルを取得.
	hFont = (HFONT)SendMessage(hwnd, WM_GETFONT, 0, 0);	// SendMessageにWM_GETFONTを指定してフォントハンドルhFontを取得し, hFontに格納.
	hOldFont = (HFONT)SelectObject(hDC, hFont);	// SelectObjectでhFontを選択.
	GetTextMetrics(hDC, &tm);	// GetTextMetricsでフォント情報を取得し, tmに格納.
	m_iLineHeight = tm.tmHeight;	// 1行分の高さをフォントの高さにする.
	SelectObject(hDC, hOldFont);	// フォントを元に戻す.
	ReleaseDC(hwnd, hDC);	// ReleaseDCでデバイスコンテキストをリリース.

	// ウィンドウのリサイズ
	MoveWindow(3, m_iLineHeight);	// MoveWindowで高さを1行分のm_iLineHeightにする.

	// UM_SIZECHILDで子ウィンドウのサイズに合わせる.
	WPARAM wParam;
	wParam = MAKEWPARAM(m_iWidth, m_iHeight);
	SendMessage(GetParent(m_hWnd), UM_SIZECHILD, wParam, (LPARAM)m_hWnd);

	// 行数のセット.
	m_iLineCount = 1;	// 1行分はできたのでm_iLineCountに1をセット.

	// 成功なので0を返す.
	return 0;

}

// キーが押された時のハンドラOnKeyDown.
void CScalableEditBox::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {

	// リターン, バックスペースの時の動作.
	if (nChar == VK_RETURN) {		// VK_RETURNの時.

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

	}
	else if (nChar == VK_BACK) {	// VK_BACKの時.

		// 変数の宣言
		POINT pt;		// 座標POINT型pt.
		DWORD dwPos;	// HIWORDは行の何番目, LOWORDはエディットボックスの総文字数となるDWORD型dwPos.
		WORD wRow;		// 行.
		WORD wAllLen;	// 総文字数.
		WORD wRowStart;	// エディットボックスの1行目の先頭からキャレットのある行の先頭までの文字数.
		WORD wCol;		// 列.
		int iHeight;	// 新しい高さiHeight.

		// バックスペースで行が減ったら小さくする.
		GetCaretPos(&pt);	// キャレットの位置を座標で取得.
		dwPos = (DWORD)SendMessage(m_hWnd, EM_CHARFROMPOS, 0, MAKELPARAM(pt.x, pt.y));	// EM_CHARFROMPOSで座標を行と列に変換.
		wRow = HIWORD(dwPos);	// 行を取り出す.
		wAllLen = LOWORD(dwPos);	// 総文字数を取り出す.
		wRowStart = (WORD)SendMessage(m_hWnd, EM_LINEINDEX, wRow, 0);	// EM_LINEINDEXでキャレット行の先頭までの文字数を取得.
		wCol = wAllLen - wRowStart;	// 総文字数からキャレット行の先頭までの文字数を引いて, ようやく何列目かがわかる.
		if (wCol == 0) {	// 列が先頭の場合.
			if (wRow > 0) {	// 行が先頭でない場合.

				// 1行分小さくする.
				iHeight = m_iHeight - m_iLineHeight;	// 新しい高さiHeightはm_iHeightからm_iLineHeightを引いたものにする.
				MoveWindow(3, iHeight);	// MoveWindowで高さを新しいiHeightにする.
				m_iLineCount--;	// m_iLineCountを減らす.

				// UM_SIZECHILDで子ウィンドウのサイズに合わせる.
				WPARAM wParam;
				wParam = MAKEWPARAM(m_iWidth, m_iHeight);
				SendMessage(GetParent(m_hWnd), UM_SIZECHILD, wParam, (LPARAM)m_hWnd);

			}
		}

	}

}

// ウィンドウサイズが変更された時のハンドラOnSize.
void CScalableEditBox::OnSize(UINT nType, int cx, int cy) {

	// 実際のウィンドウサイズを格納.
	m_iWidth = cx;	// m_iWidthにcxをセット.
	m_iHeight = cy;	// m_iHeightにcyをセット.

	// UM_SIZECHILDで子ウィンドウのサイズに合わせる.
	//WPARAM wParam;
	//wParam = MAKEWPARAM(m_iWidth, m_iHeight);
	//SendMessage(GetParent(m_hWnd), UM_SIZECHILD, wParam, (LPARAM)m_hWnd);

}