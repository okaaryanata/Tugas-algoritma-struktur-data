#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <string.h>
#include <iostream>
#include <cstdlib>
#define info(p) p->info
#define next(p) p->next
#define first(l) (l).first
#define lanakpembeli(c) (c)->lanakpembeli
#define first(ldetilbuku) (ldetilbuku).first
#define kuantitas(m) m->kuantitas
#define detailbuku(m) m->detailbuku



using namespace std;



struct databuku
{
    string judul_buku;
    string kategori;
    int harga;
    int stok;
    int terjual; //saat asign data isi terjual=0
};
typedef databuku infotypebuku;
typedef struct elm_list_buku*addressbuku;
struct elm_list_buku
{
    infotypebuku info;
    addressbuku next;
};
struct list_buku
{
    addressbuku first;
};


struct datapembeli
{

    string username,password;
};
typedef datapembeli infotypepembeli;
typedef struct bukudibeli*addressbukudibeli;
typedef struct anak_list_pembeli*addressanakpembeli;
struct anak_list_pembeli
{
    int kuantitas;
    addressanakpembeli next;
    addressbuku detailbuku;
};
typedef struct elm_list_pembeli*addresspembeli;
struct elm_list_pembeli
{
    datapembeli info;
    addresspembeli next;
    addressanakpembeli lanakpembeli;
    //addressbukudibeli pembelian;
};
 //Kalau kata aku sih typedef struct list_pembeli*addresspembeli; (ga brani ngubah takut salah)
//typedef struct list_pembeli*addresslistpembelian; //Kalau kata aku sih typedef struct listpembelian*addresslistpembelian; (ga brani ngubah takut salah)
struct list_pembeli
{
    addresspembeli first;
};

void createlistbuku (list_buku&b);
void createlistpembeli (list_pembeli&b);
addressbuku alokasi_buku (infotypebuku x);
addresspembeli alokasi_pembeli (datapembeli x);
void insertbuku (list_buku&b);
void viewbuku(list_buku&b);
addressbuku caribuku(list_buku&b,string judul);
void insertpembeli(list_pembeli&b);
void prosesbelibuku (list_pembeli&c);
void loginadmin(list_buku &c,list_pembeli&p);
void registerpembeli(list_pembeli&p);
void loginpembeli(list_buku&c, list_pembeli&p);
void menuutama();
void menu(list_buku &c,list_pembeli &p);
void menuadmin(list_buku &c, list_pembeli&p);
void menupembeli(list_buku &c,addresspembeli p);
void editbuku(list_buku &c);
void Deletefirstbuku (list_buku&b,addressbuku p);
void Deleteafterbuku (list_buku&b,addressbuku p);
void deletelastbuku(list_buku &b, addressbuku p);
void Deletebuku (list_buku&b);
addresspembeli caripembeli(list_pembeli&b,string username);
void loginregis (list_buku&c,list_pembeli&p);
void viewpembeli(list_pembeli&p);
void insertpembeli (list_pembeli&p);
void inputjmlbk(list_buku &c,addresspembeli p,addressbuku y);
void viewbuku2 (list_buku&b);
void prosesinputbuku(addresspembeli p, addressbuku y);
void dbelanja(addresspembeli p);
void viewpenjualan(list_buku &c);
#endif // HEADER_H_INCLUDED
