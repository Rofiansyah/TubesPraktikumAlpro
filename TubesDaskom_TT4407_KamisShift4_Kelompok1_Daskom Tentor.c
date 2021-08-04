#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void header(){
	printf
	("\033[0;33m\
      ||=============================================================================||\n\
      ||        DDDDDD      AAA      SSSSS    TTTTTTTT     OOOO     RRRRRRRR         ||\n\
      ||        DD   DD   AA   AA   SS        TTTTTTTT    OO  OO    RR     RR        ||\n\
      ||        DD   DD   AAAAAAA    SSS         TT      OO    OO   RR   RR          ||\n\
      ||        DD   DD   AA   AA      SSS       TT      OO    OO   RR RR            ||\n\
      ||        DD   DD   AA   AA        SS      TT       OO  OO    RR   RR          ||\n\
      ||        DDDDDD    AA   AA    SSSSS       TT        OOOO     RR     RR        ||\n\
      ||=============================================================================||\n\n\033[0m");
}

void keluar(){
	
	system("cls");
	header();
	
	printf("\033[0;32m===== TERIMA KASIH SUDAH MENGUNJUNGI DASKOM TENTOR =====\n");
	exit(0);
}

struct akun{
	char user[100], pass[100], nama[100], nim[100], kelas[100], kontak[100], kode[100], matkul[100], deskripsi[1000];
	int saldo;
} tempn, ad, asist, maha, sort[100];

struct pembelian{
	char nama[100], kontak[100], kode[100], matkul[100], deskripsi[1000], kelas[100], nim[100];
	int saldo, paket;
} pemb;

int pill, login3x=3, i, j, x;
char y, user[100], pass[100], temp[100], pil[100];

void admin();
void menuAdmin();
void daftarAsisten();
void daftarMahasiswa();
void registAsisten();
void asisten(int a);
void menuAsisten(char x[]);
void riwayat();
void pemasukan();
void mahasiswa();
void registMaha();
void loginMaha(int a);
void menuMahasiswa(char x[]);
void lihatpaket();
void lihatAsist();
void pembelian();
void paket1();
void paket2();
void paket3();

FILE *fMaha;
FILE *fMaha2;
FILE *fAsist;
FILE *fAsist2;
FILE *fPaket;
FILE *fPaket2;


int main(){
	
	system("cls");
	header();
	
	printf("===== MENU UTAMA =====\n\n");
	printf("[1.] Admin\n[2.] Asisten\n[3.] Mahasiswa\n\033[0;31m\n[0.] Keluar\n\033[0m");
	printf("\nPilihan: "); scanf("%d", &pill);
	
	switch(pill){
		case 1: admin(); break;
		case 2: asisten(3); break;
		case 3: mahasiswa(); break;
		case 0: keluar(); break;
		default: printf("\033[0;31m\n---PILIHAN TIDAK ADA---\n"); system("PAUSE");
		main();
	}
	
	return 0;

}
void admin(){
	
	system("cls");
	header();
	
	printf("===== LOGIN ADMIN =====\n\n");
	printf("Kesempatan anda tinggal %d kali\n",login3x);
	login3x--;
	printf("Username: "); fflush(stdin); gets(ad.user);
    printf("Password: "); gets(ad.pass);
    
    if(strcmp(ad.user,"pass")==0 && strcmp(ad.pass,"pass")==0){
    	printf("\033[0;32m\n---LOGIN SUKSES---\n"); system("PAUSE");
		login3x=3; 
        menuAdmin();
	}
	else{
	 	if(login3x>0){
	 		if(strcmp(ad.user,"pass")!=0 || strcmp(ad.pass,"pass")!=0){
				printf("\033[0;36m\nUsername dan Password yang Anda masukan salah\nSilahkan coba lagi...\n");
        		system("PAUSE");
        		admin();
			}
		}
		else{
			printf("\033[0;31m\nMaaf kesempatan Anda habis\n---LOGIN GAGAL---\n");
        	system("PAUSE");
        	login3x=3;
        	main();
        }
    }
}

void menuAdmin(){
	
	system("cls");
	header();
	
	printf("===== MENU ADMIN =====\n\n");
	printf("[1.] Daftar Asisten\n[2.] Daftar Mahasiswa\n[3.] Registrasi Asisten\n\n\033[0;31m[4.] Logout\n\033[0m");
	printf("\nPilihan: "); scanf("%d", &pill);
	
	switch(pill){
		case 1: daftarAsisten(); break;
		case 2: daftarMahasiswa(); break;
		case 3: registAsisten(); break;
		case 4: main(); break;
		default: printf("\033[0;31m\n---PILIHAN TIDAK ADA---\n"); system("PAUSE");
		menuAdmin();
	}
	
}

