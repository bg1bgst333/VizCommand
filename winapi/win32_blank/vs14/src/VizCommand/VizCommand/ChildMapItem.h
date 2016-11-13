// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"		// ウィンドウクラス

// チャイルドマップアイテムクラス
class CChildMapItem {

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ
		CChildMapItem(int index, CWindow *pWindow);

		// publicメンバ変数
		// メンバ変数
		int m_iIndex;	// ウィンドウリストビューのインデックスm_iIndex.
		CWindow *m_pWindow;	// ウィンドウオブジェクトm_pWindow.

};
