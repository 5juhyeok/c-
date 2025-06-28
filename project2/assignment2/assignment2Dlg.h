// assignment2Dlg.h: 헤더 파일

#pragma once

// Cassignment2Dlg 대화 상자
class Cassignment2Dlg : public CDialogEx
{
    // 생성입니다.
public:
    Cassignment2Dlg(CWnd* pParent = nullptr); // 표준 생성자입니다.

    // 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_ASSIGNMENT2_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV 지원입니다.

    // === 반드시 아래 줄이 포함되어야 함 ===
    HICON m_hIcon;

    // 메시지 맵 함수
    virtual BOOL OnInitDialog();
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    DECLARE_MESSAGE_MAP()

public:
    // 버튼 클릭 이벤트 핸들러
    afx_msg void OnBnClickedButton1(); // 고객추가
    afx_msg void OnBnClickedButton2(); // 고객삭제
    afx_msg void OnBnClickedButton3(); // 상세조회

    // CSV 불러오기 함수 선언
    void LoadCSVData();

    // 컨트롤 변수 선언
    CListCtrl m_listCustomers;   // 고객 목록 리스트
    CEdit     m_editID;          // ID 입력란
    CEdit     m_editName;        // 이름 입력란
    CEdit     m_editBirth;       // 생년월일 입력란
    CEdit     m_editAddress;     // 주소 입력란
    CEdit     m_editMemo;        // 메모 입력란

    CButton   m_btnAdd;          // 고객추가 버튼
    CButton   m_btnDelete;       // 고객삭제 버튼
    CButton   m_btnDetail;       // 상세조회 버튼
};
