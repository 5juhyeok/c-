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

// CSV ���Ͽ��� �� ������ �ҷ�����
void loadCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "CSV ������ �� �� �����ϴ�!" << endl;
        return;
    }
    string line;
    bool isFirstLine = true;
    while (getline(file, line)) {
        if (isFirstLine) { // ��� �ǳʶٱ�
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
    cout << "�� " << customers.size() << "���� �� ������ �ε� �Ϸ�" << endl;
}

// �ű� �� ���
void registerCustomer() {
    Customer c;
    cout << "\n[�ű� �� ���]" << endl;
    cout << "ID: ";
    getline(cin >> ws, c.id);
    cout << "�̸�: ";
    getline(cin, c.name);
    cout << "�������(YYYYMMDD): ";
    getline(cin, c.birth);
    cout << "�ּ�: ";
    getline(cin, c.address);
    cout << "�޸�: ";
    getline(cin, c.memo);
    customers.push_back(c);
    cout << "��� �Ϸ�!" << endl;
}

// �� ����
void deleteCustomer() {
    cout << "\n������ ���� ID �Ǵ� �̸�: ";
    string key;
    getline(cin >> ws, key);
    auto it = remove_if(customers.begin(), customers.end(),
        [&](const Customer& c) { return c.id == key || c.name == key; });
    if (it != customers.end()) {
        customers.erase(it, customers.end());
        cout << "�� ���� ���� �Ϸ�" << endl;
    }
    else {
        cout << "�ش� ���� ã�� �� �����ϴ�" << endl;
    }
}

// �� ��� ���
void listCustomers() {
    cout << "\n[�� ���] (" << customers.size() << "��)" << endl;
    cout << left << setw(8) << "ID" << setw(15) << "�̸�" << setw(12) << "�������" << setw(20) << "�ּ�" << "�޸�" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    for (const auto& c : customers) {
        cout << setw(8) << c.id
            << setw(15) << c.name
            << setw(12) << c.birth
            << setw(20) << c.address.substr(0, 18)
            << c.memo.substr(0, 20) << endl;
    }
}

// �� �� ���� ��ȸ
void viewDetails() {
    cout << "\n��ȸ�� ���� ID �Ǵ� �̸�: ";
    string key;
    getline(cin >> ws, key);
    bool found = false;
    for (const auto& c : customers) {
        if (c.id == key || c.name == key) {
            cout << "\n[�� ����]" << endl;
            cout << "ID: " << c.id << endl;
            cout << "�̸�: " << c.name << endl;
            cout << "�������: " << c.birth << endl;
            cout << "�ּ�: " << c.address << endl;
            cout << "�޸�: " << c.memo << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "���� ã�� �� �����ϴ�" << endl;
    }
}

int main() {
    // CSV ���ϸ��� �ʿ信 ���� ����
    loadCSV("customers.csv");

    while (true) {
        cout << "\n[�� ���� �ý���]" << endl;
        cout << "1. �� ���\n2. �� ����\n3. �� ��� ��ȸ\n4. �� �� ���� ��ȸ\n5. ����" << endl;
        cout << "����: ";
        int choice;
        cin >> choice;
        cin.ignore(); // �Է� ���� ����

        switch (choice) {
        case 1: registerCustomer(); break;
        case 2: deleteCustomer(); break;
        case 3: listCustomers(); break;
        case 4: viewDetails(); break;
        case 5:
            cout << "���α׷��� �����մϴ�." << endl;
            return 0;
        default:
            cout << "�߸��� �Է��Դϴ�." << endl;
        }
    }
}
