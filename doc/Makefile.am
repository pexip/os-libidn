## Process this file with automake to produce Makefile.in
# Copyright (C) 2002-2022 Simon Josefsson.
#
# This file is part of GNU Libidn.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

SUBDIRS = specifications tld java cyclo
if ENABLE_GTK_DOC
SUBDIRS += . reference
endif

EXTRA_DIST = gdoc components.fig stamp-gdoc

info_TEXINFOS = libidn.texi
libidn_TEXINFOS = fdl-1.3.texi idn-help.texi
libidn_TEXINFOS += texinfo.css example.txt example2.txt example3.txt example4.txt example5.txt
libidn_TEXINFOS += $(gdoc_TEXINFOS)
libidn_TEXINFOS += libidn-components.eps libidn-components.png	\
			libidn-components.pdf

AM_MAKEINFOHTMLFLAGS = $(AM_MAKEINFOFLAGS) \
	--no-split --css-include=texinfo.css

imagesdir = $(infodir)
images_DATA = libidn-components.png

libidn-components.eps: components.fig
	$(AM_V_GEN)fig2dev -L eps $(srcdir)/components.fig $@

libidn-components.png: components.fig
	$(AM_V_GEN)fig2dev -L png $(srcdir)/components.fig $@

libidn-components.pdf: components.fig
	$(AM_V_GEN)fig2dev -L pdf $(srcdir)/components.fig $@

idn-help.texi: $(top_srcdir)/src/idn.c
	$(AM_V_GEN)$(top_builddir)/src/idn$(EXEEXT) --help | $(GREP) '^  *-' > tmp && \
		mv tmp idn-help.texi

example.txt: $(top_srcdir)/examples/example.c
	$(AM_V_GEN)sed -e '/* example/,/^$$/d' $(top_srcdir)/examples/example.c > $@.tmp && \
		mv $@.tmp $@

example2.txt: $(top_srcdir)/examples/example2.c
	$(AM_V_GEN)sed -e '/* example/,/^$$/d' $(top_srcdir)/examples/example2.c > $@.tmp && \
		mv $@.tmp $@

example3.txt: $(top_srcdir)/examples/example3.c
	$(AM_V_GEN)sed -e '/* example/,/^$$/d' $(top_srcdir)/examples/example3.c > $@.tmp && \
		mv $@.tmp $@

example4.txt: $(top_srcdir)/examples/example4.c
	$(AM_V_GEN)sed -e '/* example/,/^$$/d' $(top_srcdir)/examples/example4.c > $@.tmp && \
		mv $@.tmp $@

example5.txt: $(top_srcdir)/examples/example5.c
	$(AM_V_GEN)sed -e '/* example/,/^$$/d' $(top_srcdir)/examples/example5.c > $@.tmp && \
		mv $@.tmp $@

BUILT_SOURCES = example.txt example2.txt example3.txt example4.txt example5.txt

# Man pages.

dist_man_MANS = idn.1 $(gdoc_MANS)
MAINTAINERCLEANFILES = $(dist_man_MANS)

idn.1: $(top_srcdir)/src/idn.c $(top_srcdir)/src/idn.ggo $(top_srcdir)/.version
	$(MAKE) -C ../lib
	$(MAKE) -C ../src
	$(AM_V_GEN)$(HELP2MAN) \
		--name="Internationalized Domain Names command line tool" \
		--output=$@ $(top_builddir)/src/idn$(EXEEXT)

# GDOC

