#include <bits/stdc++.h>

using namespace std;

struct FoodReservation {
  int no_reservasi;
  string cust;
  vector<pair<string, string>> menu;
};

class FoodReservationQueue {
private:
  
  static const int MAX_SIZE = 1000; 
  FoodReservation queue[MAX_SIZE];
  int front;
  int rear; 

public:
  FoodReservationQueue() {
    front = -1;
    rear = -1;
  }

  void enqueue(int no_reservasi, string cust, 
  vector<pair<string, string>> menu) {
    if (rear == MAX_SIZE - 1) {
      cout << "Maaf, reservasi makanan sudah penuh.\n";
    } else {
      rear++;
      queue[rear].no_reservasi = no_reservasi;
      queue[rear].cust = cust;
      queue[rear].menu = menu;
      cout << "Reservasi makanan berhasil ditambahkan.\n";
    }
  }


  void dequeue(int no_reservasi) {
    bool found = false;
    int i;
    for (i = front + 1; i <= rear; i++) {
      if (queue[i].no_reservasi == no_reservasi) {
        found = true;
        break;
      }
    }
    if (found) {
      for (; i < rear; i++) {
        queue[i] = queue[i + 1];
      }
      rear--;
     
      cout << "Reservasi makanan dengan nomor reservasi " 
      << no_reservasi << " berhasil dihapus.\n";
    } else {
      cout << "Reservasi makanan dengan nomor reservasi " 
      << no_reservasi << " tidak ditemukan.\n";
    }
  }

  void display() {
    if (front == rear) {
      cout << "Reservasi makanan kosong.\n";
    } else {
      cout << "_______________________ " << endl;
      cout << "Reservasi Makanan: "<<endl;
      cout << "_______________________ \n"<<endl;
      for (int i = front + 1; i <= rear; i++) {
        cout << "Nomor Reservasi: " << queue[i].no_reservasi << endl;
        cout << "Nama Pelanggan: " << queue[i].cust << endl;
        cout << "Menu Makanan: ";
        for (int j = 0; j < queue[i].menu.size(); j++) {
          cout << queue[i].menu[j].first << " (" << queue[i].menu[j].second << ") ";
        }
        cout <<"_______________________\n"<< endl;
      }
    }
    
  }
};

