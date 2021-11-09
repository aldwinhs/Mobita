#include <stdio.h>
#include "help.h"

void help() {
    printf("Berikut command yang tersedia\n");
    printf("1. MOVE\t -> Untuk berpindah ke lokasi selanjutnya\n");
    printf("2. PICK_UP\t -> Untuk mengambil item di lokasi sekarang\n");
    printf("3. DROP_OFF\t -> Untuk mendrop off item di lokasi sekarang (Khusus item yang baru saja di pick up)\n");
    printf("4. MAP\t -> Untuk menampilka peta\n");
    printf("5. TO_DO\t -> Untuk menampilkan pesanan yang sudah bisa dilakukan pengambilannya (PICK_UP)\n");
    printf("6. IN_PROGRESS\t -> Untuk menampilkan barang yang ada di tas dan siap untuk diantarkan");
    printf("7. BUY\t -> Untuk menampilkan gadget yang dapat kamu beli\n");
    printf("8. INVENTORY\t -> Untuk menampilkan gadget yang telah kamu beli dan siap dipakai\n");
    printf("9. HELP\t -> Untuk menampilkan list command dan kegunaannnya\n");
    // [TO DO] [OPSIONAL] printf("10. SAVE_GAME\t -> Untuk melakukan penyimpanan kondisi game sekarang untuk bisa dipakai kemudian\n");
}

/*
1. MOVE -> Untuk berpindah ke lokasi selanjutnya
2. PICK_UP -> Untuk mengambil item dilokasi sekarang
...
8. INVENTORY -> Untuk melihat gadget yang dimiliki dan menggunakannya
9. HELP -> Untuk mengeluarkan list command dan kegunaannya
*/