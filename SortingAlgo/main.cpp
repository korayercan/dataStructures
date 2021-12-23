#include <iostream>

using namespace std;

//yerle�tirmeli s�ralama (insertion sort)
function void yerlestirmeli(){
    int n; //1 den n e kadar olan listenin uzunlu�u
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
//�al��ma zaman� n^2     kar��la�t�rma say�s� = n(n-1)/2
//*******************************************************
// Direk Yerle�tirmeli S�ralama (Straight Insertion Sort)
function void direkyerlestirmeli(){
    int n; //1 den n e kadar olan listenin uzunlu�u
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
//�al��ma zaman� n^2     kar��la�t�rma say�s� = n^2/4
//*******************************************************
// �kili Yerle�tirmeli S�ralama(Binary Insertion Sort)
function ikiliyerlestirmeli(){
    int n; //1 den n e kadar olan listenin uzunlu�u
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
//�al��ma zaman� nlog(n)     kar��la�t�rma say�s� = n(log(n)-log(e)+-0.5)
//*******************************************************
//Se�meli S�ralama(Selection sort)
function void secmelis�ralama(){
    int n; //1 den n e kadar olan listenin uzunlu�u
    for(i=0;i<n;i++){
        int min = i ;
        for(j=i+1;j<n;j++){
            if(D[j]<D[min])
                min=j;
                yerdegis(min,i);
        }
    }
}
//��al��ma zaman� n(n-1)/2     kar��la�t�rma say�s� = n^2/2
//*******************************************************
//kabarc�k s�ralama(bubble sort)
function void kabarcik(){
    int n; //1 den n e kadar olan listenin uzunlu�u
    for(i=n;i>1;i--){
        for(j=0;j>i-1;j++)
            if(D[j]>D[j+1])
                yerdegis(j,j+1);
    }
}
//��al��ma zaman� n^2     kar��la�t�rma say�s� = n^2/2
//*******************************************************
//H�zl� S�ralama (quick sort)
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
//��al��ma zaman� nlog(n)     kar��la�t�rma say�s� = 2nln(n)
//*******************************************************
//k�meleme kullanarak s�ralama(heap sort)
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
//�al��ma zaman� = n log(n) Kar��la�t�rma Say�s� =2n log(n)
//*******************************************************
// Kabuk S�ralamas� ( Shell Sort)
function void kabuks�ralama(){
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
//�al��ma zaman� = n^1,5 Kar��la�t�rma Say�s� =n^1,5
//*******************************************************

int main()
{
    return 0;
}
