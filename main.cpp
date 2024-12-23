#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void sortTicketsRecursive(int tickets[], int n, int start = 0) {
    if (start >= n - 1) {
        return;
    }
    int minIndex = start;
    for (int i = start + 1; i < n; i++) {
        if (tickets[i] < tickets[minIndex]) {
            minIndex = i;
        }
    }
    int temp = tickets[start];
    tickets[start] = tickets[minIndex];
    tickets[minIndex] = temp;
    sortTicketsRecursive(tickets, n, start + 1);
}

void sortTicketsIterative(int tickets[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (tickets[j] < tickets[minIndex]) {
                minIndex = j;
            }
        }
        int temp = tickets[i];
        tickets[i] = tickets[minIndex];
        tickets[minIndex] = temp;
    }
}

int main() {
    int masuk;
    cout<<"1. Iteratif\n";
    cout<<"2. Recursive\n";
    cout<<"Pilih : ";
    cin>>masuk;

    if (masuk == 2){
        int n;
        cout<<"Masukan banyak input: ";
        cin>> n;
        clock_t start = clock(); // Catat waktu awal

        srand(time(0));
        int tickets[n]; // 1 = VIP, 2 = Ekonomi
        int minim = 1, maks = 2;
        for(int i=0;i<n;i++){
            tickets[i] = rand()% (maks - minim + 1) + minim;
        }

        int vip=0,ekonomi=0;

        cout << "INPUTAN : \n";
        for (int i = 0; i < n; i++) {
            if(tickets[i]==1){
                cout << "VIP" << " ";
                vip++;
            }else{
                cout << "EKONOMI" << " ";
                ekonomi++;
            }
        }
        cout << endl;

        sortTicketsRecursive(tickets, n);

        cout << "\n\n\nAfter Sorting: \n";
        for (int i = 0; i < n; i++) {
            if(tickets[i]==1){
                cout << "VIP" << " ";
            }else{
                cout << "EKONOMI" << " ";
            }
        }

        clock_t end = clock(); // waktu akhir

        // durasi detik
        double durasidetik = double(end - start) / CLOCKS_PER_SEC;

        // Konversi jadi milidetik
        double durasiMS = durasidetik * 1000;
        cout << "\n\nRunning time : " << durasiMS << " millisecond" << endl;


        cout << endl;
        cout<<"Total tiket VIP : "<< vip<<endl;
        cout<<"Total tiket Ekonomi : "<< ekonomi<<endl;
        cout<<"Menggunakan algoritma rekursif\n";
        return 0;
    }else if(masuk ==1){
        int n;
        cout<<"Masukan banyak input: ";
        cin>> n;
        clock_t start = clock(); // waktu awal

        srand(time(0));
        int tickets[n]; // 1 = VIP, 2 = Ekonomi
        int minim = 1, maks = 2;
        for(int i=0;i<n;i++){
            tickets[i] = rand()% (maks - minim + 1) + minim;
        }

        int vip=0,ekonomi=0;

        cout << "INPUTAN: \n";
        for (int i = 0; i < n; i++) {
            if(tickets[i]==1){
                cout << "VIP" << " ";
            }else{
                cout << "EKONOMI" << " ";
            }
        }
        cout << endl;

        sortTicketsIterative(tickets, n);

        cout << "\n\n\nAfter Sorting: \n";
        for (int i = 0; i < n; i++) {
            if(tickets[i]==1){
                vip++;
                cout << "VIP" << " ";
            }else{
                ekonomi++;
                cout << "EKONOMI" << " ";
            }
        }

        clock_t end = clock(); // waktu akhir

        // durasi detik
        double durasidetik = double(end - start) / CLOCKS_PER_SEC;

        // Konversi jadi milidetik
        double durasiMS = durasidetik * 1000;
        cout << "\n\nRunning time : " << durasiMS << " millisecond" << endl;


        cout << endl;
        cout<<"Total tiket VIP : "<< vip<<endl;
        cout<<"Total tiket Ekonomi : "<< ekonomi<<endl;
        cout<<"Menggunakan algoritma iteratif\n";
        return 0;
    }
}