gdoc_TEXINFOS =
gdoc_TEXINFOS += texi/idna_to_ascii_4i.texi
gdoc_TEXINFOS += texi/idna_to_unicode_44i.texi
gdoc_TEXINFOS += texi/idna_to_ascii_4z.texi
gdoc_TEXINFOS += texi/idna_to_ascii_8z.texi
gdoc_TEXINFOS += texi/idna_to_ascii_lz.texi
gdoc_TEXINFOS += texi/idna_to_unicode_4z4z.texi
gdoc_TEXINFOS += texi/idna_to_unicode_8z4z.texi
gdoc_TEXINFOS += texi/idna_to_unicode_8z8z.texi
gdoc_TEXINFOS += texi/idna_to_unicode_8zlz.texi
gdoc_TEXINFOS += texi/idna_to_unicode_lzlz.texi
gdoc_TEXINFOS += texi/stringprep_utf8_to_unichar.texi
gdoc_TEXINFOS += texi/stringprep_unichar_to_utf8.texi
gdoc_TEXINFOS += texi/stringprep_utf8_to_ucs4.texi
gdoc_TEXINFOS += texi/stringprep_ucs4_to_utf8.texi
gdoc_TEXINFOS += texi/stringprep_utf8_nfkc_normalize.texi
gdoc_TEXINFOS += texi/stringprep_ucs4_nfkc_normalize.texi
gdoc_TEXINFOS += texi/pr29_4.texi
gdoc_TEXINFOS += texi/pr29_4z.texi
gdoc_TEXINFOS += texi/pr29_8z.texi
gdoc_TEXINFOS += texi/punycode_encode.texi
gdoc_TEXINFOS += texi/punycode_decode.texi
gdoc_TEXINFOS += texi/stringprep_4i.texi
gdoc_TEXINFOS += texi/stringprep_4zi.texi
gdoc_TEXINFOS += texi/stringprep.texi
gdoc_TEXINFOS += texi/stringprep_profile.texi
gdoc_TEXINFOS += texi/tld_get_table.texi
gdoc_TEXINFOS += texi/tld_default_table.texi
gdoc_TEXINFOS += texi/tld_get_4.texi
gdoc_TEXINFOS += texi/tld_get_4z.texi
gdoc_TEXINFOS += texi/tld_get_z.texi
gdoc_TEXINFOS += texi/tld_check_4t.texi
gdoc_TEXINFOS += texi/tld_check_4tz.texi
gdoc_TEXINFOS += texi/tld_check_4.texi
gdoc_TEXINFOS += texi/tld_check_4z.texi
gdoc_TEXINFOS += texi/tld_check_8z.texi
gdoc_TEXINFOS += texi/tld_check_lz.texi
gdoc_TEXINFOS += texi/stringprep_locale_charset.texi
gdoc_TEXINFOS += texi/stringprep_convert.texi
gdoc_TEXINFOS += texi/stringprep_locale_to_utf8.texi
gdoc_TEXINFOS += texi/stringprep_utf8_to_locale.texi
gdoc_TEXINFOS += texi/stringprep_check_version.texi
gdoc_TEXINFOS += texi/idn_free.texi
gdoc_TEXINFOS += texi/idna_strerror.texi
gdoc_TEXINFOS += texi/pr29_strerror.texi
gdoc_TEXINFOS += texi/punycode_strerror.texi
gdoc_TEXINFOS += texi/stringprep_strerror.texi
gdoc_TEXINFOS += texi/tld_strerror.texi
gdoc_MANS =
gdoc_MANS += man/idna_to_ascii_4i.3
gdoc_MANS += man/idna_to_unicode_44i.3
gdoc_MANS += man/idna_to_ascii_4z.3
gdoc_MANS += man/idna_to_ascii_8z.3
gdoc_MANS += man/idna_to_ascii_lz.3
gdoc_MANS += man/idna_to_unicode_4z4z.3
gdoc_MANS += man/idna_to_unicode_8z4z.3
gdoc_MANS += man/idna_to_unicode_8z8z.3
gdoc_MANS += man/idna_to_unicode_8zlz.3
gdoc_MANS += man/idna_to_unicode_lzlz.3
gdoc_MANS += man/stringprep_utf8_to_unichar.3
gdoc_MANS += man/stringprep_unichar_to_utf8.3
gdoc_MANS += man/stringprep_utf8_to_ucs4.3
gdoc_MANS += man/stringprep_ucs4_to_utf8.3
gdoc_MANS += man/stringprep_utf8_nfkc_normalize.3
gdoc_MANS += man/stringprep_ucs4_nfkc_normalize.3
gdoc_MANS += man/pr29_4.3
gdoc_MANS += man/pr29_4z.3
gdoc_MANS += man/pr29_8z.3
gdoc_MANS += man/punycode_encode.3
gdoc_MANS += man/punycode_decode.3
gdoc_MANS += man/stringprep_4i.3
gdoc_MANS += man/stringprep_4zi.3
gdoc_MANS += man/stringprep.3
gdoc_MANS += man/stringprep_profile.3
gdoc_MANS += man/tld_get_table.3
gdoc_MANS += man/tld_default_table.3
gdoc_MANS += man/tld_get_4.3
gdoc_MANS += man/tld_get_4z.3
gdoc_MANS += man/tld_get_z.3
gdoc_MANS += man/tld_check_4t.3
gdoc_MANS += man/tld_check_4tz.3
gdoc_MANS += man/tld_check_4.3
gdoc_MANS += man/tld_check_4z.3
gdoc_MANS += man/tld_check_8z.3
gdoc_MANS += man/tld_check_lz.3
gdoc_MANS += man/stringprep_locale_charset.3
gdoc_MANS += man/stringprep_convert.3
gdoc_MANS += man/stringprep_locale_to_utf8.3
gdoc_MANS += man/stringprep_utf8_to_locale.3
gdoc_MANS += man/stringprep_check_version.3
gdoc_MANS += man/idn_free.3
gdoc_MANS += man/idna_strerror.3
gdoc_MANS += man/pr29_strerror.3
gdoc_MANS += man/punycode_strerror.3
gdoc_MANS += man/stringprep_strerror.3
gdoc_MANS += man/tld_strerror.3

