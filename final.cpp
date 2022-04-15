#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int jml_mhs,pilih_menu;
string matkul[8]={"Sistem Operasi","Struktur data","Komunikasi Data","Komputer Grafis"
,"Lingkungan Bisnis","Pemrograman\t","Hardware/Software","Bahasa Inggris II"};

void logo()
{
	cout << "=======================================" << endl;
	cout << "=============PENGHITUNG IPK============" << endl;
	cout << "=======================================" << endl;
}

void tabel()
{
	cout << "=======================================" << endl;
	cout << "| NIM  |\tNama\t\t| IPK |" << endl; 
	cout << "=======================================" << endl;
}
struct mahasiswa
{
	string nama;
	int nim;
	double ipk;
};

void buble_sort(struct mahasiswa mhs_arr[],int x)
{
	for(int i=0;i<(x-1);i++)
	{
		for(int j=0;j<(x-1);j++)
		{
			if(mhs_arr[j].nim > mhs_arr[j+1].nim)
			{
				struct mahasiswa swap;
				swap = mhs_arr[j];
				mhs_arr[j]=mhs_arr[j+1];
				mhs_arr[j+1]=swap;
			}
		}
	}
}

void selection_sort(struct mahasiswa mhs_arr2[],int x)
{
	for(int i=0;i<x;i++)
	{
		int maks;
		maks =i;
		for(int j=i+1;j<x;j++)
		{
			if(mhs_arr2[maks].nim>mhs_arr2[j].nim)
			{
				maks=j;
			}
		}
		if(mhs_arr2[i].nim != mhs_arr2[maks].nim)
		{
			struct mahasiswa temp;
			temp = mhs_arr2[i];
			mhs_arr2[i] = mhs_arr2[maks];
			mhs_arr2[maks] = temp;
				
		}
	}
}

void insertion_sort(struct mahasiswa mhs_arr3[],int x)
{
	struct mahasiswa temp;
	int j;
	for(int i=0;i<x;i++)
	{
		temp.nim = mhs_arr3[i].nim;
		temp.nama = mhs_arr3[i].nama;
		temp.ipk = mhs_arr3[i].ipk;
		j = i-1;
		
		while(mhs_arr3[j].nim > temp.nim && j >= 0)
		{
			mhs_arr3[j+1] = mhs_arr3[j];
			j--;
		}
		mhs_arr3[j+1].nim = temp.nim;
		mhs_arr3[j+1].nama = temp.nama;
		mhs_arr3[j+1].ipk = temp.ipk;
		
	}
	
}

int main()
{
	logo();//memanggil fungsi logo()
	cout << "Input jumlah mahasiswa : "; cin >> jml_mhs;
	//Input data diri dan nilai mahasiswa 
	
	struct mahasiswa mhs[jml_mhs];
	for(int i=0;i<jml_mhs;i++)
	{
		double jml_nilai = 0;
		cout << "Mahasiswa ke : " << i+1 << endl;
		cout << "Nama\t: "; cin >> mhs[i].nama;
		cout << "NIM\t: "; cin >> mhs[i].nim;
		cout << "==================" << endl;
		cout << "Input Nilai" << endl;
		int nilai[8];
		for(int j=0;j<8;j++)
		{
			cout << j+1 << ". " << matkul[j] << " : "; cin >> nilai[j];
			switch (nilai[j])
			{
				case 81 ... 100:
				nilai[j]=4;
				break;
				case 60 ... 80:
				nilai[j]=3;
				break;
				case 40 ... 59:
				nilai[j]=2;
				break;
				case 0 ... 39:
				nilai[j]=1;
				break; 
				default:
				break;
			}
			jml_nilai += nilai[j];
		}
		mhs[i].ipk = jml_nilai/8;
	}
	
	menu:
	cout << "Menu Sorting : " << endl;
	cout << "1. Buble Sort" << endl;
	cout << "2. Selection Sort" << endl;
	cout << "3. Insertion Sort" << endl;
	cout << "Input Pilihan : "; cin >> pilih_menu;
	
	system("cls");
	logo();
	switch (pilih_menu){
	case 1 :
	cout << "1. Bublesort" << endl;
	cout << "Sebelum : " << endl;
	tabel();
	for(int i=0;i<jml_mhs;i++)
	{
		cout << "| " << mhs[i].nim << " | " << mhs[i].nama << "\t\t\t| " << mhs[i].ipk << " | " << endl;  
	}
	cout << "=======================================" << endl;
	cout << endl << endl;
	cout << "Sesudah : " << endl;
	tabel();
	buble_sort(mhs,jml_mhs);
	for(int i=0;i<jml_mhs;i++)
	{
		cout << "| " << mhs[i].nim << " | " << mhs[i].nama << "\t\t\t| " << mhs[i].ipk << " | " << endl; 
	}
		break;
	case 2:
	cout << "2. Selectionsort" << endl;
	cout << "Sebelum : " << endl;
	tabel();
	for(int i=0;i<jml_mhs;i++)
	{
		cout << "| " << mhs[i].nim << " | " << mhs[i].nama << "\t\t\t| " << mhs[i].ipk << " | " << endl;  
	}
	cout << "=======================================" << endl;
	cout << endl << endl;
	cout << "Sesudah : " << endl;
	tabel();
	selection_sort(mhs,jml_mhs);
	for(int i=0;i<jml_mhs;i++)
	{
		cout << "| " << mhs[i].nim << " | " << mhs[i].nama << "\t\t\t| " << mhs[i].ipk << " | " << endl;  
	}
		break;
	case 3:
	cout << "3. Insertionsort" << endl;
	cout << "Sebelum : " << endl;
	tabel();
	for(int i=0;i<jml_mhs;i++)
	{
		cout << "| " << mhs[i].nim << " | " << mhs[i].nama << "\t\t\t| " << mhs[i].ipk << " | " << endl;  
	}
	cout << "=======================================" << endl;
	cout << endl << endl;
	cout << "Sesudah : " << endl;
	tabel();
	insertion_sort(mhs,jml_mhs);
	for(int i=0;i<jml_mhs;i++)
	{
		cout << "| " << mhs[i].nim << " | " << mhs[i].nama << "\t\t\t| " << mhs[i].ipk << " | " << endl;  
	}
		break;
	}
	
	cout << "=======================================" << endl;
	
}

