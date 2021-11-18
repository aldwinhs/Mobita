#include <stdio.h>
#include "help.h"

void help() {
    printf("Berikut command yang tersedia\n");
    printf("1. MOVE\t\t -> Untuk berpindah ke lokasi selanjutnya\n");
    printf("2. PICK_UP\t -> Untuk mengambil item di lokasi sekarang\n");
    printf("3. DROP_OFF\t -> Untuk mendrop off item di lokasi sekarang (Khusus item yang baru saja di pick up)\n");
    printf("4. MAP\t\t -> Untuk menampilka peta\n");
    printf("5. TO_DO\t -> Untuk menampilkan pesanan yang sudah bisa dilakukan pengambilannya (PICK_UP)\n");
    printf("6. IN_PROGRESS\t -> Untuk menampilkan barang yang ada di tas dan siap untuk diantarkan");
    printf("7. BUY\t -> Untuk menampilkan gadget yang dapat kamu beli\n");
    printf("8. INVENTORY\t -> Untuk menampilkan gadget yang telah kamu beli dan siap dipakai\n");
    printf("9. HELP\t\t -> Untuk menampilkan list command dan kegunaannnya\n");
	printf("9. EXIT\t\t -> Keluar dari permainan\n");
    // [TO DO] [OPSIONAL] printf("10. SAVE_GAME\t -> Untuk melakukan penyimpanan kondisi game sekarang untuk bisa dipakai kemudian\n");
}

void mobitastart(){
    printf(" .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.\n");
	printf("| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n");
	printf("| | ____    ____ | || |     ____     | || |   ______     | || |     _____    | || |  _________   | || |      __      | |\n");
	printf("| ||_   \\  /   _|| || |   .'    `.   | || |  |_   _ \\    | || |    |_   _|   | || | |  _   _  |  | || |     /  \\     | |\n");
	printf("| |  |   \\/   |  | || |  /  .--.  \\  | || |    | |_) |   | || |      | |     | || | |_/ | | \\_|  | || |    / /\\ \\    | |\n");
	printf("| |  | |\\  /| |  | || |  | |    | |  | || |    |  __'.   | || |      | |     | || |     | |      | || |   / ____ \\   | |\n");
	printf("| | _| |_\\/_| |_ | || |  \\  `--'  /  | || |   _| |__) |  | || |     _| |_    | || |    _| |_     | || | _/ /    \\ \\_ | |\n");
	printf("| ||_____||_____|| || |   `.____.'   | || |  |_______/   | || |    |_____|   | || |   |_____|    | || ||____|  |____|| |\n");
	printf("| |              | || |              | || |              | || |              | || |              | || |              | |\n");
	printf("| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n");
	printf("'----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' \n");
}
/* Menampilkan tulisan mobita */

void congratulations(){
	printf("                                                _             _           _     _                         _ \n");
	printf("                                               | |           | |         | |   (_)                       | |\n");
	printf("   ___    ___    _ __     __ _   _ __    __ _  | |_   _   _  | |   __ _  | |_   _    ___    _ __    ___  | |\n");
	printf("  / __|  / _ \\  | '_ \\   / _` | | '__|  / _` | | __| | | | | | |  / _` | | __| | |  / _ \\  | '_ \\  / __| | |\n");
	printf(" | (__  | (_) | | | | | | (_| | | |    | (_| | | |_  | |_| | | | | (_| | | |_  | | | (_) | | | | | \\__ \\ |_|\n");
	printf("  \\___|  \\___/  |_| |_|  \\__, | |_|     \\__,_|  \\__|  \\__,_| |_|  \\__,_|  \\__| |_|  \\___/  |_| |_| |___/ (_)\n");
	printf("                          __/ |                                                                             \n");
	printf("                         |___/                                                                              \n");
}
/* Menampilkan tulisan congratulations */

/*
1. MOVE -> Untuk berpindah ke lokasi selanjutnya
2. PICK_UP -> Untuk mengambil item dilokasi sekarang
...
8. INVENTORY -> Untuk melihat gadget yang dimiliki dan menggunakannya
9. HELP -> Untuk mengeluarkan list command dan kegunaannya
*/