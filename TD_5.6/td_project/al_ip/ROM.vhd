--------------------------------------------------------------
 --  Copyright (c) 2011-2022 Anlogic, Inc.
 --  All Right Reserved.
--------------------------------------------------------------
 -- Log	:	This file is generated by Anlogic IP Generator.
 -- File	:	F:/al/sf1_-project-master/sf1_-project-master/src/PWM/td_project/al_ip/ROM.vhd
 -- Date	:	2023 11 13
 -- TD version	:	5.6.59063
--------------------------------------------------------------

LIBRARY ieee;
USE work.ALL;
	USE ieee.std_logic_1164.all;
LIBRARY sf1_macro;
	USE sf1_macro.SF1_COMPONENTS.all;

ENTITY ROM IS
PORT (
	doa		: OUT STD_LOGIC_VECTOR(7 DOWNTO 0);

	addra	: IN STD_LOGIC_VECTOR(9 DOWNTO 0);
	clka		: IN STD_LOGIC;
	rsta		: IN STD_LOGIC
	);
END ROM;

ARCHITECTURE struct OF ROM IS

	BEGIN
	inst : SF1_LOGIC_BRAM
		GENERIC MAP (
			DATA_WIDTH_A	=> 8,
			ADDR_WIDTH_A	=> 10,
			DATA_DEPTH_A	=> 784,
			DATA_WIDTH_B	=> 8,
			ADDR_WIDTH_B	=> 10,
			DATA_DEPTH_B	=> 784,
			MODE			=> "SP",
			REGMODE_A	=> "NOREG",
			IMPLEMENT	=> "9K",
			DEBUGGABLE	=> "NO",
			PACKABLE		=> "NO",
			INIT_FILE	=> "../../../../../../../CNN/CNN_korea/python/output.mif",
			FILL_ALL		=> "NONE"
		)
		PORT MAP (
			dia		=> (others=>'0'),
			dib		=> (others=>'0'),
			addra	=> addra,
			addrb	=> (others=>'0'),
			cea		=> '1',
			ceb		=> '0',
			clka		=> clka,
			clkb		=> '0',
			web		=> '0',
			rsta		=> rsta,
			rstb		=> '0',
			doa		=> doa,
			dob		=> OPEN,
			ocea		=> '0',
			oceb		=> '0'
		);

END struct;
