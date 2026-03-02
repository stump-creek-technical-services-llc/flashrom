/*
 * This file is part of the flashrom project.
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 * SPDX-FileCopyrightText: 2026 Stump Creek Technical Services LLC <mstoops@stumpcreektechnicalservices.com>
 */

	{
		/* ZB25VQ16
		 *
		 * Datasheet reference: https://semic-boutique.com/wp-content/uploads/2016/05/ZB25VQ16.pdf
		 *
		 * 3V 16M-BIT
		 * SERIAL NOR FLASH WITH
		 * DUAL AND QUAD SPI
		 *
		 * The example chip was found in a YOGASLEEP ROHM sound machine: https://yogasleep.com/products/rohm
		 * https://github.com/stump-creek-technical-services-llc/hardware_hacking_YOGASLEEP_ROHM_3RUS1WTBU
		 */

		/* Vendor as shown on the datasheet footer
		 * (https://semic-boutique.com/wp-content/uploads/2016/05/ZB25VQ16.pdf#page=19) */
		.vendor		= "Zbit Semiconductor, Inc.",
		/* Chip name as shown on the datasheet header */
		.name		= "ZB25VQ16",
		/* See 6.1.1 SPI Modes
		 * (https://semic-boutique.com/wp-content/uploads/2016/05/ZB25VQ16.pdf#page=19) */
		.bustype	= BUS_SPI,
		/* See Table 7.4 Manufacturer and Device Identification (ZB25VQ16)
		 * (https://semic-boutique.com/wp-content/uploads/2016/05/ZB25VQ16.pdf#page=33)
		 * The documentation says the values should be 0x5E, 0x6015,
		 * but they're actually 0x0E, 0x4015. */
		.manufacture_id	= ZBIT_ID,
		.model_id	= ZBIT_ZB25VQ16,
		/* See 5.1. Flash Memory Array
		 * (https://semic-boutique.com/wp-content/uploads/2016/05/ZB25VQ16.pdf#page=11) */
		.total_size	= 2048,
		.page_size	= 256,
		.feature_bits	= FEATURE_WRSR_EWSR,
		.tested		= TEST_OK_PR,
		/* See 7.5.4 Read Identification (RDID) (9Fh)
		 * (https://semic-boutique.com/wp-content/uploads/2016/05/ZB25VQ16.pdf#page=48) */
		.probe		= PROBE_SPI_RDID,
		/* No mention of a delay in the docs. */
		.probe_timing	= TIMING_ZERO,

		/*
		 * 5.1. Flash Memory Array
		 * (https://semic-boutique.com/wp-content/uploads/2016/05/ZB25VQ16.pdf#page=11)
		 * The ZB25VQ16 memory is organized as:
		 * - 2,097,152 bytes
		 * - Uniform Sector Architecture 32 blocks of 64-Kbyte
		 * - 512 sectors of 4-Kbyte
		 * - 8,192 pages (256 bytes each)
		 * Each page can be individually programmed (bits are programmed from 1 to 0).
		 * The device is Sector, Block or Chip Erasable but not Page Erasable.
		 */
		.block_erasers	=
		{
			{
				/* See 7.2.3 Sector Erase (SE) (20h)
				 * (https://semic-boutique.com/wp-content/uploads/2016/05/ZB25VQ16.pdf#page=37) */
				.eraseblocks = { {4 * 1024, 512} },
				.block_erase = SPI_BLOCK_ERASE_20,
			}, {
				/* See 7.2.4 Block Erase (BE) (D8h) and Half Block Erase (52h)
				 * (https://semic-boutique.com/wp-content/uploads/2016/05/ZB25VQ16.pdf#page=38) */
				.eraseblocks = { {32 * 1024, 64} },
				.block_erase = SPI_BLOCK_ERASE_52,
			}, {
				/* See 7.2.4 Block Erase (BE) (D8h) and Half Block Erase (52h)
				 * (https://semic-boutique.com/wp-content/uploads/2016/05/ZB25VQ16.pdf#page=38) */
				.eraseblocks = { {64 * 1024, 32} },
				.block_erase = SPI_BLOCK_ERASE_D8,
			}, {
				/* See 7.2.5 Chip Erase (CE) (C7h or 60h)
				 * (https://semic-boutique.com/wp-content/uploads/2016/05/ZB25VQ16.pdf#page=38) */
				.eraseblocks = { {2 * 1024 * 1024, 1} },
				.block_erase = SPI_BLOCK_ERASE_60,
			}, {
				/* See 7.2.5 Chip Erase (CE) (C7h or 60h)
				 * (https://semic-boutique.com/wp-content/uploads/2016/05/ZB25VQ16.pdf#page=38) */
				.eraseblocks = { {2 * 1024 * 1024, 1} },
				.block_erase = SPI_BLOCK_ERASE_C7,
			}
		},
		.printlock	= SPI_PRETTYPRINT_STATUS_REGISTER_PLAIN, /* TODO: improve */
		/* See 7.1.2 Write Enable (06h)
		 * (https://semic-boutique.com/wp-content/uploads/2016/05/ZB25VQ16.pdf#page_34) */
		.unlock		= SPI_DISABLE_BLOCKPROTECT,
		/* See 7.2.1 Page Program (PP) (02h)
		 * (https://semic-boutique.com/wp-content/uploads/2016/05/ZB25VQ16.pdf#page=36) */
		.write		= SPI_CHIP_WRITE256,
		/* 7.3 Read Commands
		 * (https://semic-boutique.com/wp-content/uploads/2016/05/ZB25VQ16.pdf#page_36) */
		.read		= SPI_CHIP_READ,
		/* Table 8.3 Recommended Operating Ranges
		 * (https://semic-boutique.com/wp-content/uploads/2016/05/ZB25VQ16.pdf#page=54) */
		.voltage	= {2700, 3600},
	},

/* See 1. ORDERING INFORMATION */