void daftarAsisten(){
	
	system("cls");
	header();
	
	i=0;
	x=0;
	printf("===== DAFTAR ASISTEN =====\n\n");
	fAsist = fopen("Akun Asisten.dat","rb");
	fAsist2 = fopen("Akun Asisten2.dat","wb");
	
	while(fread(&asist,sizeof(asist),1,fAsist)==1){
		sort[i]=asist;
		i++; x++;
		fwrite(&asist,sizeof(asist),1,fAsist2);
	}
	
	for(i=x-1;i>=1;i--)
		for(j=1;j<=i;j++){
			if (strcmp(sort[j-1].kode,sort[j].kode)>0){
				tempn=sort[j-1];
				sort[j-1]=sort[j];
				sort[j]=tempn;
			}
		}
		
	for(i=0;i<x;i++){
		printf("%d. Kode Asisten\t: %s\n",i+1,sort[i].kode);
		printf("   Nama Matkul\t: %s\n",sort[i].matkul);
		printf("   Deskripsi\t: %s\n",sort[i].deskripsi);
		printf("   Username\t: %s\n",sort[i].user);
		printf("   Password\t: %s\n",sort[i].pass);
	}

	fclose(fAsist);
	fclose(fAsist2);
    
    printf("\033[0;36m\nTekan enter untuk kembali ke menu admin...\n"); system("PAUSE");
    menuAdmin();
    
}

void daftarMahasiswa(){
	
	system("cls");
	header();
	
	i=0;
	x=0;
	printf("===== DAFTAR MAHASISWA =====\n\n");
	fMaha = fopen("Akun Mahasiswa.dat","rb");
	
	while(fread(&maha,sizeof(maha),1,fMaha)==1){
		sort[i]=maha;
		i++; x++;
	}
	
	for(i=x-1;i>=1;i--)
		for(j=1;j<=i;j++){
			if (strcmp(sort[j-1].nama,sort[j].nama)>0){
				tempn=sort[j-1];
				sort[j-1]=sort[j];
				sort[j]=tempn;
			}
		}
		
	for(i=0;i<x;i++){
		printf("%d. Nama\t\t: %s\n",i+1,sort[i].nama); 
		printf("   NIM\t\t: %s\n",sort[i].nim);
		printf("   Kelas\t: %s\n",sort[i].kelas);
		printf("   No.Telepon\t: %s\n",sort[i].kontak);
		printf("   Username\t: %s\n",sort[i].user);
		printf("   Password\t: %s\n",sort[i].pass);
	}

	fclose(fMaha);
	printf("\033[0;36m\nTekan enter untuk kembali ke menu admin...\n"); system("PAUSE");
    menuAdmin();
 
}

void registAsisten(){
	
	system("cls");
	header();
	
	printf("===== REGISTRASI ASISTEN =====\n\n");
	printf("Kode Asisten\t: "); fflush(stdin); gets(asist.kode);
	printf("Nama Matkul\t: "); gets(asist.matkul);
	printf("Deskripsi\t: "); gets(asist.deskripsi);
	printf("Username\t: "); gets(asist.user);
	printf("Password\t: "); gets(asist.pass);
	
	fAsist = fopen("Akun Asisten.dat", "ab");
	fwrite(&asist,sizeof(asist),1,fAsist);
	fclose(fAsist);
	strcpy(temp,asist.kode);
	printf("\033[0;32m\n--- Asisten %s telah terdaftar ---\n",temp); system("PAUSE");
	system("cls");
	menuAdmin();
	
}

void asisten(int a){	
	
	fAsist = fopen("Akun Asisten.dat","rb");
	
	if(a>0){
		system("cls");
		header();
		printf("===== LOGIN ASISTEN =====\n\n");
		printf("Kesempatan anda tinggal %d kali\n", a);
		printf("Username: "); fflush(stdin); gets(user);
		printf("Password: "); gets(pass);
		while(fread(&asist,sizeof(asist),1,fAsist)==1){
			if (strcmp(asist.user, user)==0){
				if (strcmp(asist.pass, pass)==0){
					printf("\033[0;32m\n---LOGIN SUKSES---\n"); system("PAUSE");
					fclose(fAsist);
					strcpy(temp,asist.kode);
					menuAsisten(asist.kode);
				}
			}else{
				continue;
			}
		}
		fclose(fAsist);
		printf("\033[0;36m\nUsername dan Password yang Anda masukan salah\nSilahkan coba lagi...\n"); system("PAUSE");
		a--;
		asisten(a);
	}else{
		fclose(fAsist);
		main();
	}
	
}

