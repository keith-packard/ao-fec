/*
 * Copyright © 2012 Keith Packard <keithp@keithp.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 */

/* Generate the data whitening array used by the CC11* radios */

#include <stdio.h>

int pn9 = 0x1ff;

void
pn9_step() {
	pn9 = (pn9 >> 1) | (((pn9 ^ (pn9 >> 5)) & 1) << 8);
}

int val()
{
	int	ret = pn9 & 0xff;

	for (int i = 0; i < 8; i++)
		pn9_step();
	return ret;
}

int main() {
    for (int i = 0; i < 128; i++)
	printf (" /* %3d */ 0x%02x,\n", i + 1, val());
    return 0;
}
