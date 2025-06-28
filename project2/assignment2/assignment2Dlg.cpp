// assignment2Dlg.cpp: 구현 파일

#include "pch.h"
#include "framework.h"
#include "assignment2.h"
#include "assignment2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg 대화 상자 (기본 제공)
class CAboutDlg : public CDialogEx
{
public:
    CAboutDlg();

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_ABOUTBOX };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

protected:
    DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX) {}
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}
BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// Cassignment2Dlg 대화 상자

Cassignment2Dlg::Cassignment2Dlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_ASSIGNMENT2_DIALOG, pParent)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

// CSV 파일 불러오기 함수 (이름만 리스트에 표시)
void Cassignment2Dlg::LoadCSVData()
{
    CStdioFile file;
    if (!file.Open(_T("customers.csv"), CFile::modeRead | CFile::typeText))
    {
        // 파일이 없으면 무시 (최초 실행 시)
        return;
    }

    m_listCustomers.DeleteAllItems();

    CString line;
    int nItem = 0;
    while (file.ReadString(line))
    {
        CStringArray fields;
        int start = 0;
        for (int i = 0; i < 4; i++)
        {
            int end = line.Find(',', start);
            if (end == -1) end = line.GetLength();
            fields.Add(line.Mid(start, end - start));
            start = end + 1;
        }
        fields.Add(line.Mid(start)); // 5번째(메모)

        // 이름만 리스트에 추가 (fields[1])
        m_listCustomers.InsertItem(nItem, fields[1]);
        nItem++;
    }
    file.Close();
}

void Cassignment2Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_BUTTON1, m_btnAdd);
    DDX_Control(pDX, IDC_BUTTON2, m_btnDelete);
    DDX_Control(pDX, IDC_BUTTON3, m_btnDetail);
    DDX_Control(pDX, IDC_LIST_CUSTOMERS, m_listCustomers);
    DDX_Control(pDX, IDC_EDIT_ID, m_editID);
    DDX_Control(pDX, IDC_EDIT_NAME, m_editName);
    DDX_Control(pDX, IDC_EDIT_BIRTH, m_editBirth);
    DDX_Control(pDX, IDC_EDIT_ADDRESS, m_editAddress);
    DDX_Control(pDX, IDC_EDIT_MEMO, m_editMemo);
}

BEGIN_MESSAGE_MAP(Cassignment2Dlg, CDialogEx)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON1, &Cassignment2Dlg::OnBnClickedButton1) // 고객추가
    ON_BN_CLICKED(IDC_BUTTON2, &Cassignment2Dlg::OnBnClickedButton2) // 고객삭제
    ON_BN_CLICKED(IDC_BUTTON3, &Cassignment2Dlg::OnBnClickedButton3) // 상세조회
END_MESSAGE_MAP()

BOOL Cassignment2Dlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.
    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
    ASSERT(IDM_ABOUTBOX < 0xF000);

    CMenu* pSysMenu = GetSystemMenu(FALSE);
    if (pSysMenu != nullptr)
    {
        BOOL bNameValid;
        CString strAboutMenu;
        bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
        ASSERT(bNameValid);
        if (!strAboutMenu.IsEmpty())
        {
            pSysMenu->AppendMenu(MF_SEPARATOR);
            pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
        }
    }

    // 이 대화 상자의 아이콘을 설정합니다.
    SetIcon(m_hIcon, TRUE);   // 큰 아이콘
    SetIcon(m_hIcon, FALSE);  // 작은 아이콘

    // 리스트 컨트롤 컬럼 추가 (이름만)
    m_listCustomers.InsertColumn(0, _T("이름"), LVCFMT_LEFT, 150);
    m_listCustomers.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

    // CSV 파일 불러오기
    LoadCSVData();

    return TRUE;
}

void Cassignment2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
    if ((nID & 0xFFF0) == IDM_ABOUTBOX)
    {
        CAboutDlg dlgAbout;
        dlgAbout.DoModal();
    }
    else
    {
        CDialogEx::OnSysCommand(nID, lParam);
    }
}

void Cassignment2Dlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this);

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialogEx::OnPaint();
    }
}

HCURSOR Cassignment2Dlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

