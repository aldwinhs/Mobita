# Tugas Besar 1 IF2110 Algoritma dan Struktur Data

## Deskripsi Program
Program ini dibuat untuk memenuhi Tugas Besar 1 IF2110 Algoritma dan Struktur Data. Program ini merupakan program permainan simulasi kurir berbahasa C berbasis command-line interface.

Fitur yang terdapat di dalam program :
1. Melacak pesanan.
2. Navigasi peta.
3. _Pick_ up dan _drop off item_.

Folder yang terdapat di dalam program:
1. `ADT` berisi ADT-ADT yang digunakan untuk pembuatan program.
2. `config` berisi file konfigurasi.
3. `docs` berisi laporan tugas besar.
4. `driver` berisi source code untuk mengecek fungsionalitas fungsi tertentu.
5. `pcolor` berisi modul yang dipakai untuk memberi pewarnaan pada text.
6. `src` berisi fungsionalitas-fungsionalitas dan main program.

## Cara Instalasi dan Penggunaan Website
1. Clone repository
    ```bash
    git clone https://github.com/aldwinhs/Mobita.git
    ```
2. Masuk ke terminal dengan directory tempat dilakukannya _clone repository_, misalnya `../mobita`
### Untuk sistem operasi Windows
3. Pastikan gcc sudah terinstall, kemudian masukkan command `./makeFile.bat` pada terminal
### Untuk sistem operasi Linux
3. Pastikan gcc sudah terinstall [(Cek di sini)](https://linuxize.com/post/how-to-install-gcc-compiler-on-ubuntu-18-04/), kemudian masukkan command `gcc src/*.c ADT/*.c pcolor/pcolor.c -o mobita` pada terminal
4. Masukkan command `./mobita`
5. Mulai permainan, dan masukkan nama file konfigurasi, misalnya `ayam.txt`

## Anggota Kelompok
Program ini dibuat oleh Kelompok 5 K3 yang beranggotakan:
1. Mahesa Lizardy (13520116)
2. Gerald Abraham Sianturi (13520138)
3. Rania Dwi Fadhilah (13520142)
4. Jundan Haris (13520155)
5. Aldwin Hardi Swastia (13520167)
