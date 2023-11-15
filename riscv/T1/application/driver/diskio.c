/*-----------------------------------------------------------------------*/
/* Low level disk I/O module SKELETON for FatFs     (C)ChaN, 2019        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/

#include "../inc/ff.h"			/* Obtains integer types */
#include "../inc/diskio.h"		/* Declarations of disk functions */

/* Definitions of physical drive number for each drive */
#define DEV_RAM		0	/* Example: Map Ramdisk to physical drive 0 */
#define DEV_MMC		1	/* Example: Map MMC/SD card to physical drive 1 */
#define DEV_USB		2	/* Example: Map USB MSD to physical drive 2 */
#define STA_NOINIT		0x01	/* Drive not initialized */

/*-----------------------------------------------------------------------*/
/* Get Drive Status                                                      */
/*-----------------------------------------------------------------------*/

DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)
{
	DSTATUS stat;
	int result;
	uint8_t SD_ID[17];

	switch (pdrv) {
	case DEV_RAM :


				// translate the reslut code here

				return stat;

	case DEV_MMC :
//				result = SD_Init();
				result = SD_GetCID(&SD_ID);
				// translate the reslut code here
				SD_ID[16] = 0;
				if(result == 0)
				{
					stat = 0;  ///初始化成功
//					printf("%s",&SD_ID);
//					printf("\n");
				}
				else
					stat = STA_NOINIT;   ///初始化失败，检测不到SD卡

				return stat;

	case DEV_USB :


				// translate the reslut code here

				return stat;
	}
	return STA_NOINIT;
}



/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)
{
	DSTATUS stat;
	int result;

	switch (pdrv) {
	case DEV_RAM :


				// translate the reslut code here

				return stat;

	case DEV_MMC :

				SD_Init();

				// translate the reslut code here

				return disk_status(DEV_MMC);

	case DEV_USB :


				// translate the reslut code here

				return stat;
	}
	return STA_NOINIT;
}



/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		/* Data buffer to store read data */
	LBA_t sector,	/* Start sector in LBA */
	UINT count		/* Number of sectors to read */
)
{
	DRESULT res;
	int result;

	switch (pdrv) {
	case DEV_RAM :
				// translate the arguments here



				// translate the reslut code here

				return res;

	case DEV_MMC :
				// translate the arguments here

				result = SD_ReadDisk(buff, sector, count);

				// translate the reslut code here

				if(result == 0)
					res = RES_OK;
				else
					res = RES_ERROR;

				return res;

	case DEV_USB :
				// translate the arguments here



				// translate the reslut code here

				return res;
	}

	return RES_PARERR;
}



/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

#if FF_FS_READONLY == 0

DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE *buff,	/* Data to be written */
	LBA_t sector,		/* Start sector in LBA */
	UINT count			/* Number of sectors to write */
)
{
	DRESULT res;
	int result;

	switch (pdrv) {
	case DEV_RAM :
				// translate the arguments here



				// translate the reslut code here

				return res;

	case DEV_MMC :
				// translate the arguments here

				result = SD_WriteDisk((uint8_t*)buff, sector, count); //buff是const BYTE类型，而传入下一层需要的是uint8_t类型，所以此处进行强制转化

				// translate the reslut code here

				if(result == 0)
					res = RES_OK;
				else
					res = RES_ERROR;

				return res;

	case DEV_USB :
				// translate the arguments here



				// translate the reslut code here

				return res;
	}

	return RES_PARERR;
}

#endif


/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{
	DRESULT res;
	int result;

	switch (pdrv) {
	case DEV_RAM :

				// Process of the command for the RAM drive

				return res;

	case DEV_MMC :

				// Process of the command for the MMC/SD card
				switch(cmd)
				{
					//返回扇区个数
					case GET_SECTOR_COUNT:
							*(uint32_t *)buff = SD_GetSectorCount(); //此次试验是w25q128，全部用于文件系统，共16MB字节，即16777216字节
					break;

					//返回扇区大小
					case GET_SECTOR_SIZE:
							*(WORD *)buff = 512 ;
					break;
					//返回擦除扇区的最小个数
					case GET_BLOCK_SIZE:
							*(WORD *)buff = 1 ;   //每次擦除一个扇区
					break;
				}
				res = RES_OK;
				return res;

	case DEV_USB :

				// Process of the command the USB drive

				return res;
	}

	return RES_PARERR;
}

DWORD get_fattime (void)
{
	return 0;
}
