// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "WindowListItemsPanel.h"	// ウィンドウリストアイテムズパネルクラス

// ストリームコンソールアイテムズパネルCStreamConsoleItemsPanel
class CStreamConsoleItemsPanel : public CWindowListItemsPanel {

	// publicメンバ
	public:

		// メンバ関数
		virtual void OnSizeChild(WPARAM wParam, LPARAM lParam);	// 子から親へウィンドウサイズ変更の要求が発生した時の独自ハンドラ.
};