void menuAsisten(char x[]){
	
	system("cls");
	header();
	
	printf("===== MENU ASISTEN =====\n\n");
	printf("Selamat datang, %s!\n",x);
	printf("[1.] Riwayat Transaksi Mahasiwa\n[2.] Total Pemasukan\n\n\033[0;31m[4.] Logout\n\033[0m");
	printf("\nPilihan: "); scanf("%d", &pill);
	
	switch(pill){
		case 1: riwayat(); break;
		case 2: pemasukan(); break;
		case 4: main(); break;
		default: printf("\033[0;31m\n---PILIHAN TIDAK ADA---\n"); system("PAUSE");
		menuAsisten(x);
	}
}

void riwayat(){
	
	system("cls");
	header();
	
	i=1;
	printf("===== RIWAYAT TRANSAKSI =====\n\n");
	if(pemb.saldo==50000){
		fPaket2=fopen("Data Pembelian2.dat","rb");
		while(fread(&pemb,sizeof(pemb),1,fPaket2)==1){
			printf("%d. Nama Pemesan\t: %s\n",i, pemb.nama);
			printf("   NIM\t\t: %s\n", pemb.nim);
			printf("   Kelas\t: %s\n", pemb.kelas);
			printf("   No. Telepon\t: %s\n", pemb.kontak);
			printf("--- PAKET 1 dipilih ---\n");
			i++;
		}
		fclose(fPaket2);
	}
	else if(pemb.saldo==100000){
		fPaket2=fopen("Data Pembelian2.dat","rb");
		while(fread(&pemb,sizeof(pemb),1,fPaket2)==1){
			printf("%d. Nama Pemesan\t: %s\n",i, pemb.nama);
			printf("   NIM\t\t: %s\n", pemb.nim);
			printf("   Kelas\t: %s\n", pemb.kelas);
			printf("   No. Telepon\t: %s\n", pemb.kontak);
			printf("--- PAKET 2 dipilih ---\n");
			i++;
		}
		fclose(fPaket2);
	}
	else if(pemb.saldo==150000){
		fPaket2=fopen("Data Pembelian2.dat","rb");
		while(fread(&pemb,sizeof(pemb),1,fPaket2)==1){
			printf("%d. Nama Pemesan\t: %s\n",i, pemb.nama);
			printf("   NIM\t\t: %s\n", pemb.nim);
			printf("   Kelas\t: %s\n", pemb.kelas);
			printf("   No. Telepon\t: %s\n", pemb.kontak);
			printf("--- PAKET 3 dipilih ---\n");
			i++;
		}
		fclose(fPaket2);
	}
	
	printf("\033[0;36m\n\nTekan enter untuk kembali ke menu asisten...\n"); system("PAUSE");
    menuAsisten(temp);
}

void pemasukan(){
	
	system("cls");
	header();
	
	printf("===== TOTAL PEMASUKAN =====\n\n");
	if(pemb.saldo==0){
		printf("Saldo anda\t: %d",pemb.saldo);
	}
	else{
		fPaket2=fopen("Data Pembelian2.dat","rb");
		while(fread(&pemb,sizeof(pemb),1,fPaket2)==1){
			printf("Saldo anda\t: %d",pemb.saldo);
		}
		fclose(fPaket2);
	}
	
	fclose(fPaket2);
	printf("\033[0;36m\n\nTekan enter untuk kembali ke menu asisten...\n"); system("PAUSE");
    menuAsisten(temp);
	
}

void mahasiswa(){
	
	system("cls");
	header();
	
	printf("===== MAHASISWA =====\n\n");
	printf("[1.] Registrasi\n[2.] Login\n\n\033[0;31m[4.] Kembali\n\033[0m");
	printf("\nPilihan: "); scanf("%d", &pill);
	
	switch(pill){
		case 1: registMaha(); break;
		case 2: loginMaha(3); break;
		case 4: main(); break;
		default: printf("\n---PILIHAN TIDAK ADA---\n"); system("PAUSE");
		mahasiswa();
	}
}

