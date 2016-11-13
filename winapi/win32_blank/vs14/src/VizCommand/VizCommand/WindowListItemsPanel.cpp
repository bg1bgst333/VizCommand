// �w�b�_�̃C���N���[�h
#include "WindowListItemsPanel.h"	// �E�B���h�E���X�g�A�C�e���Y�p�l���N���X

// �E�B���h�E�쐬�֐�Create.
BOOL CWindowListItemsPanel::Create(int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �����o�ɃZ�b�g.
	m_x = x;	// m_x��x���Z�b�g.
	m_y = y;	// m_y��y���Z�b�g.
	m_iWidth = iWidth;	// m_iWidth��iWidth���Z�b�g.
	m_iHeight = iHeight;	// m_iHeight��iHeight���Z�b�g.

	// �N���X��"WindowListItemsPanel"�̎q�E�B���h�E���쐬.
	return CWindow::Create(_T("WindowListItemsPanel"), _T(""), WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ŃN���X��"WindowListItemsPanel"�̎q�E�B���h�E���쐬.

}

// OnClose��OnDestroy�̊ԂɎq�E�B���h�E�Ȃǂ�j�����郁���o�֐�Destroy.
void CWindowListItemsPanel::Destroy() {

	// �A�C�e�������ׂč폜.
	int c = m_vecpWindowList.size();
	for (int i = 0; i < c; i++) {
		Delete(0);	// Delete�ō폜.
	}

	// �j��.
	DestroyWindow(m_hWnd);	// DestroyWindow��m_hWnd��j��.
	m_hWnd = NULL;	// m_hWnd��NULL�ɂ���.

}

// �E�B���h�E���X�g�A�C�e����}�����郁���o�֐�Insert.
BOOL CWindowListItemsPanel::Insert(int index, int height, HINSTANCE hInstance) {

	// �A�C�e���̐���.
	CWindowListItem *pItem = new CWindowListItem();	// CWindowListItem�I�u�W�F�N�gpItem�𐶐�.
	// �}���ʒu���T�C�Y���傫���ꍇ�͈�ԍŌ�ɒǉ�.
	if (index > (int)m_vecpWindowList.size()) {
		int position = 0;
		int idx = m_vecpWindowList.size();	// idx��m_vecpWindowList.size()�ɏ�����.
		if (idx == 0) {
			position = 0;
		}
		else {
			position = m_vecpWindowList[idx - 1]->m_y + m_vecpWindowList[idx - 1]->m_iHeight;
		}
		pItem->Create(0, position, 200, height, m_hWnd, (HMENU)(IDC_WINDOW_LISTITEM + idx), hInstance);	// �E�B���h�E����.
		TCHAR tszText[256];
		_stprintf_s(tszText, _T("%d"), idx);
		pItem->SetWindowText(tszText);
		m_vecpWindowList.push_back(pItem);	// �ǉ�
	}
	else {
		int idx;	// idx��p��.
		int position = 0;
		if (index < 0) {	// index���}�C�i�X.
			idx = 0;	// idx��0�ɃZ�b�g.
		}
		else {
			idx = index;	// idx��index�ɃZ�b�g.
		}
		if (idx == 0) {
			position = 0;
		}
		else {
			position = m_vecpWindowList[idx - 1]->m_y + m_vecpWindowList[idx - 1]->m_iHeight;
		}
		pItem->Create(0, position, 200, height, m_hWnd, (HMENU)(IDC_WINDOW_LISTITEM + m_vecpWindowList.size()), hInstance);	// �E�B���h�E����.
		TCHAR tszText[256];
		_stprintf_s(tszText, _T("%d"), idx);
		pItem->SetWindowText(tszText);
		m_vecpWindowList.insert(m_vecpWindowList.begin() + idx, pItem);	// �ǉ�
		// ����height�������.
		for (int i = idx + 1; i <= (int)m_vecpWindowList.size() - 1; i++) {
			m_vecpWindowList[i]->MoveWindow(m_vecpWindowList[i]->m_x, m_vecpWindowList[i]->m_y + height, m_vecpWindowList[i]->m_iWidth, m_vecpWindowList[i]->m_iHeight);
		}
	}

	// �A�C�e���Y�p�l���̃T�C�Y��ύX.
	m_iHeight = m_iHeight + height;
	::MoveWindow(m_hWnd, m_x, m_y, m_iWidth, m_iHeight, TRUE);

	// TRUE��Ԃ�.
	return TRUE;	// TRUE��Ԃ�.

}

// �E�B���h�E���X�g�A�C�e�����폜���郁���o�֐�Delete.
void CWindowListItemsPanel::Delete(int index) {

	// �T�C�Y��0�Ȃ牽�����Ȃ�.
	if (m_vecpWindowList.size() == 0) {
		return;
	}
	else {
		// �T�C�Y�ȏ�Ȃ疖���̍폜.
		if (index >= (int)m_vecpWindowList.size()) {
			int height;
			CWindowListItem *pItem = m_vecpWindowList.at(m_vecpWindowList.size() - 1);	// m_vecpWindowList.at�Ŏ�o��.
			height = pItem->m_iHeight;
			pItem->Destroy();	// pItem->Destroy�ŃE�B���h�E�̔j��.
			delete pItem;	// delete��pItem�����.
			m_vecpWindowList.erase(m_vecpWindowList.begin() + m_vecpWindowList.size() - 1);	// m_vecpWindowList.size() - 1�Ԗڂ�erase�ō폜.
			// �A�C�e���Y�p�l���̃T�C�Y��ύX.
			m_iHeight = m_iHeight - height;
			::MoveWindow(m_hWnd, m_x, m_y, m_iWidth, m_iHeight, TRUE);
			return;
		}
		if (index < 0) {	// �}�C�i�X�Ȃ�0�̎�o��.
			int height = m_vecpWindowList[0]->m_iHeight;	// 0�Ԗڂ�m_iHeight��ۑ�.
			CWindowListItem *pItem = m_vecpWindowList.at(0);	// 0���폜..
			pItem->Destroy();	// pItem->Destroy�ŃE�B���h�E�̔j��.
			delete pItem;	// delete��pItem�����.
			m_vecpWindowList.erase(m_vecpWindowList.begin() + 0);	// 0�Ԗڂ�erase�ō폜.
			// ����height�������.
			for (int i = 0; i <= (int)m_vecpWindowList.size() - 1; i++) {
				m_vecpWindowList[i]->MoveWindow(m_vecpWindowList[i]->m_x, m_vecpWindowList[i]->m_y - height, m_vecpWindowList[i]->m_iWidth, m_vecpWindowList[i]->m_iHeight);
			}
			// �A�C�e���Y�p�l���̃T�C�Y��ύX.
			m_iHeight = m_iHeight - height;
			::MoveWindow(m_hWnd, m_x, m_y, m_iWidth, m_iHeight, TRUE);
			return;
		}
		// index�Ԗڂ̍폜.
		CWindowListItem *pItem = m_vecpWindowList.at(index);	// m_vecpWindowList.at�Ŏ�o��.
		int delHeight = pItem->m_iHeight;	// delHeight�ɕۑ�.
		pItem->Destroy();	// pItem->Destroy�ŃE�B���h�E�̔j��.
		delete pItem;	// delete��pItem�����.
		m_vecpWindowList.erase(m_vecpWindowList.begin() + index);	// index�Ԗڂ�erase�ō폜.
		// ����height�������.
		for (int i = index; i <= (int)m_vecpWindowList.size() - 1; i++) {
			m_vecpWindowList[i]->MoveWindow(m_vecpWindowList[i]->m_x, m_vecpWindowList[i]->m_y - delHeight, m_vecpWindowList[i]->m_iWidth, m_vecpWindowList[i]->m_iHeight);
		}
		// �A�C�e���Y�p�l���̃T�C�Y��ύX.
		m_iHeight = m_iHeight - delHeight;
		::MoveWindow(m_hWnd, m_x, m_y, m_iWidth, m_iHeight, TRUE);
	}

}

// �E�B���h�E���X�g�A�C�e�����擾���郁���o�֐�Get.
CWindowListItem * CWindowListItemsPanel::Get(int index){

	// index�Ԗڂ̃A�C�e����Ԃ�.
	return m_vecpWindowList[index];

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CWindowListItemsPanel::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// �E�B���h�E�쐬����
	return 0;	// �����Ȃ�0��Ԃ�.

}

// �E�B���h�E�j�����̃n���h��OnDestroy
void CWindowListItemsPanel::OnDestroy() {

}

// �E�B���h�E���ړ����ꂽ���̃n���h��OnMove.
void CWindowListItemsPanel::OnMove(int x, int y){

	::InvalidateRect(m_hWnd, NULL, TRUE);

}

// �E�B���h�E�̃T�C�Y���ύX���ꂽ���̃n���h��OnSize.
void CWindowListItemsPanel::OnSize(UINT nType, int cx, int cy) {

	// �A�C�e���Y�p�l���̈ʒu�T�C�Y����ύX.
	m_iWidth = cx;
	m_iHeight = cy;

	// �S�Ă̎q�E�B���h�E�̉��������킹��.
	for (std::vector<CWindowListItem *>::iterator it = m_vecpWindowList.begin(); it != m_vecpWindowList.end(); it++) {

		// �q�E�B���h�E�̃T�C�Y���ύX.
		(*it)->m_iWidth = cx;	// ������cx�ɍ��킹��.
		// �����͂��̂܂�.
		::MoveWindow((*it)->m_hWnd, 0, (*it)->m_y, (*it)->m_iWidth, (*it)->m_iHeight, TRUE);	// MoveWindow�Ŏq�E�B���h�E�̃T�C�Y�����̃E�B���h�E�̉����ɍ��킹��.

	}

}

// ��ʕ`��̍X�V��v�����ꂽ��.
void CWindowListItemsPanel::OnPaint(){

	// �ϐ��̐錾
	HDC hDC;
	PAINTSTRUCT ps;

	// �`��̊J�n.
	hDC = ::BeginPaint(m_hWnd, &ps);

	// �A�C�e���Y�p�l���̗̈����`�ŕ`��.
	HPEN hOldPen;
	HBRUSH hOldBrush;
	HPEN hGreenPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	HBRUSH hWhiteBrush = CreateSolidBrush(RGB(255, 255, 255));
	hOldPen = (HPEN)SelectObject(hDC, hGreenPen);
	hOldBrush = (HBRUSH)SelectObject(hDC, hWhiteBrush);
	Rectangle(hDC, m_x, m_y, m_iWidth, m_iHeight);
	SelectObject(hDC, hOldBrush);
	SelectObject(hDC, hOldPen);
	DeleteObject(hWhiteBrush);
	DeleteObject(hGreenPen);

	// �`��̏I��.
	::EndPaint(m_hWnd, &ps);

}

// �E�B���h�E����鎞�̃n���h��OnClose.
int CWindowListItemsPanel::OnClose() {

	// 0��Ԃ�.
	return 0;	// 0��Ԃ��ăE�B���h�E�����.

}