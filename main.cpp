#include <iostream>

using namespace std;

struct node {
    int data;
    node* pointer;
};

node *head = NULL;
node *head2 = NULL;

void tambahAwal(int dataBaru, node *&head){
    node* nodeBaru = new node();
    nodeBaru->data = dataBaru;
    nodeBaru->pointer = head;
    head = nodeBaru;
}

void tambahAkhir(int dataBaru, node *&head) {
    node* nodeBaru = new node();
    nodeBaru->data = dataBaru;
    nodeBaru->pointer = NULL;

    if (head == NULL) {
        head = nodeBaru;
    } else {
        node* temp = head;
        while (temp->pointer != NULL) {
            temp = temp->pointer;
        }
        temp->pointer = nodeBaru;
    }
}

void hapusAwal(node *&head) {
    if (head != NULL) {
        node* temp = head;
        head = head->pointer;
        free(temp);
    }
}

void cariData(int dataDicari, node *head) {
    node* temp = head;
    int urutan = 0;
    bool ditemukan = false;
    if (head != NULL) {
        while (temp != NULL) {
            urutan++;
            if (temp->data == dataDicari) {
                ditemukan = true;
                break;
            }
            temp = temp->pointer;
        }
        if (ditemukan) {
            cout << "Data " << dataDicari << " ditemukan di list urutan ke- " << urutan << endl;
        } else {
            cout << "Data " << dataDicari << " tidak ditemukan di dalam list." << endl;
        }
    } else {
        cout << "Data dalam list kosong.\n";
    }
}

void ubahData(int dataDiubah, int dataBaru, node *head) {
    node* temp = head;
    bool ditemukan = false;
    if (head != NULL) {
        while (temp != NULL) {
            if (temp->data == dataDiubah) {
                ditemukan = true;
                break;
            }
            temp = temp->pointer;
        }
        if (ditemukan) {
            temp->data = dataBaru;
        } else {
            cout << "Data tidak ada dalam list. \n";
        }
    } else {
        cout << "Data dalam list kosong.\n";
    }
}

void printList(node *head) {
    node* temp = head;
    if (temp != NULL) {
        cout << "Data dalam list : ";
        while (temp != NULL) {
            cout << temp->data << ", ";
            temp = temp->pointer;
        }
        cout << endl;
    } else {
        cout << "Data dalam list kosong\n";
    }
}

void gabungList(node *head1, node *head2) {
    if (head1 == NULL) {
        head = head2;
    } else {
        node* temp = head1;
        while (temp->pointer != NULL) {
            temp = temp->pointer;
        }
        temp->pointer = head2;
    }
}

void putarList(node *&head) {
    node *sebelum = NULL;
    node *sekarang = head;
    node *sesudah = NULL;

    while (sekarang != NULL) {
        sesudah = sekarang->pointer;
        sekarang->pointer = sebelum;
        sebelum = sekarang;
        sekarang = sesudah;
    }
    head = sebelum;
}


int main() {
    tambahAwal(0, head);
    tambahAwal(-1, head);
    tambahAkhir(1, head);
    tambahAkhir(2, head);

    tambahAwal(5, head2);
    tambahAwal(4, head2);
    tambahAkhir(6, head2);

    printList(head);
    putarList(head);
    printList(head);
    printList(head2);

    gabungList(head, head2);
    printList(head);

    return 0;
}