void registMaha(){
	
	system("cls");
	header();
	
	fMaha = fopen("Akun Mahasiswa.dat","ab");
	
	printf("===== MENU REGISTRASI =====\n\n");
	printf("Nama\t: "); fflush(stdin); gets(maha.nama);
	printf("NIM\t: "); gets(maha.nim);
	printf("Kelas\t: "); gets(maha.kelas);
	printf("No. Tlpn: "); gets(maha.kontak);
	printf("Username: "); gets(maha.user);
	printf("Password: "); gets(maha.pass);
	
	fwrite(&maha,sizeof(maha),1,fMaha);
	fclose(fMaha);
	strcpy(temp,maha.nama);
	printf("\033[0;32m\n---%s Telah Terdaftar---\n", temp); system("PAUSE");
	mahasiswa();
	
}

void loginMaha(int a){
	
	fMaha = fopen("Akun Mahasiswa.dat","rb");
	
	if(a>0){
		system("cls");
		header();
		printf("===== LOGIN MAHASISWA =====\n\n");
		printf("Kesempatan anda tinggal %d kali\n", a);
		printf("Username: "); fflush(stdin); gets(user);
		printf("Password: "); gets(pass);
		while(fread(&maha,sizeof(maha),1,fMaha)==1){
			if (strcmp(maha.user, user)==0){
				if (strcmp(maha.pass, pass)==0){
					printf("\033[0;32m\n---LOGIN SUKSES---\n"); system("PAUSE");
					fclose(fMaha);
					strcpy(temp, maha.nama);
					menuMahasiswa(maha.nama);
				}
			}else{
				continue;
			}
		}
		fclose(fMaha);
		printf("\033[0;36m\nUsername dan Password yang Anda masukan salah\nSilahkan coba lagi...\n"); system("PAUSE");
		a--;
		loginMaha(a);
	}else{
		fclose(fMaha);
		mahasiswa();
	}
}

void menuMahasiswa(char x[]){
	
	system("cls");
	header();
	
	printf("===== MENU MAHASISWA =====\n\n");
	printf("Selamat datang, %s!\n",x);
	printf("[1.] Lihat Paket\n[2.] Lihat Asisten\n[3.] Pembelian\n\n\033[0;31m[4.] Logout\n\033[0m");
	printf("\nPilihan: "); scanf("%d", &pill);
	
	switch(pill){
		case 1: lihatpaket(); break;
		case 2: lihatAsist(); break;
		case 3: pembelian(); break;
		case 4: mahasiswa(); break;
		default: printf("\033[0;31m\n---PILIHAN TIDAK ADA---\n"); system("PAUSE");
		menuMahasiswa(x);
	}
}

void lihatpaket(){
	
	system("cls");
	header();
	
	printf("===== LIHAT PAKET =====\n\n");
	printf
		("\
      	   ||===================================================================||\n\
      	   ||   --- PAKET 1 ---   ||   --- PAKET 2 ---   ||   --- PAKET 3 ---   ||\n\
      	   || 1x Pertemuan/Minggu || 2x Pertemuan/Minggu || 3x Pertemuan/Minggu ||\n\
      	   ||        Rabu         ||    Selasa-Jum'at    ||  Senin-Rabu-Jum'at  ||\n\
      	   ||   (14.00 - 16.00)   ||   (14.00 - 16.00)   ||   (14.00 - 16.00)   ||\n\
      	   ||      Rp50.000       ||      Rp100.000      ||      Rp150.000      ||\n\
      	   ||===================================================================||\n");
               
	printf("\033[0;36m\nTekan enter untuk kembali ke menu mahasiswa...\n"); system("PAUSE");
    menuMahasiswa(temp);
}

void lihatAsist(){
	
	system("cls");
	header();
	
	i=0;
	x=0;
	printf("===== LIHAT ASISTEN =====\n\n");
	fAsist2 = fopen("Akun Asisten2.dat","rb");
	fPaket = fopen("Data Pembelian.dat","wb");
	
	while(fread(&asist,sizeof(asist),1,fAsist2)==1){
		sort[i]=asist;
		i++; x++;
		fwrite(&asist,sizeof(asist),1,fPaket);
	}
	
	for(i=x-1;i>=1;i--)
		for(j=1;j<=i;j++){
			if (strcmp(sort[j-1].kode,sort[j].kode)>0){
				tempn=sort[j-1];
				sort[j-1]=sort[j];
				sort[j]=tempn;
			}
		}
		
	for(i=0;i<x;i++){
		printf("%d. Kode Asisten\t: %s\n",i+1,sort[i].kode);
		printf("   Nama Matkul\t: %s\n",sort[i].matkul);
		printf("   Deskripsi\t: %s\n",sort[i].deskripsi);
	}

	fclose(fAsist2);
	fclose(fPaket);
    
    printf("\033[0;36m\nTekan enter untuk kembali ke menu mahasiswa...\n"); system("PAUSE");
    menuMahasiswa(temp);
}

