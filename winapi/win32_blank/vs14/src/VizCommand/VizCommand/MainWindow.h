// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"		// ウィンドウクラス
#include "WindowListView.h"	// ウィンドウリストビュークラス
#include "ChildMap.h"	// チャイルドマップクラス

// メインウィンドウクラス
class CMainWindow : public CWindow {	// CWindowの派生クラス

	// publicメンバ
	public:

		// publicメンバ変数
		CWindowListView *m_pWindowListView;	// CWindowListViewオブジェクトポインタm_pWindowListView.
		CChildMap *m_pChildMap;	// CChildMapオブジェクトポインタm_pChildMap.

		// publicメンバ関数
		// メンバ関数
		virtual void Destroy();	// OnCloseとOnDestroyの間に子ウィンドウなどを破棄するメンバ関数Destroy.
		virtual void AddEdit(int index, int x, int y, int w, int h, HINSTANCE hInstance);	// 指定のindexのウィンドウリストアイテムにエディットボックスを追加するメンバ関数AddEdit.
		virtual void DeleteEdit(int index);	// 指定のウィンドウリストアイテムのエディットボックスを削除するメンバ関数DeleteEdit.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.
		virtual void OnDestroy();	// ウィンドウ破棄時のハンドラOnDestroy.
		virtual void OnSize(UINT nType, int cx, int cy);	// ウィンドウのサイズが変更された時のハンドラOnSize.
		virtual int OnClose();	// ウィンドウを閉じる時のハンドラOnClose.

};