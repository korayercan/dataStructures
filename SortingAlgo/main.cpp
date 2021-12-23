#include <iostream>

using namespace std;

//yerleþtirmeli sýralama (insertion sort)
function void yerlestirmeli(){
    int n; //1 den n e kadar olan listenin uzunluðu
    for(int i=1;i<n;i++){
        for(int j = i;j>=0;j--){
            if(D[j]<D[j-1]){
                yerdegis(j,j-1);
            }
            else break;
        }
    }
}
function void yerdegis(int j,int jeksi1){
    int atama = D[j];
    D[j] = D[jeksi1];
    D[jeksi1] = atama;
}
//çalýþma zamaný n^2     karþýlaþtýrma sayýsý = n(n-1)/2
//*******************************************************
// Direk Yerleþtirmeli Sýralama (Straight Insertion Sort)
function void direkyerlestirmeli(){
    int n; //1 den n e kadar olan listenin uzunluðu
    for(int i=1;i<n;i++){
      T = D[i];
      j=i;
      while(j>0&&D[j-1]>T){
        D[j]=D[j-1];
        j--;
      }
      D[j]=T;
    }
}
//çalýþma zamaný n^2     karþýlaþtýrma sayýsý = n^2/4
//*******************************************************
// Ýkili Yerleþtirmeli Sýralama(Binary Insertion Sort)
function ikiliyerlestirmeli(){
    int n; //1 den n e kadar olan listenin uzunluðu
    for(int i=1;i<n;i++){
        X = D[i];
        alt = 0;
        ust = i-1;
        while(alt<=ust){
            int pivot =(alt+ust)/2;
            if(X<D[pivot]) ust = pivot -1;
            else alt = pivot +1;
        }
        for(j=i;j>=alt;j--){
            D[j+1]=D[j];
            D[alt]=X;
        }
    }

}
//çalýþma zamaný nlog(n)     karþýlaþtýrma sayýsý = n(log(n)-log(e)+-0.5)
//*******************************************************
//Seçmeli Sýralama(Selection sort)
function void secmelisýralama(){
    int n; //1 den n e kadar olan listenin uzunluðu
    for(i=0;i<n;i++){
        int min = i ;
        for(j=i+1;j<n;j++){
            if(D[j]<D[min])
                min=j;
                yerdegis(min,i);
        }
    }
}
//ççalýþma zamaný n(n-1)/2     karþýlaþtýrma sayýsý = n^2/2
//*******************************************************
//kabarcýk sýralama(bubble sort)
function void kabarcik(){
    int n; //1 den n e kadar olan listenin uzunluðu
    for(i=n;i>1;i--){
        for(j=0;j>i-1;j++)
            if(D[j]>D[j+1])
                yerdegis(j,j+1);
    }
}
//ççalýþma zamaný n^2     karþýlaþtýrma sayýsý = n^2/2
//*******************************************************
//Hýzlý Sýralama (quick sort)
function void quicksort(int alt, int ust){
    int pivot=D[(alt+ust)/2];
    int ustsinir = ust;
    int altsinir = alt;
    do{
        while(pivot < D[ustsinir]){
            ustsinir--;
            while(pivot>D[altsinir]){
                altsinir++;
                if(altsinir <= ustsinir){
                    if(altsinir != ustsinir)
                        yerdegis(ustsinir,altsinir);
                        ustsinir--;
                        altsinir++;
                }
            }
        }
    }while(ustsinir>=altsinir);
    if(alt<ustsinir)
        quicksort(alt,ustsinir);
    if(ust>altsinir)
        quicksort(altsinir,ust);
}
//ççalýþma zamaný nlog(n)     karþýlaþtýrma sayýsý = 2nln(n)
//*******************************************************
//kümeleme kullanarak sýralama(heap sort)
function void downheap(int k, int n){
    T=D[k-1];
    while ( k <= n/2) {
        j=k+k;
        if (( j<N ) && ( D[j-1] < D[j] )
            j++;
            if ( T >= D[j-1] )  break;
            else { D[k-1] = D[j-1]; k=j;
        }
    }
    D[k-1] = T;
}

function void heapsort() {
    for ( k = n/2; k > 0; k--)
        downheap( k , n);
        do {
            yerdegis( 0 , n-1);
            --n;
            downheap( 1 , n);
        } while ( n > 1);
}
//Çalýþma zamaný = n log(n) Karþýlaþtýrma Sayýsý =2n log(n)
//*******************************************************
// Kabuk Sýralamasý ( Shell Sort)
function void kabuksýralama(){
    h=1;
    while ( ( h*3+1) < n)
        h=3*h+1;
        while ( h > 0) {
            for ( i = h-1; i < n; i++) {
                B = D[i];
                j = i;
                for ( j = i; ( j >= h) && (D[j-h] > B ); j-=h)
                    D[j] = D[j-h];
                    D[j] = B;
            }
            h /=3;
        }
}
//Çalýþma zamaný = n^1,5 Karþýlaþtýrma Sayýsý =n^1,5
//*******************************************************

int main()
{
    return 0;
}