int main() {
  FoodReservationQueue queue;
  int choice,pilihan, no_reservasi = 1, pilih_menu;
  string cust,menu_makanan, tambah,jumlah;
  vector<pair<string, string>> menu;

  do {
    cout << "==============================\n";
    cout << "  RESERVASI MAKANAN  \n";
    cout << "==============================\n";
    cout << "1. Tambah Reservasi Makanan\n";
    cout << "2. Hapus Reservasi Makanan\n";
    cout << "3. Tampilkan Reservasi Makanan\n";
    cout << "4. Keluar\n";
    cout << "Pilihan Anda: ";
    cin >> pilihan;
    cout << endl;

    switch (pilihan) {
    case 1:
      cout << "Nama Pelanggan: ";
      cin >> cust;

      //appetizer
      for (int i = 1; i >0; ) {
        cout << "Appetizer"<<endl;
        cout << endl;
        cout << "Cold:\n";
        cout << "1. Fruit Salad\n";
        cout << "2. Cocktail\n";
        cout << "3. Vegetable Salad\n";
        cout << "4. Sorbet\n";
        cout << endl;
        cout << "Hot:\n";
        cout << "5. Risoles\n";
        cout << "6. Soup\n";
        cout << "7. Crouquette\n";
        cout << "8. Skip\n";
        cout << endl;
        cout << "Pilih Menu Makanan: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
          menu_makanan = "Fruit Salad";
          cout << "Jumlah: ";
          cin >> jumlah;
          menu.push_back(make_pair(menu_makanan, jumlah));
          cout << "Tambah Pesanan (Y/N)? ";
          cin >> tambah;
          if(tambah == "Y"|| tambah=="y"){
              i = 1;
          }else{
              i = 0;
          }
          break;

        case 2:
          menu_makanan = "Cocktail";
          cout << "Jumlah: ";
          cin >> jumlah;
          menu.push_back(make_pair(menu_makanan, jumlah));
          cout << "Tambah Pesanan (Y/N)? ";
          cin >> tambah;
          if(tambah == "Y"|| tambah=="y"){
              i = 1;
          }else{
              i = 0;
          }
          break;
        
        case 3:
          menu_makanan = "Vegetable Salad";
          cout << "Jumlah: ";
          cin >> jumlah;
          menu.push_back(make_pair(menu_makanan, jumlah));
          cout << "Tambah Pesanan (Y/N)? ";
          cin >> tambah;
          if(tambah == "Y"|| tambah=="y"){
              i = 1;
          }else{
              i = 0;
          }
          break;
        
        case 4:
          menu_makanan = "Sorbet";
          cout << "Jumlah: ";
          cin >> jumlah;
          menu.push_back(make_pair(menu_makanan, jumlah));
          cout << "Tambah Pesanan (Y/N)? ";
          cin >> tambah;
          if(tambah == "Y"|| tambah=="y"){
              i = 1;
          }else{
              i = 0;
          }
          break;

        case 5:
          menu_makanan = "Risoles";
          cout << "Jumlah: ";
          cin >> jumlah;
          menu.push_back(make_pair(menu_makanan, jumlah));
          cout << "Tambah Pesanan (Y/N)? ";
          cin >> tambah;
          if(tambah == "Y"|| tambah=="y"){
              i = 1;
          }else{
              i = 0;
          }
          break;

        case 6:
          menu_makanan = "Soup";
          cout << "Jumlah: ";
          cin >> jumlah;
          menu.push_back(make_pair(menu_makanan, jumlah));
          cout << "Tambah Pesanan (Y/N)? ";
          cin >> tambah;
          if(tambah == "Y"|| tambah=="y"){
              i = 1;
          }else{
              i = 0;
          }
          break;

        case 7:
          menu_makanan = "Croquette";
          cout << "Jumlah: ";
          cin >> jumlah;
          menu.push_back(make_pair(menu_makanan, jumlah));
          cout << "Tambah Pesanan (Y/N)? ";
          cin >> tambah;
           if(tambah == "Y"|| tambah=="y"){
              i = 1;
          }else{
              i = 0;
          }
          break;
          
        
        case 8:
          i = 0;
          menu.push_back(make_pair("", ""));
          break;

        default:
          cout << "Pilihan anda tidak valid\n";
          i = 1;
          break;

        }
      }

    //main courses
    for (int i = 1; i >0; ) {
        cout << "Main Course\n";
        cout << endl;
        cout << "1. Chicken Maryland\n";
        cout << "2. Pan Seared Salmon dengan Saus Bayam Creamy\n";
        cout << "3. Lasagna Panggang\n";
        cout << "4. Bratwurst Cream Pesto (Tagliatelle Pasta)\n";
        cout << "5. Skip\n";
        cout << endl;
        cout << "Pilih Menu Makanan: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
          menu_makanan = "Chicken Maryland";
          cout << "Jumlah: ";
          cin >> jumlah;
          menu.push_back(make_pair(menu_makanan, jumlah));
          cout << "Tambah Pesanan (Y/N)? ";
          cin >> tambah;
           if(tambah == "Y"|| tambah=="y"){
              i = 1;
          }else{
              i = 0;
          }
          break;

        case 2:
          menu_makanan = "Pan Seared Salmon dengan Saus Bayam Creamy";
          cout << "Jumlah: ";
          cin >> jumlah;
          menu.push_back(make_pair(menu_makanan, jumlah));
          cout << "Tambah Pesanan (Y/N)? ";
          cin >> tambah;
          if(tambah == "Y"|| tambah=="y"){
              i = 1;
          }else{
              i = 0;
          }
          break;
        
        case 3:
          menu_makanan = "Lasagna Panggang";
          cout << "Jumlah: ";
          cin >> jumlah;
          menu.push_back(make_pair(menu_makanan, jumlah));
          cout << "Tambah Pesanan (Y/N)? ";
          cin >> tambah;
          if(tambah == "Y"|| tambah=="y"){
              i = 1;
          }else{
              i = 0;
          }
          break;
        
        case 4:
          menu_makanan = "Bratwurst Cream Pesto (Tagliatelle Pasta)";
          cout << "Jumlah: ";
          cin >> jumlah;
          menu.push_back(make_pair(menu_makanan, jumlah));
          cout << "Tambah Pesanan (Y/N)? ";
          cin >> tambah;
          if(tambah == "Y"|| tambah=="y"){
              i = 1;
          }else{
              i = 0;
          }
          break;
        
        case 5:
          i = 0;
          menu.push_back(make_pair("", ""));
          break;

        default:
          cout << "Pilihan anda tidak valid\n";
          i = 1;
          break;

        }
      }
      
      //dessert
       for (int i = 1; i >0; ) {
        cout << "Dessert\n";
        cout << endl;
        cout << "1. Pudding\n";
        cout << "2. Ice Cream\n";
        cout << "3. Apple Pie\n";
        cout << "4. Souftles\n";
        cout << "5. Skip\n";
        cout << endl;
        cout << "Pilih Menu Makanan: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
          menu_makanan = "Pudding";
          cout << "Jumlah: ";
          cin >> jumlah;
          menu.push_back(make_pair(menu_makanan, jumlah));
          cout << "Tambah Pesanan (Y/N)? ";
          cin >> tambah;
          if(tambah == "Y"|| tambah=="y"){
              i = 1;
          }else{
              i = 0;
          }
          break;

        case 2:
          menu_makanan = "Ice Cream";
          cout << "Jumlah: ";
          cin >> jumlah;
          menu.push_back(make_pair(menu_makanan, jumlah));
          cout << "Tambah Pesanan (Y/N)? ";
          cin >> tambah;
          if(tambah == "Y"|| tambah=="y"){
              i = 1;
          }else{
              i = 0;
          }
          break;
        
        case 3:
          menu_makanan = "Apple Pie";
          cout << "Jumlah: ";
          cin >> jumlah;
          menu.push_back(make_pair(menu_makanan, jumlah));
          cout << "Tambah Pesanan (Y/N)? ";
          cin >> tambah;
          if(tambah == "Y"|| tambah=="y"){
              i = 1;
          }else{
              i = 0;
          }
          break;
        
        case 4:
          menu_makanan = "Souftles";
          cout << "Jumlah: ";
          cin >> jumlah;
          menu.push_back(make_pair(menu_makanan, jumlah));
          cout << "Tambah Pesanan (Y/N)? ";
          cin >> tambah;
          if(tambah == "Y"|| tambah=="y"){
              i = 1;
          }else{
              i = 0;
          }
          break;
        
        case 5:
           i = 0;
          menu.push_back(make_pair("", ""));
          break;

        default:
          cout << "Pilihan anda tidak valid\n";
          i = 1;
          break;

        }
      }

      //Beverages
       for (int i = 1; i >0; ) {
        cout << "Beverage\n";
        cout << endl;
        cout << "1. Mineral Water\n";
        cout << "2. Tea\n";
        cout << "3. Softdrink\n";
        cout << "4. Beer\n";
        cout << "5. Skip\n";
        cout << endl;
        cout << "Pilih Menu Makanan: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
          menu_makanan = "Mineral Water";
          cout << "Jumlah: ";
          cin >> jumlah;
          menu.push_back(make_pair(menu_makanan, jumlah));
          cout << "Tambah Pesanan (Y/N)? ";
          cin >> tambah;
          if(tambah == "Y"|| tambah=="y"){
              i = 1;
          }else{
              i = 0;
          }
          break;

        case 2:
          menu_makanan = "Tea";
          cout << "Jumlah: ";
          cin >> jumlah;
          menu.push_back(make_pair(menu_makanan, jumlah));
          cout << "Tambah Pesanan (Y/N)? ";
          cin >> tambah;
          if(tambah == "Y"|| tambah=="y"){
              i = 1;
          }else{
              i = 0;
          }
          break;
        
        case 3:
          menu_makanan = "Softdrink";
          cout << "Jumlah: ";
          cin >> jumlah;
          menu.push_back(make_pair(menu_makanan, jumlah));
          cout << "Tambah Pesanan (Y/N)? ";
          cin >> tambah;
          if(tambah == "Y"|| tambah=="y"){
              i = 1;
          }else{
              i = 0;
          }
          break;
        
        case 4:
          menu_makanan = "Beer";
          cout << "Jumlah: ";
          cin >> jumlah;
          menu.push_back(make_pair(menu_makanan, jumlah));
          cout << "Tambah Pesanan (Y/N)? ";
          cin >> tambah;
          if(tambah == "Y"|| tambah=="y"){
              i = 1;
          }else{
              i = 0;
          }
          break;
        
        case 5:
           i = 0;
          menu.push_back(make_pair("", ""));
          break;

        default:
          cout << "Pilihan anda tidak valid\n";
          i = 1;
          break;

        }
      }
      
        queue.enqueue(no_reservasi, cust, menu);
        no_reservasi++;
        break;

  case 2:
    cout << "Masukan Nomor Reservasi: ";
    cin >> no_reservasi;
    queue.dequeue(no_reservasi);
    break;

  case 3:
    queue.display();
    break;

  case 4:
    cout << "Terima kasih telah menggunakan layanan kami." << endl;
    break;

  default:
    cout << "Pilihan tidak valid. Silakan coba lagi.\n" << endl;
   
    }
  } while (pilihan != 4);
}

  