void pembelian(){
	
	system("cls");
	header();
	
	i=0;
	x=0;
	printf("===== PILIH ASISTEN =====\n\n");
	fAsist2 = fopen("Akun Asisten2.dat","rb");
	while(fread(&asist,sizeof(asist),1,fAsist2)==1){
		sort[i]=asist;
		i++; x++;
	}
	
	for(i=x-1;i>=1;i--)
		for(j=1;j<=i;j++){
			if (strcmp(sort[j-1].kode,sort[j].kode)>0){
				tempn=sort[j-1];
				sort[j-1]=sort[j];
				sort[j]=tempn;
			}
		}
		
	for(i=0;i<x;i++){
		printf("%d. %s (%s)\n",i+1,sort[i].matkul,sort[i].kode);
	}
	fclose(fAsist2);
	
	fAsist2 = fopen("Akun Asisten2.dat","rb");
	fPaket = fopen("Data Pembelian.dat","wb");
	printf("\nPilih Asisten: "); fflush(stdin); gets(pil);
	
	while(fread(&asist,sizeof(asist),1,fAsist2)==1){
			if(strcmp(asist.kode,pil)!=0){
				fwrite(&asist,sizeof(asist),1,fPaket);
			}
		}
		
	fclose(fMaha);
	fclose(fAsist2);
	fclose(fPaket);
	
	remove("Data Pembelian.dat");
    rename("Akun Asisten2.dat","Data Pembelian.dat");
	
	if(strcmp(asist.kode,pil)==0){	
	
		printf
	    ("\n\
          ||==========================('PILIH PAKET')==========================||\n\
          ||   --- PAKET 1 ---   ||   --- PAKET 2 ---   ||   --- PAKET 3 ---   ||\n\
          || 1x Pertemuan/Minggu || 2x Pertemuan/Minggu || 3x Pertemuan/Minggu ||\n\
          ||        Rabu         ||   Selasa & Jum'at   ||  Senin-Rabu-Jum'at  ||\n\
          ||   (14.00 - 16.00)   ||   (14.00 - 16.00)   ||   (14.00 - 16.00)   ||\n\
          ||      Rp50.000       ||      Rp100.000      ||      Rp150.000      ||\n\
          ||===================================================================||\n");
      
    	printf("\nPilih Paket(1-3): "); scanf("%d", &pill);
    	switch(pill){
			case 1: getchar(); paket1(); break;
			case 2: getchar(); paket2(); break;
			case 3: getchar(); paket3(); break;
			default: printf("\033[0;31m\n---PILIHAN TIDAK ADA---\n"); system("PAUSE");
			pembelian();
		}
	}
	else{
		pembelian();
	}
}

void paket1(){
	
	system("cls");
	header();
	
	strcpy(pemb.nama,temp);
	strcpy(pemb.kontak,maha.kontak);
	strcpy(pemb.kode,asist.kode);
	strcpy(pemb.nim,maha.nim);
	strcpy(pemb.kelas,maha.kelas);
	printf("===== TRANSFER DAN HUBUNGI =====\n\n");
	printf("Nama Pemesan\t\t: %s\n", pemb.nama);
	printf("No. Telepon Pemesan\t: %s\n", pemb.kontak);
	printf("Asisten yang dipilih\t: %s", pemb.kode);
	printf("\n");
	printf
("\n\
    ||=====================||\n\
    ||   --- PAKET 1 ---   ||\n\
    || 1x Pertemuan/Minggu ||\n\
    ||        Rabu         ||\n\
    ||   (14.00 - 16.00)   ||\n\
    ||      Rp50.000       ||\n\
    ||=====================||\n");
      
    printf("\nNo. Rekening\t: 150203 a.n ADMIN");
    printf("\nNo. Telepon\t: 08150203 (ADMIN)\n");
    
    printf("\nApakah Anda sudah membayarnya? [y/n] "); scanf("%c",&y);
    if (y=='Y'||y=='y'){
    	
    	fPaket2 = fopen("Data Pembelian2.dat","ab");
    	pemb.saldo=50000;
    	fwrite(&pemb,sizeof(pemb),1,fPaket2);
    	fclose(fPaket2);
        printf("\033[0;32m\n--- TRANSAKSI BERHASIL ---\n"); system("PAUSE");
        menuMahasiswa(temp);
	}
	else if(y=='N'||y=='n'){
		printf("\033[0;31m\n--- TRANSAKSI GAGAL ---\n"); system("PAUSE");
		menuMahasiswa(temp);
	}
	else{
		paket1(tempn);
	}
}

