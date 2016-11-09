// �w�b�_�̃C���N���[�h
#include "WindowListView.h"	// �E�B���h�E���X�g�r���[�N���X

// �E�B���h�E�쐬�֐�Create.
BOOL CWindowListView::Create(int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �N���X��"WindowListView"�̎q�E�B���h�E���쐬.
	return CWindow::Create(_T("WindowListView"), _T(""), WS_CHILD | WS_VISIBLE | WS_VSCROLL, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ŃN���X��"WindowListView"�̎q�E�B���h�E���쐬.

}

// OnClose��OnDestroy�̊ԂɎq�E�B���h�E�Ȃǂ�j�����郁���o�֐�Destroy.
void CWindowListView::Destroy() {

	// �A�C�e���Y�̔j��.
	m_pWindowListItemsPanel->Destroy();
	delete m_pWindowListItemsPanel;
	m_pWindowListItemsPanel = NULL;

	// �j��.
	DestroyWindow(m_hWnd);	// DestroyWindow��m_hWnd��j��.
	m_hWnd = NULL;	// m_hWnd��NULL�ɂ���.

}

// �E�B���h�E���X�g�A�C�e����}�����郁���o�֐�Insert.
BOOL CWindowListView::Insert(int index, int height, HINSTANCE hInstance){

	return m_pWindowListItemsPanel->Insert(index, height, hInstance);

}

// �E�B���h�E���X�g�A�C�e�����폜���郁���o�֐�Delete.
void CWindowListView::Delete(int index){

	m_pWindowListItemsPanel->Delete(index);

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CWindowListView::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// �q�E�B���h�E�ƂȂ�E�B���h�E���X�g�A�C�e���Y�p�l���I�u�W�F�N�g�̍쐬.
	m_pWindowListItemsPanel = new CWindowListItemsPanel();	// CWindowListItemsPanel�I�u�W�F�N�gm_pWindowListItemsPanel�̍쐬.

	// �E�B���h�E���X�g�A�C�e���Y�p�l���̍쐬.
	m_pWindowListItemsPanel->Create(0, 0, 0, 0, hwnd, (HMENU)IDC_WINDOW_LIST_ITEMS_PANEL, lpCreateStruct->hInstance);	// m_pWindowListItemsPanel->Create�ŃE�B���h�E���X�g�A�C�e���Y�p�l�����쐬.

	// �X�N���[���o�[�̏�����.
	// �ϐ��̐錾
	SCROLLINFO scrinfo = {0};	// SCROLLINFO�\���̕ϐ�scrinfo.
	// scrinfo�̏�����
	scrinfo.cbSize = sizeof(SCROLLINFO);	// SCROLLINFO�\���̂̃T�C�Y.
	scrinfo.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// �ݒ肷�鍀�ڂ̃}�X�N.(SIF_PAGE�̓y�[�W�T�C�Y, SIF_RANGE�̓y�[�W�͈�, SIF_POS�͌��݈ʒu.)
	scrinfo.nMin = 0;	// �y�[�W�͈͍ŏ��l��0�ɃZ�b�g.
	scrinfo.nMax = 0;	// �y�[�W�͈͍ő�l��0�ɃZ�b�g.
	scrinfo.nPage = 0;	// �y�[�W�T�C�Y��0�ɃZ�b�g.
	scrinfo.nPos = 0;	// ���݂̈ʒu��0�ɃZ�b�g.
	SetScrollInfo(hwnd, SB_VERT, &scrinfo, TRUE);	// SetScrollInfo��scrinfo���Z�b�g.(CTL����Ȃ���VERT������.)

	// �E�B���h�E�쐬����
	return 0;	// �����Ȃ�0��Ԃ�.

}

// �E�B���h�E�j�����̃n���h��OnDestroy
void CWindowListView::OnDestroy() {

}

// �E�B���h�E�̃T�C�Y���ύX���ꂽ���̃n���h��OnSize.
void CWindowListView::OnSize(UINT nType, int cx, int cy){

	// �q�E�B���h�E�̃E�B���h�E���X�g�A�C�e���Y�p�l���̃T�C�Y���ύX.
	::MoveWindow(m_pWindowListItemsPanel->m_hWnd, m_pWindowListItemsPanel->m_x, m_pWindowListItemsPanel->m_y, cx, m_pWindowListItemsPanel->m_iHeight, TRUE);	// MoveWindow�Ŏq�E�B���h�Em_pWindowListItemsPanel�̉��̃T�C�Y�������̃E�B���h�E�ɍ��킹��.

	// �ϐ��̐錾
	SCROLLINFO scrinfo = { 0 };	// SCROLLINFO�\���̕ϐ�scrinfo.
	// scrinfo�̍X�V.
	// SCROLLINFO�\���̂̏����擾.
	scrinfo.cbSize = sizeof(SCROLLINFO);		// �T�C�Y���Z�b�g.
	scrinfo.fMask = SIF_ALL;					// �}�X�N�͂��ׂĂ̍��ڂ��Z�b�g.
	GetScrollInfo(m_hWnd, SB_VERT, &scrinfo);	// GetScrollInfo��SCROLLINFO�\���̂̏����擾.(CTL����Ȃ���VERT������.)

	//scrinfo.cbSize = sizeof(SCROLLINFO);	// SCROLLINFO�\���̂̃T�C�Y.
	scrinfo.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// �ݒ肷�鍀�ڂ̃}�X�N.(SIF_PAGE�̓y�[�W�T�C�Y, SIF_RANGE�̓y�[�W�͈�, SIF_POS�͌��݈ʒu.)
	scrinfo.nMin = 0;	// �y�[�W�͈͍ŏ��l��0�ɃZ�b�g.
	scrinfo.nMax = m_pWindowListItemsPanel->m_iHeight;	// �y�[�W�͈͍ő�l��m_pWindowListItemsPanel->m_iHeight�ɃZ�b�g.
	int temp = cy - (m_pWindowListItemsPanel->m_iHeight - scrinfo.nPos);
	if (temp >= 0) {
		scrinfo.nMax = m_pWindowListItemsPanel->m_iHeight + temp;
	}
	else {
		scrinfo.nMax = m_pWindowListItemsPanel->m_iHeight;
	}
	scrinfo.nPage = cy;	// �y�[�W�T�C�Y��cy�ɃZ�b�g.

	//scrinfo.nPos = 0;	// ���݂̈ʒu��0�ɃZ�b�g.
	SetScrollInfo(m_hWnd, SB_VERT, &scrinfo, TRUE);	// SetScrollInfo��scrinfo���Z�b�g.(CTL����Ȃ���VERT������.)

}

// �E�B���h�E����鎞�̃n���h��OnClose.
int CWindowListView::OnClose() {

	// 0��Ԃ�.
	return 0;	// 0��Ԃ��ăE�B���h�E�����.

}

// �����X�N���[�����̃n���h��OnVScroll.
void CWindowListView::OnVScroll(UINT nSBCode, UINT nPos, HWND hScroll) {

	// �ϐ��̐錾
	SCROLLINFO scrinfo = { 0 };	// SCROLLINFO�\���̕ϐ�scrinfo.(" = {0}"���邱�ƂŒ��g��0�Ŗ��߂�.)

	// SCROLLINFO�\���̂̏����擾.
	scrinfo.cbSize = sizeof(SCROLLINFO);		// �T�C�Y���Z�b�g.
	scrinfo.fMask = SIF_ALL;					// �}�X�N�͂��ׂĂ̍��ڂ��Z�b�g.
	GetScrollInfo(m_hWnd, SB_VERT, &scrinfo);	// GetScrollInfo��SCROLLINFO�\���̂̏����擾.(CTL����Ȃ���VERT������.)

	scrinfo.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;

	// �ʒm�R�[�h����
	switch (nSBCode) {	// nSBCode�ɍs��ꂽ����̒ʒm�R�[�h���i�[����Ă���̂�, ����Ŕ��肷��.

		// 1�ԏ�
		case SB_TOP:

			{
				int temp = scrinfo.nPage - (m_pWindowListItemsPanel->m_iHeight - scrinfo.nPos);
				if (temp >= 0) {
					scrinfo.nMax = m_pWindowListItemsPanel->m_iHeight + temp;
				}
				else {
					scrinfo.nMax = m_pWindowListItemsPanel->m_iHeight;
				}

				// 1�ԏ�ɃZ�b�g.
				scrinfo.nPos = scrinfo.nMin;	// ���݈ʒu��1�ԏ�ɃZ�b�g.
				break;	// ������.
			}

		// 1�ԉ�
		case SB_BOTTOM:

			// 1�ԉ��ɃZ�b�g.
			scrinfo.nPos = scrinfo.nMax;	// ���݈ʒu��1�ԉ��ɃZ�b�g.
			break;	// ������.

		// 1�s��
		case SB_LINEUP:

			{
				int temp = scrinfo.nPage - (m_pWindowListItemsPanel->m_iHeight - scrinfo.nPos);
				if (temp >= 0) {
					scrinfo.nMax = m_pWindowListItemsPanel->m_iHeight + temp;
				}
				else {
					scrinfo.nMax = m_pWindowListItemsPanel->m_iHeight;
				}

				// 1�s��ɖ߂�.
				if (scrinfo.nPos > 0) {	// scrinfo.nPos��1�ȏ�Ȃ�.	
					scrinfo.nPos--;	// scrinfo.nPos�����炷.
					m_pWindowListItemsPanel->m_y++;
				}
				break;	// ������.
			}

		// 1�s��
		case SB_LINEDOWN:

			// 1�s���ɐi�߂�.
			if (scrinfo.nPos < scrinfo.nMax - (int)scrinfo.nPage + 1) {	// scrinfo.nPos���Ō�̈ʒu���O�Ȃ�.
				scrinfo.nPos++;	// scrinfo.nPos�𑝂₷.
				m_pWindowListItemsPanel->m_y--;
			}
			break;	// ������.

		// 1�y�[�W��
		case SB_PAGEUP:
	
			{
				int temp = scrinfo.nPage - (m_pWindowListItemsPanel->m_iHeight - scrinfo.nPos);
				if (temp >= 0) {
					scrinfo.nMax = m_pWindowListItemsPanel->m_iHeight + temp;
				}
				else {
					scrinfo.nMax = m_pWindowListItemsPanel->m_iHeight;
				}

				// 1�y�[�W�߂�.
				scrinfo.nPos -= scrinfo.nPage;	// ���݈ʒu��1�y�[�W�߂�.
				m_pWindowListItemsPanel->m_y = m_pWindowListItemsPanel->m_y + scrinfo.nPage;
				if (scrinfo.nPos <= scrinfo.nMin) {
					scrinfo.nPos = scrinfo.nMin;
					m_pWindowListItemsPanel->m_y = 0;
				}

				break;	// ������.
			}

		// 1�y�[�W��
		case SB_PAGEDOWN:
			
			// 1�y�[�W�i��.
			scrinfo.nPos += scrinfo.nPage;	// ���݈ʒu��1�y�[�W�i�߂�.
			m_pWindowListItemsPanel->m_y = m_pWindowListItemsPanel->m_y - scrinfo.nPage;
			if (scrinfo.nPos + (int)scrinfo.nPage >= scrinfo.nMax) {
				scrinfo.nPos = scrinfo.nMax - scrinfo.nPage;
				m_pWindowListItemsPanel->m_y = 0 - scrinfo.nPos;
			}
			
			break;	// ������.

		
		// �X�N���[���܂݂������ꂽ��.
		case SB_THUMBTRACK:
		case SB_THUMBPOSITION:
		
			{

				int temp = scrinfo.nPage - (m_pWindowListItemsPanel->m_iHeight - scrinfo.nPos);
				if (temp >= 0) {
					scrinfo.nMax = m_pWindowListItemsPanel->m_iHeight + temp;
				}
				else {
					scrinfo.nMax = m_pWindowListItemsPanel->m_iHeight;
				}

				// �����ꂽ�ʒu���Z�b�g.
				scrinfo.nPos = nPos;	// nPos�ɗ����ꂽ�ʒu���i�[����Ă���̂�scrinfo.nPos�ɃZ�b�g.
				m_pWindowListItemsPanel->m_y = 0 - scrinfo.nPos;
				break;	// ������.

			}

		// ����ȊO.
		default:

			// ������.
			break;	// ������.

	}

	// scrinfo.nPos��hScroll�ɃZ�b�g.
	SetScrollInfo(m_hWnd, SB_VERT, &scrinfo, TRUE);	// SetScrollInfo�Ō��݂�scrinfo.nPos��hScroll�ɃZ�b�g.(CTL����Ȃ���VERT������.)
	::MoveWindow(m_pWindowListItemsPanel->m_hWnd, m_pWindowListItemsPanel->m_x, m_pWindowListItemsPanel->m_y, m_pWindowListItemsPanel->m_iWidth, m_pWindowListItemsPanel->m_iHeight, TRUE);

}