BUILT_SOURCES += $(gdoc_MANS) $(gdoc_TEXINFOS)

GDOC_SRC = $(top_srcdir)/lib/idna.c $(top_srcdir)/lib/nfkc.c	\
	$(top_srcdir)/lib/pr29.c $(top_srcdir)/lib/punycode.c	\
	$(top_srcdir)/lib/stringprep.c $(top_srcdir)/lib/tld.c	\
	$(top_srcdir)/lib/toutf8.c $(top_srcdir)/lib/version.c \
	$(top_srcdir)/lib/idn-free.c \
	$(top_srcdir)/lib/strerror-idna.c $(top_srcdir)/lib/strerror-pr29.c \
	$(top_srcdir)/lib/strerror-punycode.c \
	$(top_srcdir)/lib/strerror-stringprep.c \
	$(top_srcdir)/lib/strerror-tld.c

.PHONY: compare-makefile

compare-makefile:
	$(AM_V_GEN) \
	MANS=""; \
	TEXINFOS=""; \
	FUNCS=`$(srcdir)/gdoc -listfunc $(GDOC_SRC)`; \
	for i in $$FUNCS; do \
		MANS="$$MANS\ngdoc_MANS += man/$$i.3"; \
		TEXINFOS="$$TEXINFOS\ngdoc_TEXINFOS += texi/$$i.texi"; \
	done && \
	grep -v -e '^gdoc_MANS += ' -e '^gdoc_TEXINFOS += ' $(srcdir)/Makefile.am | \
		perl -p -e "s,^gdoc_MANS =,gdoc_MANS =$$MANS,;" | \
		perl -p -e "s,^gdoc_TEXINFOS =,gdoc_TEXINFOS =$$TEXINFOS,;" \
		> tmp-$@ && \
	diff -u $(srcdir)/Makefile.am tmp-$@ && \
	rm -f tmp-$@

$(gdoc_MANS) $(gdoc_TEXINFOS): stamp-gdoc

clean-local:
	-rm -f stamp-gdoc

stamp-gdoc: $(top_builddir)/.version $(GDOC_SRC)
	$(AM_V_at)$(MKDIR_P) man texi
	$(AM_V_GEN)for i in `$(srcdir)/gdoc -listfunc $(GDOC_SRC)`; do \
		$(srcdir)/gdoc -man \
			-bugsto $(PACKAGE_BUGREPORT) \
			-module $(PACKAGE) \
			-pkg-name "$(PACKAGE_NAME)" \
			-sourceversion $(VERSION) \
			-includefuncprefix \
			-seeinfo $(PACKAGE) \
			-verbatimcopying \
			-copyright "2002-2022 Simon Josefsson" \
			-function $$i \
			$(GDOC_SRC) > man/$$i.3 && \
		$(srcdir)/gdoc -texinfo -function $$i \
			$(GDOC_SRC) > texi/$$i.texi; \
	done
	$(AM_V_at)touch $@
