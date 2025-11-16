#include <stdio.h>
#include <ctype.h>

int clear_input_buffer(){
    int c, apakah_input_berlebihan = 0;
    c = getchar();
    if(c != '\n' && c != EOF){
        apakah_input_berlebihan = 1;
        while((c = getchar()) != '\n' && c != EOF);
    }
    return apakah_input_berlebihan;
}

int main(){
    int UKT, JmlAnggotaKeluarga, PrestasiAkademik, apakahPrioritas = 0, prioritas, karakter_ekstra;
    float IPK;
    long PenghasilanOrtu;
    char OrganisasiAktif = 'A', siapInput;
    char kriteria[6][1000] = {"UKT (1 sampai 7)", "Jumlah anggota keluarga", "Tingkat prestasi akademik", "IPK (0.00 sampai 4.00)", "Penghasilan orang tua", "Keaktifan dalam berorganisasi"};
    char tingkatPrioritas[3][20] = {"Rendah", "Sedang", "Tinggi"};
    char invalid[100] = "Masukkan tidak valid!";

    printf("Selamat datang ke dalam program beasiswa!\n");
    printf("Tolong persiapakan beberapa data di bawah ini dengan baik dan benar sebelum menginputkan pada sistem:\n\n");

    for(int i = 0; i < 6; i++){
        printf("%d. %s\n", i + 1, kriteria[i]);
    }
    
    do{
        printf("\nApakah sudah siap (Y/y): ");
        scanf("%c", &siapInput);
        karakter_ekstra = clear_input_buffer();
        siapInput = toupper(siapInput);
        if(siapInput != 'Y' || karakter_ekstra == 1){
            printf("%s", invalid);
            siapInput = 'N';
        }
    }while(siapInput != 'Y');

    printf("\nTolong masukkan %s: ", kriteria[0]);
    scanf("%d", &UKT);
    while(UKT < 1 || UKT > 7){
        printf("%s\nTolong masukkan %s: ", invalid, kriteria[0]);
        scanf("%d", &UKT);
    }

    printf("\nTolong masukkan %s: ", kriteria[1]);
    scanf("%d", &JmlAnggotaKeluarga);

    printf("\nKeterangan:\n");
    char keteranganPrestasiAkademik[4][100] = {"(Tidak Ada)", "(Lokal)", "(Nasional)", "(Internasional)"};
    for(int i = 0; i < 4; i++){
        printf("%d %s\n", i, keteranganPrestasiAkademik[i]);
    }
    printf("Tolong masukkan %s: ", kriteria[2]);
    scanf("%d", &PrestasiAkademik);
    while(PrestasiAkademik < 0 || PrestasiAkademik > 3){
        printf("%s\nTolong masukkan %s: ", invalid, kriteria[2]);
        scanf("%d", &PrestasiAkademik);
    }

    printf("\nTolong masukkan %s: ", kriteria[3]);
    scanf("%f", &IPK);
    while(IPK < 0.00 || IPK > 4.00){
        printf("%s\nTolong masukkan %s: ", invalid, kriteria[3]);
        scanf("%f", &IPK);
    }

    printf("\nTolong masukkkan %s: Rp. ", kriteria[4]);
    scanf("%ld", &PenghasilanOrtu);

    printf("\nKeterangan: (Y = Aktif dan T = Tidak Aktif)");
    printf("\nTolong masukkan %s: ", kriteria[5]);
    scanf(" %c", &OrganisasiAktif);
    while(!(OrganisasiAktif != 'Y' || OrganisasiAktif != 'T')){
        printf("%s\nTolong masukkan %s: ", invalid, kriteria[5]);
        scanf(" %c", &OrganisasiAktif);
    }

    if(UKT <= 3 || (PenghasilanOrtu < 3000000 || (PenghasilanOrtu < 5000000 && PenghasilanOrtu < 8000000)) && IPK >= 3.00){
        apakahPrioritas = 1;
    }else if(4 <= UKT && UKT >= 6 && (PenghasilanOrtu >= 3000000 && PenghasilanOrtu < 8000000) && IPK >= 3.50){
        apakahPrioritas = 1;
    }

    if(OrganisasiAktif == 'Y' && PrestasiAkademik > 0){
        prioritas = 2;
    }else if(OrganisasiAktif == 'Y' || PrestasiAkademik > 1){
        prioritas = 1;
    }else if(PrestasiAkademik == 0 && UKT > 5){
        apakahPrioritas = 0;
    }else{
        prioritas = 0;
    }

    printf("\nSiswa dinyatakan ");
    if(apakahPrioritas){
        printf("lolos seleksi akhir beasiswa: Prioritas %s\n", tingkatPrioritas[prioritas]);
    }else{
        printf("gagal seleksi beasiswa");
    }

    printf("Terima kasih!");
    return 0;
    
}
