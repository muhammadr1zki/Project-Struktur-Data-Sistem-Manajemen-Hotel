#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int choice;

    while (true) {
        // Menampilkan menu pilihan
        cout << "\nPilih program yang akan dijalankan:\n";
        cout << "1. Reservasi Kamar\n";
        cout << "2. Reservasi Makanan\n";
        cout << "3. SDM Hotel\n";
        cout << "4. Keluar\n";
        cout << "\nPilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system("ReservasiKamar.exe");
                break;
            case 2:
                system("ReservasiMakanan.exe");
                break;
            case 3:
                system("SdmHotel.exe");
                break;
            case 4:
                cout << "Terima kasih! Program selesai.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    }

    return 0;
}
