#include <iostream>
using namespace std;
#include <string.h>
class node
{
public:
    int noMhs;
    node *next;
};
class LinkedList
{
    node *START;
}
void addNode()
    {
        int nim;
        cout << "\nMasukkan Nomor Mahasiswa: ";
        cin >> nim;

        node *nodeBaru = new node;
        nodeBaru->noMhs = nim;

        if (START == NULL || nim <= START->noMhs)
        {
            if ((START != NULL) && (nim == START->noMhs))
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            nodeBaru->next = START;
            START = nodeBaru;
            return;
        }
        node *previous = START;
        node *current = START;
        while ((current != NULL) && (nim >= current->noMhs))
        {
            if (nim == current->noMhs)
            {
                cout << "\nDuplikasi tidak di ijinkan";
                return;
            }
            previous = current;
            current = current->next;
        }
        nodeBaru->next = current;
        previous->next = nodeBaru;
    }

    bool listEmpty()
    {
        return (START == NULL);
    }
    bool search(int nim, node **previous, node **current)
    {
        *previous == START;
        *current = START;
        while ((*current != NULL) && (nim != (*current)->noMhs))
        {
            *previous = *current;
            *current = (*current)->next;
        }
        return (*current != NULL);
    }
    bool delNode(int nim)
    {
        node *current, *previous;
        if (search(nim, &previous, &current))
            return false;

        if (current == START)
            START == START->next;
        else
            previous->next = current->next;
        delete current;
        return;
    }
    void traverse()
    {
        if (listEmpty())
        {
            cout << "\nList kosong\n";
        }
        else
        {
            cout << "\nData didalam list:\n";
            node *currentNode = START;
            while (currentNode != NULL)
            {
                cout << currentNode->noMhs << endl;
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    LinkedList mhs;
    int nim;
    char ch;
    while (1)
    {
        cout << endl
             << "menu";
        cout << endl
             << "1. Menambah data kedalam list " << endl;
        cout << "2. menghapus data dari dalam list " << endl;
        cout << "3. menampilkan semua data didalam list" << endl;
        cout << "4. mencari data dalam list" << endl;
        cout << "5. keluar" << endl;
        cout << endl
             << "masukkan pilihan (1-5):";
        cin >> ch;
        switch (ch)
        {
        case '1':
        {
            mhs.addNode();
        }
        break;
        case '2':
       
        break;
        case '3':
        {
            mhs.traverse();
        }
        break;
        case '4':
        {
            if (mhs.listEmpty() == true)
            {
                cout << "\nlist kosong\n";
                break;
            }
            node *previous, *current;
            cout << endl
                 << "masukkan no mahasiswa yang dicari : ";
            cin >> nim;
            if (mhs.search(nim, &previous, &current) == false)
                cout << endl
                     << "data tidak ditemukan" << endl;
            else
            {
                cout << endl
                     << "data ditemukan" << endl;
                cout << "\nNo Mahasiswa" << current->noMhs << endl;
                cout << "\n";
            }
            break;
        case '5':
        {
            exit(0);
        }
        break;
        default:
        {
            cout << "pilihan salah !." << endl;
        }
            {
                break;
            }
        }
        }
    }
}
