#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Customer {
    string id;
    string name;
    string birth;
    string address;
    string memo;
};

vector<Customer> customers;

// CSV 파일에서 고객 데이터 불러오기
void loadCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "CSV 파일을 열 수 없습니다!" << endl;
        return;
    }
    string line;
    bool isFirstLine = true;
    while (getline(file, line)) {
        if (isFirstLine) { // 헤더 건너뛰기
            isFirstLine = false;
            continue;
        }
        stringstream ss(line);
        Customer c;
        getline(ss, c.id, ',');
        getline(ss, c.name, ',');
        getline(ss, c.birth, ',');
        getline(ss, c.address, ',');
        getline(ss, c.memo, ',');
        customers.push_back(c);
    }
    cout << "총 " << customers.size() << "명의 고객 데이터 로드 완료" << endl;
}

// 신규 고객 등록
void registerCustomer() {
    Customer c;
    cout << "\n[신규 고객 등록]" << endl;
    cout << "ID: ";
    getline(cin >> ws, c.id);
    cout << "이름: ";
    getline(cin, c.name);
    cout << "생년월일(YYYYMMDD): ";
    getline(cin, c.birth);
    cout << "주소: ";
    getline(cin, c.address);
    cout << "메모: ";
    getline(cin, c.memo);
    customers.push_back(c);
    cout << "등록 완료!" << endl;
}

// 고객 삭제
void deleteCustomer() {
    cout << "\n삭제할 고객의 ID 또는 이름: ";
    string key;
    getline(cin >> ws, key);
    auto it = remove_if(customers.begin(), customers.end(),
        [&](const Customer& c) { return c.id == key || c.name == key; });
    if (it != customers.end()) {
        customers.erase(it, customers.end());
        cout << "고객 정보 삭제 완료" << endl;
    }
    else {
        cout << "해당 고객을 찾을 수 없습니다" << endl;
    }
}

// 고객 목록 출력
void listCustomers() {
    cout << "\n[고객 목록] (" << customers.size() << "명)" << endl;
    cout << left << setw(8) << "ID" << setw(15) << "이름" << setw(12) << "생년월일" << setw(20) << "주소" << "메모" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    for (const auto& c : customers) {
        cout << setw(8) << c.id
            << setw(15) << c.name
            << setw(12) << c.birth
            << setw(20) << c.address.substr(0, 18)
            << c.memo.substr(0, 20) << endl;
    }
}

// 고객 상세 정보 조회
void viewDetails() {
    cout << "\n조회할 고객의 ID 또는 이름: ";
    string key;
    getline(cin >> ws, key);
    bool found = false;
    for (const auto& c : customers) {
        if (c.id == key || c.name == key) {
            cout << "\n[상세 정보]" << endl;
            cout << "ID: " << c.id << endl;
            cout << "이름: " << c.name << endl;
            cout << "생년월일: " << c.birth << endl;
            cout << "주소: " << c.address << endl;
            cout << "메모: " << c.memo << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "고객을 찾을 수 없습니다" << endl;
    }
}

int main() {
    // CSV 파일명은 필요에 따라 수정
    loadCSV("customers.csv");

    while (true) {
        cout << "\n[고객 관리 시스템]" << endl;
        cout << "1. 고객 등록\n2. 고객 삭제\n3. 고객 목록 조회\n4. 고객 상세 정보 조회\n5. 종료" << endl;
        cout << "선택: ";
        int choice;
        cin >> choice;
        cin.ignore(); // 입력 버퍼 정리

        switch (choice) {
        case 1: registerCustomer(); break;
        case 2: deleteCustomer(); break;
        case 3: listCustomers(); break;
        case 4: viewDetails(); break;
        case 5:
            cout << "프로그램을 종료합니다." << endl;
            return 0;
        default:
            cout << "잘못된 입력입니다." << endl;
        }
    }
}
