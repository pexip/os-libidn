/* tst_version.c --- Version number sanity checks.
 * Copyright (C) 2022 Simon Josefsson
 *
 * This file is part of GNU Libidn.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <stdio.h>

#include <stringprep.h>

#include "utils.h"

void
doit (void)
{
  if (debug)
    {
      printf ("stringprep_check_version %s\n",
	      stringprep_check_version (NULL));
      printf ("STRINGPREP_VERSION %s\n", STRINGPREP_VERSION);
#ifdef PACKAGE_VERSION
      printf ("PACKAGE_VERSION %s\n", PACKAGE_VERSION);
#endif
    }

  if (!stringprep_check_version (STRINGPREP_VERSION))
    fail ("stringprep_check_version(STRINGPREP_VERSION) failed\n");

  if (!stringprep_check_version (NULL))
    fail ("stringprep_check_version(NULL) failed\n");

#ifdef PACKAGE_VERSION
  if (!stringprep_check_version (PACKAGE_VERSION))
    fail ("stringprep_check_version (PACKAGE_VERSION) == NULL\n");
#endif

  if (!stringprep_check_version ("0.0"))
    fail ("stringprep_check_version(\"0.0\") failed\n");

  if (!stringprep_check_version ("1"))
    fail ("stringprep_check_version(\"1\") failed\n");

  if (!stringprep_check_version ("1.1"))
    fail ("stringprep_check_version(\"1.1\") failed\n");

  if (stringprep_check_version ("100.100"))
    fail ("stringprep_check_version(\"100.100\") failed\n");

  if (!stringprep_check_version ("1.40"))
    fail ("stringprep_check_version(\"1.40\") failed\n");
}
