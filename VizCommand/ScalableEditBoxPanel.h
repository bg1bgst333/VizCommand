// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "EditBoxPanel.h"		// エディットボックスパネルクラス
#include "ScalableEditBox.h"	// スカラブルエディットボックスクラス

// スカラブルエディットボックスパネルクラスCScalableEditBoxPanel
class CScalableEditBoxPanel : public CEditBoxPanel {

	// publicメンバ
	public:

		// publicメンバ関数
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass
		static BOOL RegisterClass(HINSTANCE hInstance, HBRUSH hBrush);	// ウィンドウクラス登録関数RegisterClass(背景ブラシ指定)

		// コンストラクタ・デストラクタ
		CScalableEditBoxPanel();	// コンストラクタCScalableEditBoxPanel()
		virtual ~CScalableEditBoxPanel();	// デストラクタ~CScalableEditBoxPanel()

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.
		virtual void OnSize(UINT nType, int cx, int cy);	// ウィンドウサイズが変更された時のハンドラOnSize.
		virtual void OnUserMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);	// ユーザ定義メッセージが発生した時のハンドラ.
		virtual void OnSizeChild(WPARAM wParam, LPARAM lParam);	// 子から親へウィンドウサイズ変更の要求が発生した時の独自ハンドラ.

};