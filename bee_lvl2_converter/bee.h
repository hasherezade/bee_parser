#pragma once

#include <Windows.h>
#include <iostream>

const WORD MAGIC1 = 0x454e;
const DWORD MAGIC2 = 0x0EF1FAB9;

enum BEE_TYPE {
	BEE_NONE,
	BEE_SCRAMBLED1,
	BEE_SCRAMBLED2
};

typedef struct {
	WORD magic; // 0x454e
	WORD machine_id;
	WORD pe_offset;
} t_scrambled1;

typedef struct {
	DWORD magic; // 0x0EF1FAB9
	WORD machine_id;
	WORD pe_offset;
} t_scrambled2;

BEE_TYPE check_type(BYTE *buf, size_t buf_size);

bool unscramble_bee_to_pe(BYTE *buf, size_t buf_size);

