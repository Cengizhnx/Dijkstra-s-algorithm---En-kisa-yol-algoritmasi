// Dijkstra201307087.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <limits.h>
#include <stdio.h>
#include <iostream>

using namespace std;

#define V 8   //8 düğüm olduğu için V sabitini 8 tanımlıyorz.

int minyol(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}
                                                            //Uzaklık değerlerini kaynak düğüm için 0 olarak atadım, böylece ilk önce seçilecek.
int yaz(int dist[], int n) {
    cout << "Dugum | Kaynak dugumden olan uzaklik\n";
    for (int i = 0; i < V; i++)
       printf("%d \t %d\n", i, dist[i]);
    return 0;
}
                                                            //Grafikteki tüm düğümleri En kısa yola (minyol) gelene kadar döngü içerisine girmesini sağladım.
void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {               //Ziyaret edilmeyen ve en yakın olan yeni bir düğüm alıyoruz.
        int u = minyol(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)                                //Bu tepe noktasını En kısa yola (minyol) ekliyoruz.
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) dist[v] = dist[u] + graph[u][v];
    }                                                               //tepe düğümün tüm bitişik köşeleri için mesafeleri güncelliyoruz.
    yaz(dist, V);
}

int main() {                                         //Her düğüm için komşu düğümlerine olan uzaklıkları grafiğe uygun olarak giriyoruz.
    int graph[V][V] = { { 0, 2, 5, 0, 2, 0, 0, 0},        // 0. düğümden başlanıyor.
       { 2, 0, 8, 3, 0, 0, 0, 0 },                          
       { 5, 8, 0, 7, 3, 0, 0, 0 },                          
       { 0, 0, 0, 0, 0, 4, 3, 0 },                          
       { 0, 0, 0, 9, 0, 6, 0, 7 },
       { 0, 0, 0, 4, 6, 0, 4, 6 },
       { 0, 0, 0, 3, 0, 4, 0, 1 },
       { 0, 0, 0, 0, 7, 6, 0, 0 },                          // 7. düğümde bitti. Toplam 8 düğüm.
    };
    dijkstra(graph, 0);
    return 0;
}

// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin
