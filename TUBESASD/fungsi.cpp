#include "HEADER.h"
#include <string.h>
#include <iostream>
#include <conio.h>
#include<stdio.h>


using namespace std;

void createlistbuku (list_buku&b)
{first(b) = NULL;}

void createlistpembeli (list_pembeli&b)
{first(b) = NULL;}

addressbuku alokasi_buku(infotypebuku x)
{
    addressbuku p= new elm_list_buku;
    if (p==NULL)
    {cout<<"Insert gagal";}
    else
    {   info(p)=x;
        next(p)=NULL;
        return p;}
}

void insertbuku (list_buku&b)
{
    cout<<endl;
    cout<<"================================================================================"<<endl;
    cout<<"                                TOKO BUKU ONLINE\n";
    cout<<"================================================================================"<<endl;
    cout<<"                               ----Tambah Buku----"<<endl;
    infotypebuku x;
    cout<<"Masukkan Judul Buku \t: ";cin>>x.judul_buku;
    addressbuku p = caribuku(b,x.judul_buku);
    if (p!=NULL)
    {
        cout<<"Judul Buku Telah Tersedia"<<endl;
    }
    else{
    cout<<"Masukkan Kategori \t: ";cin>>x.kategori;
    cout<<"Masukkan Harga \t\t: ";cin>>x.harga;
    cout<<"Masukkan Stok \t\t: ";cin>>x.stok;
    cout<<"Jumlah Terjual \t\t: ";cin>>x.terjual;
    addressbuku baru=alokasi_buku(x);
    if (first(b)==NULL)
    {
        first(b)=baru;
    }
    else
    {
        next(baru)=first(b);
        first(b)=baru;
    }}
    cout<<endl;
    cout<<"Data Buku Berhasil Ditambahkan";
}

void viewbuku (list_buku&b)
{
    cout<<endl;
    cout<<"================================================================================"<<endl;
    cout<<"                                TOKO BUKU ONLINE\n";
    cout<<"================================================================================"<<endl;
    cout<<"                                ----View Buku----"<<endl;
    addressbuku p = first(b);
    if (p==NULL)
    {
        cout<<"Data Buku Kosong"<<endl;
    }
    else{
    while (p!=NULL)
    {
        cout<<"Judul Buku \t:"<<p->info.judul_buku<<endl;
        cout<<"Kategori \t:"<<info(p).kategori<<endl;
        cout<<"Harga \t\t:"<<info(p).harga<<endl;
        cout<<"Stok \t\t:"<<info(p).stok<<endl;
        cout<<"Jumlah Terjual \t:"<<info(p).terjual<<endl;
        p=next(p);
        cout<<"------------------------------------------------------"<<endl<<endl;
    }}
}
void viewbuku2 (list_buku&b)
{
    addressbuku p = first(b);
    if (p==NULL)
    {
        cout<<"Data Buku Kosong"<<endl;
    }
    else{
    while (p!=NULL)
    {
        cout<<"Judul Buku \t:"<<info(p).judul_buku<<endl;
        cout<<"Kategori \t:"<<info(p).kategori<<endl;
        cout<<"Harga \t\t:"<<info(p).harga<<endl;
        if(info(p).stok==0){
            cout<<"Stok \t\t: Buku kosong"<<endl;
        }
        else{
        cout<<"Stok \t\t:"<<info(p).stok<<endl;}
        //cout<<"Jumlah Terjual :"<<info(p).terjual<<endl;
        p=next(p);
        cout<<"------------------------------------------------------"<<endl<<endl;
    }}}

addressbuku caribuku(list_buku&b,string judul)
{
    addressbuku p = first(b);
    if (p==NULL)
    {
        return NULL;
    }
    else{
    while ((p!=NULL)&&(info(p).judul_buku!=judul))
    {
        p=next(p);}
    if (p==NULL)
        return NULL;
    else
    return p;}
}

addresspembeli caripembeli(list_pembeli&b,string username)
{
    addresspembeli p = first(b);
    if (p==NULL)
    {
        return NULL;
    }
    else{
    while ((p!=NULL)&&(info(p).username!=username))
    {
        p=next(p);}
    return p;}
}


addresspembeli alokasi_pembeli (datapembeli x)
{
    addresspembeli p = new elm_list_pembeli;
    info(p) = x;
    next(p) = NULL;
    lanakpembeli(p)=NULL;
    return p;
}


void editbuku(list_buku &c)
{
    cout<<endl;
    cout<<"================================================================================"<<endl;
    cout<<"                                TOKO BUKU ONLINE\n";
    cout<<"================================================================================"<<endl;
    cout<<"                                ----Edit Buku----"<<endl;
    string a;
    cout<<"Masukkan judul buku \: ";cin>>a;
    cout<<endl;
    addressbuku p=caribuku(c,a);
    if(p!=NULL){
    cout<<"--Info buku--"<<endl;
    cout<<"Judul Buku \t:"<<info(p).judul_buku<<endl;
    cout<<"Kategori \t:"<<info(p).kategori<<endl;
    cout<<"Harga \t\t:"<<info(p).harga<<endl;
    cout<<"Stok \t\t:"<<info(p).stok<<endl;
    cout<<"Jumlah Terjual \t:"<<info(p).terjual<<endl;
    cout<<"------------------------------------------------------"<<endl<<endl;
    cout<<"Masukkan Data Baru\n"<<endl;
    cout<<"Masukkan Judul Buku \t: ";cin>>info(p).judul_buku;
    cout<<"Masukkan Kategori \t: ";cin>>info(p).kategori;
    cout<<"Masukkan Harga \t\t: ";cin>>info(p).harga;
    cout<<"Masukkan Stok \t\t: ";cin>>info(p).stok;
    cout<<"Jumlah Terjual \t\t: ";cin>>info(p).terjual;
    getch();
    system("cls");
    viewbuku(c);}
    else{
        cout<<"Data Buku Kosong"<<endl;
        cout<<"Silahkan Tambah Buku"<<endl;}
}

void Deletefirstbuku (list_buku&b,addressbuku p) {
    p = first(b);
    first(b) = next (p);
    next(p) = NULL;
    delete p;
};

void Deleteafterbuku (list_buku&b, addressbuku p) {
    addressbuku q = first(b);
    while (next(q)!=p)
    {
        q=next(q);
    }
    next(q)=next(p);
    next(p) = NULL;
    delete p;
};

void deletelastbuku(list_buku&b, addressbuku p)
{
    addressbuku q = first(b);
    while (next(q)!=p)
    {
        q=next(q);
    }
    next(q)=NULL;
    delete p;
}

void Deletebuku (list_buku&b) {
    cout<<endl;
    cout<<"================================================================================"<<endl;
    cout<<"                                TOKO BUKU ONLINE\n";
    cout<<"================================================================================"<<endl;
    cout<<"                                ----Delete Buku----"<<endl;
    string judul;
    cout<<"Masukkan Judul : ";cin>>judul;
    addressbuku p = caribuku(b,judul);
    if(p!=NULL){
        if(first(b)==p)
        {
            Deletefirstbuku(b,p);
        }
        else if(next(p)==NULL)
        {
            deletelastbuku(b,p);
        }
        else
        {
            Deleteafterbuku(b,p);
        }
        cout<<endl;
        cout<<"Data Buku Berhasil Dihapus"<<endl;
    }
    else{
        cout<<endl;
        cout<<"Buku Tidak Tersedia"<<endl;
    }
};

void menuadmin(list_buku &c, list_pembeli&p)
{
int pil,pil2;
    cout<<endl;
    cout<<"================================================================================"<<endl;
    cout<<"                                TOKO BUKU ONLINE\n";
    cout<<"================================================================================"<<endl;
    cout<<"     1. View Buku\n";
    cout<<"     2. Tambah Buku\n";
    cout<<"     3. Edit Detail Buku\n";
    cout<<"     4. Delete Buku\n";
    cout<<"     5. View Penjualan\n";
    cout<<"     6. Menu Utama\n";
    cout<<endl;
    cout<<"Pilih menu: "; cin>>pil;
    switch(pil)
    {
        case 1 :
            {
                system("cls");
                viewbuku(c);
                getch();
                break;
            }
        case 2 :
            {
                system("cls");
                insertbuku(c);
                getch();
                break;
            }
        case 3 :
            {
                system("cls");
                editbuku(c);
                getch();
                break;

            }
        case 4 :
            {
                system("cls");
                Deletebuku(c);
                getch();
                break;

            }
        case 5 :
            {
                system("cls");
                viewpenjualan(c);
                getch();
                break;
            }
        case 6 :
            {
                system("cls");
                menu(c,p);
                break;
            }
}
system("cls");
menuadmin(c,p);
}

void loginadmin(list_buku &c,list_pembeli&p)
{
    string a ="admin";
    string b ="admin";
    string un,pass;
    cout<<endl;
    cout<<"================================================================================"<<endl;
    cout<<"                                TOKO BUKU ONLINE\n";
    cout<<"================================================================================"<<endl;
    cout<<"                                  ----Admin----"<<endl;
    cout<<"     Username : "; cin>>un;
    cout<<"     Password : "; cin>>pass;
    if((un==a) && (pass==b))
    {
        cout<<endl;
        cout<<"     Login Berhasil"<<endl;
        getch();
        system("cls");
        menuadmin(c,p);
    } else
    {
        system("cls");
        int i=1;
        while ( i<3 && un!=a && pass!=b){
            system("cls");
            cout<<endl;
         cout<<"================================================================================"<<endl;
    cout<<"                                TOKO BUKU ONLINE\n";
    cout<<"================================================================================"<<endl;
    cout<<"                                  ----Admin----"<<endl;
            cout<<"     Username : "; cin>>un;
            cout<<"     Password : "; cin>>pass;
            i++;
        }
    if((un==a) && (pass==b))
    {
        cout<<endl;
        cout<<"     Login Berhasil"<<endl;
        getch();
        system("cls");
        menuadmin(c,p);
    } else {
    cout<<endl;
    cout<<"     Login Gagal"<<endl;
    getch();
    system("cls");
    menu(c,p);}}

}

void menu(list_buku &c,list_pembeli &p)
{

    int pil,pil2;
    cout<<endl;
    cout<<"================================================================================"<<endl;
    cout<<"                                TOKO BUKU ONLINE\n";
    cout<<"================================================================================"<<endl;
    cout<<"Silahkan Pilih Akses Anda"<<endl<<endl;
    cout<<"     1. Admin\n";
    cout<<"     2. Pembeli\n";
    cout<<"     3. Keluar\n";
    cout<<endl;
    cout<<"Pilih : "; cin>>pil;
    switch(pil)
    {
        case 1 :
            {
                system("cls");
                loginadmin(c,p);
                getch();
                break;
            }
        case 2 :
            {
                system("cls");
                loginregis(c,p);
                break;
            }   }
}


void menupembeli(list_buku &c,addresspembeli p)
{
    string judul;
    list_pembeli m;
    cout<<endl;
    cout<<"================================================================================"<<endl;
    cout<<"                                TOKO BUKU ONLINE\n";
    cout<<"================================================================================"<<endl;string un;

    cout<<"---Daftar Buku--- \n\n";
    viewbuku2(c);
    addressbuku l=first(c);
    if(l!=NULL){
    cout<<"\nMasukan judul buku : "; cin>>judul;
    addressbuku y = caribuku(c,judul);
    if(y==NULL)
    {
        cout<<"Judul Buku salah\n";
    } else
    {
        system("cls");
         cout<<endl;
    cout<<"================================================================================"<<endl;
    cout<<"                                TOKO BUKU ONLINE\n";
    cout<<"================================================================================"<<endl;
    cout<<"                             ----Pembelian Buku----"<<endl;
        cout<<"\t----Info Buku----"<<endl;
        cout<<"\tJudul Buku \t:"<<info(y).judul_buku<<endl;
        cout<<"\tKategori \t:"<<info(y).kategori<<endl;
        cout<<"\tHarga \t\t:"<<info(y).harga<<endl;
        cout<<"\tStok \t\t:"<<info(y).stok<<endl;
        inputjmlbk(c,p,y);
        string pil2;
            cout<<endl;
            cout<<"Tekan y untuk tambah buku ,Tekan 9 untuk kembali mengaakhiri pembelian";cin>>pil2;
            if(pil2=="y")
            {
                system("cls");
                menupembeli(c,p);
            }
            else if(pil2=="9")
            {
                getch();
            system("cls");
    cout<<"\n================================================================================"<<endl;
    cout<<"                                TOKO BUKU ONLINE\n";
    cout<<"================================================================================"<<endl;
    cout<<"                             ----Nota Pembelian----"<<endl;
    int total=0;
    addressanakpembeli z = lanakpembeli(p);
    while (z!=NULL){
        cout<<"Judul Buku \t: "<<info(detailbuku(z)).judul_buku<<endl;
        cout<<"Jumlah Buku \t: "<<kuantitas(z)<<endl;
        cout<<"Total Harga \t: "<<kuantitas(z)*info(detailbuku(z)).harga<<endl;
        total=(total+(kuantitas(z)*info(detailbuku(z)).harga));
        cout<<"--------------------------------------------------------------"<<endl;
        z=next(z);}
    cout<<"Total Harga Keseluruhan: "<<total<<endl;
    cout<<"TERIMA KASIH TELAH BERBELANJA DI TOKO KAMI";
    getch();
    system("cls");
    menu(c,m);
            }
        }
    }
}


void inputjmlbk(list_buku &c,addresspembeli p,addressbuku y)
{
    int jml;
    string pil2;
    cout<<"\n\nJumlah buku : ";cin>>jml;
        if(jml>info(y).stok)
        {
            cout<<endl;
            cout<<"Jumlah buku melebihi stok"<<endl;
            cout<<"Input Ulang"<<endl;
            getch();
            inputjmlbk(c,p,y);


        } else
        {
            cout<<"Buku berhasil ditambahkan";
            if (lanakpembeli(p)==NULL)
            {
                    addressanakpembeli m = new anak_list_pembeli;
                    kuantitas(m)=jml;
                    next(m)=NULL;
                    detailbuku(m)=y;
                    lanakpembeli(p)=m;
            }
            else{
                    addressanakpembeli m = new anak_list_pembeli;
                    kuantitas(m)=jml;
                    next(m)=lanakpembeli(p);
                    detailbuku(m)=y;
                    lanakpembeli(p)=m;
            }
            info(y).stok=info(y).stok-jml;
            info(y).terjual=info(y).terjual+jml;
            getch();
            system("cls");
    cout<<"\n================================================================================"<<endl;
    cout<<"                                TOKO BUKU ONLINE\n";
    cout<<"================================================================================"<<endl;
    cout<<"                             ----Nota Pembelian----"<<endl;
    int total=0;
    addressanakpembeli z = lanakpembeli(p);
    while (z!=NULL){
        cout<<"Judul Buku \t: "<<info(detailbuku(z)).judul_buku<<endl;
        cout<<"Jumlah Buku \t: "<<kuantitas(z)<<endl;
        cout<<"Total Harga \t: "<<kuantitas(z)*info(detailbuku(z)).harga<<endl;
        total=(total+(kuantitas(z)*info(detailbuku(z)).harga));
        cout<<"--------------------------------------------------------------"<<endl;
        z=next(z);}
    cout<<"Total Harga Keseluruhan: "<<total;
}}
void dbelanja(addresspembeli p)
{

    cout<<"\n================================================================================"<<endl;
    cout<<"                                TOKO BUKU ONLINE\n";
    cout<<"================================================================================"<<endl;
    cout<<"                             ----Nota Pembelian----"<<endl;
    int total=0;
    addressanakpembeli z = lanakpembeli(p);
    while (z!=NULL){
        cout<<"Judul Buku \t: "<<info(detailbuku(z)).judul_buku<<endl;
        cout<<"Jumlah Buku \t: "<<kuantitas(z)<<endl;
        cout<<"Total Harga \t: "<<kuantitas(z)*info(detailbuku(z)).harga<<endl;
        total=(total+(kuantitas(z)*info(detailbuku(z)).harga));
        cout<<"--------------------------------------------------------------"<<endl;
        z=next(z);
    }
    cout<<"Total Harga Keseluruhan: "<<total;
}



void insertpembeli (list_pembeli&p)
{
    cout<<endl;
    cout<<"================================================================================"<<endl;
    cout<<"                                TOKO BUKU ONLINE\n";
    cout<<"================================================================================"<<endl;string un;

    datapembeli x;
    cout<<"\tUsername \t: ";cin>>x.username;
    addresspembeli y = caripembeli(p,x.username);
    if (y!=NULL)
    {
        cout<<"\tUser Telah Tersedia"<<endl;
    }
    else{
    cout<<"\tPassword \t: ";cin>>x.password;
    addresspembeli baru=alokasi_pembeli(x);
    if (first(p)==NULL)
    {
        first(p)=baru;
    }
    else
    {
        next(baru)=first(p);
        first(p)=baru;
    }
    cout<<endl;
    cout<<"Register Berhasil"<<endl;}
}


void loginpembeli(list_buku &c, list_pembeli&p)
{

    cout<<endl;
    cout<<"================================================================================"<<endl;
    cout<<"                                TOKO BUKU ONLINE\n";
    cout<<"================================================================================"<<endl;string un;

    string pass;
    cout<<"     Username : "; cin>>un;
    addresspembeli y = caripembeli(p,un);
    if (y==NULL)
    {
        cout<<endl;
        cout<<"     Registrasi dulu"<<endl;
        getch();
        system("cls");
        loginregis(c,p);
    }
    else{
    cout<<"     Password : "; cin>>pass;
    if(pass==info(y).password){
        cout<<endl;
        cout<<"     Login berhasil"<<endl;
        getch();
        system("cls");
        menupembeli(c,y);
    }
    else
    {
        cout<<endl;
        cout<<"Login gagal "<<endl;
        getch();
        system("cls");
        loginpembeli(c,p);}
    }
}

void loginregis (list_buku&c,list_pembeli&p)
{
    int pil2;
    cout<<endl;
    cout<<"================================================================================"<<endl;
    cout<<"                                TOKO BUKU ONLINE\n";
    cout<<"================================================================================"<<endl;
    cout<<"     1. Login\n";
    cout<<"     2. Register\n";
    cout<<"     3. Menu Utama\n\n";
    cout<<"Pilih : "; cin>>pil2;

    if(pil2==1)
    {
        system("cls");
        loginpembeli(c,p);
    } else if (pil2==2)
    {
        system("cls");
        insertpembeli(p);
        getch();
        system("cls");
        loginregis(c,p);}
    else if(pil2==3)
    {
        system("cls");
        menu(c,p);
    }
}
void viewpembeli(list_pembeli&p)
{
    addresspembeli y = first(p);
    if (y==NULL){
        cout<<"kosong"<<endl;
    }
    else{
    while (y!=NULL)
    {
        cout<<info(y).username<<info(y).password<<endl;
        y=next(y);
    }}
}
void viewpenjualan(list_buku &c)
{
    cout<<endl;
    cout<<"================================================================================"<<endl;
    cout<<"                                TOKO BUKU ONLINE\n";
    cout<<"================================================================================"<<endl;
    cout<<"                           ----View Penjualan Buku----"<<endl;
    int jumlah=0;
    addressbuku p = first(c);
    while (p!=NULL){
        cout<<"Judul Buku \t: "<<info(p).judul_buku<<endl;
        cout<<"Jumlah Terjual \t: "<<info(p).terjual<<endl;
        cout<<"Pemasukan \t: "<<info(p).terjual*info(p).harga<<endl;
        jumlah=jumlah+info(p).terjual*info(p).harga;
        p=next(p);
        cout<<"------------------------------------------------------"<<endl<<endl;
    }
    cout<<"Total Pemasukan : "<<jumlah<<endl;
}