void paket2(){
	
	system("cls");
	header();
	
	strcpy(pemb.nama,temp);
	strcpy(pemb.kontak,maha.kontak);
	strcpy(pemb.kode,asist.kode);
	strcpy(pemb.nim,maha.nim);
	strcpy(pemb.kelas,maha.kelas);
	printf("===== TRANSFER DAN HUBUNGI =====\n\n");
	printf("Nama Pemesan\t\t: %s\n", pemb.nama);
	printf("No. Telepon Pemesan\t: %s\n", pemb.kontak);
	printf("Asisten yang dipilih\t: %s", pemb.kode);
	printf("\n");
	printf
("\n\
    ||=====================||\n\
    ||   --- PAKET 2 ---   ||\n\
    || 2x Pertemuan/Minggu ||\n\
    ||   Selasa & Jum'at   ||\n\
    ||   (14.00 - 16.00)   ||\n\
    ||      Rp100.000      ||\n\
    ||=====================||\n");
      
    printf("\nNo. Rekening\t: 150203 a.n ADMIN");
    printf("\nNo. Telepon\t: 08150203 (ADMIN)\n");
    
    printf("\nApakah Anda sudah membayarnya? [y/n] "); scanf("%c",&y);
    if (y=='Y'||y=='y'){
    	
    	fPaket2 = fopen("Data Pembelian2.dat","ab");
    	pemb.saldo=100000;
    	fwrite(&pemb,sizeof(pemb),1,fPaket2);
    	fclose(fPaket2);
    	printf("\033[0;32m\n--- TRANSAKSI BERHASIL ---\n"); system("PAUSE");
        menuMahasiswa(temp);

	}
	else if(y=='N'||y=='n'){
		printf("\033[0;31m\n--- TRANSAKSI GAGAL ---\n"); system("PAUSE");
		menuMahasiswa(temp);
	}
	else{
		paket2(tempn);
	}
	
}

void paket3(){
	
	system("cls");
	header();
	
	strcpy(pemb.nama,temp);
	strcpy(pemb.kontak,maha.kontak);
	strcpy(pemb.kode,asist.kode);
	strcpy(pemb.nim,maha.nim);
	strcpy(pemb.kelas,maha.kelas);
	printf("===== TRANSFER DAN HUBUNGI =====\n\n");
	printf("Nama Pemesan\t\t: %s\n", pemb.nama);
	printf("No. Telepon Pemesan\t: %s\n", pemb.kontak);
	printf("Asisten yang dipilih\t: %s", pemb.kode);
	printf("\n");
	printf
("\n\
    ||=====================||\n\
    ||   --- PAKET 3 ---   ||\n\
    || 3x Pertemuan/Minggu ||\n\
    ||  Senin-Rabu-Jum'at  ||\n\
    ||   (14.00 - 16.00)   ||\n\
    ||      Rp150.000      ||\n\
    ||=====================||\n");
      
    printf("\nNo. Rekening\t: 150203 a.n ADMIN");
    printf("\nNo. Telepon\t: 08150203 (ADMIN)\n");
    
    printf("\nApakah Anda sudah membayarnya? [y/n] "); scanf("%c",&y);
    if (y=='Y'||y=='y'){
    	
    	fPaket2 = fopen("Data Pembelian2.dat","ab");
    	pemb.saldo=150000;
    	fwrite(&pemb,sizeof(pemb),1,fPaket2);
    	fclose(fPaket2);
        printf("\033[0;32m\n--- TRANSAKSI BERHASIL ---\n"); system("PAUSE");
        menuMahasiswa(temp);
	}
	else if(y=='N'||y=='n'){
		printf("\033[0;31m\n--- TRANSAKSI GAGAL ---\n"); system("PAUSE");
		menuMahasiswa(temp);
	}
	else{
		paket3(tempn);
	}
	
}
