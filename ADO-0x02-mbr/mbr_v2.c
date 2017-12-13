/* With help of Guilherme... */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	uint8_t status;
	uint8_t primeiroSetor[3];
	uint8_t tipo;
	uint8_t ultimoSetor[3];
	uint32_t LBA;
	uint32_t numeroDeSetores;
} disco;

int main() {
	FILE *fileRead = fopen("mbr.bin", "rb");
	disco sda1, sda2, sda3, sda4;

	if(fileRead == NULL) {
    	printf("Erro ao ler arquivo!\n");
    	exit(EXIT_FAILURE);
  	}

  	printf("Dispositivo  Boot    Start	 End	  Bloks	Id System\n");

  	int i;

  	fseek(fileRead, 446, SEEK_CUR);

  	fread(&sda1, sizeof(disco), 1, fileRead);
  	fread(&sda2, sizeof(disco), 1, fileRead);
  	fread(&sda3, sizeof(disco), 1, fileRead);
  	fread(&sda4, sizeof(disco), 1, fileRead);

  	if (sda1.tipo != 0x00) {
  		printf("/dev/sda1");
	  	printf("       ");
	  	printf(sda1.status == 0x80 ? "*" : " ");
	  	printf("     %d   %u     %d %02X", sda1.LBA, sda1.LBA + sda1.numeroDeSetores, sda1.numeroDeSetores / 2, sda1.tipo);
	  	printf(" ");
	  	printf(sda1.tipo == 0X83 ? "Linux" : "Linux LVM");
	  	printf("\n");
  	}

  	if (sda2.tipo != 0x00) {
  		printf("/dev/sda2");
	  	printf("       ");
	  	printf(sda2.status == 0x80 ? "*" : " ");
	  	printf("  %d  %u    %d %02X", sda2.LBA, sda2.LBA + sda2.numeroDeSetores, sda2.numeroDeSetores / 2, sda2.tipo);
	  	printf(" ");
	  	printf(sda2.tipo == 0X83 ? "Linux" : "Linux LVM");
	  	printf("\n");
  	}

  	if (sda3.tipo != 0x00) {
  		printf("/dev/sda3");
	  	printf("       ");
	  	printf(sda3.status == 0x80 ? "*" : " ");
	  	printf(" %d %u    %d %02X", sda3.LBA, sda3.LBA + sda3.numeroDeSetores, sda2.numeroDeSetores / 2, sda3.tipo);
	  	printf(" ");
	  	printf(sda3.tipo == 0X83 ? "Linux" : "Linux LVM");
	  	printf("\n");
  	}

  	if (sda4.tipo != 0x00) {
  		printf("/dev/sda4");
	  	printf("       ");
	  	printf(sda4.status == 0x80 ? "*" : " ");
	  	printf("        %d         %u    %d %02X", sda4.LBA, sda4.LBA + sda4.numeroDeSetores, sda2.numeroDeSetores / 2, sda4.tipo);
	  	printf(" ");
	  	printf(sda4.tipo == 0X83 ? "Linux" : "Linux LVM");
	  	printf("\n");
  	}

  	fclose(fileRead);

  	return EXIT_SUCCESS;
}