// 고객추가 버튼 클릭
void Cassignment2Dlg::OnBnClickedButton1()
{
    CString strID, strName, strBirth, strAddress, strMemo;
    m_editID.GetWindowText(strID);
    m_editName.GetWindowText(strName);
    m_editBirth.GetWindowText(strBirth);
    m_editAddress.GetWindowText(strAddress);
    m_editMemo.GetWindowText(strMemo);

    if (strID.IsEmpty() || strName.IsEmpty()) {
        MessageBox(_T("ID와 이름은 필수입니다."), _T("입력 오류"), MB_ICONWARNING);
        return;
    }

    // 리스트에 이름만 추가
    int nItem = m_listCustomers.InsertItem(0, strName);

    // 입력란 초기화
    m_editID.SetWindowText(_T(""));
    m_editName.SetWindowText(_T(""));
    m_editBirth.SetWindowText(_T(""));
    m_editAddress.SetWindowText(_T(""));
    m_editMemo.SetWindowText(_T(""));

    // CSV 파일에 저장 (맨 끝에 추가)
    CStdioFile file;
    if (file.Open(_T("customers.csv"), CFile::modeWrite | CFile::modeNoTruncate | CFile::typeText))
    {
        file.SeekToEnd();
        CString newLine;
        newLine.Format(_T("%s,%s,%s,%s,%s\n"),
            strID, strName, strBirth, strAddress, strMemo);
        file.WriteString(newLine);
        file.Close();
    }

    MessageBox(_T("고객이 추가되었습니다."), _T("완료"), MB_ICONINFORMATION);
}

// 고객삭제 버튼 클릭 (이름 기준으로 삭제)
void Cassignment2Dlg::OnBnClickedButton2()
{
    int nSel = m_listCustomers.GetNextItem(-1, LVNI_SELECTED);
    if (nSel == -1)
    {
        MessageBox(_T("삭제할 고객을 선택하세요."), _T("알림"), MB_ICONWARNING);
        return;
    }

    CString selName = m_listCustomers.GetItemText(nSel, 0);
    m_listCustomers.DeleteItem(nSel);

    // 전체 리스트의 이름을 기준으로 CSV 파일을 다시 저장
    CStdioFile fileRead;
    CStdioFile fileWrite;
    CArray<CString, CString> lines;
    if (fileRead.Open(_T("customers.csv"), CFile::modeRead | CFile::typeText))
    {
        CString line;
        while (fileRead.ReadString(line))
        {
            CStringArray fields;
            int start = 0;
            for (int i = 0; i < 4; i++)
            {
                int end = line.Find(',', start);
                if (end == -1) end = line.GetLength();
                fields.Add(line.Mid(start, end - start));
                start = end + 1;
            }
            fields.Add(line.Mid(start));
            // 이름이 삭제 대상이 아니면 저장
            if (fields[1] != selName)
                lines.Add(line);
        }
        fileRead.Close();

        // 다시 저장
        if (fileWrite.Open(_T("customers.csv"), CFile::modeCreate | CFile::modeWrite | CFile::typeText))
        {
            for (int i = 0; i < lines.GetSize(); i++)
                fileWrite.WriteString(lines[i] + _T("\n"));
            fileWrite.Close();
        }
    }

    MessageBox(_T("고객이 삭제되었습니다."), _T("삭제 완료"), MB_ICONINFORMATION);
}

// 상세조회 버튼 클릭 (이름 기준으로 CSV에서 전체 정보 찾아서 입력란에 표시)
void Cassignment2Dlg::OnBnClickedButton3()
{
    int nSel = m_listCustomers.GetNextItem(-1, LVNI_SELECTED);
    if (nSel == -1)
    {
        MessageBox(_T("상세조회할 고객을 선택하세요."), _T("알림"), MB_ICONWARNING);
        return;
    }

    CString selName = m_listCustomers.GetItemText(nSel, 0);

    CStdioFile file;
    if (file.Open(_T("customers.csv"), CFile::modeRead | CFile::typeText))
    {
        CString line;
        while (file.ReadString(line))
        {
            CStringArray fields;
            int start = 0;
            for (int i = 0; i < 4; i++)
            {
                int end = line.Find(',', start);
                if (end == -1) end = line.GetLength();
                fields.Add(line.Mid(start, end - start));
                start = end + 1;
            }
            fields.Add(line.Mid(start));
            if (fields[1] == selName)
            {
                m_editID.SetWindowText(fields[0]);
                m_editName.SetWindowText(fields[1]);
                m_editBirth.SetWindowText(fields[2]);
                m_editAddress.SetWindowText(fields[3]);
                m_editMemo.SetWindowText(fields[4]);
                break;
            }
        }
        file.Close();
    }
}
