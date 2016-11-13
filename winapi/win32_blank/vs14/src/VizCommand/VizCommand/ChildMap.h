// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 既定のヘッダ
#include <map>	// std::map
// 独自のヘッダ
#include "Window.h"		// ウィンドウクラス
#include "ChildMapItem.h"	// チャイルドマップアイテムクラス

// チャイルドマップクラス
class CChildMap {

	// publicメンバ
	public:

		// publicメンバ変数
		// メンバ変数
		std::map<std::wstring, CChildMapItem *> m_mappChildMap;	// チャイルドマップm_mappChildMap.

		// publicメンバ関数
		// メンバ関数
		void Add(const std::wstring &wstrTag, CChildMapItem *pChild);	// 追加
		void Remove(const std::wstring &wstrTag);	// 削除.
		CChildMapItem *Get(const std::wstring &wstrTag);	// 取得.

};

