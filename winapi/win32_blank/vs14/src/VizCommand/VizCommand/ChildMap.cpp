// ヘッダのインクルード
#include "ChildMap.h"	// チャイルドマップクラス

// 追加
void CChildMap::Add(const std::wstring &wstrTag, CChildMapItem *pChild){

	m_mappChildMap.insert(std::make_pair(wstrTag, pChild));

}

// 削除
void CChildMap::Remove(const std::wstring & wszTag){

	m_mappChildMap.erase(wszTag);

}

// 取得
CChildMapItem * CChildMap::Get(const std::wstring & wszTag){
	
	return m_mappChildMap[wszTag];

}
