#include<stdio.h>

int tugas[20], quiz[20], uts[20], uas[20];

int main(){
    int i;
    float akhir[20];

    for (i = 0; i < 3; i++)
    {
        scanf("%d", &tugas[i]);
        scanf("%d", &quiz[i]);  
        scanf("%d", &uts[i]);
        scanf("%d", &uas[i]);
    }

    for (i = 0; i < 3; i++){
        akhir[i] = (tugas[i]*0.1)+(quiz[i]*0.2)+(uts[i]*0.3)+(uas[i]*0.4);
    }

    for ( i = 0; i < 3; i++){
        printf("Mahasiswa ke-%d\n", i+1);
        printf("Nilai akhir: %.0f\n", akhir[i]);

        if(akhir[i] > 90){
            printf("Huruf mutu: A");
        }else if (86 < akhir[i] && akhir[i] <= 90){
            printf("Huruf mutu: A-");
        }else if (81 <= akhir[i] && akhir[i] <= 86){
            printf("Huruf mutu: B+");
        }else if (76 <= akhir[i] && akhir[i] <= 80){
            printf("Huruf mutu: B");
        }else if (71 <= akhir[i] && akhir[i] <= 75){
            printf("Huruf mutu: B-");
        }else if (66 <= akhir[i] && akhir[i] <= 70){
            printf("Huruf mutu: C+");
        }else if (61 <= akhir[i] &&     akhir[i] <= 65){
            printf("Huruf mutu: C");
        }else if (56 <= akhir[i] && akhir[i] <= 60){
            printf("Huruf mutu: C-");
        }else if (46 <= akhir[i] && akhir[i] <= 55){
            printf("Huruf mutu: D");
        }else{
            printf("Huruf mutu: E");
        }
        printf("\n");
    }
}